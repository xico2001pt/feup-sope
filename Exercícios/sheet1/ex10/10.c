#include <sys/times.h>
#include <unistd.h>
#include <stdio.h>

#define LOOPS 100000
int main(void) {
    clock_t start, end;
    struct tms t;
    long ticks_per_second = sysconf(_SC_CLK_TCK);

    start = times(&t);
    for (unsigned long i = 0; i < LOOPS; ++i)
        printf("Hello World!\n");
    end = times(&t);

    printf("Duration: %f seconds\n", (double) (end - start) / ticks_per_second);

    return 0;
}