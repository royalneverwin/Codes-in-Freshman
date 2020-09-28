#include <stdio.h>
#include <string.h>
int main(){
    int n;
    scanf("%d",&n);
    int i,j,k,l;
    int a,b,c,d,e,f;
    int x,y,z;
    int num[12];
    char C[]="ABCDEFGHIJKL";
    char uniq;
    char ch[6][12];
    char result[3][5];
    char re1[]="even";
    char re2[]="up";
    char re3[]="down";
    int right1[12],right2[12];
    for(i=0;i<n;i++){
        x=y=z=0;
        for(l=0;l<12;l++){
            num[l]=0;
            right1[l]=0;
            right2[l]=0;
        }
        scanf("%s%s%s%s%s%s%s%s%s",ch[0],ch[1],result[0],ch[2],ch[3],result[1],ch[4],ch[5],result[2]);
        a=strlen(ch[0]);
        b=strlen(ch[1]);
        c=strlen(ch[2]);
        d=strlen(ch[3]);
        e=strlen(ch[4]);
        f=strlen(ch[5]);
        if(strcmp(result[0],re1)==0){
            x=1;
            for(j=0;j<a;j++) {
                for (k = 0; k < 12; k++) {
                    if (ch[0][j] ==C[k]){
                        num[k]=2;
                    }
                }
            }
            for(j=0;j<b;j++) {
                for (k = 0; k < 12; k++) {
                    if (ch[1][j] ==C[k]){
                        num[k]=2;
                    }
                }
            }
        }
        if(strcmp(result[1],re1)==0){
            y=1;
            for(j=0;j<c;j++) {
                for (k = 0; k < 12; k++) {
                    if (ch[2][j] ==C[k]){
                        num[k]=2;
                    }
                }
            }
            for(j=0;j<d;j++) {
                for (k = 0; k < 12; k++) {
                    if (ch[3][j] ==C[k]){
                        num[k]=2;
                    }
                }
            }
        } if(strcmp(result[2],re1)==0){
            z=1;
            for(j=0;j<e;j++) {
                for (k = 0; k < 12; k++) {
                    if (ch[4][j] ==C[k]){
                        num[k]=2;
                    }
                }
            }
            for(j=0;j<f;j++) {
                for (k = 0; k < 12; k++) {
                    if (ch[5][j] ==C[k]){
                        num[k]=2;
                    }
                }
            }
        }
        //for(l=0;l<12;l++){
        //    printf("%d ",num[l]);
        // }
        if((x==1&&y==1)||(x==1&&z==1)||(y==1&&z==1)){
            if(x==0){
                if(strcmp(result[0],re2)==0){
                    for(j=0;j<a;j++){
                        for(k=0;k<12;k++){
                            if(ch[0][j]==C[k]&&num[k]==0){
                                uniq=C[k];
                                printf("%c is the counterfeit coin and it is heavy.\n",uniq);
                                // return 0;
                            }
                        }
                    }
                    for(j=0;j<b;j++){
                        for(k=0;k<12;k++){
                            if(ch[1][j]==C[k]&&num[k]==0){
                                uniq=C[k];
                                printf("%c is the counterfeit coin and it is light.\n",uniq);
                                //return 0;
                            }
                        }
                    }
                }
                else if(strcmp(result[0],re3)==0){
                    for(j=0;j<a;j++){
                        for(k=0;k<12;k++){
                            if(ch[0][j]==C[k]&&num[k]==0){
                                uniq=C[k];
                                printf("%c is the counterfeit coin and it is light.\n",uniq);
                                // return 0;
                            }
                        }
                    }
                    for(j=0;j<b;j++){
                        for(k=0;k<12;k++){
                            if(ch[1][j]==C[k]&&num[k]==0){
                                uniq=C[k];
                                printf("%c is the counterfeit coin and it is heavy.\n",uniq);
                                //  return 0;
                            }
                        }
                    }
                }
            }
            else if(y==0){
                if(strcmp(result[1],re2)==0){
                    for(j=0;j<c;j++){
                        for(k=0;k<12;k++){
                            if(ch[2][j]==C[k]&&num[k]==0){
                                uniq=C[k];
                                printf("%c is the counterfeit coin and it is heavy.\n",uniq);
                                // return 0;
                            }
                        }
                    }
                    for(j=0;j<d;j++){
                        for(k=0;k<12;k++){
                            if(ch[3][j]==C[k]&&num[k]==0){
                                uniq=C[k];
                                printf("%c is the counterfeit coin and it is light.\n",uniq);
                                // return 0;
                            }
                        }
                    }
                }
                if(strcmp(result[1],re3)==0){
                    for(j=0;j<c;j++){
                        for(k=0;k<12;k++){
                            if(ch[2][j]==C[k]&&num[k]==0){
                                uniq=C[k];
                                printf("%c is the counterfeit coin and it is light.\n",uniq);
                                //  return 0;
                            }
                        }
                    }
                    for(j=0;j<d;j++){
                        for(k=0;k<12;k++){
                            if(ch[3][j]==C[k]&&num[k]==0){
                                uniq=C[k];
                                printf("%c is the counterfeit coin and it is heavy.\n",uniq);
                                // return 0;
                            }
                        }
                    }
                }
            }
            else if(z==0){
                if(strcmp(result[2],re2)==0){
                    for(j=0;j<e;j++){
                        for(k=0;k<12;k++){
                            if(ch[4][j]==C[k]&&num[k]==0){
                                uniq=C[k];
                                printf("%c is the counterfeit coin and it is heavy.\n",uniq);
                                // return 0;
                            }
                        }
                    }
                    for(j=0;j<f;j++){
                        for(k=0;k<12;k++){
                            if(ch[5][j]==C[k]&&num[k]==0){
                                uniq=C[k];
                                printf("%c is the counterfeit coin and it is light.\n",uniq);
                                //  return 0;
                            }
                        }
                    }
                }
                if(strcmp(result[2],re3)==0){
                    for(j=0;j<e;j++){
                        for(k=0;k<12;k++){
                            if(ch[4][j]==C[k]&&num[k]==0){
                                uniq=C[k];
                                printf("%c is the counterfeit coin and it is light.\n",uniq);
                                // return 0;
                            }
                        }
                    }
                    for(j=0;j<f;j++){
                        for(k=0;k<12;k++){
                            if(ch[5][j]==C[k]&&num[k]==0){
                                uniq=C[k];
                                printf("%c is the counterfeit coin and it is heavy.\n",uniq);
                                // return 0;
                            }
                        }
                    }
                }
            }
        }
        else if(x==0&&y==0&&z==0){
            if(strcmp(result[0],re2)==0) {
                for (j = 0; j < a; j++) {
                    for (k = 0; k < 12; k++) {
                        if (ch[0][j] == C[k]) {
                            num[k] = 3;
                        }
                    }
                }
                for (j = 0; j < b; j++) {
                    for (k = 0; k < 12; k++) {
                        if (ch[1][j] == C[k]) {
                            num[k] = 1;
                        }
                    }
                }
                for(l=0;l<12;l++){
                    if(num[l]==0){
                        num[l]=2;
                    }
                }
                if(strcmp(result[1],re2)==0){
                    for(j=0;j<c;j++){
                        for(k=0;k<12;k++){
                            if(ch[2][j]==C[k]&&num[k]==3){
                                right1[k]=1;
                            }
                        }
                    }
                    for(j=0;j<d;j++){
                        for(k=0;k<12;k++){
                            if(ch[3][j]==C[k]&&num[k]==1){
                                right1[k]=1;
                            }
                        }
                    }
                    if(strcmp(result[2],re2)==0){
                        for(j=0;j<e;j++){
                            for(k=0;k<12;k++){
                                if(ch[4][j]==C[k]&&num[k]==3){
                                    right2[k]=1;
                                }
                            }
                        }
                        for(j=0;j<f;j++){
                            for(k=0;k<12;k++){
                                if(ch[5][j]==C[k]&&num[k]==1){
                                    right2[k]=1;
                                }
                            }
                        }
                        for(l=0;l<12;l++){
                            if(right1[l]&&right2[l]){
                                uniq=C[l];
                                if(num[l]==1) {
                                    printf("%c is the counterfeit coin and it is light.\n", uniq);
                                }
                                else{
                                    printf("%c is the counterfeit coin and it is heavy.\n", uniq);
                                }
                            }
                        }
                    }
                    else{
                        for(j=0;j<e;j++){
                            for(k=0;k<12;k++){
                                if(ch[4][j]==C[k]&&num[k]==1){
                                    right2[k]=1;
                                }
                            }
                        }
                        for(j=0;j<f;j++){
                            for(k=0;k<12;k++){
                                if(ch[5][j]==C[k]&&num[k]==3){
                                    right2[k]=1;
                                }
                            }
                        }
                        for(l=0;l<12;l++){
                            if(right1[l]&&right2[l]){
                                uniq=C[l];
                                if(num[l]==1) {
                                    printf("%c is the counterfeit coin and it is light.\n", uniq);
                                }
                                else{
                                    printf("%c is the counterfeit coin and it is heavy.\n", uniq);
                                }
                            }
                        }
                    }
                }
                else{
                    for(j=0;j<c;j++){
                        for(k=0;k<12;k++){
                            if(ch[2][j]==C[k]&&num[k]==1){
                                right1[k]=1;
                            }
                        }
                    }
                    for(j=0;j<d;j++){
                        for(k=0;k<12;k++){
                            if(ch[3][j]==C[k]&&num[k]==3){
                                right1[k]=1;
                            }
                        }
                    }
                    if(strcmp(result[2],re2)==0){
                        for(j=0;j<e;j++){
                            for(k=0;k<12;k++){
                                if(ch[4][j]==C[k]&&num[k]==3){
                                    right2[k]=1;
                                }
                            }
                        }
                        for(j=0;j<f;j++){
                            for(k=0;k<12;k++){
                                if(ch[5][j]==C[k]&&num[k]==1){
                                    right2[k]=1;
                                }
                            }
                        }
                        for(l=0;l<12;l++){
                            if(right1[l]&&right2[l]){
                                uniq=C[l];
                                if(num[l]==1) {
                                    printf("%c is the counterfeit coin and it is light.\n", uniq);
                                }
                                else{
                                    printf("%c is the counterfeit coin and it is heavy.\n", uniq);
                                }
                            }
                        }
                    }
                    else{
                        for(j=0;j<e;j++){
                            for(k=0;k<12;k++){
                                if(ch[4][j]==C[k]&&num[k]==1){
                                    right2[k]=1;
                                }
                            }
                        }
                        for(j=0;j<f;j++){
                            for(k=0;k<12;k++){
                                if(ch[5][j]==C[k]&&num[k]==3){
                                    right2[k]=1;
                                }
                            }
                        }
                        for(l=0;l<12;l++){
                            if(right1[l]&&right2[l]){
                                uniq=C[l];
                                if(num[l]==1) {
                                    printf("%c is the counterfeit coin and it is light.\n", uniq);
                                }
                                else{
                                    printf("%c is the counterfeit coin and it is heavy.\n", uniq);
                                }
                            }
                        }
                    }
                }
            }
            else{
                for (j = 0; j < a; j++) {
                    for (k = 0; k < 12; k++) {
                        if (ch[0][j] == C[k]) {
                            num[k] = 1;
                        }
                    }
                }
                for (j = 0; j < b; j++) {
                    for (k = 0; k < 12; k++) {
                        if (ch[1][j]== C[k]) {
                            num[k] = 3;
                        }
                    }
                }
                for(l=0;l<12;l++){
                    if(num[l]==0){
                        num[l]=2;
                    }
                }
                if(strcmp(result[1],re2)==0){
                    for(j=0;j<c;j++){
                        for(k=0;k<12;k++){
                            if(ch[2][j]==C[k]&&num[k]==3){
                                right1[k]=1;
                            }
                        }
                    }
                    for(j=0;j<d;j++){
                        for(k=0;k<12;k++){
                            if(ch[3][j]==C[k]&&num[k]==1){
                                right1[k]=1;
                            }
                        }
                    }
                    if(strcmp(result[2],re2)==0){
                        for(j=0;j<e;j++){
                            for(k=0;k<12;k++){
                                if(ch[4][j]==C[k]&&num[k]==3){
                                    right2[k]=1;
                                }
                            }
                        }
                        for(j=0;j<f;j++){
                            for(k=0;k<12;k++){
                                if(ch[5][j]==C[k]&&num[k]==1){
                                    right2[k]=1;
                                }
                            }
                        }
                        for(l=0;l<12;l++){
                            if(right1[l]&&right2[l]){
                                uniq=C[l];
                                if(num[l]==1) {
                                    printf("%c is the counterfeit coin and it is light.\n", uniq);
                                }
                                else{
                                    printf("%c is the counterfeit coin and it is heavy.\n", uniq);
                                }
                            }
                        }
                    }
                    else{
                        for(j=0;j<e;j++){
                            for(k=0;k<12;k++){
                                if(ch[4][j]==C[k]&&num[k]==1){
                                    right2[k]=1;
                                }
                            }
                        }
                        for(j=0;j<f;j++){
                            for(k=0;k<12;k++){
                                if(ch[5][j]==C[k]&&num[k]==3){
                                    right2[k]=1;
                                }
                            }
                        }
                        for(l=0;l<12;l++){
                            if(right1[l]&&right2[l]){
                                uniq=C[l];
                                if(num[l]==1) {
                                    printf("%c is the counterfeit coin and it is light.\n", uniq);
                                }
                                else{
                                    printf("%c is the counterfeit coin and it is heavy.\n", uniq);
                                }
                            }
                        }
                    }
                }
                else{
                    for(j=0;j<c;j++){
                        for(k=0;k<12;k++){
                            if(ch[2][j]==C[k]&&num[k]==1){
                                right1[k]=1;
                            }
                        }
                    }
                    for(j=0;j<d;j++){
                        for(k=0;k<12;k++){
                            if(ch[3][j]==C[k]&&num[k]==3){
                                right1[k]=1;
                            }
                        }
                    }
                    if(strcmp(result[2],re2)==0){
                        for(j=0;j<e;j++){
                            for(k=0;k<12;k++){
                                if(ch[4][j]==C[k]&&num[k]==3){
                                    right2[k]=1;
                                }
                            }
                        }
                        for(j=0;j<f;j++){
                            for(k=0;k<12;k++){
                                if(ch[5][j]==C[k]&&num[k]==1){
                                    right2[k]=1;
                                }
                            }
                        }
                        for(l=0;l<12;l++){
                            if(right1[l]&&right2[l]){
                                uniq=C[l];
                                if(num[l]==1) {
                                    printf("%c is the counterfeit coin and it is light.\n", uniq);
                                }
                                else{
                                    printf("%c is the counterfeit coin and it is heavy.\n", uniq);
                                }
                            }
                        }
                    }
                    else{
                        for(j=0;j<e;j++){
                            for(k=0;k<12;k++){
                                if(ch[4][j]==C[k]&&num[k]==1){
                                    right2[k]=1;
                                }
                            }
                        }
                        for(j=0;j<f;j++){
                            for(k=0;k<12;k++){
                                if(ch[5][j]==C[k]&&num[k]==3){
                                    right2[k]=1;
                                }
                            }
                        }
                        for(l=0;l<12;l++){
                            if(right1[l]&&right2[l]){
                                uniq=C[l];
                                if(num[l]==1) {
                                    printf("%c is the counterfeit coin and it is light.\n", uniq);
                                }
                                else{
                                    printf("%c is the counterfeit coin and it is heavy.\n", uniq);
                                }
                            }
                        }
                    }
                }
            }
        }
        else{
            if(x==1){
                if(strcmp(result[1],re2)==0){
                    for(j=0;j<c;j++){
                        for(k=0;k<12;k++){
                            if(ch[2][j]==C[k]&&num[k]!=2){
                                num[k]=3;
                            }
                        }
                    }
                    for(j=0;j<d;j++){
                        for(k=0;k<12;k++){
                            if(ch[3][j]==C[k]&&num[k]!=2){
                                num[k]=1;
                            }
                        }
                    }
                    if(strcmp(result[2],re2)==0){
                        for(j=0;j<e;j++){
                            for(k=0;k<12;k++){
                                if(ch[4][j]==C[k]&&num[k]==3){
                                    uniq=C[k];
                                    printf("%c is the counterfeit coin and it is heavy.\n",uniq);
                                    // return 0;
                                }
                            }
                        }
                        for(j=0;j<f;j++){
                            for(k=0;k<12;k++){
                                if(ch[5][j]==C[k]&&num[k]==1){
                                    uniq=C[k];
                                    printf("%c is the counterfeit coin and it is light.\n",uniq);
                                    // return 0;
                                }
                            }
                        }
                    }
                    else{
                        for(j=0;j<e;j++){
                            for(k=0;k<12;k++){
                                if(ch[4][j]==C[k]&&num[k]==1){
                                    uniq=C[k];
                                    printf("%c is the counterfeit coin and it is light.\n",uniq);
                                    // return 0;
                                }
                            }
                        }
                        for(j=0;j<f;j++){
                            for(k=0;k<12;k++){
                                if(ch[5][j]==C[k]&&num[k]==3){
                                    uniq=C[k];
                                    printf("%c is the counterfeit coin and it is heavy.\n",uniq);
                                    // return 0;
                                }
                            }
                        }
                    }
                }
                else{
                    for(j=0;j<c;j++){
                        for(k=0;k<12;k++){
                            if(ch[2][j]==C[k]&&num[k]!=2){
                                num[k]=1;
                            }
                        }
                    }
                    for(j=0;j<d;j++){
                        for(k=0;k<12;k++){
                            if(ch[3][j]==C[k]&&num[k]!=2){
                                num[k]=3;
                            }
                        }
                    }
                    if(strcmp(result[2],re2)==0){
                        for(j=0;j<e;j++){
                            for(k=0;k<12;k++){
                                if(ch[4][j]==C[k]&&num[k]==3){
                                    uniq=C[k];
                                    printf("%c is the counterfeit coin and it is heavy.\n",uniq);
                                    //   return 0;
                                }
                            }
                        }
                        for(j=0;j<f;j++){
                            for(k=0;k<12;k++){
                                if(ch[5][j]==C[k]&&num[k]==1){
                                    uniq=C[k];
                                    printf("%c is the counterfeit coin and it is light.\n",uniq);
                                    //return 0;
                                }
                            }
                        }
                    }
                    else{
                        for(j=0;j<e;j++){
                            for(k=0;k<12;k++){
                                if(ch[4][j]==C[k]&&num[k]==1){
                                    uniq=C[k];
                                    printf("%c is the counterfeit coin and it is light.\n",uniq);
                                    // return 0;
                                }
                            }
                        }
                        for(j=0;j<f;j++){
                            for(k=0;k<12;k++){
                                if(ch[5][j]==C[k]&&num[k]==3){
                                    uniq=C[k];
                                    printf("%c is the counterfeit coin and it is heavy.\n",uniq);
                                    //  return 0;
                                }
                            }
                        }
                    }
                }
            }
            if(y==1){
                if(strcmp(result[0],re2)==0){
                    for(j=0;j<a;j++){
                        for(k=0;k<12;k++){
                            if(ch[0][j]==C[k]&&num[k]!=2){
                                num[k]=3;
                            }
                        }
                    }
                    for(j=0;j<b;j++){
                        for(k=0;k<12;k++){
                            if(ch[1][j]==C[k]&&num[k]!=2){
                                num[k]=1;
                            }
                        }
                    }
                    if(strcmp(result[2],re2)==0){
                        for(j=0;j<e;j++){
                            for(k=0;k<12;k++){
                                if(ch[4][j]==C[k]&&num[k]==3){
                                    uniq=C[k];
                                    printf("%c is the counterfeit coin and it is heavy.\n",uniq);
                                    //   return 0;
                                }
                            }
                        }
                        for(j=0;j<f;j++){
                            for(k=0;k<12;k++){
                                if(ch[5][j]==C[k]&&num[k]==1){
                                    uniq=C[k];
                                    printf("%c is the counterfeit coin and it is light.\n",uniq);
                                    //    return 0;
                                }
                            }
                        }
                    }
                    else{
                        for(j=0;j<e;j++){
                            for(k=0;k<12;k++){
                                if(ch[4][j]==C[k]&&num[k]==1){
                                    uniq=C[k];
                                    printf("%c is the counterfeit coin and it is light.\n",uniq);
                                    //   return 0;
                                }
                            }
                        }
                        for(j=0;j<f;j++){
                            for(k=0;k<12;k++){
                                if(ch[5][j]==C[k]&&num[k]==3){
                                    uniq=C[k];
                                    printf("%c is the counterfeit coin and it is heavy.\n",uniq);
                                    //   return 0;
                                }
                            }
                        }
                    }
                }
                else{
                    for(j=0;j<a;j++){
                        for(k=0;k<12;k++){
                            if(ch[0][j]==C[k]&&num[k]!=2){
                                num[k]=1;
                            }
                        }
                    }
                    for(j=0;j<b;j++){
                        for(k=0;k<12;k++){
                            if(ch[1][j]==C[k]&&num[k]!=2){
                                num[k]=3;
                            }
                        }
                    }
                    if(strcmp(result[2],re2)==0){
                        for(j=0;j<e;j++){
                            for(k=0;k<12;k++){
                                if(ch[4][j]==C[k]&&num[k]==3){
                                    uniq=C[k];
                                    printf("%c is the counterfeit coin and it is heavy.\n",uniq);
                                    // return 0;
                                }
                            }
                        }
                        for(j=0;j<f;j++){
                            for(k=0;k<12;k++){
                                if(ch[5][j]==C[k]&&num[k]==1){
                                    uniq=C[k];
                                    printf("%c is the counterfeit coin and it is light.\n",uniq);
                                    //  return 0;
                                }
                            }
                        }
                    }
                    else{
                        for(j=0;j<e;j++){
                            for(k=0;k<12;k++){
                                if(ch[4][j]==C[k]&&num[k]==1){
                                    uniq=C[k];
                                    printf("%c is the counterfeit coin and it is light.\n",uniq);
                                    //  return 0;
                                }
                            }
                        }
                        for(j=0;j<f;j++){
                            for(k=0;k<12;k++){
                                if(ch[5][j]==C[k]&&num[k]==3){
                                    uniq=C[k];
                                    printf("%c is the counterfeit coin and it is heavy.\n",uniq);
                                    //  return 0;
                                }
                            }
                        }
                    }
                }
            }
            if(z==1){
                if(strcmp(result[1],re2)==0){
                    for(j=0;j<c;j++){
                        for(k=0;k<12;k++){
                            if(ch[2][j]==C[k]&&num[k]!=2){
                                num[k]=3;
                            }
                        }
                    }
                    for(j=0;j<d;j++){
                        for(k=0;k<12;k++){
                            if(ch[3][j]==C[k]&&num[k]!=2){
                                num[k]=1;
                            }
                        }
                    }
                    if(strcmp(result[0],re2)==0){
                        for(j=0;j<a;j++){
                            for(k=0;k<12;k++){
                                if(ch[0][j]==C[k]&&num[k]==3){
                                    uniq=C[k];
                                    printf("%c is the counterfeit coin and it is heavy.\n",uniq);
                                    //  return 0;
                                }
                            }
                        }
                        for(j=0;j<b;j++){
                            for(k=0;k<12;k++){
                                if(ch[1][j]==C[k]&&num[k]==1){
                                    uniq=C[k];
                                    printf("%c is the counterfeit coin and it is light.\n",uniq);
                                    //  return 0;
                                }
                            }
                        }
                    }
                    else{
                        for(j=0;j<a;j++){
                            for(k=0;k<12;k++){
                                if(ch[0][j]==C[k]&&num[k]==1){
                                    uniq=C[k];
                                    printf("%c is the counterfeit coin and it is light.\n",uniq);
                                    //  return 0;
                                }
                            }
                        }
                        for(j=0;j<b;j++){
                            for(k=0;k<12;k++){
                                if(ch[1][j]==C[k]&&num[k]==3){
                                    uniq=C[k];
                                    printf("%c is the counterfeit coin and it is heavy.\n",uniq);
                                    //  return 0;
                                }
                            }
                        }
                    }
                }
                else{
                    for(j=0;j<c;j++){
                        for(k=0;k<12;k++){
                            if(ch[2][j]==C[k]&&num[k]!=2){
                                num[k]=1;
                            }
                        }
                    }
                    for(j=0;j<d;j++){
                        for(k=0;k<12;k++){
                            if(ch[3][j]==C[k]&&num[k]!=2){
                                num[k]=3;
                            }
                        }
                    }
                    if(strcmp(result[0],re2)==0){
                        for(j=0;j<a;j++){
                            for(k=0;k<12;k++){
                                if(ch[0][j]==C[k]&&num[k]==3){
                                    uniq=C[k];
                                    printf("%c is the counterfeit coin and it is heavy.\n",uniq);
                                    //   return 0;
                                }
                            }
                        }
                        for(j=0;j<b;j++){
                            for(k=0;k<12;k++){
                                if(ch[1][j]==C[k]&&num[k]==1){
                                    uniq=C[k];
                                    printf("%c is the counterfeit coin and it is light.\n",uniq);
                                    //   return 0;
                                }
                            }
                        }
                    }
                    else{
                        for(j=0;j<a;j++){
                            for(k=0;k<12;k++){
                                if(ch[0][j]==C[k]&&num[k]==1){
                                    uniq=C[k];
                                    printf("%c is the counterfeit coin and it is light.\n",uniq);
                                    // return 0;
                                }
                            }
                        }
                        for(j=0;j<b;j++){
                            for(k=0;k<12;k++){
                                if(ch[1][j]==C[k]&&num[k]==3){
                                    uniq=C[k];
                                    printf("%c is the counterfeit coin and it is heavy.\n",uniq);
                                    // return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

/*简化版：
#include <stdio.h>
#include <string.h>
void restart(int *pt);
int main() {
    int n;
    scanf("%d", &n);
    char ch1[3][13], ch2[3][13];
    char result[3][5];
    int i, j, k, l, m;
    char result1[] = "even";
    char result2[] = "up";
    char result3[] = "down";
    char a[] = "ABCDEFGHIJKL";
    int num[12];
    int flag1, flag2;
    int num1[3], num2[3];
    for (i = 0; i < n; i++) {
        flag2 = 1;
        for (j = 0; j < 3; j++) {
            scanf("%s%s%s", ch1[j], ch2[j], result[j]);
        }
        for (j = 0; j < 12; j++) {
            restart(num);
            num[j] = 2;
            flag1 = 1;
            for (k = 0; k < 3;k++) {
                num1[k] = num2[k] = 0;
            }
//            for(k=0;k<3;k++) {
//                printf("%s %s %s\n", ch1[k], ch2[k], result[k]);
//            }
            for (k = 0; k < 3; k++) {
                for (l = 0; l < strlen(ch1[k]); l++) {
                    for (m = 0; m < 12; m++) {
                        if (a[m] == ch1[k][l]) {
                            num1[k] += num[m];
                            break;
                        }
                    }
                }
                for (l = 0; l < strlen(ch2[k]); l++) {
                    for (m = 0; m < 12; m++) {
                        if (a[m] == ch2[k][l]) {
                            num2[k] += num[m];
                            break;
                        }
                    }
                }
            }
            for (k = 0; k < 3; k++) {
                if (num1[k] == num2[k] && strcmp(result[k], result1) == 0) {
                    continue;
                } else if (num1[k] > num2[k] && strcmp(result[k], result2) == 0) {
                    continue;
                } else if (num1[k] < num2[k] && strcmp(result[k], result3) == 0) {
                    continue;
                } else {
                    flag1 = 0;
                }
            }
            if (flag1) {
                printf("%c is the counterfeit coin and it is heavy.\n", a[j]);
                flag2 = 0;
                break;
            }
        }
        if (flag2) {
            for (j = 0; j < 12; j++) {
                restart(num);
                num[j] = 0;
                flag1 = 1;
                for (k = 0; k < 3;k++) {
                    num1[k] = num2[k] = 0;
                }
                for (k = 0; k < 3; k++) {
                    for (l = 0; l < strlen(ch1[k]); l++) {
                        for (m = 0; m < 12; m++) {
                            if (a[m] == ch1[k][l]) {
                                num1[k] += num[m];
                                break;
                            }
                        }
                    }
                    for (l = 0; l < strlen(ch2[k]); l++) {
                        for (m = 0; m < 12; m++) {
                            if (a[m] == ch2[k][l]) {
                                num2[k] += num[m];
                                break;
                            }
                        }
                    }
                }
                for (k = 0; k < 3; k++) {
                    if (num1[k] == num2[k] && strcmp(result[k], result1) == 0) {
                        continue;
                    } else if (num1[k] > num2[k] && strcmp(result[k], result2) == 0) {
                        continue;
                    } else if (num1[k] < num2[k] && strcmp(result[k], result3) == 0) {
                        continue;
                    } else {
                        flag1 = 0;
                    }
                }
                if (flag1) {
                    printf("%c is the counterfeit coin and it is light.\n", a[j]);
                    break;
                }
            }
        }
    }
    return 0;
}
void restart(int *pt){
    int i;
    for(i=0;i<12;i++){
        pt[i]=1;
    }
}*/











