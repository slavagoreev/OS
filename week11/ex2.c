#include <stdio.h>
#include <zconf.h>

int main() {
    setvbuf(stdout, NULL, _IOFBF, 1000);
    char* hello[5] = {"H", "e", "l", "l", "o"};
    for (int i = 0; i < 5; i++) {
        printf(hello[i]);
        sleep(1);
    }

    return 0;
}