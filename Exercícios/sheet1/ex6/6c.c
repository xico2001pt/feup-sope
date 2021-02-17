#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Invalid arguments!\n");
        return 1;
    }

    if ((open(argv[1], O_RDONLY)) == -1) {
        perror("Error opening the file");
        return 1;
    }

    printf("File opened successfully\n");
    return 0;
}