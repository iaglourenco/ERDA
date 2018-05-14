### Makefile ###
## Projeto 2 Word Frequency Counter
## Iago Lourenço 15610116
## Bruno Camilo 16080293
all: prog run clean rmpoper

prog: main.o ST.o
	gcc -g -o prog main.o ST.o -lm

main.o: main.c
	gcc -g -c main.c

ST.o: ST.c
	gcc -g -c ST.c

clean:
	rm -rf *.o

rmpoper: clean
	rm -rf prog
	#clear

run: prog clean
	clear
	./prog
