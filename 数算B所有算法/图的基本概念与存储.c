#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 100
typedef struct{//邻接矩阵表示法
    int vexs[MAXNUM];//顶点信息
    int arcs[MAXNUM][MAXNUM];//邻接矩阵
    int n;
}Graph;


struct EdgeNode;//邻接表表示法
typedef struct EdgeNode *PEdgeNode;
typedef struct EdgeNode *EdgeList;
struct EdgeNode{
    int endvex;//相邻顶点字段
    int weight;//边的权
    PEdgeNode nextedge;//链字段
};//边表的结点
typedef struct{
    int vertex;//顶点信息
    EdgeList edgelist;//边表头指针
}VexNode;
typedef struct{
    VexNode vexs[MAXNUM];
    int n;//图顶点个数
}GraphList;


void DFSList(GraphList *pgraphlist, int visited[], int i){//图的深度优先周游算法,邻接表
    int j;
    PEdgeNode p;
    printf("node: %d\n", pgraphlist->vexs[i].vertex);
    visited[i] = 1;
    p = pgraphlist->vexs[i].edgelist;//取边表中第一个边节点
    while(p != NULL){
        if(visited[p->endvex] == 0) {
            DFSList(pgraphlist, visited, p->endvex);
        }
        p = p->nextedge;//取边表中下一个边节点
    }
}
void traverDFS(GraphList *pgraphlist){
    int visited[MAXNUM];
    int n;
    n = pgraphlist->n;
    int i;
    for(i = 0; i < n; i++){
        visited[i] = 0;
    }
    for(i = 0; i < n; i++){
        if(visited[i] == 0){
            DFSList(pgraphlist, visited, i);
        }
    }
}


void DFSInMatrix(Graph *pgraph, int visited[], int i){//图的深度优先周游算法，邻接矩阵
    int j;
    printf("node: %d\n", pgraph->vexs[i]);
    visited[i] = 1;
    for(j = 0; j < pgraph->n; j++){
        if((pgraph->arcs[i][j] == 1) && (visited[j] == 0)){
            DFSInMatrix(pgraph, visited, j);
        }
    }
}
void TRAVERdfs(Graph *pgraph){
    int visited[MAXNUM];
    int i;
    for(i = 0; i < pgraph->n; i++){
        visited[i] = 0;
    }
    for(i = 0; i < pgraph->n; i++){
        if(visited[i] == 0){
            DFSInMatrix(pgraph, visited, i);
        }
    }
}

struct Node;
typedef struct Node *PNode;
struct Node{
    int info;
    PNode link;
};
struct LinkQueue{
    PNode f;
    PNode r;
};
typedef struct LinkQueue *PLinkQueue;
PLinkQueue createEmptyQueue_link( );
/* 表示创建一个空队列 */
int isEmptyQueue_link( PLinkQueue plqu );
/*判断plqu所指的队列是否为空队列，当plqu所指的队列为空队列时，则返回1，否则返回0*/
void enQueue_link( PLinkQueue plqu, int x);
/*表示往plqu所指的队列中插入一个值为ｘ的元素*/
int deQueue_link( PLinkQueue plqu);
/*表示从plqu所指的队列中删除队列头部元素*/

/* 从vi出发进行广度优先搜索，图用邻接表表示法表示 */
void bFSInList(GraphList *pgraphlist, int visited[], int i)//图的广度优先算法
{
    PLinkQueue pq;
    PEdgeNode p;
    int j;
    pq = createEmptyQueue_link();    /* 置队列为空 */
    printf("node:%d\n",pgraphlist->vexs[i].vertex);
    visited[i]=1;
    enQueue_link(pq,i);    /* 将顶点序号进队 */
    while (!isEmptyQueue_link(pq) )     /* 队列非空时执行 */
    {
        j = deQueue_link(pq);     /* 队头顶点出队 */
        p=pgraphlist->vexs[j].edgelist;
        while( p!=NULL)
        {
            if (!visited[p->endvex])
                /*访问相邻接的未被访问过的顶点 */
            {
                printf("node:%c\n",pgraphlist->vexs[p->endvex].vertex);
                visited[p->endvex]=1;
                enQueue_link(pq,p->endvex);
                /*访问的顶点入队 */
            }
            p=p->nextedge;
        }
    }
}
void traverBFS(GraphList *pgraphlist)
{
    int visited[MAXNUM];
    int i,n;
    n=pgraphlist->n;
    for(i=0;i<n;i++){
        visited[i]=0;
    }
    for(i=0; i<n; i++) {
        if (visited[i] == 0) {
            bFSInList(pgraphlist, visited, i);
        }
    }
}