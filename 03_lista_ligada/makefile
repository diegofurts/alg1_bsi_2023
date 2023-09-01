CC = gcc
programa = main

main: main.c lista.c lista.h
	$(CC) -o $(programa) main.c lista.c

clean:
	rm *.o $(programa)

exec:
	$(CC) -o $(programa) main.c lista.c
	./$(programa)
