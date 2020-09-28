#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 300
struct Seqlist{
    int element[MAXNUM];
    int n;
};
typedef struct Seqlist *PSeqlist;
PSeqlist createNullList(int n){
    PSeqlist palist;
    palist = (PSeqlist)malloc(sizeof(struct Seqlist));
    if (palist != NULL){
        palist->n = n;
        int i;
        for(i=1;i<=n;i++){
            palist->element[i-1] = i;
        }
        for(i = n+1; i<= MAXNUM;i++){
            palist->element[i-1] = 0;
        }
        return palist;
    }
    return NULL;
}
int Delete(PSeqlist monkey, int delete){
    int q;
    if(delete < 0 || delete > monkey->n-1){
        return 0;
    }
    for(q = delete; q<monkey->n-1;q++){
        monkey->element[q] = monkey->element[q+1];
    }
    monkey->element[monkey->n-1] = 0;
    monkey->n--;
    return 1;
}
int main(){
    int n, m, delete, start;
    while(1){
        start = 0;
        scanf("%d%d", &n, &m);
        if(n == 0||m == 0){
            return 0;
        }
        PSeqlist monkey = createNullList(n);
        int i;
        for(i = n;i>1;i--) {
            delete = (m - 1) % i;
            start += delete;
            if (start >= i) {
                start = start - i;
            }
            Delete(monkey, start);
            if(start == i-1){
                start = 0;
            }
        }
        printf("%d\n", monkey->element[0]);
    }
    return 0;
}