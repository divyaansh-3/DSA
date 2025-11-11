#include<stdio.h>
void bs(int *a,int low,int high, int key){
    if(low>high){
    printf("\nelement not found");
    return;}
    int mid=(low+high)/2;
    if(a[mid]==key){
        printf("element found at index %d",mid);
        return;
    }
    else if(key<a[mid]){
        bs(a,low,mid-1,key);

    }
    else{
        bs(a,mid+1,high,key);
    }

    
}
int sort(int *a,int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("\nSorted array is: ");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
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
    sort(a,n);
    int key;
    printf("\nEnter the element you are searching:");
    scanf("%d",&key);

    int low=0;
    int high=n-1;
    bs(a,low,high,key);
    return 0;
}
