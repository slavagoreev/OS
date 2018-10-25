#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

// The same method as main but just for printing needs
void linkHandler(ino_t inode) {
	DIR *directoryPointer = opendir("./tmp");
	if (directoryPointer == NULL) return;

	char currentPath[256];		
	struct stat fileStat;

	struct dirent* directoryEntry;
	while ((directoryEntry = readdir(directoryPointer)) != NULL) {
		sprintf(currentPath, "./tmp/%s", directoryEntry->d_name);
		stat(currentPath, &fileStat);
		if (fileStat.st_ino == inode) {
            printf("%s\n", directoryEntry->d_name);
        }
	}
}

int main() {
	DIR *directoryPointer = opendir("./tmp");
	if (directoryPointer == NULL) return EXIT_FAILURE;

	char currentPath[256];		
	struct stat fileStat;	

	struct dirent* directoryEntry;
	while ((directoryEntry = readdir(directoryPointer)) != NULL) {
        // Store ./tmp/filename into currentPath
		sprintf(currentPath, "./tmp/%s", directoryEntry->d_name);
		stat(currentPath, &fileStat);
		
        // Take only files with 2 or more hardlinks and not directory links
        if (fileStat.st_nlink >= 2 && 
			strcmp(directoryEntry->d_name, ".") != 0 &&
			strcmp(directoryEntry->d_name, "..") != 0) {
            // Loop over whole dir to print all link occurancies inside of it
	        printf("Hard links for: %s\n", currentPath);
            linkHandler(fileStat.st_ino);
        }
	}

	return EXIT_SUCCESS;
}