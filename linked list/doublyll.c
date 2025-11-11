#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head1 = NULL, *head2 = NULL;

struct Node* createList() {
    struct Node *head = NULL, *newNode, *temp;
    int n, data;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = newNode->prev = NULL;
        if(head == NULL)
            head = newNode;
        else {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    return head;
}

void display(struct Node *head) {
    struct Node *temp = head;
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* insertNode(struct Node *head) {
    int data, pos, i = 1;
    struct Node *newNode, *temp = head;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data to insert: ");
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    printf("Enter position to insert: ");
    scanf("%d", &pos);
    if(pos == 1) {
        newNode->next = head;
        if(head) head->prev = newNode;
        head = newNode;
    } else {
        while(i < pos - 1 && temp != NULL) {
            temp = temp->next;
            i++;
        }
        if(temp == NULL)
            printf("Invalid position!\n");
        else {
            newNode->next = temp->next;
            newNode->prev = temp;
            if(temp->next) temp->next->prev = newNode;
            temp->next = newNode;
        }
    }
    return head;
}

struct Node* deleteNode(struct Node *head) {
    struct Node *temp = head;
    int pos, i = 1;
    if(head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    if(pos == 1) {
        head = head->next;
        if(head) head->prev = NULL;
        free(temp);
    } else {
        while(i < pos && temp != NULL) {
            temp = temp->next;
            i++;
        }
        if(temp == NULL)
            printf("Invalid position!\n");
        else {
            if(temp->prev) temp->prev->next = temp->next;
            if(temp->next) temp->next->prev = temp->prev;
            free(temp);
        }
    }
    return head;
}

struct Node* reverseList(struct Node *head) {
    struct Node *temp = NULL, *current = head;
    while(current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if(temp != NULL)
        head = temp->prev;
    return head;
}

struct Node* concatenate(struct Node *head1, struct Node *head2) {
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    struct Node *temp = head1;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    head2->prev = temp;
    return head1;
}

int main() {
    int choice;
    while(1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create first list\n");
        printf("2. Create second list\n");
        printf("3. Display lists\n");
        printf("4. Insert node\n");
        printf("5. Delete node\n");
        printf("6. Reverse first list\n");
        printf("7. Concatenate lists\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                head1 = createList();
                break;
            case 2:
                head2 = createList();
                break;
            case 3:
                printf("\nFirst List: ");
                display(head1);
                printf("Second List: ");
                display(head2);
                break;
            case 4:
                head1 = insertNode(head1);
                break;
            case 5:
                head1 = deleteNode(head1);
                break;
            case 6:
                head1 = reverseList(head1);
                printf("List reversed successfully.\n");
                break;
            case 7:
                head1 = concatenate(head1, head2);
                printf("Lists concatenated successfully.\n");
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
