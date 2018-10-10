#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int N = 10 * 1024 * 1024;

int main() {
    int i = 0;
    while(i < 10) {
        int* space = malloc(N);
        memset(space, 0, N);

        int who = RUSAGE_SELF;
        struct rusage usage;
        getrusage(who, &usage);
        printf("Memory usage = %ldMB\n", usage.ru_maxrss / (1024 * 1024));
        sleep(1);
        i++;
    }
    return 0;
}
