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


int main(){
    int t;
    int n;
    int num[1001];
    scanf("%d", &t);
    int i, j, k;
    int pu, w;
    int flag = 1;
    for(i = 1; i <= t; i++){
        flag = 1;
        scanf("%d", &n);
        for(j = 0; j < n; j++){
            scanf("%d", &num[j]);
        }
        PSeqStack p;
        p = createEmptyStack_seq(n);
        pu = 1;
        for(k = 0; k < n; k++) {
            if(pu <= num[k]) {
                for (j = pu; j <= num[k]; j++) {
                    push_seq(p, j);
                }
                pop_seq(p);
                pu = num[k] + 1;
            } else{
                w = Pop_Seq(p);
//                printf("%d %d\n", w, num[k]);
                if(w != num[k]){
                    printf("no\n");
                    flag = 0;
                    break;
                }
            }
//            for(j = 0; j <= p->t; j++){
//                printf("%d ", p->s[j]);
//            }
//            putchar('\n');
        }
        if(flag == 1){
            printf("yes\n");
        }
        free(p);
    }
    return 0;
}