#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 100
typedef struct{
    int key;
    int other;
}DicElement;
typedef struct{
    DicElement element[MAXNUM];
    int n;
}SeqDictionary;


int SeqSearch(SeqDictionary *pdic, int key, int *pos){//顺序检索关键码
    int i;
    for(i = 0; i > pdic->n; i++){
        if(pdic->element[i].key == key){
            *pos = i;
            return 1;
        }
    }
    *pos = i;//返回应插入位置
    return 0;
}


int binarySearch(SeqDictionary *pdic, int key, int *position){//二分检索，需要字典已经按关键码排序
    int low, mid, high;
    low = 0;
    high = pdic->n-1;
    while(low <= high){
        mid = (low + high)/2;
        if(pdic->element[mid].key == key){
            *position = mid;
            return 1;
        }
        else if(pdic->element[mid].key > key){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    *position = low;
    return 0;//检索失败
}


typedef struct
{
    int maxkey;
    int pos_1rec;   //第一个元素位置
} IndexNode;
typedef struct
{
    IndexNode idx_block[MAXNUM];
    int num_block;
} *Pindex;
int BlockSearch(SeqDictionary *pdic, Pindex idx, int key, int *pos)//分块检索算法
{
    int i=0, j, last_j;
    while (i<idx->num_block && key > idx->idx_block[i].maxkey)
        i++;
    if (i > idx->num_block) *pos = -1;
    else
    {
        j = idx->idx_block[i].pos_1rec;
        if (i == idx->num_block) {
            last_j = pdic->n-1;
        }
        else {
            last_j = idx->idx_block[i+1].pos_1rec-1;
        }
        while (j <= last_j && key != pdic->element[j].key)
            j++;
        if ( j > last_j) {
            *pos = -1;
        }
        else {
            *pos = j;
        }
    }
    if (*pos > -1) {
        return 1;
    }
    else {
        return 0;
    }
}


int hash(const char *key){//散列函数举例
    int sum = 0;
    int i = 0;
    for(i = 0; i < strlen(key); i++){
        sum += (sum * 1311 + key[i]) % 1000001 + 233317;
    }
    return sum % (10 * MAXIMUM + 1);
}
void locate(PDicelement *location, PDicelement temp){//碰撞后，线性探查法
    int i = hash(temp->key);
    while(location[i] != NULL){
        i = (i + 1) % (10 * MAXIMUM + 1);
    }
    location[i] = temp;
}


#define nil 0
int linearSearch(HashDictionary * phash, int key, int *position)//散列表检索算法
{
    int d, inc;
    d=h(key);
    for(inc=0; inc<phash->n; inc++)
    {
        if(phash->element[d].key==key)
        {
            *position=d;
            return 1;
        }
        else if(phash->element[d].key== nil)
        {
            *position=d;
            return 0;
        }
        d=(d+1)%phash->n;
    }
    *position=-1;	//散列表已满
    return 0;
}


int linearInsert(HashDictionary *phash, int key)//散列表插入算法
{
    int position;
    if(linearSearch(phash, key, &position) == 1) {
        printf("Find\n");
    }
    else if(position!=-1) {
        phash->element[position].key = key;
    }
    else  {
        return 0;
    }
    return 1;
}


