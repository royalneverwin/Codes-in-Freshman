#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
struct Node;
typedef struct Node * PNode;
struct Node{
    char info;
    PNode link;
};
struct LinkStack{
    PNode top;
};
typedef struct LinkStack * PLinkStack;
PNode createNullStack(void){
    PNode plstack;
    plstack = (PNode)malloc(sizeof(struct Node));
    if(plstack){
        plstack->link = NULL;
        return plstack;
    }
    else{
        return NULL;
    }
}
int push(PLinkStack plstack, char info){
    PNode p ;
    p = (PNode)malloc(sizeof(struct Node));
    if(p){
        p->info = info;
        p->link = plstack->top;
        plstack->top = p;
        return 1;
    }
    else{
        return 0;
    }
}
void pop(PLinkStack plstack){
    PNode p;
    p = plstack->top;
    if(p->link != NULL) {
        plstack->top = p->link;
    }
    else{
        plstack->top = NULL;
    }
    free(p);
}
int isEmptyStack(PLinkStack plstack){
    if(plstack->top->link == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    PLinkStack plstack;
    PNode p, q;
    p = q = NULL;
    plstack = (PLinkStack)malloc(sizeof(struct LinkStack));
    plstack->top = createNullStack();
    char c;
    while((c = getchar()) != EOF){
        push(plstack, c);
        if(plstack->top->link->link != NULL){
            p = plstack->top;
            q = plstack->top->link;
            if((p->info == ')' && q->info == '(') || (p->info == '}' && q->info == '{') || (p->info == ']' && q->info == '[')){
                pop(plstack);
                pop(plstack);
            }
        }
    }
    if(isEmptyStack(plstack)){
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}

