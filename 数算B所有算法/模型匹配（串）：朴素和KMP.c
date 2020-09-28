#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAXIMUM 500
struct SeqString{
    char c[MAXIMUM];
    int n;
};
typedef struct SeqString *PSeqString;


PSeqString CreateNULLStr_Seq( void ) {
    PSeqString pstr;
    pstr = (PSeqString) malloc(sizeof(struct SeqString));
    if (!pstr) {
        printf("内存溢出!\n");
        return NULL;
    } else {
        pstr->n = 0;
        return pstr;
    }
}


PSeqString strcat_Seq( struct SeqString s1, struct SeqString s2 ){
    int i;
    PSeqString s = NULL;
    printf("s1 = %s, s2 = %s\n", s1.c, s2.c);
    if (s1.n+s2.n >= MAXIMUM) // 必须保证新的字符串长度合法
    { printf("长度溢出！\n");
        return NULL ;
    }
    else{
        s = CreateNULLStr_Seq(); // 创建空串
        for ( i = 0; i < s1.n; i++) {
            s->c[i] = s1.c[i];
        }
        // 将s1传给s
        for ( i = 0; i < s2.n; i++) {
            s->c[s1.n+i] = s2.c[i]; // 将s2传给s
        }
        s->n = s1.n+s2.n; // 联结后的长度
        s->c[s->n] = '\0'; // 最后结束标志
        return s;
    }
}


PSeqString substr_Seq( struct SeqString s, int i, int j ){
    PSeqString s1; int k;
    s1 = CreateNULLStr_Seq(); // 创建空串
    if (!s1) {
        return NULL;
    }
    if ( i >= 0 && i <= s.n && j > 0) // i, j 必须合法
    {
        if(s.n < i+j-1) {
            j = s.n-i+1; // 从i开始的连续字符数不够j个时
        }
        for ( k = 0; k < j; k++) {
            s1->c[k] = s.c[i+k-1];
        }
        s1->c[j] = '\0'; // 最后结束标志
        s1->n = j; // 串长
    } else {
        s1->c[0] = '\0'; // 空串
    }
    return s1;
}


void DelSubStr_Seq( PSeqString s, int i, int j )
{
    int k;
    if (i+j-1 > s->n)      // 若i, j的值超出范围，进行超界处理
        printf("超界!\n");
    else
    {
        for ( k = i+j-1; k<s->n; k++) // 被删除子串后的所有字符前移j个位置
        {
            s->c[k-j] = s->c[k];
        }
        s->n -= j;    // 删除后的串长
        s->c[s->n] = '\0';   // 结束标志
    }
}


void InsertSubStr_Seq( PSeqString s, int i, struct SeqString r )
{
    int k;
    if ( i >= s->n || s->n+r.n > MAXIMUM ) {

        // 插入位置必须合法，新的串长度不能越界
        printf("不能插入!\n");
    }
    else
    {
        for ( k = s->n-1; k >= i-1; k--) {// 从第i个位置起空出连续r.n个位置
            s->c[k + r.n] = s->c[k];
        }
        for ( k = 0; k< r.n; k++) {// 插入子串
            s->c[i + k - 1] = r.c[k];
        }
        s->n += r.n;   // 修改串长
        s->c[s->n] = '\0';   // 结束标志
    }
}


int LocSubStr_Seq(PSeqString t, PSeqString p){//t主，p辅
    int pi = 0, tj = 0;
    while ( pi < p->n && tj < t->n) //反复比较
    {
        if ( p->c[pi] == t->c[tj]){
            pi++; tj++;
        } //继续匹配下一个字符
        else{
            tj = tj-pi+1; pi = 0;
        } //主串、子串pi、tj值回溯，重新开始
    }
    if( pi >= p->n) {
        return (tj-p->n+1); //匹配成功，返回位置
    }
    else {
        return 0; //匹配失败
    }
}


int KMP( PSeqString t, PSeqString p, int *next){//无回溯
    int i, j;
    i = j =0;
    while(i < p->n && j < t->n) {
        if (i == -1 || p->c[i] == t->c[i]) {
            i++;
            j++;
        } else {
            i = next[i];
        }
    }
    if(i >= p->n){
        return(j-p->n+1);
    }
    else{
        return 0;
    }
}


void makeNext(PSeqString p, int *next){
    int i = 0;
    int k = -1;
    next[0] = -1;
    while(i < p->n-1){
        while(k >= 0 && p->c[i] != p->c[k]) {
            k = next[k];
        }
        k++;
        i++;
        next[i] = k;
    }
}