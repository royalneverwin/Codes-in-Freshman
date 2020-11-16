#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAXIMUM 10000
struct EdgeNode;
typedef struct EdgeNode *PEdgeNode;
typedef struct EdgeNode *EdgeList;
struct EdgeNode{
    char endvex[100];
    int weight;
    PEdgeNode nextedge;
};
typedef struct{
    char vertex[100];
    EdgeList edgelist;
}Vexnode;
typedef struct{
    Vexnode vexs[100];
    int n;
}Graphlist;
typedef struct{
    char vertex[100];
    int length;
    int prevex;
}Path;
Graphlist *Creategraph(void){//创建邻接表
    Graphlist *graph;
    graph = (Graphlist *)malloc(sizeof(Graphlist));
    int P;
    scanf("%d", &P);//表中元素个数（地点个数
    getchar();
    graph->n = P;
    int i;
    for(i = 0; i < P; i++){
        gets(graph->vexs[i].vertex);//地点名
        graph->vexs[i].edgelist = NULL;
//        printf("%s", graph->vexs[i].vertex);
    }
    return graph;
}
void AddEdgenode(Vexnode *vexs, char *s, int weight){//添加表边
    if(vexs->edgelist == NULL){
        vexs->edgelist = (PEdgeNode)malloc(sizeof(struct EdgeNode));
        strcpy(vexs->edgelist->endvex, s);
        vexs->edgelist->weight = weight;
        vexs->edgelist->nextedge = NULL;
    }
    else{
        PEdgeNode temp;
        temp = vexs->edgelist;
        while(temp->nextedge != NULL){
            temp = temp->nextedge;
        }
        temp->nextedge = (PEdgeNode)malloc(sizeof(struct EdgeNode));
        strcpy(temp->nextedge->endvex, s);
        temp->nextedge->weight = weight;
        temp->nextedge->nextedge = NULL;
    }
}
void CreateEdgelist(Graphlist *graph){//创建表边
    int Q;
    scanf("%d", &Q);
    getchar();
    char v1[100], v2[100], num[10];//v1,v2是一条边的两点，num是权值
    char String[200];
    int i, j, k, flag;
    int weight;
    for(k = 0; k < Q; k++) {
        i = j = 0, flag = 1;
        gets(String);
        for(i = 0; i < strlen(String); i++){
            if(String[i] != ' ' && flag == 1) {
                v1[j] = String[i];
                j++;
            }
            else if(String[i] == ' ' && flag == 1){
                flag = 0;
                v1[j] = '\0';
                j = 0;
            }
            else if(String[i] != ' ' && flag == 0){
                v2[j] = String[i];
                j++;
            }
            else if(String[i] == ' ' && flag == 0){
                v2[j] = '\0';
                j = 0;
                i++;
                break;
            }
        }
        while(i < strlen(String)){
            num[j] = String[i];
            j++;
            i++;
        }
        num[j] = '\0';
        weight = atoi(num);
//        printf("%s %s %d ", v1, v2, weight);
        for (i = 0; i < graph->n; i++) {
            if (strcmp(graph->vexs[i].vertex, v1) == 0) {
                AddEdgenode(&(graph->vexs[i]), v2, weight);
            }
            if (strcmp(graph->vexs[i].vertex, v2) == 0) {
                AddEdgenode(&(graph->vexs[i]), v1, weight);
            }
        }
    }
}
void Dijkstra(Graphlist *graph, Path *dist,int start) {
    int U[100];//判断是否在集合U里面
    int i, j;
    PEdgeNode temp;
    for (i = 0; i < graph->n; i++) {//初始化
        strcpy(dist[i].vertex, graph->vexs[i].vertex);
        U[i] = 0;
        dist[i].length = MAXIMUM;
        dist[i].prevex = start;
    }
    dist[start].length = 0;
    U[start] = 1;//把起点放入集合U
    temp = graph->vexs[start].edgelist;
    while (temp != NULL) {//把与起点相连的点的length设成权
        for (i = 0; i < graph->n; i++) {
            if (strcmp(temp->endvex, dist[i].vertex) == 0) {
                dist[i].length = temp->weight;
                break;
            }
        }
        temp = temp->nextedge;
    }
    int minlength, min;
    for (j = 0; j < graph->n; j++) {//找到权最小的点，放入集合U中
        minlength = MAXIMUM;
        min = start;
        for (i = 0; i < graph->n; i++) {
            if ((U[i] == 0) && (dist[i].length < minlength)) {
                minlength = dist[i].length;
                min = i;
            }
        }
        if(min == start){//如果找不到，break
            break;
        }
        U[min] = 1;
        temp = graph->vexs[min].edgelist;
        while(temp != NULL){//更新未放入集合U中点的length
            for(i = 0; i < graph->n; i++){
                if((U[i] == 0) && (strcmp(temp->endvex, dist[i].vertex) == 0)){
                    if(dist[i].length > (dist[min].length + temp->weight)){
                        dist[i].length = dist[min].length + temp->weight;
                        dist[i].prevex = min;
                    }
                    break;
                }
            }
            temp = temp->nextedge;
        }
    }
}
void ShowWay(Graphlist *graph, Path *dist){
    int Distance[100];
    char start[100], stop[100];//start起点，stop终点
    char stop1[100];
    char String[200];
    int i, j, flag;
    int path[40];
    for(i = 0; i < 40; i++){
        path[i] = 0;
    }
    gets(String);
    i = j = 0;
    flag = 1;
    for(i = 0; i < strlen(String); i++){
        if(String[i] != ' ' && flag == 1){
            start[j] = String[i];
            j++;
        }
        else if(String[i] == ' '){
            start[j] = '\0';
            flag = 0;
            j = 0;
        }
        else if(String[i] != ' ' && flag == 0){
            stop[j] = String[i];
            j++;
        }
    }
    stop[j] = '\0';
    if(strcmp(start, stop) == 0){
        printf("%s\n", start);
    }
    else {
        for (i = 0; i < graph->n; i++) {
            if (strcmp(graph->vexs[i].vertex, start) == 0) {
                Dijkstra(graph, dist, i);//创建Path dist【】
                break;
            }
        }
        j = 39;
        for (i = 0; i < graph->n; i++) {
            if (strcmp(dist[i].vertex, stop) == 0) {
                path[j] = i;
                strcpy(stop1, dist[dist[i].prevex].vertex);//更新stop，回溯
                j--;
                break;
            }
        }
        while (strcmp(stop1, start) != 0) {
            i = dist[i].prevex;
            path[j] = i;
            j--;
            strcpy(stop1, dist[dist[i].prevex].vertex);
        }
        i = dist[i].prevex;
        path[j] = i;
        while (j < 40) {//输出结果
            printf("%s", dist[path[j]].vertex);
            j++;
            if(j != 40) {
                printf("->(%d)->", dist[path[j]].length-dist[path[j-1]].length);
            }
        }
    }
}
int main()
{
    Graphlist *graph = Creategraph();
    CreateEdgelist(graph);
    Path dist[100];
    int R;
    scanf("%d", &R);//R代表查找路线次数
    getchar();
    int i;
    for(i = 0; i < R; i++){
        ShowWay(graph, dist);
        putchar('\n');
    }
    return 0;
}
