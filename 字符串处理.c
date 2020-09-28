#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 10000
struct SeqStack{     //字符栈
    char s[MAX];
    int t;
};
struct SeqStack1{   //数字栈
    int s[MAX];
    int t;
};
typedef struct SeqStack * PSeqStack;
typedef struct SeqStack1 * PSeqStack1;
int flag = 0;    //判断是否加空格
int flag1 = 0;   //判断是否是单个数字输入
PSeqStack createNullStack(void){
    PSeqStack plstack;
    plstack = (PSeqStack)malloc(sizeof(struct SeqStack));
    if(plstack){
        plstack->t = -1;
        return plstack;
    }
    else{
        return NULL;
    }
}
PSeqStack1 createNullStack1(void){
    PSeqStack1 plstack1;
    plstack1 = (PSeqStack1)malloc(sizeof(struct SeqStack1));
    if(plstack1){
        plstack1->t = 0;
        plstack1->s[plstack1->t] = 0;
        return plstack1;
    }
    else{
        return NULL;
    }
}
int push(PSeqStack plstack, char info){
    plstack->t++;
    if(plstack->t < MAX) {
        plstack->s[plstack->t] = info;
        return 1;
    }
    else{
        return 0;
    }
}
int push1(PSeqStack1 plstack1, int info){
    plstack1->t++;
    if(plstack1->t < MAX) {
        plstack1->s[plstack1->t] = info;
        return 1;
    }
    else{
        return 0;
    }
}
void pop(PSeqStack plstack){
    if(plstack->t > -1) {
        plstack->t--;
    }
}
void pop1(PSeqStack1 plstack1){
    if(plstack1->t > -1) {
        plstack1->t--;
    }
}
char pop_ele(PSeqStack plstack){
    plstack->t--;
    return plstack->s[plstack->t+1];
}
int pop_ele1(PSeqStack1 plstack1){
    plstack1->t--;
    return plstack1->s[plstack1->t+1];
}
int operate(char input, char * postfix, int j, PSeqStack plstack){   //转化为后缀表达式时对操作符的处理
    if(plstack->t == -1){
        push(plstack, input);
        if(flag) {
            postfix[j] = ' ';
            j++;
            flag = 0;
        }
    }
    else{
        if(input == '(') {
            push(plstack, input);
            if(flag) {
                postfix[j] = ' ';
                j++;
                flag = 0;
            }
        }
        else if(input == ')'){
            char input1;
            if(flag) {
                postfix[j] = ' ';
                j++;
                flag = 0;
            }
            while(plstack->s[plstack->t] != '('){
                input1 = pop_ele(plstack);
                postfix[j] = input1;
                j++;
                postfix[j] = ' ';
                j++;
            }
            pop(plstack);
        }
        else if(input == '+' || input == '-'){
            char input1;
            if(flag) {
                postfix[j] = ' ';
                j++;
                flag = 0;
            }
            while(plstack->s[plstack->t] != '(' && plstack->t != -1){
                input1 = pop_ele(plstack);
                postfix[j] = input1;
                j++;
                postfix[j] = ' ';
                j++;
            }
            push(plstack, input);
        }
        else if(input == '*' || input == '/'){
            char input1;
            if(flag) {
                postfix[j] = ' ';
                j++;
                flag = 0;
            }
            while(plstack->s[plstack->t] != '(' && plstack->t != -1 && plstack->s[plstack->t] != '+' && plstack->s[plstack->t] != '-'){
                input1 = pop_ele(plstack);
                postfix[j] = input1;
                j++;
                postfix[j] = ' ';
                j++;
            }
            push(plstack, input);
        }
        else if(input == '^'){
            push(plstack, input);
            if(flag) {
                postfix[j] = ' ';
                j++;
                flag = 0;
            }
        }
    }
    return j;
}
int main(){
    int N;
    scanf("%d", &N);
    getchar();
    int i;
    char input;
    char input1;
    char postfix[10000];
    int j;
    for(i = 0; i < N; i++){
        j = 0;
        PSeqStack plstack;
        plstack = createNullStack();
        while((input = getchar()) != EOF && input != '\n'){
            if(input >= '0' && input <= '9'){
                postfix[j] = input;
                flag = 1;
                j++;
            }
            else if(input == '-'){
                input1 = getchar();
                if(input1 == ' '){
                    j = operate(input, postfix, j, plstack);
                    flag1 = 1;
                }
                else{
                    postfix[j] = input;
                    j++;
                    postfix[j] = input1;
                    j++;
                    flag = 1;
                }
            }
            else if(input != ' '){
                flag1 = 1;
                j = operate(input, postfix, j, plstack);
            }
        }
        if(flag1 == 0){
            postfix[j] = '\0';
            printf("%d\n", atoi(postfix));
            continue;
        }
        flag1 = 0;
        while(plstack->t != -1){
            if(flag) {
                postfix[j] = ' ';
                j++;
                flag = 0;
            }
            input = pop_ele(plstack);
            postfix[j] = input;
            j++;
            postfix[j] = ' ';
            j++;
        }
        free(plstack);
        int k = 0, l = 0;
        int num, num1, num2;
        char input2[10000];
//        for(k = 0; k < j; k++){
//            printf("%c", postfix[k]);
//        }
//        putchar('\n');
        PSeqStack1 plstack1;
        plstack1 = createNullStack1();
        int text;
        k = 0;
        while(k < j){    //对后缀表达式进行运算
            if(postfix[k] >= '0' && postfix[k] <= '9'){
                input2[l] = postfix[k];
                l++;
                k++;
            }
            else if(postfix[k] == '-'){
                if(postfix[k+1] == ' '){
                    num2 = pop_ele1(plstack1);
                    num1 = pop_ele1(plstack1);
                    push1(plstack1, num1 - num2);
                    k++;
                }
                else{
                    input2[l] = postfix[k];
                    l++;
                    k++;
                }
            }
            else if(postfix[k] == ' '){
                if(l != 0) {
                    input2[l] = '\0';
                    num = atoi(input2);
                    push1(plstack1, num);
                    l = 0;
                }
                k++;
            }
            else{
                num2 = pop_ele1(plstack1);
                num1 = pop_ele1(plstack1);
                if(postfix[k] == '+'){
                    push1(plstack1, num1 + num2);
                }
                else if(postfix[k] == '*'){
                    push1(plstack1, num1 * num2);
                }
                else if(postfix[k] == '/'){
                    push1(plstack1, num1 / num2);
                }
                else if(postfix[k] == '^'){
                    push1(plstack1, (int)pow((double)num1, num2));
                }
                k++;
            }
        }
        printf("%d", pop_ele1(plstack1));
        if(i < N - 1){
            putchar('\n');
        }
        free(plstack1);
    }
    return 0;
}

