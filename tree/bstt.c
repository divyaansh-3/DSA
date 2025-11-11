#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createnode(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node *root, int value) {
    if (root == NULL)
        return createnode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

void inorder(struct node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf(" %d ", root->data);
    inorder(root->right);
}

void preorder(struct node* root) {
    if (root == NULL) return;
    printf(" %d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf(" %d ", root->data);
}

struct node* search(struct node *root, int key) {
    if (root == NULL)
        return NULL;
    else if (root->data == key)
        return root;
    else if (root->data < key)
        return search(root->right, key);
    else
        return search(root->left, key);
}

struct node* findMin(struct node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct node* deleteNode(struct node* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct node *root = NULL, *p;
    int n, value, key, choice;
    printf("\nEnter the number of nodes to insert: ");
    scanf("%d", &n);
    printf("Enter the values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    while (1) {
        printf("\n\n--- MENU ---\n");
        printf("1. Inorder Traversal\n");
        printf("2. Preorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Search Element\n");
        printf("5. Insert Element\n");
        printf("6. Delete Element\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Inorder Traversal: ");
                inorder(root);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorder(root);
                break;
            case 3:
                printf("Postorder Traversal: ");
                postorder(root);
                break;
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &key);
                p = search(root, key);
                if (p)
                    printf("%d found in tree", key);
                else
                    printf("%d not found", key);
                break;
            case 5:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d inserted successfully.", value);
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("%d deleted (if present).", key);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!");
        }
    }
    return 0;
}
