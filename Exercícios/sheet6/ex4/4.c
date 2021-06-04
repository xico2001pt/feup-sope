#include <stdio.h>
#include <unistd.h>

int main() {
    // compile and redirect to a file...
    // open with a hex editor
    int i = 1234567;
    write(STDOUT_FILENO, &i, sizeof(i));
    printf("\n%d", i);
    return 0;
}