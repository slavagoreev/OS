#include <unistd.h>

int pfd[2];          /* Pipe file descriptors */
int status;

int main() {
    status = pipe(pfd);
    if (status == -1) {
       printf("Could'n create a pipe!");
       return 1;
    }
    char *firstString = "Hello world\n";
    char len = strlen(firstString);
    char secondString[len];

    switch (fork()) {
        case -1:
            printf("Fork error!");
            return 1;

        case 0:
            //Child
            close(pfd[1]);
            read(pfd[0], secondString, len);
            close(pfd[0]);
            printf("First string: %s\n", firstString);
            printf("Second string: %s\n", secondString);

        default:
            //Parent
            close(pfd[0]);
            write(pfd[1], firstString, len);
            close(pfd[1]);
    }
    return 0;
}