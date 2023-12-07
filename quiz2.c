
#include<stdio.h>  

#include<stdlib.h>  

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head;  

void insertion_last()  
{  
   struct node *ptr,*temp;  
   int item;  
   ptr = (struct node *) malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else{  
    printf("Enter value : ");  
    scanf("%d",&item);  
    printf("%d\n", item);
    ptr->data=item;  
    
    if(head == NULL){  
        ptr->next = NULL;  
        ptr->prev = NULL;  
        head = ptr;  
    }  
    else{  
     temp = head;  
     while(temp->next!=NULL){  
        temp = temp->next;  
     }  
     temp->next = ptr;  
     ptr ->prev=temp;  
     ptr->next = NULL;  
    }  
   }  
   printf("node inserted\n\n");  
}

void display()  
{  
    struct node *ptr;  
    printf(" printing values...\n");  
    ptr = head;  
    while(ptr != NULL)  
    {  
        printf("%d   ",ptr->data);  
        ptr=ptr->next;  
    }  
}

void insertion_specified() {
    struct node *ptr, *temp;
    int item, loc, i;
    ptr = (struct node *) malloc(sizeof(struct node));
    if(ptr == NULL) {
        printf("\nOVERFLOW");
    } else {
        printf("Enter the location : ");
        scanf("%d", &loc);
        printf("%d\n",loc);
        temp = head;
        for(i = 1; i < loc; i++) {
            if(temp == NULL) {
                printf("\nInvalid location\n");
                return;
            }
            temp = temp->next;
        }
        printf("Enter value : ");
        scanf("%d", &item);
        printf("%d\n",item);
        ptr->data = item;
        ptr->next = temp->next;
        ptr->prev = temp;
        if(temp->next != NULL) {
            temp->next->prev = ptr;
        }
        temp->next = ptr;
        
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