EXECUTAVEL = vazamento

all:
	@gcc *.c -o $(EXECUTAVEL)

clean:
	@rm -f $(EXECUTAVEL)

fsanitize:
	@gcc -g -fsanitize=address,undefined *.c -o $(EXECUTAVEL)
	@./$(EXECUTAVEL)

valgrind:
	@gcc -g *.c -o $(EXECUTAVEL)
	@valgrind --leak-check=full ./$(EXECUTAVEL)

run: all
	@./$(EXECUTAVEL)