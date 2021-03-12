#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define NTHREADS 5

void *rot(void *a) {
	printf("\n\t In thread PID: %d ; TID: %lu.", getpid(), (unsigned long) pthread_self());
	int *val = (int *) a;
	int *res = malloc(sizeof(int));
	*res = (*val) * (*val);
	return (void *) res;
	}

int main() {
	int i;	// thread counter
	void *thread_result;
	pthread_t ids[NTHREADS];	// storage of (system) Thread Identifiers
	int id_storage[NTHREADS];

	setbuf (stdout, NULL);	// only for debugging
	printf("\nMain thread PID: %d ; TID: %lu.\n", getpid(), (unsigned long) pthread_self());

	// new threads creation
	for(i=0; i<NTHREADS; i++) {
		id_storage[i] = i;
		if (pthread_create(&ids[i], NULL, rot, &id_storage[i]) != 0)
			exit(-1);	// here, we decided to end process
		else
			printf("\nNew thread %d ; TID: %lu.", i, (unsigned long) ids[i]);
		}
	// wait for finishing of created threads
	for(i=0; i<NTHREADS; i++) {
		pthread_join(ids[i], &thread_result);
		printf("\nTermination of thread %d: %lu, with termination value: %d", i, (unsigned long)ids[i], *((int *)thread_result));
		free(thread_result);
		}

	printf("\n");
	pthread_exit(NULL);	// here, not really necessary...
	return 0;	// will not run this!
}
