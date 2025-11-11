#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;   // ✅ just reordered for clarity
};

// ✅ 1. Use NULL instead of 0 for pointers
void preorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf(" %d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf(" %d",root->data);
    inorder(root->right);

}

struct node *create() {
    int x;
    printf("\nEnter the value of node (-1 for no node): ");
    scanf(" %d", &x);  // space before %d clears input buffer

    if (x == -1)
        return NULL;   // stop recursion

    // allocate memory ONLY after confirming valid input
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;

    printf("\nEnter the value of the node to the left of %d", x);
    newnode->left = create();

    printf("\nEnter the value of the node to the right of %d", x);
    newnode->right = create();

    return newnode;
}


int main() {
    struct node *root = NULL;    // ✅ use NULL, not 0
    root = create();

    // ✅ 5. Add newline before traversal label for clarity
    printf("\nPreorder traversal is:\n");
    preorder(root);
    return 0;
}
