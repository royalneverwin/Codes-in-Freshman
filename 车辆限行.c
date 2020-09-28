#include <stdio.h>
int runnian(int n);
int main(){
    int n;
    scanf("%d",&n);
    getchar();
    int a,b,c;
    int i,j;
    int total;
    int left,num;
    char ch[100][7];
    for(i=0;i<n;i++){
        total=num=0;
        scanf("%d-%d-%d",&a,&b,&c);
        getchar();
        scanf("%s",ch[i]);
        for(j=2000;j<a;j++){
            if(runnian(j)){
                num++;
            }
        }
        total+=((a-2000)*365+num);
        if(runnian(a)){
            if(b==1){
                total+=c-1;
            }
            if(b==2){
                total=total+31+c-1;
            }
            if(b==3){
                total=total+60+c-1;
            }
            if(b==4){
                total=total+91+c-1;
            }
            if(b==5){
                total=total+121+c-1;
            }
            if(b==6){
                total=total+152+c-1;
            }
            if(b==7){
                total=total+182+c-1;
            }
            if(b==8){
                total=total+213+c-1;
            }
            if(b==9){
                total=total+244+c-1;
            }
            if(b==10){
                total=total+274+c-1;
            }
            if(b==11){
                total=total+305+c-1;
            }
            if(b==12){
                total=total+335+c-1;
            }
        }
        else{
            if(b==1){
                total=total+c-1;
            }
            if(b==2){
                total=total+31+c-1;
            }
            if(b==3){
                total=total+59+c-1;
            }
            if(b==4){
                total=total+90+c-1;
            }
            if(b==5){
                total=total+120+c-1;
            }
            if(b==6){
                total=total+151+c-1;
            }
            if(b==7){
                total=total+181+c-1;
            }
            if(b==8){
                total=total+212+c-1;
            }
            if(b==9){
                total=total+243+c-1;
            }
            if(b==10){
                total=total+273+c-1;
            }
            if(b==11){
                total=total+304+c-1;
            }
            if(b==12){
                total=total+334+c-1;
            }
        }
        left=total%7;
        //printf("%d %d %d %d %d",a,b,c,total,left);
        if(left==2&&(ch[i][5]=='1'||ch[i][5]=='6')){
            puts("yes");
        }
        else if(left==3&&(ch[i][5]=='2'||ch[i][5]=='7')){
            puts("yes");
        }
        else if(left==4&&(ch[i][5]=='3'||ch[i][5]=='8')){
            puts("yes");
        }
        else if(left==5&&(ch[i][5]=='4'||ch[i][5]=='9')){
            puts("yes");
        }
        else if(left==6&&(ch[i][5]=='5'||ch[i][5]=='0'||(ch[i][5]>='A'&&ch[i][5]<='Z'))){
            puts("yes");
        }
        else{
            puts("no");
        }
    }
    return 0;
}
int runnian(int n){
    int a=0;
    if(n%100==0){
        if(n%400==0){
            a=1;
        }
    }
    else if(n%4==0){
        a=1;
    }
    return a;
}

