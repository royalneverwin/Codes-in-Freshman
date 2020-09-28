#include <stdio.h>
#include <stdlib.h>
#define MAXNODE 100
#define MAXINT 2147483647
#define MAXNUM 50//数组w中最多容纳的元素个数
struct HtNode{//前m个存储外部节点，后m-1个用于内部节点
    int ww;
    int parent;
    int llink;
    int rlink;
};
struct HtTree{
    struct HtNode ht[MAXNODE];
    int root;//哈夫曼树根在数组中的位置
};
typedef struct HtTree *PHtTree;


void Select(PHtTree pht, int pos, int *x1, int *x2){
    int m1 = MAXINT;
    int m2 = MAXINT;
    int j;
    for(j = 0; j < pos; j++){
        if(pht->ht[j].ww < m1 && pht->ht[j].parent == -1){
            m2 = m1;//保留最小到次小
            *x2 = *x1;
            m1 = pht->ht[j].ww;
            *x1 = j;
        }
        else if(pht->ht[j].ww < m2 && pht->ht[j].parent == -1){
            m2 = pht->ht[j].ww;
            *x2 = j;
        }
    }
}
PHtTree Huffman(int m, int *w) {//m个叶结点，w为数组存m个数据
    PHtTree pht;
    int i, j;
    int x1, x2;//存放权值最小的两个结点的位置
    pht = (PHtTree) malloc(sizeof(struct HtTree));
    if (pht == NULL) {
        printf("Out of space!\n");
        return pht;
    }
    for(i = 0; i < 2*m-1; i++){//置初态
        pht->ht[i].llink = -1;
        pht->ht[i].rlink = -1;
        pht->ht[i].parent = -1;
        if(i < m){
            pht->ht[i].ww = w[i];
        }
        else{
            pht->ht[i].ww = -1;
        }
    }
    for(i = 0; i < m-1; i++){//每次构造一个内部节点
        x1 = x2 = -1;
        Select(pht, m+i, &x1, &x2);//选小值作为左右子女
        pht->ht[x1].parent = m+i;
        pht->ht[x2].parent = m+i;
        pht->ht[m+i].ww = pht->ht[x1].ww + pht->ht[x2].ww;
        pht->ht[m+i].llink = x1;
        pht->ht[m+i].rlink = x2;
        pht->root = m+i;
    }
    return pht;
}//从结点引向左子女的边标上号码0， 引向右子女的边标上号码1