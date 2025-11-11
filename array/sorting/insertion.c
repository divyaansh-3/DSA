#include<stdio.h>
void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    insertionSort(a,n);
    printf("\nyour sorted array is: ");
    for(i=0;i<n;i++){
        printf(" %d ",a[i]);
    }
    return 0;
}
