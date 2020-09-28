#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 1000
struct ParTreeNode{//父指针表示法
    int info;
    int parent;
};
struct ParTree{
    struct ParTreeNode *nodelist;
    int n;
};
typedef struct ParTree *PParTree;


int rightSibling_partree(PParTree t, int p){
    int i;
    if(p >= 0 && p < t->n){
        for(i = p+1; i < t->n; i++){//默认先根序列存放在数组中
            if(t->nodelist[i].parent == t->nodelist[p].parent){
                return i;
            }
        }
    }
    return -1;
}


struct EdgeNode{//子表表示法，子表中节点的结构
    int nodeposition;
    struct EdgeNode *link;
};
struct ChiTreeNode{//结点表中节点的结构
    int info;
    struct EdgeNode *children;
};
struct ChiTree{//树结构定义
    int root;
    int n;
    struct ChiTreeNode nodelist[MAXNUM];
};
typedef struct ChiTree *PChiTree;


int rightSibling_chitree(PChiTree t, int p){
    int i;
    struct EdgeNode *v;
    for(i = 0; i < t->n; i++){
        v = t->nodelist[i].children;
        while(v != NULL){
            if(v->nodeposition == p){
                if(v->link == NULL){
                    return -1;
                }
                else{
                    return v->link->nodeposition;
                }
            }
            else{
                v = v->link;
            }
        }
    }
    return -1;
}


int parent_chitree(PChiTree t, int p){
    int i;
    struct EdgeNode *v;
    for(i = 0; i < t->n; i++){
        v = t->nodelist[i].children;
        while(v != NULL){
            if(v->nodeposition == p){
                return i;
            }
            else{
                v = v->link;
            }
        }
    }
    return -1;
}


struct CSNode;//长子-兄弟表示法
typedef struct CSNode *PCSNode;
struct CSNode{
    int info;
    PCSNode lchild;
    PCSNode rsibling;
};
typedef struct CSNode *CSTree;
typedef CSTree *PCSTree;

typedef struct node *Node;
struct node{
    int info;
    Node child;
    Node sibling;
};
int visit(Node p){
    return p->info;
}
Node leftChild(Node p){
    return p->child;
}
Node rightSibling(Node p){
    return p->sibling;
}
void preOrder(Node p){//先根周游
    Node c;
    visit(p);
    c = leftChild(p);
    while(c != NULL){
        preOrder(c);
        c = rightSibling(c);
    }
}


void inOrder(Node p){//中根周游
    Node c;
    c = leftChild(p);
    if(c == NULL){
        visit(p);
        return;
    }
    inOrder(c);
    visit(p);
    c = rightSibling(c);
    while(c != NULL){
        inOrder(c);
        c = rightSibling(c);
    }
}


void postOrder(Node p){
    Node c;
    c = leftChild(p);
    while(c != NULL){
        postOrder(c);
        c = rightSibling(c);
    }
    visit(p);
}


void levelOrder(Tree t)//宽度周游
{
    Node c;
    Queue q;
    q = createEmptyQueue();
    c = root(t);
    if (c==NULL)    return;
    enQueue(q, c);
    while (!isEmptyQueue(q))
    {
        c = frontQueue(q);
        deQueue(q);
        visit(c);
        c = leftChild(c);
        while (c != NULL) {
            enQueue(q, c);
            c = rightSibling(c);
        }
    }
}


