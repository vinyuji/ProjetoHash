

all: meu_programa

meu_programa: arquivo.o hash.o main.o Lista.o grafico.o
	gcc Lista.o arquivo.o hash.o main.o grafico.o -o meu_programa -lm

arquivo.o: arquivo.c
	gcc -c arquivo.c

hash.o: hash.c
	gcc -c hash.c

main.o: main.c
	gcc -c main.c

Lista.o: Lista.c
	gcc -c Lista.c

grafico.o:
	gcc -c grafico.c

clean:
	rm -f meu_programa arquivo.o hash.o main.o Lista.o

