#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 1000
struct Seqlist{
    int *element;
    int n;
};
typedef struct Seqlist *PSeqlist;


PSeqlist createNullList_seq(int m){
    PSeqlist palist;
    palist = (PSeqlist)malloc(sizeof(struct Seqlist));
    if(palist != NULL){
        palist->element = (int *)malloc(sizeof(int) * m);
        if(palist->element != NULL){
            palist->n = 0;
            return palist;
        }
        else{
            free(palist);
        }
    }
    printf("Out of space!\n");
    return NULL;
}


int insert(PSeqlist palist, int p, int x) {
    int q;
    if(p < 0 || p > MAXNUM-1){
        printf("not exist!\n");
        return 0;
    }
    for(q = palist->n-1; q >= p; q--){
        palist->element[q+1] = palist->element[q];
    }
    palist->element[p] = x;
    palist->n = palist->n + 1;
    return 1;
}


int delete(PSeqlist palist, int p){
    int q;
    if(p < 0 || p > palist->n-1){
        printf("not exist!\n");
        return 0;
    }
    for(q = p; q < palist->n-1; q++){
        palist->element[q] = palist->element[q+1];
    }
    palist->n = palist->n - 1;
    return 1;
}


int main(){
    PSeqlist p;
    int i, j;
    int m, n;
    int locat;
    scanf("%d %d", &n, &m);
    while(m != 0 && n != 0) {
        locat = 0;
        p = createNullList_seq(n);
        for(i = 0; i < n; i++){
            insert(p, i, i+1);
        }
        while(p->n > 1){
            locat = (locat+m-1) % p->n;
            delete(p, locat);
            locat = locat % p->n;
        }
        printf("%d\n", p->element[0]);
        scanf("%d %d", &n, &m);
        free(p);
    }
}