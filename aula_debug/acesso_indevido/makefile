all:
	@gcc *.c -o acesso_indevido

clean:
	@rm -f acesso_indevido

fsanitize:
	@gcc -g -fsanitize=address *.c -o acesso_indevido
	@./acesso_indevido

valgrind:
	@gcc -g *.c -o acesso_indevido
	@valgrind ./acesso_indevido

run: all
	@./acesso_indevido