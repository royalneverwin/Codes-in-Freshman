#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAXIMUM 100
#define SPECIAL INT_MAX
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
    if(p < 0 || p > palist->n-1){
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


int locate(PSeqlist palist ,int x){
    int  q;
    for (q = 0; q < palist->n ; q++) {
        if (palist->element[q] == x) {
            return q;
        }
    }
    return  -1;
}


int retrieve(PSeqlist palist, int p){
    if(p >= 0 && p < palist->n){
        return palist->element[p];
    }
    printf("not exist!\n");
    return SPECIAL;
}


int next(PSeqlist palist, int p){
    if (( p >= 0 )&&( p < palist->n - 1 )) {
        return palist->element[p + 1];
    }
    else {
        return SPECIAL;
    }
}


int previous(PSeqlist palist, int p){
    if (p > 0  &&  p < palist->n) {
        return palist->element[p - 1];
    }
    else
        return SPECIAL;
}


int isNUllList(PSeqlist palist){
    return (palist->n == 0);
}

