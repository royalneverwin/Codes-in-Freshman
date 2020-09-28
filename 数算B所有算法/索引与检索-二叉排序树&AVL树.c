#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 100
struct BinTreeNode;
typedef struct BinTreeNode *PBinTreeNode;
struct BinTreeNode{
    int info;
    int key;
    PBinTreeNode lchild;
    PBinTreeNode rchild;
};
typedef struct BinTreeNode *BinTree;
typedef BinTree *PBinTree;
typedef struct{
    int key;
    int other;
}DicElement;
typedef struct{
    DicElement element[MAXNUM];
    int n;
}SeqDictionary;



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


void CreateTree(PBinTree ptree, SeqDictionary dic){
    int i;
    for(i = 0; i < dic.n; i++){
        insertNode(ptree, dic.element[i].key);
    }
}


void deleteNode(PBinTree ptree, int key)//二叉排序树删除算法
{
    PBinTreeNode parentp, p, r;
    p=*ptree;
    parentp=NULL;
    while(p!=NULL)//找到删除的p和p的父结点
    {
        if(p->key==key) {
            break;
        }
        parentp=p;
        if(p->key>key) {
            p=p->lchild;
        }
        else {
            p=p->rchild;
        }
    }
    if(p==NULL) {
        return;
    }
    if(p->lchild == NULL){//p无左子树
        if(parentp==NULL){
            *ptree=p->rchild;
        }
        else if(parentp->lchild==p) {
            parentp->lchild=p->rchild;
        }
        else{
            parentp->rchild=p->rchild;
        }
    }
    else{//p有左子树
        r=p->lchild;
        while(r->rchild!=NULL) {//r为p左子树中根周游的最后一个节点
            r=r->rchild;
        }
        r->rchild=p->rchild;
        if(parentp==NULL) {
            *ptree=p->lchild;
        }
        else if(parentp->lchild==p){
            parentp->lchild=p->lchild;
        }
        else {
            parentp->rchild = p->lchild;
        }
    }
    free(p);
}
//也可用最大子孙代替法

