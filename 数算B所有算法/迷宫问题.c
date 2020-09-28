

/*******************************************************************
求迷宫中的一条路径
*******************************************************************/

#define M 8    /* maze数组的行数 */
#define N 11     /* maze数组的列数 */
#define MAXNUM 54
#define ERROR 0
#define OK 1
#include "stdio.h"
#include "malloc.h"

typedef struct
{
    int x, y, d;
} DataType;

struct SeqStack /*顺序栈类型定义*/
{
    DataType s[MAXNUM];
    int t;   /* 指示栈顶位置，空栈=-1 */
};

typedef struct SeqStack *PSeqStack;
int isEmptyStack_seq( PSeqStack pastack );
PSeqStack createEmptyStack_seq( void );
void mazePath (int *maze[],int *direction[],int x1,int y1,int x2,int y2);
int push_seq( PSeqStack pastack, DataType x );
int pop_seq(PSeqStack pastack);
DataType top_seq(PSeqStack pastack);

int maze[M][N]={{1,1,1,1,1,1,1,1,1,1,1},{1,0,1,0,0,1,1,1,0,0,1},
                {1,0,0,0,0,0,1,0,0,1,1},{1,0,1,1,1,0,0,0,1,1,1},
                {1,0,0,0,1,0,1,1,0,1,1},{1,1,0,0,1,0,1,1,0,0,1},
                {1,1,1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1,1}};
int direction[4][2]={{0,1},{1,0},{0,-1},{-1,0}};


main()
{
    int *m[M];
    int **p;
    int *d[4];
    int i;
    for (i=0;i<M;i++)
        m[i]=maze[i];       /*m[i]中是maze第i行的开始地址*/
    p=m;    /*p中是的开始地址*/
    for(i=0;i<4;i++)
        d[i]=direction[i];
    mazePath(p,d,1,1,6,9); /*mazepath要修改数组maze的数值*/
}


/* 迷宫maze[M][N]中,求从入口maze[x1][y1]到出口maze[x2][y2]的一条路径?
其中 1<=x1,x2<=M-2 , 1<=y1,y2<=N-2 */
void mazePath(int *maze[],int *direction[],int x1,int y1,int x2,int y2)
{
    int i, j, k;
    int g,h;
    PSeqStack st;
    DataType element;
    st = createEmptyStack_seq( );
    /* 创建空栈 */
    maze[x1][y1] = 2;  /* 从入口开始进入,作标记 */
    element.x = x1;
    element.y = y1;
    element.d = -1;
    push_seq(st,element);
    /* 入口点进栈 */
    while (!isEmptyStack_seq(st))  /* 走不通时,一步步回退 */
    {
        element = top_seq(st);
        pop_seq(st);
        i = element.x;
        j = element.y;
        k = element.d + 1;
        while (k<=3)
            /* 依次试探每个方向 */
        {
            g = i + direction[k][0];
            h = j + direction[k][1];