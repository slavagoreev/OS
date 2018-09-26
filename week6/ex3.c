#include <signal.h>

void interruptHandler(int sig) {
    printf("\nCtrl-C press detected\n");
    exit(0);
}

int main(void) {
    signal(SIGINT, interruptHandler);
    while (1)
        pause();
    return 0;
}