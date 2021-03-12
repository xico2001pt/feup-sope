all: 5 9 8 10 13

5: ./ex5/5.c
	cc ./ex5/5.c -Wall -o ./ex5/5

8: ./ex8/8.c
	cc ./ex8/8.c -Wall -o ./ex8/8

9: ./ex9/9.c
	cc ./ex9/9.c -Wall -lpthread -o ./ex9/9

10: ./ex10/10.c
	cc ./ex10/10.c -Wall -lpthread -o ./ex10/10

13: ./ex13/13a.c ./ex13/13b.c ./ex13/13c.c ./ex13/13d.c
	cc ./ex13/13a.c -Wall -o ./ex13/13a
	cc ./ex13/13b.c -Wall -o ./ex13/13b
	cc ./ex13/13c.c -Wall -o ./ex13/13c
	cc ./ex13/13d.c -Wall -o ./ex13/13d

clean:
	rm -f ./ex5/5 ./ex8/8 ./ex9/9 ./ex10/10 ./ex13/13a ./ex13/13b ./ex13/13c ./ex13/13d