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
//Plink Create_Mi(void);
Plink Insert(Plink start, int x, int y);
void Show(Plink start);
int main(void){
    Plink start1, start2,start3,p;
    int n;
    int x,y;
    scanf("%d", &n);
    int i;
    for(i = 1; i <= n; i++) {
        x = 0;
        y = 0;
        start1 = NULL;
        start2 = NULL;
        start3 = NULL;
        while (y >= 0) {
//            printf("%d%d",x, y);
            scanf("%d%d", &x, &y);
//            printf("\n%d %d\n", x, y);
//            printf("%d", n);
//            printf("%d%d",x, y);
            start1 = Insert(start1, x, y);
//            Show(start1);
        }
        x = 0;
        y = 0;
        while (y >= 0) {
            scanf("%d%d", &x, &y);
//            printf("\n%d %d\n", x, y);
            start1 = Insert(start1, x, y);
//            Show(start1);
        }
        p = start1;
        while (p->x == 0 && p->y >= 0) {
            p = p->next;
        }
        if (p->y < 0) {
            continue;
        } else {
            printf("[ %d %d ]", p->x, p->y);
            p = p->next;
        }
        while (p->y >= 0) {
            if (p->x != 0) {
                printf(" [ %d %d ]", p->x, p->y);
            }
            p = p->next;

        }
        putchar('\n');
    }
    return 0;
}
//Plink Create_Mi(void){
//    Plink start, p ;
//    p = (Plink)malloc(sizeof(struct Mi));
//    if(p == NULL){
//        printf("Out of space!");
//        return NULL;
//    }
//    else{
//        start = p;
//        start->next = NULL;
//        return start;
//    }
//}
Plink Insert(Plink start, int x, int y){
    Plink p, q=NULL, temp=NULL;
    p = (Plink)malloc(sizeof(struct Mi));
    p->x = x;
    p->y = y;
//    printf("%d%d",x, y);
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
//                printf("\np:%d %d\n", p->x, p->y);
//                printf("\nq:%d %d\n", q->x, q->y);

            }
        }
    }
//    printf("\n%d %d\n", p->x, p->y);
    return start;
}
void Show(Plink start){
    Plink p;
    p = start;
    while(1){
        printf(" %d %d ", p->x, p->y);
        if(p->next != NULL) {
            p = p->next;
        }
        else{
            putchar('\n');
            return;
        }
    }
}