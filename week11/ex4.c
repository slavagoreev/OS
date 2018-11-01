#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/mman.h>
#include <zconf.h>

int main() {
    int sourceFileDescriptor = open("./ex1.txt", O_RDONLY);
    int destinationFileDescriptor = open("./ex1.memcpy.txt", O_RDWR);
    if (sourceFileDescriptor < 0 && destinationFileDescriptor < 0) {
        EXIT_FAILURE;
    }
    struct stat stbuf;
    stat("./ex1.txt", &stbuf); //getting size of file
    size_t length = (size_t) stbuf.st_size;

    char *src = mmap (NULL, length, PROT_READ, MAP_SHARED, sourceFileDescriptor, 0);
    ftruncate(destinationFileDescriptor, length);
    char *dest = mmap (NULL, length, PROT_READ|PROT_WRITE, MAP_SHARED, destinationFileDescriptor, 0);

    memcpy(dest, src, length);

    munmap(src, length);
    munmap(dest, length);

    close(sourceFileDescriptor);
    close(destinationFileDescriptor);

    return 0;
}