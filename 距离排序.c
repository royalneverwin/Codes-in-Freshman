#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{
    int a1[3];
    int a2[3];
    double dis;

}RecordNode;
typedef struct{
    RecordNode record[46];
    int n;
}SortObject;
void add(RecordNode node, SortObject* pvector){
    pvector->record[pvector->n] = node;
    pvector->n++;
}
void BubbleSort(SortObject* pvector) {
    int i, j, noswap;
    RecordNode temp;
    for (i = 1; i <= pvector->n - 1; i++) {
        noswap = 1;
        for (j = pvector->n - 1; j >= i; j--) {
            if (pvector->record[j - 1].dis < pvector->record[j].dis) {
                temp = pvector->record[j - 1];
                pvector->record[j - 1] = pvector->record[j];
                pvector->record[j] = temp;
                noswap = 0;
            }
        }
        if (noswap) {
            break;
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    int point[11][3];
    int i,j,k;
    int num;
    for(i = 0; i < n; i++){
        for(j = 0; j < 3; j++){
            scanf("%d", &num);
            point[i][j] = num;
        }
    }
    SortObject *pvector;
    pvector = (SortObject*)malloc(sizeof(SortObject));
    pvector->n = 0;
    RecordNode node;
    for(i = 0; i < n-1; i++){
        for(k = i+1; k < n; k++){
            for(j = 0; j < 3; j++){
                node.a1[j] = point[i][j];
            }
            for(j = 0; j < 3; j++){
                node.a2[j] = point[k][j];
            }
            node.dis = sqrt(pow(node.a1[0]-node.a2[0], 2) + pow(node.a1[1]-node.a2[1], 2) + pow(node.a1[2]-node.a2[2], 2));
            add(node, pvector);
        }
    }
    BubbleSort(pvector);
    for(i = 0; i < pvector->n; i++){
        printf("(%d,%d,%d)-(%d,%d,%d)=%.2f", pvector->record[i].a1[0], pvector->record[i].a1[1], pvector->record[i].a1[2], pvector->record[i].a2[0], pvector->record[i].a2[1], pvector->record[i].a2[2], pvector->record[i].dis);
        if(i != pvector->n-1){
            putchar('\n');
        }
    }
    free(pvector);
    return 0;
}