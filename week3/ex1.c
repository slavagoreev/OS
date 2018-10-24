#include <stdio.h>
#include <limits.h>
#include <float.h>

int ex1() {
    int *pc;
    int c;

    printf("\nEX 1\n");
    c = 22;
    printf("Address of c:%d\n", &c);
    printf("Value of c:%d\n\n", c);

    pc = &c;
    printf("Address of pointer pc:%d\n", pc);
    printf("Content of pointer pc:%d\n\n", *pc);

    c = 11;
    printf("Address of pointer pc:%d\n", pc);
    printf("Content of pointer pc:%d\n\n", *pc);

    *pc = 2;
    printf("Address of c:%d\n",&c);
    printf("Value of c:%d",c);
    printf("\n-----\n");
    return 0;
}