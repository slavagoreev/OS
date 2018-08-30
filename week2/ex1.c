#include <stdio.h>
#include <limits.h>
#include <float.h>

int ex1() {
    int i = INT_MAX;
    float f = FLT_MAX;
    double d = DBL_MAX;

    printf("\nEX 1");
    printf("\n%d bit for int, INT_MAX is %d", sizeof(i), i);
    printf("\n%d bit for float, FLT_MAX is %f", sizeof(f), f);
    printf("\n%d bit for double, DBL_MAX is %lf", sizeof(d), d);
    printf("\n-----\n");
    return 0;
}