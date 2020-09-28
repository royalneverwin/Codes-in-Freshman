#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 1000
#define D 3
#define R 10
struct Node;
typedef struct Node *RadixNode;
struct Node{ /* 单链表结点类型*/
int key[D];
int info;
RadixNode  next;
};
typedef struct Node *RadixList;
typedef struct QueueNode{
    RadixNode f;     /*队列的头指针*/
    RadixNode e;    /*队列的尾指针*/
}Queue;
Queue queue[R];


void radixSort(RadixList plist, int d, int r){
    int i, j, k;
    RadixNode p, head;
    head = plist->next;
    for(j = d-1; j >= 0; j--){
        p = head;
        for(i = 0; i < r; i++){
            queue[i].f = NULL;
            queue[i].e = NULL;
        }
        while(p != NULL) {
            k = p->key[j];
            if (queue[k].f == NULL) {
                queue[k].f = p;
            } else {
                queue[k].e->next = p;
            }
            queue[k].e = p;
            p = p->next;
        }
        i = 0;
        while(queue[i].f == NULL){
            i++;
        }
        p = queue[i].e;
        head = queue[i].f;
        for(i = 0; i < r; i++){
            if(queue[i].f != NULL){
                p->next = queue[i].f;
                p = queue[i].e;
            }
        }
        p->next = NULL;
    }
}


typedef struct{
    int key;
    int info;
}RecordNode;
typedef struct{
    RecordNode record[MAXNUM];
    int n;
}SortObject;


void merge(RecordNode r[], RecordNode r1[], int low, int m, int high){//两个有序文件
    int i, j, k;
    i = low;
    j = m + 1;
    k = low;
    while((i <= m) && (j <= high)){//从两个有序文件中的第一个记录中选出小的记录
        if(r[i].key <= r[j].key)
        {
            r1[k] = r[i];
            k++;
            i++;
        }
        else{
            r1[k] = r[j];
            k++;
            j++;
        }
    }
    while(i <= m){
        r1[k] = r[i];
        k++;
        i++;
    }
    while(j <= high){
        r1[k] = r[j];
        k++;
        j++;
    }
}
void mergePass(RecordNode r[], RecordNode r1[], int n, int length){//对r做一趟归并，结果在r1中，length为本趟归并的有序子文件长度
    int i, j;
    i = 0;
    while(i + 2*length - 1 < n){
        merge(r, r1, i, i+length-1, i+2*length-1);
        i += 2*length;
    }
    if(i+length-1 < n-1){//剩下两个子文件，其中一个长度小于length
        merge(r, r1, i, i+length-1, n-1);
    }
    else{//只剩下一个子文件
        for(j = i; j < n; j++){
            r1[j] = r[j];
        }
    }
}
void mergeSort(SortObject *pvector){
    RecordNode record[MAXNUM];
    int length;
    length = 1;
    while(length < pvector->n){
        mergePass(pvector->record, record, pvector->n, length);//一趟归并，结果存在r1中
        length *= 2;
        mergePass(record, pvector->record, pvector->n, length);//一趟归并，结果存在r中
        length *= 2;
    }
}