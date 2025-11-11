#include<stdio.h>
void bubbleSort(int arr[], int n) {
    
    for(int i = 0; i < n - 1; i++) {
        int flag=0;
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag=1;
            }
        }
        if(!flag){
            break;
        }
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
    bubbleSort(a,n);
    printf("\nyour sorted array is: ");
    for(i=0;i<n;i++){
        printf(" %d ",a[i]);
    }
    return 0;
}
/* time complexity of this code is O(n^2);
best case is if array is already sorted, O(n);
worst case time complexity is when arry is reverse sorted*/
