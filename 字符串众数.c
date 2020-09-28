#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool a(char *p1,char (*p2)[500],int b);
bool c(char *p1);
int main() {
    int N;
    scanf("%d",&N);
    char ch[129][500];
    int i,j,k,l,max;
    for(i=0;i<N;i++){
        scanf("%s",ch[i]);
    }
    char *pt[129];
    for(i=0;i<N;i++){
        if(c(ch[i])){
            pt[i]="0";
        }
        else {
            for (j = 0; ch[i][j] != '\0'; j++) {
                if (ch[i][0] == '-') {
                    if (ch[i][j] != '0' && ch[i][j] != '-') {
                        ch[i][j - 1] = '-';
                        pt[i] = &ch[i][j - 1];
                        break;
                    }
                }
                else {
                    if (ch[i][j] != '0' && ch[i][j] != '+') {
                        pt[i] = &ch[i][j];
                        break;
                    }
                }
            }
        }
    }
    //for(l=0;l<N;l++){
      //  printf("%s\n",pt[l]);
    //}

    char ch1[129][500];
    int num[129]={0};
    j=0;
    for(i=0;i<N;i++){
        if(a(pt[i],ch1,j)){
            strcpy(ch1[j],pt[i]);
            j++;
        }
    }
    if(j==1){
        printf("no");
    }
    else {
        for (i = 0; i < N; i++) {
            for (k = 0; k < j; k++){
                if(strcmp(pt[i],ch1[k])==0){
                    num[k]++;
                }
            }
        }
        max=num[0];
        l=0;
        for(k=0;k<j;k++){
            if(num[k]>max){
                max=num[k];
                l=k;
            }
        }
        printf("%s",ch1[l]);
    }
    return 0;
}
bool a(char *p1,char (*p2)[500],int b){
    bool w=true;
    if(b==0){
        return w;
    }
    else{
        int i;
        for(i=0;i<b;i++){
            if(strcmp(p1,*(p2+i))==0){
                w=false;
                break;
            }
        }
    }
    return w;
}
bool c(char *p1){
    bool w=true;
    int i;
    for(i=0;p1[i]!='\0';i++) {
        if (p1[i] != '0'&&p1[i]!='-'&&p1[i]!='+') {
            w = false;
            break;
        }
    }
    return w;
}