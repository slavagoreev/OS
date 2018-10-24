#include <stdio.h>

void swap(int arr[], int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int first, int last) {
    int pivot = arr[last];
    int i = first - 1;
    for (int j = first; j <= last - 1; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr, &arr[i], &arr[j]);
        }
    }
    swap(arr, &arr[i + 1], &arr[last]);
    return i + 1;
}

void quickSort(int arr[], int first, int last) {
    if (first < last) {
        int pivot = partition(arr, first, last);
        quickSort(arr, first, pivot - 1);
        quickSort(arr, pivot + 1, last);
    }
}

int ex4() {
    printf("\nEX 4\n");

    int arr[10] = { 9, 1, 8, 2, 7, 3, 6, 4, 5, 0 };
    print(arr, 10);
    quickSort(arr, 0, 9);
    print(arr, 10);

    printf("\n-----\n");
    return 0;
}