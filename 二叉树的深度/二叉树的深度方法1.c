#include <stdio.h>
#include <stdlib.h>
#define MAXNODE 12
typedef struct{
    int lchild;
    int rchild;
}Node;
struct SeqBTree{
    Node nodelist[MAXNODE];
    int n;
};
typedef struct SeqBTree *PSeqBTree;
PSeqBTree pabtree;
int maxheight(int i, PSeqBTree t){
    int left, right;
    if(t->nodelist[i].lchild == -1){
        left = 1;
    }
    else{
        left = 1+maxheight(t->nodelist[i].lchild, t);
    }
    if(t->nodelist[i].rchild == -1){
        right = 1;
    }
    else{
         right = 1+maxheight(t->nodelist[i].rchild, t);
    }
    if(right > left){
        return right;
    }
    else{
        return left;
    }
}
int main(){
    int n;
    scanf("%d", &n);
    int i;
    int left, right;
    PSeqBTree t;
    t = (PSeqBTree)malloc(sizeof(struct SeqBTree));
    for(i = 1; i <= n; i++){
        scanf("%d%d", &left, &right);
        t->nodelist[i].lchild = left;
        t->nodelist[i].rchild = right;
    }
    printf("%d", maxheight(1, t));
    return 0;
}