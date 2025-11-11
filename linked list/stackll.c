#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;


void push() {
    int value;
    printf("Enter the data: ");
    scanf("%d", &value);

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = value;
    newnode->next = top; 
    top = newnode;       
    printf("%d pushed to stack\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    struct node *temp = top;
    int poppedValue = temp->data;
    top = top->next; 
    free(temp);      
    printf("%d popped from stack\n", poppedValue);
}

void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct node *temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    int choice;
    do {
        printf("\n---------------STACK MENU----------------\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }

    } while(choice != 4);

    return 0;
}
