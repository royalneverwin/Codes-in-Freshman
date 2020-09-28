#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAXNUM 100
typedef struct{//邻接矩阵表示法
    int vexs[MAXNUM];//顶点信息
    int arcs[MAXNUM][MAXNUM];//邻接矩阵
    int n;
}Graph;
typedef struct{
    int start_vex, stop_vex;//边的起点和终点
    int weight;//边的权
}Edge;
void prim(Graph * pGraph, Edge mst[])
{
    int  i, j, min, vx, vy;
    int weight, minweight;
    Edge edge;
    for(i=0; i<pGraph->n-1; i++)//初始化mst数组
    {
        mst[i].start_vex=0;
        mst[i].stop_vex=i+1;
        mst[i].weight=pGraph->arcs[0][i+1];
    }
    for(i=0; i<pGraph->n-1; i++)     /* 共n-1条边 */
    {
        minweight=INT_MAX; min=i;
        /* 从所有边(vx,vy)(vx∈U,vy∈V-U)中选出最短的边 */
        for(j = i; j < pGraph->n-1; j++)
            if(mst[j].weight < minweight)
            {
                minweight = mst[j].weight;
                min = j;
            }
        /* mst[min]是最短的边(vx,vy)(vx∈U, vy∈V-U)，*/
        /* 将mst[min]加入最小生成树 */
        edge=mst[min]; mst[min]=mst[i]; mst[i]=edge;
        vx=mst[i].stop_vex;    /* vx为刚加入最小生成树的顶点下标 */
        for(j=i+1; j<pGraph->n-1; j++) /* 调整mst[i+1]到mst[n-1] */
        {
            vy=mst[j].stop_vex;
            weight=pGraph->arcs[vx][vy];
            if(weight < mst[j].weight)
            {
                mst[j].weight = weight;
                mst[j].start_vex = vx;
            }
        }
    }
}