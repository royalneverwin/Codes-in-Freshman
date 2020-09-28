#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Mi;
typedef struct Mi * PMi;
struct Mi{
    int x;
    int y;
    PMi next;
};
typedef struct Mi * Plink;
Plink Insert(Plink start, int x, int y);
void Show(Plink start);
Plink Add(Plink start1, Plink start2);
Plink Mul(Plink start1, Plink start2);
int main(void){
    Plink start1, start2,start3,start4;
    int x,y;
    x=1;
    y=1;
    start1 = NULL;
    start2 = NULL;
    start3 = NULL;
    start4 = NULL;
    while(x != 0 || y != 0){
        scanf("%d%d", &x, &y);
        start1 = Insert(start1, x, y);
    }
    x=1;
    y=1;
    while(x != 0 || y != 0){
        scanf("%d%d",&x, &y);
        start2 = Insert(start2, x, y);
    }

    start3 = Add(start1, start2);
    start4 = Mul(start1, start2);
    Show(start3);
    putchar('\n');
    Show(start4);
    return 0;
}
Plink Insert(Plink start, int x, int y){
    Plink p, q=NULL, temp=NULL;
    p = (Plink)malloc(sizeof(struct Mi));
    p->x = x;
    p->y = y;
    if (start == NULL){
        start = p;
        p->next = NULL;
    }
    else{
        q = start;
        if (start->y < y){
            p->next = start;
            start = p;
        }
        else {
            while (q->y > y && q->next != NULL) {
                temp = q;
                q = q->next;
            }
            if (q->y == y) {
                q->x += x;
                free(p);
            }
            else if(q->y > y && q->next == NULL){
                q->next = p;
                p->next = NULL;
            }
            else {
                temp->next = p;
                p->next = q;
            }
        }
    }
    return start;
}
void Show(Plink start){
    Plink p;
    p = start;
    while(p->x == 0 && p->next != NULL){
        p = p->next;
    }
    if(p->next == NULL){
    }
    else{
        if(p->y == 0){
            printf("%d", p->x);
        }
        else{
            if(p->x == -1){
                printf("-");
            }
            else{
                printf("%d", p->x);
            }
            printf("x");
            if(p->y != 1){
                printf("^%d", p->y);
            }
        }
    }
    while(p->next != NULL){
        p = p->next;
        if(p->x != 0) {
            if (p->y == 0) {
                if(p->x > 0){
                    printf("+%d", p->x);
                }
                else {
                    printf("%d", p->x);
                }
            } else {
                if (p->x == -1) {
                    printf("-");
                } else if (p->x < 0) {
                    printf("%d", p->x);
                } else {
                    printf("+%d", p->x);
                }
                printf("x");
                if (p->y != 1) {
                    printf("^%d", p->y);
                }
            }
        }
    }
}
Plink Add(Plink start1, Plink start2){
    Plink start, p;
    start = NULL;
    int x,y;
    p = start1;
    while(1) {
        x = p->x;
        y = p->y;
        start = Insert(start, x, y);
        if(p->next != NULL){
            p = p->next;
        }
        else{
            break;
        }
    }
    p = start2;
    while(1){
        x = p->x;
        y = p->y;
        start = Insert(start, x, y);
        if(p->next != NULL){
            p = p->next;
        }
        else{
            break;
        }
    }
    return start;
}
Plink Mul(Plink start1, Plink start2){
    Plink start, p, q;
    start = NULL;
    int x, y;
    p = start1;
    while(1){
        q = start2;
        while(1) {
            x = p->x * q->x;
            y = p->y + q->y;
            start = Insert(start, x, y);
            if (q->next != NULL) {
                q = q->next;
            } else {
                break;
            }
        }
        if(p->next != NULL){
            p = p->next;
        }
        else{
            break;
        }
    }
    return start;
}