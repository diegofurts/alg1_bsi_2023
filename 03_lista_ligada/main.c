#include <stdio.h>
#include <string.h>

#include "lista.h"

int main() {

	t_lista l;
	t_elemento e;

	inicializar(&l);

	// e = pesquisar(46346, &l);
	// printf(" -> %d\n", e.chave);

	
	e.chave = 247;
	inserir(e, &l);

	remover(247231, &l);
	imprimir(&l);

	e.chave = 865;
	inserir(e, &l);

	e.chave = 943;
	inserir(e, &l);

	e.chave = 234;
	inserir(e, &l);


	// e = pesquisar(46346, &l);
	// printf(" -> %d\n", e.chave);

	// e = pesquisar(247, &l);
	// printf(" -> %d\n", e.chave);

	remover(234, &l);
	imprimir(&l);

}