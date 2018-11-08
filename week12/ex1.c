#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/mman.h>
#include <zconf.h>

int main() {
    int randomData = open("/dev/urandom", O_RDONLY);
    if (randomData < 0) {
        return 1;
    } else {
        unsigned char myRandomData[20];
        size_t randomDataLen = 0;
        while (randomDataLen < sizeof myRandomData) {
            ssize_t result = read(randomData, myRandomData + randomDataLen, (sizeof myRandomData) - randomDataLen);
            if (result < 0)
                return 1;
            randomDataLen += result;
        }
        printf("%s\n", myRandomData);
        printf("20 Symbols as hex\n", myRandomData);
        for (int i = 0; i < 20; i ++) {
            printf("%u ", myRandomData[i]);
        }
        close(randomData);
    }
}