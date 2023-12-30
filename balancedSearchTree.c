#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
int data;
struct tree * left;
struct tree * right;
int height;
}Tree;

int heightTree (Tree *p){
    if (p == NULL){
        return -1;
    }
    else{
        return  p->height;
    }
}
Tree* createTree(Tree *p,int x){
     if (p == NULL) {
        p = malloc(sizeof(Tree));
        p->data = x;
        p->left = NULL;
        p->right = NULL;
        p->height = 0;
    }
    else{
       if (x < p->data) {
            p->left = createTree(p->left, x);
        }
        else if (x > p->data) {
            p->right = createTree(p->right, x);
        }
    p->height = 1 + max((p->left) , heightTree(p->right));
    }
    return p;
}

int 