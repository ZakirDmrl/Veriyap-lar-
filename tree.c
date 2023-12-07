#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int data){
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void inOrderTraversal(struct TreeNode *root);
void preOrderTraversal(struct TreeNode *root);
void postOrderTraversal(struct TreeNode *root);
void inOrderTraversal(struct TreeNode *root){  // left-> root-> right
    if(root != NULL){
        inOrderTraversal(root->left);
        printf("%d ",root->data);
        inOrderTraversal(root->right);
        
    }
}
void preOrderTraversal(struct TreeNode *root){ // root->left->right
    if(root != NULL){
        printf("%d ",root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
void postOrderTraversal(struct TreeNode *root){ // left->right->root
    if(root != NULL){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}
int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(4);
    root->left->right = createNode(5);

    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}