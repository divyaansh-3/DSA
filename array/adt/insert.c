#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, size, length;

    printf("enter the size of your array: ");
    scanf("%d", &size);

    int *a = (int *)malloc(size * sizeof(int));

    if(a == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\nenter the number of elements to be added to your array: ");
    scanf("%d", &n);

    if(n > size){
        printf("Number of elements cannot exceed array size!\n");
        return 1;
    }

    printf("\nenter the elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    length = n;

    printf("\nyour array is: ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    int key, pos;
    printf("\nenter the new number to be inserted: ");
    scanf("%d", &key);

    printf("\nenter the index where it is to inserted: ");
    scanf("%d", &pos);

    // validate position
    if(pos < 0 || pos > length){
        printf("\nInvalid position!\n");
        return 1;
    }

    // check if room exists
    if(length == size){
        printf("\nNo space for insertion!\n");
        return 1;
    }

    // shift elements
    for(int i = length - 1; i >= pos; i--){
        a[i + 1] = a[i];
    }

    a[pos] = key;

    length++;
    n++;

    printf("\nyour new array is: ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    free(a);
    return 0;
}
