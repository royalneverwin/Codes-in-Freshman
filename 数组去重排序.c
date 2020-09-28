#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int record[100000];
    int n;
}SortObject;
void add(int num, SortObject* pvector){
    pvector->record[pvector->n] = num;
    pvector->n++;
}


void ShellSort(SortObject* pvector){
    int i, j, increment, temp;
    increment = pvector->n/2;
    while(increment > 0){
        for(i = pvector->n - increment-1; i>= 0; i--) {
            temp = pvector->record[i];
            j = i + increment;
            while ((pvector->record[j] < temp) && (j <= pvector->n - 1)) {
                pvector->record[j - increment] = pvector->record[j];
                j += increment;
            }
            pvector->record[j - increment] = temp;
        }
        increment /= 2;

    }
}


void sift(SortObject* pvector, int i, int n){
    int child, temp;
    temp = pvector->record[i];
    child = 2*i+1;
    while(child < n){
        if((child < n-1) && (pvector->record[child] < pvector->record[child+1])){
            child += 1;
        }
        if(temp < pvector->record[child]){
            pvector->record[i] = pvector->record[child];
            pvector->record[child] = temp;
            i = child;
            child = 2*i+1;
        }
        else{
            break;
        }
    }

}
void heapSort(SortObject* pvector){
    int i, n, temp;
    n = pvector->n;
    for(i = n/2-1; i >=0; i--){
        sift(pvector, i, n);
    }
    for(i = n-1; i > 0; i--){
        temp = pvector->record[0];
        pvector->record[0] = pvector->record[i];
        pvector->record[i] = temp;
        sift(pvector, 0, i);
    }
}


void quickSort(SortObject* pvector, int l, int r){
    int i, j, temp;
    if(l >= r){
        return;
    }
    else{
        i = l;
        j = r;
        temp = pvector->record[i];
        while(i != j){
            while((pvector->record[j] > temp) && (j > i)){
                j--;
            }
            if(j > i){
                pvector->record[i] = pvector->record[j];
                i++;
                while((pvector->record[i] < temp) && (i < j)){
                    i++;
                }
                if(i < j){
                    pvector->record[j] = pvector->record[i];
                    j--;
                }
            }
        }
        pvector->record[i] = temp;
        quickSort(pvector, l, i-1);
        quickSort(pvector, i+1, r);
    }
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


void BubbleSort(SortObject* pvector){
    int i, j, noswap;
    RecordNode temp;
    for(i = 0; i < pvector->n-1; i++){
        noswap = 1;
        for(j = 0; j < pvector->n-i-1; j++){
            if(pvector->record[j].dis > pvector->record[j+1].dis){
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
int main(){
    int n;
    scanf("%d", &n);
    int i;
    int num, temp;
    SortObject *pvector;
    pvector = (SortObject*)malloc(sizeof(SortObject));
    pvector->n = 0;
    for(i = 1; i <= n; i++){
        scanf("%d", &num);
        add(num, pvector);
    }
    quickSort(pvector, 0, n-1);
    printf("%d", pvector->record[0]);
    temp = pvector->record[0];
    for(i = 1; i < pvector->n; i++){
        if(pvector->record[i] != temp){
            printf(" %d", pvector->record[i]);
            temp = pvector->record[i];
        }
    }
    free(pvector);
    return 0;
}