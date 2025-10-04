#include<stdio.h>
#define MAXSIZE 10
int queue[MAXSIZE];
int rear=-1,front=0;
void insert(){
    int n;
    if(rear== MAXSIZE-1){
        printf("\nQueue overflow");

    }
    else{
        printf("\nenter an element:");
        scanf("%d",&n);
        rear++;
        queue[rear]=n;
    }
}
void delete(){
    if(front>rear ){
        printf("\nQueue is empty");
    }
    else{
        int n=queue[front];
        printf("\ndeleted element is %d",n);
        front++;
             

        }
    }
    void display(){
        if(front>rear){
            printf("\nQueue is empty");
        }
        else{
            printf("\nQueue elements are:");
            for(int i=rear;i>=front;i--){
                printf("%d\n",queue[i]);
            }
        }
    }

int main(){
    int choice;
    do{
    printf("\n---------Queue----------\n");
    printf("\n1.insert,\n2.delete,\n3.display,\n4.Exit");
    printf("\n--------------------------\n");
    printf("enter your choice");
    scanf("%d",&choice);
    switch(choice){
        case 1: insert();break;
        case 2: delete();break;
        case 3: display();break;
        case 4: printf("\n---------Exiting------\n");break;
        default:printf("invlaid choice");

    }
     
    }while(choice != 4);
}