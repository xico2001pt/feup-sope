all: 1 2 3 7 11

1: ex1/1.c
	cc -Wall ex1/1.c -o ex1/1

2: ex2/2a.c ex2/2b.c ex2/2c.c
	cc -Wall ex2/2a.c -o ex2/2a
	cc -Wall ex2/2b.c -o ex2/2b
	cc -Wall ex2/2c.c -o ex2/2c

3: ex3/3.c
	cc -Wall ex3/3.c -o ex3/3

7: ex7/7.c
	cc -Wall ex7/7.c -o ex7/7 -lpthread

11: ex11/11.c
	cc -Wall ex11/11.c -o ex11/11 -lpthread

clean:
	rm -f ex1/1 ex2/2a ex2/2b ex2/2c ex3/3 ex7/7 ex11/11