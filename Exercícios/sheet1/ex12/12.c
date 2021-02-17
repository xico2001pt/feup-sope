#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATHNAME_SIZE 100

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s dirname\n", argv[0]);
        return -1;
    }

    DIR *directory = opendir(argv[1]);
    if (directory == NULL) {
        perror("Error opening directory");
        return -1;
    }

    struct dirent *entry;
    char pathname[MAX_PATHNAME_SIZE];
    while ((entry = readdir(directory)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        
        memset(pathname, 0, MAX_PATHNAME_SIZE);
        strcpy(pathname, "./");
        strcpy(pathname, argv[1]);
        strcat(pathname, "/");
        strcat(pathname, entry->d_name);

        struct stat buf;
        if (stat(pathname, &buf) != 0) {
            perror("Stat call error");
            return -1;
        }
        if (!S_ISREG(buf.st_mode))  // Not a regular file
            continue;
        
        printf("%s: %ld Bytes\n", entry->d_name, buf.st_size);
    }

    closedir(directory);
    
    return 0;
}