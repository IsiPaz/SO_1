all: lista.o funciones.o gametda.o main

lista.o: lista.c
	gcc -W -c lista.c -o lista.o

funciones.o: funciones.c
	gcc -W -c funciones.c -o funciones.o

gametda.o: gametda.c
	gcc -W -c gametda.c -o gametda.o

main: main.o
	gcc main.o funciones.o lista.o gametda.o -o a.out

main.o: main.c
	gcc -W -c main.c -o main.o 

clean:
	rm main.o
	rm funciones.o
	rm lista.o
	rm gametda.o