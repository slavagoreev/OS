#include <stdlib.h>
#include <stdio.h>


int min (a, b) {
    if (a > b) {
        return b;
    } else {
        return a;
    }
}

void* new_realloc(void *ptr, size_t originalLength, size_t newLength){
   if (newLength == 0) {
      free(ptr);
      return NULL;
   } else if (!ptr) {
      return malloc(newLength);
   } else {
      void *ptrNew = malloc(newLength);
      if (ptrNew) {
          int minLen = min(originalLength, newLength);
          memcpy(ptrNew, ptr, minLen);
          free(ptr);
      }
      return ptrNew;
    }
}

void printIntArr(int* arr, int length) {
    printf("\n[");
    for (int i = 0; i < length - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[length - 1]);
}

int main() {
    printf("Enter original array size: ");
	int n = 0;
	scanf("%d", &n);

    int length = n * sizeof(int);
    int *arr = (int*)malloc(length);
	for(int i = 0; i < n; i++){
		arr[i] = i;
	}
    printIntArr(arr, n);

    printf("\nEnter new array size: ");
	int N = 0;
	scanf("%d", &N);
    int lengthN = N * sizeof(int);

    arr = new_realloc(arr, length, lengthN);
    if (lengthN > 0) {
        printIntArr(arr, N);
    } else {
        printf("Array was freed\n");
    }
	
	return 0;
}