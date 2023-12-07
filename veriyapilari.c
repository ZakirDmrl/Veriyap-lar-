#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node * head;

void insertion_last(){
    struct node *ptr,*temp;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("Memory allocation failed\n");
        return ;
    }
    else{
        printf("\nEnter the element to be inserted : ");
        scanf("%d",&item);
        printf("%d\n",item);
        ptr->data = item;
    
        if(head == NULL){
            ptr->prev = NULL;
            ptr->next = NULL;
            head = ptr;
        }
        else {
            temp = head;
            while(temp->next != NULL){
                temp=temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
        }
    }
    printf("Node inserted\n\n");
}

void display(){
    struct node *ptr;
    ptr = head;
    if(head == NULL){
        printf("List is empty!!!\n");
        return;
    }
    else{
        printf("Nodes of doubly linked list are:\n");
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}
    
void insertion_specified(){
    struct node *ptr1,*temp;
    int pos,item;
    ptr1=(struct node *)malloc(sizeof(struct node));
   
    if((ptr1==NULL)){
        printf("Memory allocation failure \n");
        return;
    }
    else{
        printf("\nEnter position where you want to insert a new node: ");
        scanf("%d",&pos);
        printf("%d\n",pos);
        temp = head;
        for(int i=1 ; i<pos ;i++){
            if(temp == NULL){
                printf("Position does not exist.\n");
                break;
            }
            temp = temp -> next;
        }
        printf("Enter value : ");
        scanf("%d",&item);
        printf("%d\n",item);
        ptr1->data = item;
        ptr1->next = temp->next;
        ptr1->prev = temp;
        
        if (temp->next != NULL){
            temp->next->prev = ptr1;
        }
        temp->next = ptr1;
    
    }
    printf("node inserted\n\n"); 
}
int main ()  

{  

    insertion_last();

    insertion_last(); 

    insertion_last(); 

    display(); 

    insertion_specified();

    display();

    return 0;

}