#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define NTHREADS 2

static pthread_t ids[NTHREADS];
char * messages[NTHREADS] = {"Systems", "Operating"};

int displayText(char string[], int priority) {
    if (priority >= 0 && priority < NTHREADS - 1) {
        if (pthread_join(ids[priority + 1], NULL) != 0) {
            perror("Error waiting for thread");
            return -1;
        }
    }
    printf("%s ", string);
    return 0;
}

void *rot(void *a) {
    displayText(messages[1], 1);
	pthread_exit(NULL);
}

int main() {
    ids[0] = pthread_self();
    if (pthread_create(&ids[1], NULL, rot, NULL) != 0)
        return -1;
    if (displayText(messages[0], 0))
        return -1;
    printf("\n");
    return 0;
}
