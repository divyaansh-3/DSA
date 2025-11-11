#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
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
        newNode->next = NULL;
        if(head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            temp = head;
            while(temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
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
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("(back to head)\n");
}

struct Node* insertNode(struct Node *head) {
    int data, pos, i = 1;
    struct Node *newNode, *temp = head;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data to insert: ");
    scanf("%d", &data);
    newNode->data = data;
    if(head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return head;
    }
    printf("Enter position to insert: ");
    scanf("%d", &pos);
    if(pos == 1) {
        while(temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    } else {
        for(i = 1; i < pos - 1 && temp->next != head; i++)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

struct Node* deleteNode(struct Node *head) {
    struct Node *temp = head, *prev;
    int pos, i = 1;
    if(head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    if(pos == 1) {
        while(temp->next != head)
            temp = temp->next;
        if(head->next == head) {
            free(head);
            head = NULL;
        } else {
            temp->next = head->next;
            free(head);
            head = temp->next;
        }
    } else {
        temp = head;
        for(i = 1; i < pos && temp->next != head; i++) {
            prev = temp;
            temp = temp->next;
        }
        if(temp == head)
            printf("Invalid position!\n");
        else {
            prev->next = temp->next;
            free(temp);
        }
    }
    return head;
}

struct Node* reverseList(struct Node *head) {
    struct Node *prev = NULL, *current = head, *next = NULL, *last = head;
    if(head == NULL)
        return head;
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while(current != head);
    head->next = prev;
    head = prev;
    return head;
}

struct Node* concatenate(struct Node *head1, struct Node *head2) {
    struct Node *temp;
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    temp = head1;
    while(temp->next != head1)
        temp = temp->next;
    temp->next = head2;
    temp = head2;
    while(temp->next != head2)
        temp = temp->next;
    temp->next = head1;
    return head1;
}

int main() {
    int choice;
    while(1) {
        printf("\n--- Circular Linked List Menu ---\n");
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
