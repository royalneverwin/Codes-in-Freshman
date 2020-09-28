#include<stdio.h>
#include<stdlib.h>
struct stack{
    int s[100];
    int t;
};
struct EdgeNode;
typedef struct EdgeNode *PEdgeNode;
typedef struct EdgeNode *EdgeList;
struct EdgeNode{
    int endvex;
    PEdgeNode nextedge;
};
typedef struct{
    int vertex;
    int du;
    EdgeList edgelist;
}Vexnode;
typedef struct{
    Vexnode vexs[100];
    int n;
}Graphlist;
typedef struct stack *Stack;
Stack create()
{
    Stack pastack;
    pastack=(Stack)malloc(sizeof(struct stack));
    if(pastack==NULL) printf("out of space!!\n");
    else pastack->t=-1;
    return(pastack);
}
int IsNotEmpty(Stack pastack)
{
    if(pastack->t==-1) return 0;
    else return 1;
}

void push(Stack pastack,int x)
{
    pastack->t=pastack->t+1;
    pastack->s[pastack->t]=x;
}

void pop(Stack pastack)
{
    if(pastack->t==-1) printf("underflow\n");
    else pastack->t=pastack->t-1;
}

int top(Stack pastack)
{
    int p;
    p=pastack->s[pastack->t];
    return p;
}
void topoSort(Graphlist *pgraph){
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
int main()
{
    Graphlist graph;
    int v, a;
    scanf("%d%d", &v, &a);
    int i;
    graph.n = v;
    for(i = 0; i < v; i++){
        graph.vexs[i].vertex = 0;
        graph.vexs[i].edgelist = NULL;
        graph.vexs[i].du = 0;
    }
    int start, end;
    PEdgeNode temp;
    for(i = 0; i < a; i++){
        scanf("%d%d", &start, &end);
        graph.vexs[end-1].du++;
        if(graph.vexs[start-1].edgelist == NULL){
            graph.vexs[start-1].edgelist = (PEdgeNode)malloc(sizeof(struct EdgeNode));
            graph.vexs[start-1].edgelist->endvex = end - 1;
            graph.vexs[start-1].edgelist->nextedge = NULL;
        }
        else {
            temp = graph.vexs[start - 1].edgelist;
            while (temp->nextedge != NULL) {
                temp = temp->nextedge;
            }
            temp->nextedge = (PEdgeNode) malloc(sizeof(struct EdgeNode));
            temp->nextedge->endvex = end - 1;
            temp->nextedge->nextedge = NULL;
        }
    }
    topoSort(&graph);
    return 0;
}
