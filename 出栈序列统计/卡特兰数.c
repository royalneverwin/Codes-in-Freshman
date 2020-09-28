#include <stdio.h>
int Time(int n){
    if(n == 1 || n == 0){
        return 1;
    }
    else{
        int i;
        int time = 0;
        for(i = 1; i<= n; i++){
            time += Time(i-1)*Time(n-i);
        }
        return time;
    }
}
int main(){
    int n;
    scanf("%d", &n);
    int i;
    int time = 0;
    for(i = 1; i<= n; i++){
        time += Time(i-1)*Time(n-i);
    }
    printf("%d", time);
}