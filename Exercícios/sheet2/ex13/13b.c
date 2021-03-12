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

    if (mkfifo(PIPE_DIR, 0666) < 0) perror("mkfifo()");
    if ((pid = fork()) == -1) { perror("fork()"); exit(2); }
    else if (pid == 0) {  // Child
        while ((np = open(PIPE_DIR, O_RDONLY)) < 0) {}
        char msg[50];
        read(np, msg, 50);
        strcat(msg, "Systems");
        printf("%s\n", msg);
        close(np);
    }
    else {  // Parent
        while ((np = open(PIPE_DIR, O_WRONLY)) < 0) {}
        write(np, "Operating ", 1+strlen("Operating "));
        close(np);
        if (wait(&status) == 0) perror("wait()");
        if (unlink(PIPE_DIR)) perror("unlink()");
    }
    return 0;
}