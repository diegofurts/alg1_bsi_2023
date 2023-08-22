#include <stdio.h>
#include <string.h>

#include "lista.h"

int main() {

	t_lista l;
	t_elemento e;

	criar(&l);

	e.chave = 247;
	strcpy(e.nome, "joao");
	inserir(e, &l);

	e.chave = 865;
	strcpy(e.nome, "jose");
	inserir(e, &l);

	e.chave = 865;
	strcpy(e.nome, "maria");
	inserir(e, &l);

	for (int i = 0; i <= MAX; i++) {
		e.chave = i;
		inserir(e, &l);
	}

	remover(120, &l);
	remover(247, &l);

	e.chave = 247;
	strcpy(e.nome, "mariana");
	inserir(e, &l);

	imprimir(&l);

}