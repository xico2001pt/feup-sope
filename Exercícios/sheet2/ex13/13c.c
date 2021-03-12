#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <wait.h>

int main() {
    pid_t pid;
    int status, pp[2];
    char msg[50];

    if (pipe(pp) == -1) { perror("pipe()"); exit(1); }
    if ((pid = fork()) == -1) { perror("fork()"); exit(2); }
    else if (pid == 0) {  // Child
        close(pp[1]);
        read(pp[0], msg, 50);
        strcat(msg, "Systems");
        printf("Child: %s\n", msg);

        close(pp[0]);
        write(pp[1], "Systems", 1+strlen("Systems"));
        close(pp[1]);
    }
    else {  // Parent
        close(pp[0]);
        write(pp[1], "Operating ", 1+strlen("Operating "));
        
        close(pp[1]);
        char msg2[50] = "Operating ";
        close(pp[1]);
        read(pp[0], msg, 50);
        strcat(msg2, "Systems");
        printf("Parent: %s\n", msg2);
        wait(&status);
    }
    return 0;
}