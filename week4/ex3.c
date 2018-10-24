#include <stdio.h>

int main(){
    printf("$ ");
    char input[256];
    scanf("%s", input);
    system(input);
    return 0;
}