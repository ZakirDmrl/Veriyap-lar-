#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    int height; 
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->height = 1; 
    return newNode;
}

int getHeight(TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

void updateHeight(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    node->height = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int getBalanceFactor(TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

TreeNode* rotateRight(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

TreeNode* rotateLeft(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {

        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        TreeNode* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    updateHeight(root);

    int balance = getBalanceFactor(root);

    if (balance > 1) {
        if (getBalanceFactor(root->left) >= 0) {
            return rotateRight(root);
        } else {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }

    if (balance < -1) {
        if (getBalanceFactor(root->right) <= 0) {
            return rotateLeft(root);
        } else {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }

    return root;
}

TreeNode* insertNode(TreeNode* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->data) {
        root->left = insertNode(root->left, key);
    } else if (key > root->data) {
        root->right = insertNode(root->right, key);
    } else {
        return root;
    }

    updateHeight(root);

    int balance = getBalanceFactor(root);

    // Left Heavy
    if (balance > 1) {
        if (key < root->left->data) {
            // Left-Left (LL) Case
            return rotateRight(root);
        } else {
            // Left-Right (LR) Case
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }

    // Right Heavy
    if (balance < -1) {
        if (key > root->right->data) {
            // Right-Right (RR) Case
            return rotateLeft(root);
        } else {
            // Right-Left (RL) Case
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }

    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    TreeNode* root = NULL;

    root = insertNode(root, 9);
    root = insertNode(root, 5);
    root = insertNode(root, 10);
    root = insertNode(root, 0);
    root = insertNode(root, 6);
    root = insertNode(root, 11);
    root = insertNode(root, -1);
    root = insertNode(root, 1);
    root = insertNode(root, 2);

    printf("Inorder traversal of AVL tree: ");
    inorderTraversal(root);
    printf("\n");

    root = deleteNode(root, 10);

    printf("Inorder traversal of AVL tree after deletion: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
