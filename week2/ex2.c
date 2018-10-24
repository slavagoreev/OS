#include <stdio.h>
#include <stdlib.h>

int len = 0;

static char *read_stdin(void) {
    size_t cap = 4096; /* Initial capacity for the char buffer */

    char *buffer = malloc(cap * sizeof(char));
    int c;

    /* Read char by char, breaking if we reach EOF or a newline */
    while ((c = fgetc(stdin)) != '\n' && !feof(stdin)) {
        buffer[len] = c;

        /* When cap == len, we need to resize the buffer
         * so that we don't overwrite any bytes
         */
        if (++len == cap)
            /* Make the output buffer twice its current size */
            buffer = realloc(buffer, (cap *= 2) * sizeof(char));
    }

    /* Trim off any unused bytes from the buffer */
    buffer = realloc(buffer, (len + 1) * sizeof(char));

    /* Pad the last byte so we don't overread the buffer in the future */
    buffer[len] = '\0';

    return buffer;
}

int ex2() {

    printf("\nEX 2");
    printf("\nEnter some string to reverse it: ");

    char *input = read_stdin();
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", input[i]);
    }
    printf("\n\n-----\n");
    free(input);
    return 0;
}