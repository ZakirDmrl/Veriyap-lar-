#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct AvlAgac{
    int deger;
    int yukseklik;
    struct  AvlAgac *sol;
    struct AvlAgac *sag;
}Avl;

int height(Avl *p){
    if (p == NULL){
        return -1;
    }
    else{
        return p->yukseklik;
    }
}

Avl insert(Avl *p,int x){
    if (p == NULL){
        p = (Avl*)malloc(sizeof(Avl));
    }
    else{
        if (x <= p->deger) {
            p->sol=insert(&(p->sol),x);
            if(height(p->sol)-height(p->sag) == 2)
            if (x < p->left->data)
 p = singlerotateright(p);
 else p = doublerotateright(p);
 }

 else if (x > p.data)
 { p.right = insert(p.right, x);
 if (height(p.left) - height(p.right) == -2)
 if (x > p.right.data)
 p = singlerotateleft(p);
 else p = doublerotateleft(p);
 }
 p.height = max(height(p.left), height(p.right)) + 1;
 return p;
 }
 int max(int a, int b)
 { if (a > b) return a;
 else return b;
 }
}

    