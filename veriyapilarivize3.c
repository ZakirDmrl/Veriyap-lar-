//Stacks
#include <stdio.h>
#include <stdlib.h>
#define SENTINEL -100000000  


struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

int ekle(int data,struct Node **stack_head){ // Stack formatında old. için sona ekleme yapacağız
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = (*stack_head);
    newNode->data = data;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = temp->next; // yani NULL
}
void cikar(struct Node **stack_head){ // Stack formatında old. için sondaki elemanı sileceğiz
    int result;
    struct Node *temp = (*stack_head);
    while(temp->next != NULL){
        temp = temp->next;
    }
    result = temp->data;
    temp->prev->next = NULL;  
    free(temp);
    return result;
}

int main() {

    int a;

    struct Node *yigin_gostergesi=NULL;

    ekle(100,&yigin_gostergesi);

    ekle(20,&yigin_gostergesi);

    ekle(60,&yigin_gostergesi);

    yazdir1(yigin_gostergesi);

    

    a=cikar(&yigin_gostergesi);

    if(a!=SENTINEL) printf("çıkarılan eleman : %d\n",a);

    printf("yığının son hali : \n");

    recursive_yazdir(yigin_gostergesi);

    int x=yigin_bosmu(yigin_gostergesi);  //  fonk., yığın boş ise 1 değil ise 0 döndürecek

    printf("%d",x);  // yığın boş ise ekrana 1 değil ise 0 yazdırmalı

    return 0;

}