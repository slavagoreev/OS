#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>

void stopHandler(int sig) {
    printf("\nSecond child stopped!\n");
    exit(0);
}

int pfd[2];          /* Pipe file descriptors */
int status;

int main(void) {
    int first_pid;
    int second_pid;

    status = pipe(pfd);
    if (status == -1) {
       printf("Could'n create a pipe!");
       return 1;
    }

    first_pid = fork();
    if (first_pid == 0) {
        // First child
        close(pfd[1]);
        first_pid = getpid();

        read(pfd[0], &second_pid, sizeof(first_pid));
        printf("Caught message from first child (PID=%d) to second child (PID=%d)", first_pid, second_pid);
        
        sleep(2);
        kill(second_pid, SIGSTOP);
        close(pfd[0]);
    } else {
        // Parent
        second_pid = fork();
        if (second_pid == 0) {
            // Second child
            signal(SIGSTOP, stopHandler);
            while(1);
        } else {
            close(pfd[0]);
            printf("\nCreated 1st fork: %d\n", first_pid);
            printf("Created 2nd fork: %d\n", second_pid);
            write(pfd[1], &second_pid, sizeof(second_pid));
            close(pfd[1]);

            int status;
            waitpid(second_pid, &status, NULL);
            printf("2nd child exited with %d status\n", status);
        }
    }
    
    return 0;
}