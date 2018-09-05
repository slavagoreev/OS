#include <stdio.h>
#include "ex1.c"
#include "ex2.c"
#include "ex3.c"
#include "ex4.c"

void print(int arr[], int n) {
    for (int k = 0; k < n; ++k) {
        printf("%d ", arr[k]);
    }
    printf("\n");
}

int main(){
    ex1();
    ex2();
    ex3();
    ex4();
}