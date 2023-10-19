#include <stdio.h>
#include <string.h>

#include "abb.h"

int main() {

	t_abb T;

	inicializar(&T);

	inserir(15, &T);
	em_ordem(&T);
	printf("\n");

	inserir(10, &T);
	em_ordem(&T);
	printf("\n");

	inserir(35, &T);
	em_ordem(&T);
	printf("\n");
	
	inserir(11, &T);
	em_ordem(&T);
	printf("\n");
	
	inserir(5, &T);
	em_ordem(&T);
	printf("\n");
	
	inserir(2, &T);
	em_ordem(&T);
	printf("\n");
	
	inserir(1, &T);
	em_ordem(&T);
	printf("\n");
	
	inserir(90, &T);
	em_ordem(&T);
	printf("\n");
	
	inserir(13, &T);
	em_ordem(&T);
	printf("\n");
	
	inserir(30, &T);
	em_ordem(&T);
	printf("\n");

	inserir(28, &T);
	em_ordem(&T);
	printf("\n");
	

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