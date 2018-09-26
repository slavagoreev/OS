#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>

void termHandler(int sig) {
    printf("\nChild terminated!\n");
    exit(0);
}

int main(void) {
    signal(SIGTERM, termHandler);
    int child_pid;
    child_pid = fork();
    switch (child_pid) {
        case -1:
            printf("Fork error!");
            return 1;

        case 0:
            // Child
            while(1) {
                sleep(1);
                printf("I'm alive!\n");
            }
        default:
            // Parent
           sleep(10);
           kill(child_pid, SIGTERM);
    }
    return 0;
}