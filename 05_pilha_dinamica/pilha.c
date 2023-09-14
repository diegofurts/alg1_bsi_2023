#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int inicializar(t_pilha *P) {

	// limpar antes seria uma boa
	P->topo = NULL;
	P->count = 0;
	return SUCESSO;

}

int push(int e, t_pilha *P) { // primeira pos

	t_apontador a = (t_apontador) malloc(sizeof(t_no));

	if (a == NULL) {
		printf("Pilha (memoria) cheia!\n");
		return CHEIA;
	}

	a->elemento = e;
	a->proximo = P->topo;
	P->topo = a;
	P->count++;

	return SUCESSO;

}

int pop(t_pilha *P) {

	if (vazia(P)) {
		printf("Pilha esta vazia, nao tem mais nada para tirar da pobre coitada\n");
		return NAO_EXISTE;
	}

	t_apontador a = P->topo;
	int e = a->elemento;


	P->topo = P->topo->proximo;
	free(a);

	P->count--;

	return e;

}

int vazia(t_pilha *P) {

	if (P->topo == NULL)
		return 1;

	return 0;

}


int cheia(t_pilha *P) {
	
	t_apontador a = (t_apontador) malloc(sizeof(t_no));

	if (a == NULL)
		return 1;

	return 0;
}

int topo(t_pilha *P) {
	if (vazia(P)) {
		printf("Nao tem topo!!!!\n");
		return VAZIA;
	} else {
		return P->topo->elemento;
	}
}

int contar(t_pilha *P) {
	return P->count;
}