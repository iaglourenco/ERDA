### Makefile ###
## Projeto 1 matrizes
## Iago Lourenço 15610116
## Bruno Camilo 16080293
all: prog run clean rmpoper

prog: main.o lista.o matriz.o
	gcc -g -o prog main.o lista.o matriz.o -lm

matriz.o: matriz.c
	gcc -g -c matriz.c

lista.o: lista.c
	gcc -g -c lista.c

main.o: main.c
	gcc -g -c main.c

clean:
	rm -rf *.o

rmpoper: clean
	rm -rf prog
	#clear

run: prog clean
	clear
	./prog #<in.txt
