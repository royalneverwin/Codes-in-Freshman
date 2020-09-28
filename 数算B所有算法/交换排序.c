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


void bubbleSort(SortObject *pvector){
    int i, j, noswap;
    RecordNode temp;
    for(i = 0; i < pvector->n-1; i++){//做n-1次起泡
        noswap = 1;
        for(j = 0; j < pvector->n-i-1; j++){
            if(pvector->record[j+1].key < pvector->record[j].key){
                temp = pvector->record[j];
                pvector->record[j] = pvector->record[j+1];
                pvector->record[j+1] = temp;
                noswap = 0;
            }
        }
        if(noswap){
            break;
        }
    }
}


void quickSort(SortObject *pvector, int l, int r){
    int i, j;
    RecordNode temp;
    if(l > r){
        return;
    }
    i = l;
    j = r;
    temp = pvector->record[i];
    while(i != j){
        while((pvector->record[j].key >= temp.key) && (j > i)){
            j--;
        }
        if(i < j){
            pvector->record[i] = pvector->record[j];
            i++;
        }
        while((pvector->record[i].key <- temp.key) && (j > i)){
            i++;
        }
        if(i < j){
            pvector->record[j] = pvector->record[i];
            j--;
        }
    }
    pvector->record[i] = temp;
    quickSort(pvector, l, i-1);
    quickSort(pvector, i+1, r);
}