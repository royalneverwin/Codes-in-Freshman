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


void insertSort(SortObject *pvector){//直接插入排序
    int i, j;
    RecordNode temp;
    for(i = 1; i < pvector->n; i++){
        temp = pvector->record[i];
        j = i - 1;
        while((temp.key < pvector->record[j].key) && (j >= 0)){
            pvector->record[j+1] = pvector->record[j];
            j--;
        }
        if(j != (i-1)){
            pvector->record[j+1] = temp;
        }
    }
}


void binSort(SortObject *pvector){//二分插入排序
    int i, j, left, mid, right;
    RecordNode temp;
    for(i = 1; i < pvector->n; i++){
        temp = pvector->record[i];
        left = 0;
        right = i - 1;
        while(left <= right){
            mid = (left + right) / 2;
            if(temp.key < pvector->record[mid].key){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        for(j = i-1; j >= left; j--){
            pvector->record[j+1] = pvector->record[j];
        }
        if(left != i){
            pvector->record[left] = temp;
        }
    }
}


void ShellSort(SortObject *pvector){
    int i, j, increment;
    RecordNode temp;
    for(increment = pvector->n/2; increment > 0; increment /= 2){
        for(i = increment; i < pvector->n; i++){
            temp = pvector->record[i];
            j = i - increment;
            while(j >= 0 && temp.key < pvector->record[j].key){
                pvector->record[j+increment] = pvector->record[j];
                j = j - increment;
            }
            pvector->record[j+increment] = temp;
        }
    }
}