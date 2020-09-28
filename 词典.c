#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char key[30];
    char ele[30];
}Dicelement;
typedef Dicelement *PDicelement;
int hash(const char *key){
    int sum = 0;
    int i = 0;
    while(key[i] != '\0'){
        sum += (key[i] * 2333 + key[i-1] * 1777) % 1000001 + 23317;
        i++;
    }
    return sum % 1000001;
}
void locate(PDicelement *location, PDicelement temp){
    int i = hash(temp->key);
    while(location[i] != NULL){
        i = (i + 1) % 1000001;
    }
    location[i] = temp;
}
int main(){
    PDicelement location[1000001];
    int i, j;
    for(i = 0; i < 1000001; i++){
        location[i] = NULL;
    }
    i = j = 0;
    PDicelement temp;
    temp = (PDicelement)malloc(sizeof(Dicelement));
    char c;
    int flag2 = 1;
    int flag1 = 1;
    scanf("%c", &c);
    while(c != '\n' || flag1){
        flag1 = 1;
        if(c == ' '){
            flag2 = 0;
            temp->ele[i] = '\0';
        }
        else if(c == '\n'){
            flag1 = 0;
            temp->key[j] = '\0';
            i = j = 0;
            flag2 = 1;
            locate(location, temp);
            temp = (PDicelement)malloc(sizeof(Dicelement));
        }
        else{
            if(flag2){
                temp->ele[i] = c;
                i++;
            }
            else{
                temp->key[j] = c;
                j++;
            }
        }
        scanf("%c", &c);
    }
    char word[30];
    while(gets(word) != NULL) {
        i = hash(word);
        if (location[i] == NULL) {
            printf("eh\n");
        } else {
            while (location[i] != NULL) {
                if (strcmp(location[i]->key, word) == 0) {
                    printf("%s\n", location[i]->ele);
                    break;
                } else {
                    i = (i + 1) % 1000001;
                }
            }
            if(location[i] == NULL){
                printf("eh\n");
            }
        }
    }
    return 0;
}
