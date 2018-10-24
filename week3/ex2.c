#include <stdio.h>

void bubbleSort(int arr[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i; j < count; j++) {
            if (arr[j] < arr[i]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void print(int arr[], int n) {
    for (int k = 0; k < n; ++k) {
        printf("%d ", arr[k]);
    }
    printf("\n");
}

int ex2() {
    printf("\nEX 2\n");
    int arr[10] = { 9, 1, 8, 2, 7, 3, 6, 4, 5, 0 };
    print(arr, 10);
    bubbleSort(arr, 10);
    print(arr, 10);

    printf("\n-----\n");
    return 0;
}