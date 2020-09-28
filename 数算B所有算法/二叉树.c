#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 1000
struct SeqBTree{//顺序表示的二叉树定义
    int nodelist[MAXNUM];
    int n;//改造成完全二叉树后，结点的个数
};
typedef struct SeqBTree *PSeqBTree;
PSeqBTree pabtree;


int root_seq(PSeqBTree t){
    return t->nodelist[0];
}


int parent_seq(PSeqBTree t, int p){
    return t->nodelist[(p-1)/2];
}


int leftchild(PSeqBTree t, int p){
    return t->nodelist[2*p+1];
}


int rightchild_seq(PSeqBTree t, int p){
    return t->nodelist[2*p+2];
}


struct BinTreeNode;
typedef struct BinTreeNode *PBinTreeNode;
struct BinTreeNode{//二叉树链式表示
    int info;
    PBinTreeNode llink;
    PBinTreeNode rlink;
};
struct BinTree{
    PBinTreeNode t;
};
typedef struct BinTree *PBinTree;


PBinTreeNode creatRest_Btree()//递归创建从根开始的二叉树，且是利用先根序列
{
    PBinTreeNode pbnode;
    char ch;
    scanf("%c", &ch);
    if(ch =='@') {
        pbnode = NULL;
    }
    else{
        pbnode = (PBinTreeNode)malloc(sizeof(struct BinTreeNode));
        if(pbnode==NULL)
        {
            printf("Out of space!\n");
            return pbnode;
        }
        pbnode->info = ch;
        pbnode->llink = creatRest_Btree(); /*构造左子树*/
        pbnode->rlink = creatRest_Btree(); /*构造右子树*/
    }
    return pbnode;
}
PBinTree createBTree(void)/*创建完整的二叉树*/
{
    PBinTree pbtree;
    pbtree = (PBinTree) malloc(sizeof(struct BinTree));
    if (pbtree != NULL)
        pbtree->t = creatRest_Btree();/*递归创建从根开始的二叉树*/
    return pbtree;
}


int visit(PBinTreeNode p){
    return p->info;
}
PBinTreeNode Leftchild(PBinTreeNode p){
    return p->llink;
}
PBinTreeNode Rightchild(PBinTreeNode p){
    return p->rlink;
}
void preOrder(PBinTreeNode p){//先根次序
    if(p == NULL){
        return;
    }
    visit(p);
    preOrder(Leftchild(p));
    preOrder(Rightchild(p));
}


void postOrder(PBinTreeNode p){//后根次序
    if(p == NULL){
        return;
    }
    postOrder(Leftchild(p));
    postOrder(Rightchild(p));
    visit(p);
}


void inOrder(PBinTreeNode p){//中根次序
    if(p == NULL){
        return;
    }
    inOrder(Leftchild(p));
    visit(p);
    inOrder(Rightchild(p));
}


void levelOrder(PBinTree p)//宽度优先周游，需要一个额外的队列
{
    PBinTreeNode c;
    Queue q;
    q = createEmptyQueue();
    c = p->t;
    if (c == NULL)    {
        return;
    }
    enQueue(q, c);
    while (!isEmptyQueue(q))
    {   c = frontQueue(q);
        deQueue(q);
        visit(c);
        c = Leftchild(c);
        while (c!=NULL) {
            enQueue(q, c);
            c = RightSibling(c);
        }
    }
}



