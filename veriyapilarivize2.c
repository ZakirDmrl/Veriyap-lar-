//Double Linked List 

#include <stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}node;

node* olustur(int data){
    node* new_node =malloc(sizeof(node)); 
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void basaekle(node** head, int data){
    node* new_node = malloc(sizeof(node));
    (*head)->prev= new_node;
    new_node->data=data;
    new_node->next = *head;
    new_node->prev = NULL;
    *head = new_node;

}

void sonaekle(node* head,int data){
    node* new_node = malloc(sizeof(node));
    new_node->data =data;
    node* temp = head;
    while (temp->next !=NULL) {
        temp=temp->next;
    }
    new_node->prev = temp;
    new_node->next = temp->next;
    temp->next = new_node;

}
void ortayaeklehgfnhgh(node* head,int data,int loc){
    node* new_node = malloc(sizeof(node));
    node* temp = head;
    for(int i=1 ;i<loc;i++){
        if(temp!=NULL){
            printf("Overflow");
            sonaekle(head,data);
        }
        temp = temp->next;
    }
    
    new_node->data = data;
    new_node->prev = temp;
    new_node->next = temp->next;
    temp->next->prev = new_node;
    temp->next = new_node; 
}
void ortayaekle(node* head,int data,int loc){
    node* new_node = malloc(sizeof(node));
    node* temp = head;
    // if(loc == 0 ){
    //     basaekle(&head,data);
    //     return;
    // }
    for(int i=1 ;i<loc;i++){
        if(temp!=NULL){
            printf("Overflow\n");
            // free(new_node);
            // free(temp);
            sonaekle(head,data);
            return;
        }
        temp = temp->next;
    }
    
    new_node->data = data;
    new_node->prev = temp;
    new_node->next = temp->next;
    temp->next->prev = new_node;
    temp->next = new_node; 

    // free(temp);
    // free(new_node);
}
void yazdir(node* head){
    while (head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
    
}
int sil(node **head,int loc){
    node* temp = (*head);
    int result;
    if(loc == 0){
        result = temp->data;
        (*head) = temp->next;
        temp->prev = NULL;
        return result;
    }
    for(int i = 1;i<loc;i++){
        temp = temp->next;
    }
    result = temp->next->data;
    temp->next= temp->next->next;
    temp->next->next->prev = temp;
    return result;
}

void sondanBasaYazdir(node* head){
    while(head->next != NULL){
    head = head->next;
    }
    while(head->prev != NULL){
        printf("%d ",head->data);
        head = head->prev;
    }
    printf("%d\n ",head->data);

}

int main(){
node* head = olustur(1);
basaekle(&head,4);
// basaekle(&head,7);
// basaekle(&head,98);
// sonaekle(head,67);
// sonaekle(head,34);
// sonaekle(head,56);
// basaekle(&head,7);
// ortayaekle(head,4,1);
// basaekle(&head,2);
// ortayaekle(head,3,8);
// sonaekle(head,4);
// ortayaekle(head,31,20);
// ortayaekle(head,6,3);
// printf("%d",head->data);
// yazdir(head);
// sil(&head,1);
yazdir(head);
sondanBasaYazdir(head);

    return 0;
}