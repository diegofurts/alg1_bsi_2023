all:
	@gcc *.c -o nao_inicializado

clean:
	@rm -f nao_inicializado

fsanitize:
	@gcc -g -fsanitize=address,undefined *.c -o nao_inicializado
	@./nao_inicializado

valgrind:
	@gcc -g *.c -o nao_inicializado
	@valgrind ./nao_inicializado

run: all
	@./nao_inicializado