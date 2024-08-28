#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
    int data;               
    struct TreeNode* left;  
    struct TreeNode* right; 
} TreeNode;


TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode)); 
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1); // Exit if memory allocation fails
    }
    newNode->data = value; 
    newNode->left = NULL; 
    newNode->right = NULL; 
    return newNode;
}


void printTree(TreeNode* root) {
    if (root != NULL) {
        printTree(root->left); 
        printf("%d ", root->data); 
        printTree(root->right); 
    }
}


void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left); 
        freeTree(root->right); 
        free(root);             
    }
}

int main() {
    // Create nodes
    TreeNode* root = createNode(1);        
    root->left = createNode(2);              
    root->right = createNode(3);             
    root->left->left = createNode(4);        
    root->left->right = createNode(5);      

    // Print the binary tree nodes
    printf("In-order traversal of the binary tree:\n");
    printTree(root);
    printf("\n");

  
    freeTree(root);

    return 0;
}
