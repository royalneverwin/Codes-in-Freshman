#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define  MAXNUM 100
#define MAX INT_MAX
typedef struct{//邻接矩阵表示法
    int vexs[MAXNUM];//顶点信息
    int arcs[MAXNUM][MAXNUM];//邻接矩阵
    int n;
}Graph;
typedef struct{
    int vertex;//顶点信息
    int length;//最短路径长度
    int prevex;//最短路径上vi的前趋顶点
}Path;


void dijkstra(Graph graph, Path dist[])//从v0到其他顶点
{
    int  i, j, minvex;
    int min;
    dist[0].length=0;
    dist[0].prevex=0;
    dist[0].vertex=graph.vexs[0];
    graph.arcs[0][0]=1;     /* 表示顶点v0在集合U中 */
    for(i=1; i<graph.n; i++)    /* 初始化集合V-U中顶点的距离值 */
    {
        dist[i].length=graph.arcs[0][i];
        dist[i].vertex=graph.vexs[i];
        if(dist[i].length!=MAX) {
            dist[i].prevex=0;
        }
        else {
            dist[i].prevex= -1;
        }
    }
    for(i=1; i<graph.n; i++)
    {
        min=MAX;
        minvex=0;
        for(j=1; j<graph.n; j++)    /*在V-U中选出距离值最小顶点*/
            if( (graph.arcs[j][j]==0) && (dist[j].length < min) )
            {
                min=dist[j].length;
                minvex=j;
            }
        if(minvex==0) {
            break;     /* 从v0没有路径可通往集合V-U中的顶点 */
        }
        graph.arcs[minvex][minvex]=1;     /* V-U路径最小顶点minvex */
        for(j=1; j<graph.n; j++)      /* 调整集合V-U中的顶点的最短路径 */
        {
            if(graph.arcs[j][j]==1) {
                continue;
            }
            if(dist[j].length > dist[minvex].length + graph.arcs[minvex][j])
            {
                dist[j].length = dist[minvex].length+graph.arcs[minvex][j];
                dist[j].prevex = minvex;
            }
        }
    }
}


typedef struct
{   /* 存放每对顶点间最短路径长度 */
    int a[MAXNUM][MAXNUM];
    /* nextvex[i][j]存放vi到vj最短路径上vi的后继顶点的下标值 */
    int nextvex[MAXNUM][MAXNUM];
}ShortPath;
void Floyd(Graph * pGraph, ShortPath * ppath) {
    int  i, j, k;
    for(i=0; i<pGraph->n; i++) {//初始化ShortPath
        for (j = 0; j < pGraph->n; j++) {
            if (pGraph->arcs[i][j] != MAX) {
                ppath->nextvex[i][j] = j;
            }
            else {
                ppath->nextvex[i][j] = -1;
            }
            ppath->a[i][j] = pGraph->arcs[i][j];
        }
    }
    for(k=0; k<pGraph->n; k++) {
        for (i = 0; i < pGraph->n; i++) {
            for (j = 0; j < pGraph->n; j++) {
                if ((ppath->a[i][k] >= MAX) || (ppath->a[k][j] >= MAX)) {
                    continue;
                }
                if (ppath->a[i][j] > (ppath->a[i][k] + ppath->a[k][j])) {
                    ppath->a[i][j] = ppath->a[i][k] + ppath->a[k][j];
                    ppath->nextvex[i][j] = ppath->nextvex[i][k];
                }
            }
        }
    }
}


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
void findInDegree(GraphList *g, int *indegree){
    int i;
    PEdgeNode p;
    for(i = 0; i < g->n; i++){
        indegree[i] = 0;
    }
    for(i = 0; i < g->n; i++){
        p = g->vexs[i].edgelist;
        while(p != NULL){
            ++indegree[p->endvex];
            p = p->nextedge;
        }
    }
}
int topoSort(GraphList *paov, int *ptopo){
    EdgeList p;
    int i, j, k, nodeno = 0;
    PStack mystack;
    mystack = (PStack)malloc(sizeof(struct Stack));
    mystack->top = -1;
    int *indegree = (int*)malloc(sizeof(int) *paov->n);
    findInDegree(paov, indegree);
    for(i = 0; i < paov->n; i++){
        if(indegree[i] == 0){
            push(mystack, i);	/* 将入度为零的顶点入栈 */
        }
    }
    while(mystack->top != -1){
        j = mystack->top;
        pop(mystack);
        ptopo[nodeno] = j;
        nodeno++;
        p = paov->vexs[j].edgelist;
        while(p != NULL){
            k = p->endvex;
            indegree[k]--;
            if(indegree[k] == 0){
                push(mystack, k);  /* 将新的入度为零的边入栈*/
            }
            p = p->nextedge;
        }
    }
    free(indegree);
    if(nodeno < paov->n){
        printf("The aov network has a cycle.\n");
        return 0;
    }
    return 1;
}


void toposort(GraphList *pgraph){//邻接表拓扑算法&简易版
    int i, j = 0;
    PEdgeNode temp;
    while(j < pgraph->n) {
        for (i = 0; i < pgraph->n; i++) {
            if (pgraph->vexs[i].du == 0) {
                printf("v%d ", i+1);
                pgraph->vexs[i].du = -1;
                temp = pgraph->vexs[i].edgelist;
                while (temp) {
                    pgraph->vexs[temp->endvex].du--;
                    temp = temp->nextedge;
                }
                break;
            }
        }
        j++;
    }
}