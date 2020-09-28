#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 1000
typedef struct{
    int key;
    int info;
}RecordNode;
typedef struct{
    RecordNode record[MAXNUM];
    int n;
}SortObject;


void slectSort(SortObject *pvector){
    int i, j, k;
    RecordNode temp;
    for(i = 0; i < pvector->n-1; i++){
        k = i;
        for(j = i + 1; j < pvector->n; j++){
            if(pvector->record[j].key < pvector->record[k].key){
                k = j;
            }
        }
        if(k != i){
            temp = pvector->record[i];
            pvector->record[i] = pvector->record[k];
            pvector->record[k] = temp;
        }
    }
}


#define leftchild(i) 2*(i) + 1
void sift(SortObject *p, int i, int n){//大根堆
    int child;
    RecordNode temp;
    temp = p->record[i];
    child = leftchild(i);
    while(child < n){
        if((child < n-1) && (p->record[child].key < p->record[child+1].key)){
            child++;
        }
        if(temp.key < p->record[child].key){
            p->record[i] = p->record[child];
            i = child;
            child = leftchild(i);
        }
        else{
            break;
        }
    }
    p->record[i] = temp;
}
void heapSort(SortObject *pvector){
    int i, n;
    RecordNode temp;
    n = pvector->n;
    for(i = n/2-1; i >= 0; i--){
        sift(pvector, i ,n);
    }
    for(i = n-1; i > 0; i--){//进行n-1趟堆排序
        temp = pvector->record[0];
        pvector->record[0] = pvector->record[i];
        pvector->record[i] = temp;
        sift(pvector, 0, i);
    }
}