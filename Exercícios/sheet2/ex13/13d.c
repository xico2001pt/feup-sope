#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <wait.h>

#define PIPE_DIR "/tmp/np"

int main() {
    pid_t pid;
    int status, np;
    char msg[50];

    if (mkfifo(PIPE_DIR, 0666) < 0) perror("mkfifo()");
    if ((pid = fork()) == -1) { perror("fork()"); exit(2); }
    else if (pid == 0) {  // Child
        while ((np = open(PIPE_DIR, O_RDONLY)) < 0) {}
        read(np, msg, 50);
        strcat(msg, "Systems");
        printf("Child: %s\n", msg);
        close(np);

        while ((np = open(PIPE_DIR, O_WRONLY)) < 0) {}
        write(np, "Systems", 1+strlen("Systems"));
        close(np);
    }
    else {  // Parent
        while ((np = open(PIPE_DIR, O_WRONLY)) < 0) {}
        write(np, "Operating ", 1+strlen("Operating "));
        close(np);

        while ((np = open(PIPE_DIR, O_RDONLY)) < 0) {}
        char msg2[50] = "Operating ";
        read(np, msg, 50);
        strcat(msg2, "Systems");
        printf("Parent: %s\n", msg2);
        close(np);
        if (wait(&status) == 0) perror("wait()");
        if (unlink(PIPE_DIR)) perror("unlink()");
    }
    return 0;
}