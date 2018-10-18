#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Page { 
    int page_id;
    int last_used;
};

bool olderThan(struct Page a, struct Page b) { 
    return (a.last_used < b.last_used); 
}
int min(int a, int b) { 
    return (a < b) ? a : b; 
} 

// Returns hit = true / miss = false
bool appendToMemory(
    struct Page* memory, 
    int newPageId, 
    int memorySize, 
    int currentlyFilled
) {
    int oldestFrame = 0;
    bool newPageIsInMemory = false;
    for (int i = 0; i < min(memorySize, currentlyFilled); i++) {
        if (olderThan(memory[i], memory[oldestFrame])) {
            oldestFrame = i;
        }
        if (memory[i].page_id == newPageId) {
            newPageIsInMemory = true;
            memory[i].last_used = currentlyFilled;
        }
    }
    if (!newPageIsInMemory) {
        struct Page newPage;
        newPage.page_id = newPageId;
        newPage.last_used = currentlyFilled;
        if (currentlyFilled < memorySize) {
            memory[currentlyFilled] = newPage;
        } else {
            memory[oldestFrame] = newPage;
        }
    }
    return newPageIsInMemory;

}

int main(int argc, char** argv) {
    if (argc != 2) { 
        printf("Enter the memory size as parameter");
        return 1; 
    }
    int memorySize = atoi(argv[1]);
    struct Page memory[memorySize];

    int tick = 0, currentPage, hits = 0;
    FILE* fp;
    if (fp = fopen("references.txt", "r")) {
        while (fscanf(fp, "%d", &currentPage) != EOF) {
            if (appendToMemory(memory, currentPage, memorySize, tick)) {
                hits++;
            }
            ++tick;
        }
        fclose(fp);
    }
    printf("\n%f - hits per miss ratio. %d - hits. %d - misses. %d - total\n", 
            (double)hits/(tick - hits), hits, (tick - hits), tick);
 
    return 0;
}
