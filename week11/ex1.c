#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int descriptor = open("ex1.txt", O_RDWR | O_CREAT, 'w');
    const char *text = "This is a nice day!!!";
    size_t stingLength = strlen(text);
    
    char *map = mmap(0, stingLength, PROT_READ | PROT_WRITE, MAP_SHARED, descriptor, 0);
    ftruncate(descriptor, (off_t) stingLength);
    memcpy(map, text, stingLength);
    munmap(map, stingLength);
    close(descriptor);
    return 0;
}