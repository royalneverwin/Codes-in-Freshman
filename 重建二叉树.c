#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct BinTreeNode;
typedef struct BinTreeNode *PBinTreeNode;
struct BinTreeNode{
    char info;
    PBinTreeNode lchild;
    PBinTreeNode rchild;
};
typedef struct BinTreeNode *BinTree;
typedef BinTree *PBinTree;
void Select(PBinTreeNode tree, char *first, char *mid){
    char root;
    root = first[0];
    int i = 0, j = 0, k = 1, l = 0;
    char new_first1[100], new_first2[100], new_mid1[100], new_mid2[100];
    tree->info = root;
    if(strlen(first) == 1 && strlen(mid) == 1){
        tree->lchild = NULL;
        tree->rchild = NULL;
        return;
    }
    else {
        while (mid[i] != root) {
            new_mid1[i] = mid[i];
            i++;
        }
        new_mid1[i] = '\0';
        i++;
        while (mid[i] != '\0') {
            new_mid2[j] = mid[i];
            i++;
            j++;
        }
        new_mid2[j] = '\0';
        for (i = 0; i < strlen(new_mid1); i++) {
            new_first1[k - 1] = first[k];
            k++;
        }
        new_first1[k - 1] = '\0';
        while (k < strlen(first)) {
            new_first2[l] = first[k];
            l++;
            k++;
        }
        new_first2[l] = '\0';
        if(strlen(new_first1) == 0){
            tree->lchild = NULL;
            PBinTreeNode rchild;
            rchild = (PBinTreeNode) malloc(sizeof(struct BinTreeNode));
            tree->rchild = rchild;
            Select(rchild, new_first2, new_mid2);
        }
        else if(strlen(new_first2) == 0){
            tree->rchild = NULL;
            PBinTreeNode lchild;
            lchild = (PBinTreeNode) malloc(sizeof(struct BinTreeNode));
            tree->lchild = lchild;
            Select(lchild, new_first1, new_mid1);
        }
        else {
            PBinTreeNode lchild, rchild;
            lchild = (PBinTreeNode) malloc(sizeof(struct BinTreeNode));
            rchild = (PBinTreeNode) malloc(sizeof(struct BinTreeNode));
            tree->lchild = lchild;
            tree->rchild = rchild;
            Select(lchild, new_first1, new_mid1);
            Select(rchild, new_first2, new_mid2);
        }
    }
}
void show(PBinTreeNode tree){
    if(tree->lchild != NULL){
        show(tree->lchild);
    }
    if(tree->rchild != NULL){
        show(tree->rchild);
    }
    printf("%c", tree->info);
}
int main(){
    BinTree t;
    t = (BinTree)malloc(sizeof(struct BinTreeNode));
    char first[100], mid[100];
    char c;
    int i = 0, j = 0;
    int flag = 1;
    while(scanf("%c", &c) != EOF){
        if(c != ' ' && c != '\n' && flag){
            first[i] = c;
            i++;
        }
        else if(c != ' ' && c != '\n' && !flag){
            mid[j] = c;
            j++;
        }
        if(c == ' '){
            flag = 0;
        }
        if(c == '\n'){
            first[i] = '\0';
            mid[j] = '\0';
//            for(i = 0; i < strlen(first); i++){
//                printf("%c", first[i]);
//            }
//            putchar('\n');
//            for(i = 0; i < strlen(mid); i++){
//                printf("%c", mid[i]);
//            }
//            putchar('\n');
            i = j = 0;
            flag = 1;
            Select(t, first, mid);
            show(t);
            putchar('\n');
        }
    }
}
