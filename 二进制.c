#include <stdio.h>
void to_base(unsigned long a,int b);
int main(void)
{
    unsigned long num;
    int time;
    scanf("%lu %d",&num,&time);
    to_base(num,time);
}
void to_base(unsigned long a,int b)
{
    int r;
    r=a%b;
    if(a>=b)
        to_base(a/b,b);
    printf("%d ",r);
}