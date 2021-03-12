#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void func(int signo) {
	printf("World\n");
}

int main() {
	pid_t pid;

    if ((pid = fork()) < 0) {
        fprintf(stderr, "Fork error\n");
        return -1;
    }
    else if (pid == 0) {  // Child
        printf("Hello ");
		raise(1);
	}
    else {
        signal(1, func);
        // sleep(1);
    }
	return 0;
}
