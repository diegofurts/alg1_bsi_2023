#include <stdio.h>
#include <string.h>

#include "abb.h"

int main() {

	t_abb T;

	inicializar(&T);

	inserir(15, &T);
	inserir(10, &T);
	inserir(35, &T);
	inserir(11, &T);
	inserir(5, &T);
	inserir(2, &T);
	inserir(1, &T);
	inserir(90, &T);
	inserir(13, &T);
	inserir(30, &T);

	// pesquisar(30, &T);
	// pesquisar(97, &T);

	// remover(5, &T);
	// pesquisar(5, &T);

	// remover(11, &T);
	// pesquisar(11, &T);

	remover(10, &T);
	pesquisar(10, &T);

	em_ordem(&T);
	printf("\n");

	limpar(&T);

}