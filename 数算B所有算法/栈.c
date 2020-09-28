#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 1000
struct SeqStack{
    int *s;
    int t;
};
typedef struct SeqStack *PSeqStack;


PSeqStack createEmptyStack_seq(int m){
    PSeqStack pastack;
    pastack = (PSeqStack)malloc(sizeof(struct SeqStack));
    if(pastack != NULL){
        pastack->s = (int *)malloc(sizeof(int) * m);
        if(pastack->s != NULL){
            pastack->t = -1;
            return pastack;
        }
        else{
            free(pastack);
        }
    }
    printf("out of space!\n");
    return NULL;
}


int isEmptyStack_seq( PSeqStack plstack )
{
    return (plstack->t == -1);
}


int push_seq(PSeqStack pastack, int x){
    if(pastack->t >= MAXNUM - 1){
        printf("overflow!\n");
        return 0;
    }
    else{
        pastack->t++;
        pastack->s[pastack->t] = x;
        return 1;
    }
}


void pop_seq(PSeqStack pastack){
    if(pastack->t == -1){
        printf("Underflow!\n");
    }
    else{
        pastack->t--;
    }
}


int Pop_Seq(PSeqStack pastack){
    int temp;
    if(pastack->t == -1){
        printf("Underflow!\n");
        return 0;
    }
    else{
        temp = pastack->s[pastack->t];
        pastack->t--;
        return temp;
    }
}


struct Node;
typedef struct Node *PNode;
struct Node{
    int info;
    PNode link;
};
struct LinkStack{
    PNode top;
};
typedef struct LinkStack *PLinkStack;


PLinkStack CreateEmptyStack_link(void){
    PLinkStack plstack;
    plstack = (PLinkStack)malloc(sizeof(struct LinkStack));
    if(plstack != NULL){
        plstack->top = NULL;
    }
    else{
        printf("Not enough space!\n");
    }
    return plstack;
}


int isEmptyStack_link( PLinkStack plstack)
{
    return (plstack->top == NULL);
}


int push_link(PLinkStack plstack, int x){
    PNode p;
    p = (PNode)malloc(sizeof(struct Node));
    if(p == NULL){
        printf("Out of space!\n");
        return 0;
    }
    else{
        p->info = x;
        p->link = plstack->top;
        plstack->top = p;
        return 1;
    }
}


void pop_link(PLinkStack plstack){
    PNode p;
    if(isEmptyStack_link(plstack)){
        printf("Empty stack pop.\n");
    }
    else{
        p = plstack->top;
        plstack->top = p->link;
        free(p);
    }
}



int Pop_Link( PLinkStack plstack)
{
    PNode p;
    int temp;
    if(isEmptyStack_link( plstack ) )
    {
        printf("Empty stack pop. \n");
        return 0;
    }
    else
    {
        p = plstack->top;
        temp = p->info;
        plstack->top = p->link;
        free(p);
        return temp;
    }
}


int GetTop( PLinkStack plstack )
{
    return plstack->top->info;
}
