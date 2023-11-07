

all: meu_programa

meu_programa: arquivo.o hash.o main.o Lista.o
	gcc Lista.o arquivo.o hash.o main.o -o meu_programa

arquivo.o: arquivo.c
	gcc -c arquivo.c

hash.o: hash.c
	gcc -c hash.c

main.o: main.c
	gcc -c main.c

Lista.o: Lista.c
	gcc -c Lista.c

clean:
	rm -f meu_programa arquivo.o hash.o main.o Lista.o

