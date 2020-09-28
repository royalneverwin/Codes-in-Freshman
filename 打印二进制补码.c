#include <stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    int i;
    for(i=31;i>=0;i--)
        printf("%d",(x>>i)&1);

    return 0;
}





