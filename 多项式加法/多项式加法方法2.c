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
    int n;
    scanf("%d", &n);
    int i;
    int ci, xi;
    char c;
    PLinkList p1, p2, p3;
    PNode temp1, temp2;
    for(i= 0; i < n; i++){
        p1 = createNulllist_Link();
        p2 = createNulllist_Link();
        p3 = createNulllist_Link();
        scanf("%d%d", &xi, &ci);
        while(ci >= 0){
            insert(p1, xi, ci);
//            Insert_Link(p1, xi, ci);
            scanf("%d%d", &xi, &ci);
        }
        insert(p1, xi, ci);
//        Insert_Link(p1, xi, ci);
        scanf("%d%d", &xi, &ci);
        while(ci >= 0){
            insert(p2, xi, ci);
//            Insert_Link(p2, xi, ci);
            scanf("%d%d", &xi, &ci);
        }
        insert(p2, xi, ci);
//        Insert_Link(p2, xi, ci);
        temp1 = p1->head->link;
        temp2 = p2->head->link;
        while(temp1->ci >= 0 && temp2->ci >= 0){
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
        while(temp1->ci >= 0){
            insert(p3, temp1->xi, temp1->ci);
            temp1 = temp1->link;
        }
        while(temp2->ci >= 0){
            insert(p3, temp2->xi, temp2->ci);
            temp2 = temp2->link;
        }
        temp1 = p3->head->link;
        while(temp1 != NULL){
            if(temp1->xi != 0) {
                printf("[ %d %d ] ", temp1->xi, temp1->ci);
            }
            temp1 = temp1->link;
        }
        putchar('\n');
    }
    return 0;
}