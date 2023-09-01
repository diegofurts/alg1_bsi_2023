#include <stdio.h>
#include "pilha.h"


void inicializar(t_pilha *P) {
	P->topo = -1;
}


int push(int e, t_pilha *P) {

	if (cheia(P)) {
		printf("Pilha cheia\n");
		return CHEIA;
	}

	P->topo++;
	P->pilha[P->topo] = e;

	return SUCESSO;

}

int pop(t_pilha *P) {

	if (vazia(P)) {
		printf("Nao pode popar\n");
		return VAZIA;
	}

	int e = P->pilha[P->topo];
	P->topo--;	

	return e;

}

int vazia(t_pilha *P) {
	if (P->topo < 0) {
		return 1;
	} else {
		return 0;
	}
}

int cheia(t_pilha *P) {
	// return (P->topo == MAX - 1) ? 1 : 0;
	// return P->topo == MAX -1;
	if (P->topo == MAX - 1) {
		return 1;
	} else {
		return 0;
	}
}

int topo(t_pilha *P) {

	if (vazia(P)) {
		printf("Nao tem topo!!!!\n");
		return VAZIA;
	}
	return P->pilha[P->topo];

}


int contar(t_pilha *P) {
	return P->topo + 1;
}