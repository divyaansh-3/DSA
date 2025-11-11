#include<stdio.h>
void linearsearch(int *a,int n, int key){
    int i;
    int flag=0;
    for(i=0;i<n;i++){
        if(a[i]==key){
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("\nelement not found.");
    }
    else{
        printf("element found at index %d",i);
    }

}
int main(){
    
    int n,i;
    printf("enter the no of elements in your array:");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter elements:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\nYour array is: ");
    for(i=0;i<n;i++){
        printf(" %d ",a[i]);

    }
    int key;
    printf("\nEnter the element you are searching:");
    scanf("%d",&key);
    linearsearch(a,n,key);
    return 0;

}