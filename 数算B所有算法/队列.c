#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 1000
struct SeqQueue{
    int q[MAXNUM];
    int f, r;
};
typedef struct SeqQueue *PSeqQueue;


PSeqQueue createEmptyQueue_seq( void )
{
    PSeqQueue paqu;
    paqu = (struct SeqQueue *)malloc(sizeof(struct SeqQueue));
    if (paqu==NULL) printf("Out of space! \n");
    else
    {
        paqu->f = 0;
        paqu->r = 0;
    }
    return paqu;
}


void enQueue_seq(PSeqQueue paqu, int x){
    if((paqu->r+1) % MAXNUM == paqu->f){
        printf("Full.\n");
    }
    else{
        paqu->q[paqu->r] = x;
        paqu->r = (paqu->r + 1) % MAXNUM;
    }
}


int isEmptyQueue_seq( PSeqQueue paqu )
{
    return (paqu->f == paqu->r);
}


void deQueue_seq(PSeqQueue paqu){
    if(paqu->f == paqu->r){
        printf("Empty Queue.\n");
    }
    else{
        paqu->f = (paqu->f + 1) % MAXNUM;
    }
}


int frontQueue_seq( PSeqQueue paqu )
{
    return paqu->q[paqu->f];
}


struct Node;
typedef struct Node *PNode;
struct Node{
    int info;
    PNode link;
};
struct LinkQueue{
    PNode f;
    PNode r;
};
typedef struct LinkQueue *PLinkQueue;


PLinkQueue createEmptyQueue_link( )
{
    PLinkQueue plqu;
    plqu = (struct LinkQueue *)malloc(sizeof(struct LinkQueue));
    if (plqu != NULL)
    {
        plqu->f = NULL;
        plqu->r = NULL;
    }
    else printf("Out of space!! \n");
    return (plqu);
}


int isEmptyQueue_link( PLinkQueue plqu )
{
    return (plqu->f == NULL);
}


void enQueue_link(PLinkQueue plqu, int x){
    PNode p;
    p = (PNode)malloc(sizeof(struct Node));
    if(p == NULL){
        printf("Out of space!\n");
    }
    else{
        p->info = x;
        p->link = NULL;
        if(plqu->f == NULL){
            plqu->f = p;
            plqu->r = p;
        }
        else{
            plqu->r->link = p;
            plqu->r = p;
        }
    }
}


void deQueue_link(PLinkQueue plqu){
    PNode p;
    if(plqu->f == NULL){
        printf("Empty queue.\n");
    }
    else{
        p = plqu->f;
        plqu->f = p->link;
        free(p);
    }
}


int frontQueue_link( PLinkQueue plqu )
{
    return plqu->f->info;
}