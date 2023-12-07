#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

node* add_beg(node* head, int data);
node* removeNode(node* head, int data);  // Corrected function declaration

int main() {
    node* head = malloc(sizeof(node));
    head->data = 5;
    head->next = NULL;
    head = add_beg(head, 6);
    node* ptr = head;
    // head = removeNode(head, 5);
    while (ptr->next != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}

node* add_beg(node* head, int data) {
    node* temp = malloc(sizeof(node));
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}

node* removeNode(node* head, int data) {
    node* current = head;
    node* prev = NULL;

    // Find the node with the specified data
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    // If the node is not found, do nothing
    if (current == NULL) {
        printf("Node with data %d not found\n", data);
        return head;
    }

    // Adjust the pointers to remove the node
    if (prev != NULL) {
        prev->next = current->next;
    } else {
        // If the node to be removed is the head, update the head
        head = current->next;
    }

    // Free the memory of the removed node
    free(current);

    return head;
}
