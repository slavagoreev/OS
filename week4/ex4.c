#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    printf("$ ");
    char program[256];
    scanf("%s", program);

    int i = 0;
    char *p = strtok(program, " ");
    char *array[3];

    while (p != NULL) {
        array[i++] = p;
        p = strtok(NULL, " ");
    }

    pid_t pid;

    if ((pid = fork()) < 0) {
        perror("Fork error.");
        exit(1);
    } else if (!pid) {
        // Child.
//        execve(array[0], array, NULL);
    } else {
        execve("/bin/sh", array, NULL);
    }
    return 0;
}