#include <stdio.h>
#include <stdlib.h>
struct Monkey{
    int number;
    struct Monkey *pt;
};
typedef struct Monkey *M;
M Create(int n);
M delete(M start, int n, int number);
int main(void){
    int n, m;
    while(1) {
        scanf("%d%d", &n, &m);
        if (n == 0 || m == 0) {
            return 0;
        }//0 0直接退出
        M start, p, q;
        start = Create(n);//创建环形链表
        int number;
        int i;
        while(n > 1) {
            p = start;
            for (i = 1; i <= m; i++) {
                q = p->pt;
                if (i != m) {
                    p = q;
                }
            }//找到退出的猴子的编号
            number = p->number;
            start = delete(start, n, number);//从链表中删掉退出的猴子，并把下一个猴子设为start
            if (start) {
                n--;
            }
        }//多余一个猴子的时候继续循环
        printf("%d\n", start->number);
    }
    return 0;
}
M Create(int n){
    M p, q, start;
    start = NULL;
    int i;
    for(i=1; i<=n; i++){
        p = (M)malloc(sizeof(struct Monkey));
        if(i==1){
            start = p;
            start->number = i;
            q = p;
        }
        else{
            q->pt = p;
            q = p;
            q->number = i;
            if (i == n){
                q->pt = start;//设置环形链表
            }
        }
    }
    return start;
}
M delete(M start, int n, int number){
    M temp1, p, q;
    p = start;
    while(p->number != number){
        temp1 = p->pt;
        q = p;
        p = temp1;
    }
    if (p == start) {//如果要删除的是第一个
        q = p->pt;
        while (q->pt != start) {
            q = q->pt;
        }//找到指向start的链表（即链表的最后一个）
    }
    q->pt = p->pt;//删除p
    start = q->pt;//重制start
    return start;
}
