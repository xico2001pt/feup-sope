#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <wait.h>

#define MAX_PATHNAME_SIZE 300

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
    while ((entry = readdir(directory)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        
        sprintf(pathname, "%s/%s", argv[1], entry->d_name);

        struct stat buf;
        if (stat(pathname, &buf) != 0) {
            perror("Stat call error");
            return -1;
        }
        if (S_ISREG(buf.st_mode))  // Not a regular file
            printf("%s: %ld Bytes\n", pathname, buf.st_size);
        else if (S_ISDIR(buf.st_mode)) {
            pid_t pid = fork();
            if (pid < 0 ) {
                perror("fork()");
            } else if (pid == 0) {
                char * argvn[2];
                argvn[0] = argv[0]; argvn[1] = pathname;
                main(argc, argvn);
                return 0;
            } else {
                int status;
                wait(&status);
            }
        }
    }
    closedir(directory);
    
    return 0;
}