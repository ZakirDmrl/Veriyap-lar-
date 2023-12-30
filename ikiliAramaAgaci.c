#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct agacdugum{
    struct agacdugum *soldal;
    struct agacdugum *sagdal;
    int data;
};

typedef struct agacdugum AGACDUGUM;
typedef struct agacdugum *AGACDUGUMPTR;

AGACDUGUMPTR dugumekle(AGACDUGUMPTR agacptr,int veri){
    if(agacptr == NULL){
        agacptr = (AGACDUGUMPTR) malloc(sizeof(struct agacdugum));
    }
    if(agacptr!=NULL){
        agacptr->data = veri;
        agacptr->soldal =NULL;
        agacptr->sagdal =NULL;
    }
    else printf("%d eklenemedi.Bellek yetersiz.\n",veri);
 if(veri<agacptr->data){ printf("Ağaçın soluna veri eklendi\n ");
 agacptr->soldal = dugumekle(agacptr->soldal,veri);}
 else
 if(veri>agacptr->data){printf("Ağaçın sağına veri eklendi\n ");
 agacptr->sagdal = dugumekle(agacptr->sagdal,veri);}
 // eğer girilen değer ler daha önce var ise alınmıyor.
 else printf("Eşit olduğu için alınmadı\n ");
 return agacptr;
}

/* Agacın inorder dolaşılması */
 void inorder(AGACDUGUMPTR agacptr) {
 if (agacptr != NULL) {
 inorder(agacptr->soldal);
 printf("%3d",agacptr->data);
 inorder(agacptr->sagdal); } }
 /* Ağacın preorder dolaşılması */
 void preorder(AGACDUGUMPTR agacptr) {
 if (agacptr != NULL) {
 printf("%3d",agacptr->data);
 preorder(agacptr->soldal);
 preorder(agacptr->sagdal); } }
 /* Ağacın postorder dolaşılması */
 void postorder(AGACDUGUMPTR agacptr) {
 if (agacptr != NULL) {
 postorder(agacptr->soldal);
 postorder(agacptr->sagdal);
 printf("%3d",agacptr->data); } 
 }

 void main() {
int i, dugum;
 AGACDUGUMPTR agacptr = NULL;
 for(i=0; i<12; ++i) { /* Ağaca yerleştirilecek sayılar */
 scanf("%d",&dugum); printf("\n"); 
 // girilen değeri düğüm ekleme fonksiyonuna gönderiyoruz.
 agacptr = dugumekle(agacptr, dugum); 
 } printf("\n");

 printf("Ağacın preorder dolaşılması :\n");
 preorder(agacptr); printf("\n");
 
 printf("Ağacın inorder dolaşılması :\n");
 inorder(agacptr); printf("\n");
 printf("Ağacın postorder dolaşılması :\n");
 postorder(agacptr); printf("\n");
 }