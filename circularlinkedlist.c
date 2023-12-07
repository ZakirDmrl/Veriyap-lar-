// Singly Linked List
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};

struct node* addToEmpty(int data){
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next =temp;
    return temp;
}

struct node* addAtBeg(struct node* tail, int data){
    struct node* temp = malloc(sizeof(struct node));
    temp -> data = data;
    temp -> next = tail -> next;
    tail-> next = temp;
    return tail;
}
void print(struct node* tail){
    struct node* ptr = tail->next;
    do{
        printf("%d ",ptr->data);
        ptr = ptr->next;
        
    }while(ptr != tail->next);
    
}

int main(){
    struct node* tail;
    tail = addToEmpty(45);
    tail = addAtBeg(tail,34);
    tail = addAtBeg(tail,35);
    tail = addAtBeg(tail,36);
    print(tail);
}