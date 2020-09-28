#include <stdio.h>
#include <stdlib.h>
#define MAXIMUM 10001
typedef struct{
    int key;
    int ele;
}Dicelement;
typedef struct{
    Dicelement element[MAXIMUM];
    int n;
}SeqDictionary;
int Calculate(SeqDictionary A, SeqDictionary B, int sum){
    int result = 0;
    int i, j;
    for(i = 0; i < A.n; i++){
        for(j = 0; j < B.n; j++){
            if(A.element[i].ele + B.element[j].ele == sum){
                result++;
            }
        }
    }
    return result;
}
int main(){
    int n, i, j, a, b, a_num, b_num, sum;
    SeqDictionary A, B;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        A.n = B.n = 0;
        scanf("%d", &sum);
        scanf("%d", &a);
        for(j = 0; j < a; j++){
            scanf("%d", &a_num);
            A.element[j].key = j+1;
            A.element[j].ele = a_num;
            A.n++;
        }
        scanf("%d", &b);
        for(j = 0; j < b; j++){
            scanf("%d", &b_num);
            B.element[j].key = j+1;
            B.element[j].ele = b_num;
            B.n++;
        }
        printf("%d", Calculate(A, B, sum));
        if(i != n){
            putchar('\n');
        }
    }
    return 0;
}