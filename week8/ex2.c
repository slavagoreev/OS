#include <stdio.h>
#include <stdlib.h>

int N = 10 * 1024 * 1024;

int main() {
    int i = 0;
    while(i < 10) {
        int* space = malloc(N);
        memset(space, 0, N);
        sleep(1);
        i++;
    }
    return 0;
}
