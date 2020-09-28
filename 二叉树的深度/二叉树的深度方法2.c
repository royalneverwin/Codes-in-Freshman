#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 11
struct Node{
    int left;
    int right;
    int info;
};
struct SeqBTree{//顺序表示的二叉树定义
    struct Node nodelist[MAXNUM];
    int n;//改造成完全二叉树后，结点的个数
};


int max(struct SeqBTree t, int num){
    if(t.nodelist[num].left == -1 && t.nodelist[num].right == -1){
        return 1;
    }
    else if(t.nodelist[num].left == -1){
        return 1+max(t, t.nodelist[num].right-1);
    }
    else if(t.nodelist[num].right == -1){
        return 1+max(t, t.nodelist[num].left-1);
    }
    else{
        if(max(t, t.nodelist[num].right-1) > max(t, t.nodelist[num].left-1)){
            return 1+max(t, t.nodelist[num].right-1);
        }
        else{
            return 1+max(t, t.nodelist[num].left-1);
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    struct SeqBTree t;
    t.n = n;
    int i;
    int left, right;
    for(i = 0; i < n; i++){
        scanf("%d%d", &left, &right);
        t.nodelist[i].info = i+1;
        t.nodelist[i].left = left;
        t.nodelist[i].right = right;
    }
    struct Node temp;
    int height = 1;
    for(i = 0; i < n; i++){
        if(max(t, i) > height){
            height = max(t, i);
        }
    }
    printf("%d", height);
    return 0;
}