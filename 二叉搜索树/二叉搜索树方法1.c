#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXIMUM 1000
struct BinTreeNode;
typedef struct BinTreeNode *PBinTreeNode;
struct BinTreeNode{
    int info;
    PBinTreeNode lchild;
    PBinTreeNode rchild;
};
typedef struct BinTreeNode *BinTree;
typedef BinTree *PBinTree;
struct array{
    int node[MAXIMUM];
    int n;
};
typedef struct array *Parray;
void create_array(Parray arraynode, int max){
    int num;
    int i = 0;
    while(scanf("%d", &num) != EOF){
        arraynode->node[i] = num;
        i++;
        arraynode->n++;
        if(i >= max){
            printf("Out of Place!\n");
            return;
        }
    }
}
void Insert(PBinTree t, int node){
    if(*t == NULL){
        PBinTreeNode p;
        p = (PBinTreeNode)malloc(sizeof(struct BinTreeNode));
        p->info = node;
        p->lchild = NULL;
        p->rchild = NULL;
        *t = p;
    }
    else{
        if(node > (*t)->info){
            Insert(&((*t)->rchild), node);
        }
        else if(node < (*t)->info){
            Insert(&((*t)->lchild), node);
        }
    }
}
void show(PBinTreeNode tree){
    printf("%d ", tree->info);
    if(tree->lchild != NULL){
        show(tree->lchild);
    }
    if(tree->rchild != NULL){
        show(tree->rchild);
    }
}
int main(){
    Parray arraynode;
    arraynode = (Parray)malloc(sizeof(struct array));
    arraynode->n = 0;
    create_array(arraynode, MAXIMUM);
    PBinTree t;
    t = (PBinTree)malloc(sizeof(BinTree));
    *t = NULL;
    int i;
    for(i = 0; i < arraynode->n; i++){
        Insert(t, arraynode->node[i]);
    }

    show(*t);
    return 0;
}