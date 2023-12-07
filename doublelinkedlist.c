
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} node;

node* addToEmpty(node *head, int data);
node* node_add(node *head, int data);
node* removeNode(node *head, int data);

node* insertion_specified(node *head,int loc,int data){
    int i;
    node* temp;
    node* ptr;
    ptr = (node *) malloc(sizeof(node));
    
    if( head == NULL){
        printf("OVERFLOW");
    }
    else{
        temp = head;
    }
    for(i < 0 ; i <= loc; i++){
        if(temp == NULL){
            printf("\n Invalid location\n");
        }
        temp = temp->next;
    }
    ptr->data = data;
    ptr->next = temp->next;
    ptr->prev = temp; //yeni düğümün önceki düğümü (ptr->prev) belirlenir
    if(temp->next != NULL){
        temp->next->prev= ptr; //eğer listenin sonuna değilse, bir sonraki düğümün önceki düğümü ptr olarak ayarlanır, 
    }
    temp->next = ptr; //  yeni düğüm listeye eklenir.

}
int main() {
    node *head = addToEmpty(NULL, 5);
    head = node_add(head, 6);
    head = node_add(head, 7);
    head = node_add(head, 8);
    head = node_add(head, 9);
    head = insertion_specified(head,2,10);
    
    node* ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    // Example of removing a node with data 7
    head = removeNode(head, 7);

    // Display the updated list
    printf("\nUpdated List: ");
    ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}

node* addToEmpty(node *head, int data) {
    node *temp = malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    head = temp;
    return head;
}

node* node_add(node *head, int data) {
    node *temp = malloc(sizeof(node));
    temp->next = head;
    temp->prev = NULL;
    temp->data = data;

    // Update the previous pointer of the existing head
    if (head != NULL) {
        head->prev = temp;
    }
    head = temp;
    return head;
}

node* removeNode(node *head, int data) {
    node *current = head;

    // Find the node with the specified data
    while (current != NULL && current->data != data) {
        current = current->next;
    }

    // If the node is not found, do nothing
    if (current == NULL) {
        printf("Node with data %d not found\n", data);
        return head;
    }

    // Adjust the pointers to remove the node
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    // If the node to be removed is the head, update the head
    if (current == head) {
        head = current->next;
    }

    // Free the memory of the removed node
    free(current);

    return head;
}
