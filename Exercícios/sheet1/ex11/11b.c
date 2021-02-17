#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 50

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s file1 file2\n", argv[0]);
        return 1;
    }

    FILE *file1 = fopen(argv[1], "r");
    if (file1 == NULL) {
        perror("Error opening the file 1");
        return 1;
    }

    FILE *file2 = fopen(argv[2], "w");
    if (file2 == NULL) {
        perror("Error opening the file 2");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes;
    while ((bytes = fread(buffer, sizeof(char), BUFFER_SIZE, file1)) > 0) {
        fwrite(buffer, sizeof(char), bytes, file2);
    }

    fclose(file1);
    fclose(file2);
    return 0;
}