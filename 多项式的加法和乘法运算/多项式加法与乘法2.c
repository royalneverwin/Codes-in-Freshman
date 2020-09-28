#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAXIMUM 100
#define SPECIAL INT_MAX
struct Node;
typedef struct Node *PNode;
struct Node{
    int ci;
    int xi;
    PNode link;
};
struct LinkList{
    PNode head;
};
typedef struct LinkList *PLinkList;


struct DoubleNode{
    int info;
    struct DoubleNode *llink, *rlink;
};
typedef struct DoubleNode *PDoubleNode;
struct DoubleList{
    PDoubleNode head;
    PDoubleNode rear;
};
typedef struct DoubleList *PDoubleList;


PLinkList createNulllist_Link(void){
    PLinkList plist;
    PNode p;
    plist = (PLinkList)malloc(sizeof(struct LinkList));
    if(plist != NULL){
        p = (PNode)malloc(sizeof(struct Node));
        if(p != NULL){
            plist->head = p;
            p->link = NULL;
        }
        else{
            plist->head = NULL;
        }
    }
    else{
        printf("out of space!\n");
        return NULL;
    }
    return plist;
}


int Insert_Link(PLinkList plist, int xi, int ci){
    PNode q, p;
    p = plist->head;
    q = (PNode)malloc( sizeof( struct Node ) );
    if( q == NULL ){
        printf( "Out of space!!! \n" );
        return 0;
    }
    else{
        q->xi = xi;
        q->ci = ci;
        if(p->link != NULL){
            p = p->link;
        }
        p->link = q;
        q->link = NULL;
        return 1;
    }
}


void insert(PLinkList plist, int xi, int ci){
    PNode q, p, temp;
    p = plist->head;
    q = (PNode)malloc(sizeof(struct Node));
    q->xi = xi;
    q->ci = ci;
    q->link = NULL;
    if(p->link == NULL){
        p->link = q;
    }
    else{
        temp = p;
        p = p->link;
        while(p->ci > q->ci && p->link != NULL){
            temp = p;
            p = p->link;
        }
        if(p->link == NULL && p->ci > q->ci){
            p->link = q;
        }
        else if(p->ci == q->ci){
            p->xi += q->xi;
            free(q);
        }
        else{
            temp->link = q;
            q->link = p;
        }
    }
}


int main(){
    int ci, xi;
    char c;
    PLinkList p1, p2, p3, p4;
    PNode temp1, temp2;
    p1 = createNulllist_Link();
    p2 = createNulllist_Link();
    p3 = createNulllist_Link();
    p4 = createNulllist_Link();
    scanf("%d%d", &xi, &ci);
    while(ci != 0 || xi != 0){
        insert(p1, xi, ci);
//            Insert_Link(p1, xi, ci);
        scanf("%d%d", &xi, &ci);
    }
    scanf("%d%d", &xi, &ci);
    while(ci != 0 || xi != 0){
        insert(p2, xi, ci);
//            Insert_Link(p2, xi, ci);
        scanf("%d%d", &xi, &ci);
    }
    temp1 = p1->head->link;
    temp2 = p2->head->link;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->ci > temp2->ci){
            insert(p3, temp1->xi, temp1->ci);
            temp1 = temp1->link;
        }
        else if(temp1->ci == temp2->ci){
            insert(p3, temp1->xi+temp2->xi, temp1->ci);
            temp1 = temp1->link;
            temp2 = temp2->link;
        }
        else{
            insert(p3, temp2->xi, temp2->ci);
            temp2 = temp2->link;
        }
    }
    while(temp1 != NULL){
        insert(p3, temp1->xi, temp1->ci);
        temp1 = temp1->link;
    }
    while(temp2 != NULL){
        insert(p3, temp2->xi, temp2->ci);
        temp2 = temp2->link;
    }
    temp1 = p3->head->link;
    int flag = 1;
    while(temp1 != NULL){
        if(temp1->xi != 0) {
            if(temp1->xi > 0){
                if(flag != 1){
                    if(temp1->xi == 1){
                        printf("+");
                    }
                    else {
                        printf("+%d", temp1->xi);
                    }
                }
                else{
                    if(temp1->xi != 1) {
                        printf("%d", temp1->xi);
                    }
                }
            }
            else{
                if(temp1->xi == -1){
                    printf("-");
                }
                else {
                    printf("%d", temp1->xi);
                }
            }
            if(temp1->ci > 1){
                printf("x^%d", temp1->ci);
            }
            else if(temp1->ci == 1){
                printf("x");
            }
            flag = 0;
        }
        temp1 = temp1->link;
    }
    putchar('\n');
    temp1 = p1->head->link;
    temp2 = p2->head->link;
    while(temp2 != NULL){
        while(temp1 != NULL){
            insert(p4, temp1->xi * temp2->xi, temp1->ci + temp2->ci);
            temp1 = temp1->link;
        }
        temp1 = p1->head->link;
        temp2 = temp2->link;
    }
    temp1 = p4->head->link;
    flag = 1;
    while(temp1 != NULL){
        if(temp1->xi != 0) {
            if(temp1->xi > 0){
                if(flag != 1){
                    if(temp1->xi == 1){
                        printf("+");
                    }
                    else {
                        printf("+%d", temp1->xi);
                    }
                }
                else{
                    if(temp1->xi != 1) {
                        printf("%d", temp1->xi);
                    }
                }
            }
            else{
                if(temp1->xi == -1){
                    printf("-");
                }
                else {
                    printf("%d", temp1->xi);
                }
            }
            if(temp1->ci > 1){
                printf("x^%d", temp1->ci);
            }
            else if(temp1->ci == 1){
                printf("x");
            }
            flag = 0;
        }
        temp1 = temp1->link;
    }
    return 0;
}