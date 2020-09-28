#include <stdio.h>
int main(){
    int row,col;
    scanf("%d%d",&row,&col);
    int num[101][101];
    int i,j;
    for(i=1;i<=row;i++){
        for(j=1;j<=col;j++){
            scanf("%d",&num[i][j]);
        }
    }
    for(j=0;j<=col+1;j++){
        num[0][j]=num[row+1][j]=-100;
    }
    for(i=0;i<=row+1;i++){
        num[i][0]=num[i][col+1]=-100;
    }
    int a=1,b=1;
    while(num[a][b]!=-100){
        if(a!=1||b!=1) {
            putchar('\n');
        }
        printf("%d",num[a][b]);
        num[a][b]=-100;
        if(num[a-1][b]==-100&&num[a][b-1]==-100){
            if(num[a][b+1]==-100){
                a++;
                continue;
            }
            else{
                b++;
                continue;
            }
        }
        else if(num[a-1][b]==-100&&num[a][b+1]==-100){
            if(num[a+1][b]==-100){
                b--;
                continue;
            }
            else{
                a++;
                continue;
            }
        }
        else if(num[a+1][b]==-100&&num[a][b+1]==-100){
            if(num[a][b-1]==-100){
                a--;
                continue;
            }
            else{
                b--;
                continue;
            }
        }
        else if(num[a+1][b]==-100&&num[a][b-1]==-100) {
            if(num[a-1][b]==-100){
                b++;
                continue;
            }
            else{
                a--;
                continue;
            }
        }
    }
    return 0;
}
/*方法二：
#include <stdio.h>

#define INF 1000000

int main(void)
{
    int row, col, i, j;
    int a[100][100] = {0};
    int flag = 1;
    int x = 0, y = 0;
    scanf("%d%d", &row, &col);
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            scanf("%d", &a[i][j]);

     //flag = 1, 右
     //flag = 2, 下
     //flag = 3, 左
     //flag = 4, 上

    printf("%d\n", a[x][y]);
    if (row == 1 && col == 1)
        return 0;
    else if (col == 1)
        flag = 2;
    for (i = 1; i < row * col; i++)
    {
        a[x][y] = INF;
        if (flag == 1)
        {
            y++;
            if (y == col - 1 || a[x][y + 1] == INF)
                flag = 2;
        }
        else if (flag == 2)
        {
            x++;
            if (x == row - 1 || a[x + 1][y] == INF)
                flag = 3;
        }
        else if (flag == 3)
        {
            y--;
            if (y == 0 || a[x][y - 1] == INF)
                flag = 4;
        }
        else
        {
            x--;
            if (x == 0 || a[x - 1][y] == INF)
                flag = 1;
        }
        printf("%d\n", a[x][y]);
    }
    return 0;
}*/

/*方法三：
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int time=0;
int row,col;
void f(int pt[][100],int x,int y);
int main() {
    int num[100][100];
    scanf("%d%d",&row,&col);
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&num[i][j]);
        }
    }
    f(num,0,0);
    return 0;
}
void f(int pt[][100],int x,int y){
    if(time!=0){
        putchar('\n');
    }
    printf("%d",pt[x][y]);
    time++;
    if(x==row-1&&y==col-1){
        return;
    }
    if(y==0){
        if(x<col-1){
            y=x+1;
            x=0;
        }
        else{
            y=col-1;
            x=x+1-y;
        }
    }
    else if(x==row-1){
        if(x+y<col-1){
            y=x+y+1;
            x=0;
        }
        else{
            x=x+y+2-col;
            y=col-1;
        }
    }
    else{
        x++;
        y--;
    }
    f(pt,x,y);
}*/

/*方法四：
 * #include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
int time=1;
void change(int *p1,int *p2);
int row,col;
int flag1=1,flag2=1,flag3=1,flag4=1;
int row1,col1,row2,col2;
int main() {
    scanf("%d%d",&row,&col);
    int num[101][101];
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&num[i][j]);
        }
    }
    i=j=0;
    row2=row-1;
    col2=col-1;
    row1=col1=0;
    while(time<=row*col){
        printf("%d\n",num[i][j]);
        time++;
        change(&i,&j);
    }
    return 0;
}
void change(int *p1,int *p2){
  //  printf("%d %d %d %d\n",row1,row2,col1,col2);
    if(*p1==row1&&flag1==1){
        if(*p2==col2){
            (*p1)++;
            row1++;
            flag1=0;
            flag2=1;
        } else{
            (*p2)++;
        }
    } else if(*p2==col2&&flag2==1){
        if(*p1==row2){
            col2--;
            (*p2)--;
            flag2=0;
            flag3=1;
        } else{
            (*p1)++;
        }
    } else if(*p1==row2&&flag3==1){
        if(*p2==col1){
            row2--;
            (*p1)--;
            flag3=0;
            flag4=1;
        } else{
            (*p2)--;
        }
    } else if(*p2==col1&&flag4==1){
        if(*p1==row1){
           // printf("yes!\n");
            col1++;
            (*p2)++;
            flag4=0;
            flag1=1;
        } else{
            (*p1)--;
        }
    }
}
 */