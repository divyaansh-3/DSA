#include<stdio.h>
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        int flag=0;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        if(minIndex!=i){
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        flag=1;
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
    selectionSort(a,n);
    printf("\nyour sorted array is: ");
    for(i=0;i<n;i++){
        printf(" %d ",a[i]);
    }
    return 0;
}

/*
-----------------------------------------
TIME COMPLEXITY:
-----------------------------------------
Best Case (Already Sorted): O(n)
Average Case: O(n^2)
Worst Case: O(n^2)

SPACE COMPLEXITY: O(1)
-----------------------------------------
*/
