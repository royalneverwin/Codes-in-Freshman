#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
struct SeqStack{
    char s[MAX+1];
    int t;
};
typedef struct SeqStack * PSeqStack;
PSeqStack createNullStack(void){//????
    PSeqStack plstack;
    plstack = (PSeqStack)malloc(sizeof(struct SeqStack));
    if(plstack){
        plstack->t = -1;
        return plstack;
    }
    else{
        return NULL;
    }
}
int push(PSeqStack plstack, char info){//???????
    plstack->t++;
    if(plstack->t < MAX) {
        plstack->s[plstack->t] = info;
        return 1;
    }
    else{
        return 0;
    }
}
void pop(PSeqStack plstack){//??????
    if(plstack->t > -1) {
        plstack->t--;
    }
}
int isEmptyStack(PSeqStack plstack){
    if(plstack->t == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    PSeqStack plstack;
    plstack = createNullStack();
    char c;
    char p, q;
    while((c = getchar()) != EOF){
        push(plstack, c);
        if(plstack->t >= 1){
            p = plstack->s[plstack->t];
            q = plstack->s[plstack->t-1];
            if((p == ')' && q == '(') || (p == '}' && q == '{') || (p == ']' && q == '[')){//???????????
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

