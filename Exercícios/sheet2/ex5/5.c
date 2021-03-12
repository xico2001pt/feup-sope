#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <wait.h>

int main(void) {
    pid_t pid;
    int status;

    if ((pid = fork()) < 0) {
        fprintf(stderr, "Fork error\n");
        return -1;
    }
    else if (pid == 0)  // Child
        printf("Hello ");
    else {
        if (wait(&status) != pid)
            fprintf(stderr,"wait error\n");
        // sleep(1);
        printf("World!\n");
    }
    return 0;
}