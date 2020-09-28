#include <stdio.h>
int num=1;
void total(int m,int n,int k,int a);
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int m;
    for(m=0;;m++){
        num=1;
        total(m,n,k,n);
        if(num){
            printf("%d",m);
            break;
        }
    }
} void total(int m,int n,int k,int a){
    if(a==1){
        if((m-k)/n<1||(m-k)%n!=0){
            num=0;
        }
    }
    else{
        if((m-k)%n!=0){
            num=0;
        }
        else{
            m=(m-k)*(n-1)/n;
            a--;
            total(m,n,k,a);
        }
    }
}