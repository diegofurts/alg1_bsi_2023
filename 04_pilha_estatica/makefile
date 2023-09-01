CC = gcc
programa = main

main: main.c pilha.c pilha.h
	$(CC) -o $(programa) main.c pilha.c

clean:
	rm *.o $(programa)

exec:
	$(CC) -o $(programa) main.c pilha.c
	./$(programa)
