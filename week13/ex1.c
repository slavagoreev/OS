#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 5
#define M 3



void readToArray(int* array, FILE* file, int amount) {
    int cursor = 0;
    while (cursor < amount) {
        fscanf(file, "%d", &array[cursor]);
        cursor++;
    }
}

void readTo2dArray(int **array, FILE *file, int n, int m) {
    for (int i = 0; i < n; i++) {
        readToArray(&array[i], file, m);
    }
}

int main() {
    // The existing resource vector
    int *Exist = malloc(sizeof(int) * M);
    // The available resource vector
    int *Available = malloc(sizeof(int) * M);
    // An N*M matrix defines the number of resources of each class currently allocated to Available process.
    int **Allocated = malloc(sizeof(int *) * N);
    // An N*M matrix indicates the current request of each process.
    int **Request = malloc(sizeof(int *) * N);

    FILE* fp = fopen("input_ok.txt", "r");
//    if (fp = fopen("input_dl.txt", "r")) {
    if (fp) {
        readToArray(Exist, fp, M);
        readToArray(Available, fp, M);
        readTo2dArray(Allocated, fp, N, M);
        readTo2dArray(Request, fp, N, M);




        int deadlock = 0;
        int *touched = (int *) calloc(N, sizeof(int));
        for (int loop = 0; loop < N; loop++) {
            int chosen = 0;
            for (int i = 0; i < N; i++) {
                if (touched[i]) continue;
                int can_run = 1;
                for (int j = 0; j < M; j++) {
                    if (Allocated[i][j] + Available[j] < Request[i][j]) {
                        can_run = 0;
                        break;
                    }
                }
                if (can_run) {
                    touched[i] = 1;
                    chosen = 1;
                    for (int j = 0; j < M; j++) {
                        Available[j] += Allocated[i][j];
                        Allocated[i][j] = 0;
                    }
                    break;
                }
            }
            if (!chosen) deadlock = 1;
        }
        FILE *o = fopen("output_dl.txt", "w");
        if (deadlock) {
            fprintf(o, "Processes with deadlocks:\n");
            for (int i = 0; i < N; i++) {
                if (!touched[i]) fprintf(o, "Process %d\n", i + 1);
            }
        } else fprintf(o, "No deadlock is detected.\n");
        
        
        fclose(fp);
    } else {
        ferror(fp);
    }

    return 0;
}
