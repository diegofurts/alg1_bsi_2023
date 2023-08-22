CC = gcc
CFLAGS = -Wall -O2
programa = main

main: main.c conjunto.c conjunto.h
	$(CC) $(CFLAGS) -o $(programa) main.c conjunto.c

clean:
	rm *.o $(programa)

exec:
	$(CC) $(CFLAGS) -o $(programa) main.c conjunto.c
	./$(programa)
