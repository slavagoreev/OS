#include <signal.h>

void killHandler(int sig) {
    printf("\nYou've killed Kenny!\n");
    exit(0);
}

void stopHandler(int sig) {
    printf("\nYou've stopped Kenny!\n");
    exit(0);
}

void usr1Handler(int sig) {
    printf("\nYou've SIGUSR1 Kenny!\n");
    exit(0);
}

int main(void) {
    signal(SIGKILL, killHandler);
    signal(SIGSTOP, stopHandler);
    signal(SIGUSR1, usr1Handler);
    while (1)
        pause();
    return 0;
}