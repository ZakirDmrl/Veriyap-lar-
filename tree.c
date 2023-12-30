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
int treeNodeCount(struct TreeNode* root);
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
struct TreeNode* min(struct TreeNode*root){
    struct TreeNode *temp1,*temp2;
    
    if(root->left == NULL && root->right == NULL){
        return root;
    }
    if (root->left != NULL && root->right == NULL){
        temp1 = min(root->left);   
        return ((root->data < temp1->data) ?root:temp1);
        
    }
    if(root->right != NULL && root->left == NULL){
        temp2 =  min(root->right);   
        return ((root->data < temp2->data) ?root:temp2);
        

    }

    else{
        temp1 = min(root->left);   
   
        temp2 =  min(root->right);   
        
        struct TreeNode *temp3 = (temp1->data>temp2->data)? temp2:temp1;
        return ((root->data < temp3->data) ?root:temp3);
    }
}
// int max(struct TreeNode*root) {
// }
int treeNodeCount(struct TreeNode* root){
    if(root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    
        int l = treeNodeCount(root->left);
        int r =  treeNodeCount(root->right);
        
    return l+r+1;


}
int main() {
    struct TreeNode* root = createNode(3);
    root->left = createNode(2);
    root->right = createNode(5);
    root->left->left = createNode(6);
    root->left->right = createNode(7);
    root->right->left = createNode(4);
    root->left->right = createNode(1);
    root->right->left->left = createNode(0);

 struct TreeNode *minTree = min(root);
 printf("en kucuk = %d\n",minTree->data);
    // printf("In-order traversal: ");
    // inOrderTraversal(root);
    // printf("\n");

    // printf("Pre-order traversal: ");
    // preOrderTraversal(root);
    // printf("\n");

    // printf("Post-order traversal: ");
    // postOrderTraversal(root);
    // printf("\n");

    return 0;
}