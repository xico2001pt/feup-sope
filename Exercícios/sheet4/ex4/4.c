#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    size_t size = (size_t) 50e6;
    while (1) {
        char *c = (char *) malloc(size);
        memset(c, 'A', size);
        sleep(1);
    }
    return 0;
}