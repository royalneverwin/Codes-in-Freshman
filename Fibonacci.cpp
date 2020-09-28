#include <stdio.h>
int F(int n);
int main()
{
    int n;
    int num;
    scanf("%d",&n);
    num=F(n);
    printf("%d",num);
    return 0;
}
int F(int n)
{
    int a[1000];
    int i=2;
     a[0]=1;
     a[1]=1;
     while(i<1000)
     {
         a[i]=a[i-2]+a[i-1];
         i++;
     }
    return a[n-1];

}
/*方法二：
    int num[n];
    num[0]=a;
    num[1]-b;
    void F(int a,int b){
    if(time<n){
        num[time]=a+b;
        time++;
        F(b,num[time-1]);
    }
}*/