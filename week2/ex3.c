#include <stdio.h>

void ex3(int n) {
    int spaces = n - 1;
    for (int i= 1; i <= n; i++){
        for(int j = 1; j <= spaces; j++){
            printf(" ");
        }
        for (int k = 1; k <= 2*i-1; ++k) {
            printf("*");
        }
        for(int j = 1; j <= spaces; j++){
            printf(" ");
        }
        printf("\n");
        spaces--;
    }
}