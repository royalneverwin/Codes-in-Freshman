#include <stdio.h>
#include <stdlib.h>
#define MAXIMUM 100
typedef struct{
    char Stars[26];
    int arcs[26][26];
    int n;
}Graph;
typedef struct{
    char start_vex;
    char stop_vex;
    int weight;
}Edge;
void CreateGraph(Graph *pgraph, int n){
    pgraph->n = n;
    char alpha = 'A';
    int i, j;
    for(i = 0; i < n; i++){
        pgraph->Stars[i] = alpha;
        alpha++;
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            pgraph->arcs[i][j] = MAXIMUM;
        }
    }
    char c1, c2;
    int num, quan;
    for(i = 1; i < n; i++) {
        getchar();
        scanf("%c", &c1);
        getchar();
        scanf("%d", &num);
        if(num != 0){
            for(j = 0; j < num; j++){
                getchar();
                scanf("%c", &c2);
                getchar();
                scanf("%d", &quan);
                pgraph->arcs[c1-'A'][c2-'A'] = quan;
                pgraph->arcs[c2-'A'][c1-'A'] = quan;
            }
        }
    }
}
void Prim(Graph *pgraph, Edge *mst){
    int i, j, min, minweight;
    char vx, vy;
    Edge temp;
    for(i = 1; i < pgraph->n; i++){
        mst[i-1].start_vex = 0 + 'A';
        mst[i-1].stop_vex = i + 'A';
        mst[i-1].weight = pgraph->arcs[0][i];
    }
    for(i = 1; i < pgraph->n; i++){
        minweight = MAXIMUM;
        min = i;
        for(j = i-1; j < pgraph->n-1; j++){
            if(mst[j].weight < minweight){
                minweight = mst[j].weight;
                min = j;
            }
        }
        temp = mst[i-1];
        mst[i-1] = mst[min];
        mst[min] = temp;
        vx = mst[i-1].stop_vex;
        for(j = i; j < pgraph->n-1; j++){
            vy = mst[j].stop_vex;
            if(pgraph->arcs[vx-'A'][vy-'A'] < mst[j].weight){
                mst[j].weight = pgraph->arcs[vx-'A'][vy-'A'];
                mst[j].start_vex = vx;
            }
        }
    }
}
int main(){
    int n;
    int i, j, sum = 0;
    scanf("%d", &n);
    Graph graph;
    CreateGraph(&graph, n);
    Edge mst[n];
    Prim(&graph, mst);
    for(i = 0; i < n-1; i++){
        sum += mst[i].weight;
    }
    printf("%d", sum);
}