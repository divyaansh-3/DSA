#include<stdio.h>
int fibonacci(int n){
    if(n<=1){
        return n;

    }
    else{
        int first=0;
        int second=1;
        int next;
        for(int i=2;i<=n;i++){
            next=first+second;
            first=second;
            second=next;
        }
        return next;
    }
    
}
void fib(int n){
    int first=0;
    int second=1;
    if(n==0){
        printf("%d",first);
    }
    else if (n==1){
        printf("\n%d %d",first,second);
    }
    else{
        printf("\n%d %d ",first,second);
        for(int i=2;i<=n;i++){
            int next=first+second;
            printf("%d ",next);
            first=second;
            second=next;
            
        }
    }
}
int recurfib(int n){
    if(n<=1){
        return n;
    }
    else{
        return recurfib(n-2)+recurfib(n-1);
    }
}
int f[40];
int mfib(int n){
    if(n<=1){
        f[n]=n;
        return n;
    }
    else{
        if(f[n-2]==-1){
            f[n-2]=mfib(n-2);
        }
        if(f[n-1]==-1){
            f[n-1]=mfib(n-1);
        }
        return f[n-2]+f[n-1];
    }
}
int main(){
    int choice;
    int n;
    for(int i=0;i<40;i++){
        f[i]=-1;
    }
    printf("\nENTER THE VALUE :");
    scanf("%d",&n);
    do{
        printf("\n--------FIBONACCI SERIES----------\n");
        printf("\n1.USE ITERATIVE METHOD \n2.USE RECURSIVE METHOD \n3.PRINT THE SERIES \n4.USE MEMOIZATION \n5.EXIT");
        printf("\n----------------------------------\n");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("value corresponding to that term is : %d",fibonacci(n));
                break;
            case 2: printf("value corresponding to that term is : %d",recurfib(n));break;
            case 3: fib(n);break;
            case 4: printf("value corresponding to that term is : %d",mfib(n));break;
            case 5: printf("\n--------EXITING------------\n");break;

        }

    }while(choice!=5);

    
}