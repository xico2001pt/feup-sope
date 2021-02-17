#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 50

int main(int argc, char *argv[]) {
    if (argc == 1 || argc > 3) {
        printf("Usage: %s file1 file2\n", argv[0]);
        return 1;
    }

    int file1 = open(argv[1], O_RDONLY);
    if (file1 == -1) {
        perror("Error opening the file 1");
        return 1;
    }

    int file2 = (argc == 2 ? STDOUT_FILENO : open(argv[2], O_WRONLY));
    if (file2 == -1) {
        perror("Error opening the file 2");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes;
    while ((bytes = read(file1, buffer, BUFFER_SIZE)) != 0) {
        if (bytes == -1) {
            printf("Error reading bytes\n");
            return 1;
        }
        if (write(file2, buffer, bytes) == -1) {
            printf("Error writing bytes\n");
            return 1;
        }
    }

    close(file1);
    close(file2);
    return 0;
}