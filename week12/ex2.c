#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>

int main(int argc, char** argv) {
    char ch;
    int fileNamesStart = 1;
    if (strcmp(argv[1], "-a") == 0)
        fileNamesStart++;
    FILE** fileDescriptors = (FILE*)malloc(sizeof(FILE*) * (argc - fileNamesStart));
    char* mode = "w+";
    if (strcmp(argv[1], "-a") == 0)
        mode = "aw+";
    for (int i = fileNamesStart; i < argc; i++) {
        fileDescriptors[i] = fopen(argv[i], "aw+");
    }
    char* buffer[10000];
    int bufCursor = 0;
    while(scanf("%c" , &buffer[bufCursor]) != EOF) {
        bufCursor++;
    }
    for (int i = 0; i < bufCursor; i++) {
        printf("%c", buffer[i]);
    }
    for (int j = fileNamesStart; j < argc; j++) {
        printf("Writing to file number %d id %d\n", j, fileDescriptors[j]);
        for (int i = 0; i < bufCursor; i++) {
            int results = fprintf(fileDescriptors[j], "%c", buffer[i]);;
            if (results == EOF) {
                printf("Failed to write to %d", fileDescriptors[j]);
            }
        }
        
        fclose(fileDescriptors[j]);
    }
}