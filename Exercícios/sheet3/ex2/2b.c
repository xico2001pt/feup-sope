/*
*	EXEC: 1st example of typical usage!
*
* Note:	execve is the syscal!
*	execv, execvp, execvpe, execl, execlp, execle are library functions.
*
* Exercise:
* 	change this code to show that USER was changed after the exec.
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/types.h>

// preparation for execve:
char *cmdline[] = { "sleep", "30", (void *)0 };
char *newenviron[] = { "USER=Linus", NULL };
int status;

int main() {
	pid_t id;
setbuf(stdout, NULL);	// to make sure printf() have no buffer so, nodelay!

printf("\nParent: %d. USER=%s", getpid(), getenv("USER"));

id = fork();
switch (id) {
	case -1:
		perror ("fork()");
		exit (1);
	case 0:	// child
		printf("\nChild: %d. USER=%s", getpid(), getenv("USER"));
		printf("\nChild: check that following exec was succeful with: \"ps x | grep sleep\"\n");
		if (execve("/bin/sleep", cmdline, newenviron) == -1)
			perror("execve");
		printf("\nYou will not see this unless execve() fails! Know why?...\n");
		return 0;	// if execve fails...
	default:
		printf("\nParent still: %d. USER=%s", getpid(), getenv("USER"));
	}
wait(&status);
return 0;
}
