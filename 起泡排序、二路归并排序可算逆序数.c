#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int record[20001];
    int n;
}SortObject;
int ni;
void add(int num, SortObject* pvector){
    pvector->record[pvector->n] = num;
    pvector->n++;
}
int BubbleSort(SortObject* pvector){
    int i, j, noswap, time = 0;
    int temp;
    for(i = 0; i < pvector->n-1; i++){
        noswap = 1;
        for(j = 0; j < pvector->n-i-1; j++){
            if(pvector->record[j] > pvector->record[j+1]){
                temp = pvector->record[j];
                pvector->record[j] = pvector->record[j+1];
                pvector->record[j+1] = temp;
                noswap = 0;
                time++;
            }
        }
        if(noswap){
            break;
        }
    }
    return time;
}
void merge(int* record, int* record1, int low, int mid, int high ){
    int i, j, k;
    i = low;
    j = mid+1;
    k = low;
    while((i <= mid) && (j <= high)){
        if(record[i] <= record[j]){
            record1[k] = record[i];
            k++;
            i++;
        }
        else{
            record1[k] = record[j];
            k++;
            j++;
            ni += j-k;
        }
    }
    while(i <= mid){
        record1[k] = record[i];
        k++;
        i++;
    }
    while(j <= high){
        record1[k] = record[j];
        k++;
        j++;
    }
}
void mergePass(int* record, int* record1, int n, int length){
    int i,j;
    i = 0;
    while(i+2*length-1 < n){
        merge(record, record1, i, i+length-1, i+2*length-1);
        i += 2*length;
    }
    if(i+length-1 < n-1){
        merge(record, record1, i, i+length-1, n-1);
    }
    else{
        for(j = i; j < n; j++){
            record1[j] = record[j];
        }
    }
}
void mergeSort(SortObject* pvector){
    int record1[100000];
    int length;
    length = 1;
    while (length < pvector->n) {
        mergePass(pvector->record, record1, pvector->n, length);
        length *= 2;
        mergePass(record1, pvector->record, pvector->n, length);
        length *= 2;
    }
}
int main(){
    int N, num;
    scanf("%d", &N);
    int i;
    SortObject* pvector;
    pvector = (SortObject*)malloc(sizeof(SortObject));
    while(N != 0){
        ni = 0;
        pvector->n = 0;
        for(i = 0; i < N; i++){
            scanf("%d", &num);
            add(num, pvector);
        }
        mergeSort(pvector);
        printf("%d\n", ni);
//        for(i=0; i<pvector->n; i++){
//            printf("%d ", pvector->record[i]);
//        }
//        putchar('\n');
        scanf("%d", &N);
    }
    free(pvector);
    return 0;
}