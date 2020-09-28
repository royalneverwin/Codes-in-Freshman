#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 1000
struct BinTreeNode;
typedef struct BinTreeNode *PBinTreeNode;
struct BinTreeNode{//二叉树链式表示
    int key;
    PBinTreeNode lchild;
    PBinTreeNode rchild;
};
typedef struct BinTreeNode *BinTree;
typedef  BinTree *PBinTree;




int searchNode(PBinTree ptree, int key, PBinTreeNode *position){
    PBinTreeNode p, q;
    p = q = *ptree;
    while(p != NULL){
        q = p;
        if(p->key == key){
            *position = p;
            return 1;
        }
        else if(p->key > key){
            p = p->lchild;
        }
        else{
            p = p->rchild;
        }
    }
    *position = q;
    return 0;
}


void insertNode(PBinTree ptree, int key){
    PBinTreeNode p, position;
    if(searchNode(ptree, key, &position) == 1){
        return;
    }
    p = (PBinTreeNode)malloc(sizeof(struct BinTreeNode));
    if(p == NULL){
        printf("Out of space.\n");
        exit(1);
    }
    p->key = key;
    p->lchild = p->rchild = NULL;
    if(position == NULL){
        *ptree = p;
    }
    else if(key < position->key){
        position->lchild = p;
    }
    else{
        position->rchild = p;
    }
}
PBinTreeNode Leftchild(PBinTreeNode p){
    return p->lchild;
}
PBinTreeNode Rightchild(PBinTreeNode p){
    return p->rchild;
}
void preOrder(PBinTreeNode p){//先根次序
    if(p == NULL){
        return;
    }
    printf("%d ", p->key);
    preOrder(Leftchild(p));
    preOrder(Rightchild(p));
}

int main(){
    PBinTree tree;
    tree = (PBinTree)malloc(sizeof(BinTree));
    *tree = NULL;
    PBinTreeNode p;
    int num;
    while(scanf("%d", &num) != EOF){
        insertNode(tree, num);
    }
    preOrder(*tree);
    return 0;
}