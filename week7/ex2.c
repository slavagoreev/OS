#include <stdio.h>

int main() {
    printf("\nEnter N: ");
    int N;
    scanf("%d", &N);
    int *array = malloc(N * sizeof(int));
    printf("\n");
    for (int i = 0; i < N; i++) {
        array[i] = i;
    }
    printf("[");
    for (int i = 0; i < N; i++) {
        printf("%d, ", array[i]);
    }
    printf("]\n");
    return 0;
}