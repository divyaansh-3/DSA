#include <stdio.h>

void sortArray(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (a[mid] == key)
            return mid;

        else if (key < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int main() {
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sortArray(a, n);

    printf("\nSorted Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n\nEnter element to search: ");
    scanf("%d", &key);

    int result = binarySearch(a, n, key);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
