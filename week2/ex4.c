#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void ex4() {
    printf("\nEnter two numbers to swap: ");
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    swap(&a, &b);
    printf("%d %d", a, b);
}