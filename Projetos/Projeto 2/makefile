### Makefile ###
## Projeto 2 Word Frequency Counter
## Iago Lourenço 15610116
## Bruno Camilo 16080293
all: prog run clean

prog: main.o ST.o item.o
	gcc -g -o prog main.o ST.o item.o -lm

main.o: main.c
	gcc -g -c main.c

ST.o: ST.c
	gcc -g -c ST.c

item.o: item.c
	gcc -g -c item.c

clean:
	rm -rf *.o

run: prog clean
	clear
	./prog -n5 < tale.txt
