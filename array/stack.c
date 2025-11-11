#include<stdio.h>
#define MAXSIZE 10
int stack[MAXSIZE],top=-1;
void push(){
	int n;
	if(top==MAXSIZE-1){
		printf("\nstack overflow");
	}
	else{
		printf("\nenter an element:");
		scanf("%d",&n);
		top++;
		stack[top]=n;
	}
}
void pop(){
	if(top==-1){
		printf("\nStack is empty");
	}
	else{
		int n;
		n=stack[top];
		top--;
		printf("\npoped element is %d",n);
	}
}
void display(){
    int i;
	if(top==-1){
		printf("\nStack is empty");
	}
	else{
		for(i=top;i>=0;i--){
            printf("element is %d\n",stack[i]);
            
        }
	}
	
}
int main(){
	int choice;
    do{
	
	printf("\n-----------Stack-------------");
	printf("\n1.Push,\n2.pop,\n3.Display,\n4.Exit");
	printf("\n---------------------------");
	printf("\nenter your choice:");
	scanf("%d",&choice);
	switch(choice){
		case 1:push();
		break;
		case 2:pop();
		break;
		case 3:display();
		break;
		case 4:
			printf("------Exiting-------");
			break;
		default:
			printf("\nInvalid choice");
			
	}
}while(choice !=4);
	
	
}