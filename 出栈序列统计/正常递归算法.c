#include <stdio.h>
#include <stdlib.h>
#define MAX 15
int n;
int time = 0;
struct SeqStack{
    int s[MAX+1];
    int t;
};
typedef struct SeqStack * PSeqStack;
PSeqStack createNullStack(void){
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
int push(PSeqStack plstack, char info){
    plstack->t++;
    if(plstack->t < MAX) {
        plstack->s[plstack->t] = info;
        return 1;
    }
    else{
        return 0;
    }
}
void pop(PSeqStack plstack){
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
void PushPop(PSeqStack plstack, int num){
    if(num > n){
        time++;
    }
    else{
        if(plstack->t == -1){
            push(plstack, num);
            PushPop(plstack, num+1);
        }
        else{
            struct SeqStack temp;
            temp = *plstack;
            pop(plstack);
            PushPop(plstack, num);
            *plstack = temp;
            push(plstack, num);
            PushPop(plstack, num+1);
        }
    }
}
int main(){
    PSeqStack plstack;
    plstack = createNullStack();
    scanf("%d", &n);
    PushPop(plstack, 1);
    printf("%d", time);
    return 0;
}

