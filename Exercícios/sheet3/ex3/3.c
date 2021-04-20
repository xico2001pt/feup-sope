#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handler(int sig){
	printf("%d got %d\n", getpid(), sig);
}

int main(){
	signal(SIGINT, handler);
	signal(SIGUSR1, handler);
	int pid = fork();	
	printf("I'm %d\n", getpid());
	if(pid == 0){
		int pid2 = fork();
		if(pid2 == 0){
			printf("I'm %d\n", getpid());
		}
		else if(pid2 > 0){
			printf("I'm parent of %d\n", pid2);
		}
	}
	else if(pid > 0){
		printf("I'm parent of %d\n", pid);
	}
	sleep(10);
}