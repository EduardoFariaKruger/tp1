# Makefile de exemplo (Manual do GNU Make)
     
CFLAGS = -Wall # flags de compilacao
CC = gcc

all: tp1.o racionais.o
	$(CC) -o tp1 tp1.o racionais.o

racionais.o: racionais.c
	$(CC) -c $(CFLAGS) racionais.c

tp1.o: tp1.c
	$(CC) -c $(CFLAGS) tp1.c

clean:
	rm -f *.o tp1
