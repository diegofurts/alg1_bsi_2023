#include <stdio.h>
#include "pilha.h"

int main() {

	t_pilha P;
	int e;

	inicializar(&P);

	push(5, &P);
	push(7, &P);
	push(9, &P);

	e = pop(&P);
	printf("%d\n", e);

	push(10, &P);

	while(!vazia(&P)) {
		e = pop(&P);
		printf("%d\n", e);
	}

}