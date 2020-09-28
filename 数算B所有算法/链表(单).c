#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAXIMUM 100
#define SPECIAL INT_MAX
struct Node;
typedef struct Node *PNode;
struct Node{
    int info;
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


int Insert_Link(PLinkList plist, int x){
    PNode q, p;
    p = plist->head;
    q = (PNode)malloc( sizeof( struct Node ) );
    if( q == NULL ){
        printf( "Out of space!!! \n" );
        return 0;
    }
    else{
        q->info = x;
        if(p->link != NULL){
            p = p->link;
        }
        p->link = q;
        q->link = NULL;
        return 1;
    }
}


int Delete_Link(PLinkList plist, int x){
    PNode p, q;
    p = plist->head->link;
    q = plist->head;
    if(p == NULL){
        printf("Null list!\n");
        return 0;
    }
    while(p != NULL){
        if(p->info == x){
            q->link = p->link;
            free(p);
            return 1;
        }
        else{
            p = p->link;
            q = p;
        }
    }
    printf("No find.\n");
    return 0;
}


PNode Locate_Link(PLinkList plist, int x){
    PNode temp;
    temp = plist->head->link;
    while(temp != NULL){
        if(temp->info == x){
            return temp;
        }
        else{
            temp = temp->link;
        }
    }
    return NULL;
}


int IsNull_Link(PLinkList plist){
    if(plist->head->link == NULL){
        return 1;
    }
    else{
        return 0;
    }
}