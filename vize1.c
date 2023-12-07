#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct Node Node;
struct Node{
	int data;
	Node *link;
};
Node *head = NULL;

int isEmpty();
int listLen();
void printList();
void toBeg(int data);
void toPos(int data);
void toEnd(int data);

int isEmpty(){
    if(head == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int listLen(){
    if(isEmpty()){
        printf("Liste bos hata degeri \n");
		return INT_MIN;
    }
    else{
        Node* tempHead = head;
        int counter = 0;
        do{
            counter++;
            tempHead = tempHead->link;
        }while(tempHead != head);
        return counter;
    }
}
void toBeg(int data){
    Node* newNode = malloc(sizeof(Node));
    newNode -> link = NULL;
	if(isEmpty())
	{
		head = newNode;
		head -> link = head;
	}
    else
	{
		Node *tempHead = head;
		
		while(tempHead -> link != head)
		{
			tempHead = tempHead -> link;
		}

        newNode->data = data;
        newNode->link =head;
        head = newNode;
    }
}
void  toPos(int data){
    int pos;
    do{
        printf("Veriyi eklemek istediğiniz pozisyonu giriniz: ");
        scanf("%d",&pos);
    }while(pos < 0 && pos > listLen());
    if(isEmpty() || pos == 1){
        toBeg(pos);
    }
    else{
        Node *tempHead = head;
        Node* newNode = malloc(sizeof(Node));
        newNode->data = data;
        newNode ->link = NULL;
        while(pos != 1){
            pos--;
            tempHead = tempHead -> link;
        }
        newNode->link = tempHead->link;
        tempHead->link = newNode;
        printf("Eleman eklendi \n");
    }
}
void printfList(){
    if(isEmpty()){
        printf("Lsite bos");
    }
    else{
        Node* tempHead = head;
        while(tempHead->link != NULL){
            printf("%d",tempHead->data);
        }
    }
}
int main(){
    toBeg(10);
    toBeg(11);
    toBeg(12);
    printfList();
    // toPos(15);
    // printfList();
}