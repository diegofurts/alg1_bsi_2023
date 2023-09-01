#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int inicializar(t_lista *l) {

	// idealmente, limpar a lista que TALVEZ exista

	l->primeiro = NULL;
	return SUCESSO;

}

static t_apontador pesquisar_pos(t_chave chave, t_lista *l) {

	t_apontador p = l->primeiro;

	while (p != NULL) {

		// achou o elemento?
		if (p->elemento.chave == chave)
			return p;

		p = p->proximo;
	}

	return p;

}

t_elemento pesquisar(t_chave chave, t_lista *l) {

	t_apontador p = pesquisar_pos(chave, l);

	if (p == NULL) {
		printf("Deu ruim, nao achou!\n");

		t_elemento e;
		e.chave = -1;

		return e;
	} else {
		return p->elemento;
	}

}


int inserir(t_elemento e, t_lista *l) { // primeira pos

	t_apontador p = (t_apontador) malloc(sizeof(t_no));

	if (p == NULL) {
		printf("Lista (memoria) cheia!\n");
		return CHEIA;
	}

	p->elemento = e;
	p->proximo = l->primeiro;
	l->primeiro = p;

	return SUCESSO;

}

int remover(t_chave chave, t_lista *l) {

	if (vazia(l)) {
		printf("Nao achei para remover\n");
		return NAO_EXISTE;
	}

	t_apontador p = l->primeiro;
	t_apontador p2; // aux


	if (p->elemento.chave == chave) { // chave na primeira pos

		p2 = l->primeiro;
		l->primeiro = p2->proximo;

		free(p2);

		return SUCESSO;

	}

	while (p->proximo!=NULL) {

		if (p->proximo->elemento.chave == chave) {

			p2 = p->proximo;
			p->proximo = p2->proximo;

			free(p2);

			return SUCESSO;

		}

		p = p->proximo;
	}

	printf("Nao achei para remover\n");
	return NAO_EXISTE;

}

int vazia(t_lista *l) {

	if (l->primeiro == NULL)
		return 1;

	return 0;

}


int cheia(t_lista *l);


void imprimir(t_lista *l) {

	t_apontador p = l->primeiro;

	while (p != NULL) {
		printf("%d ", p->elemento.chave);
		p = p->proximo;
	}
	printf("\n");

}