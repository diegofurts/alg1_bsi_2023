#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "abb.h"

static int f_hash(t_chave c) {
	return (c*c + 183) % M;
}

void limpar_hash(t_hash h) {

	for (int i = 0; i < M; i++) {
		limpar(&h[i]);
	}

}

void inicializar_hash(t_hash h) {
	for (int i = 0; i < M; i++) {
		inicializar(&h[i]);
	}	
}

t_chave pesquisar_hash(t_chave c, t_hash h) {

	int pos = f_hash(c);
	return pesquisar(c, &h[pos]);

}

int inserir_hash(t_chave c, t_hash h) {

	int pos = f_hash(c);
	// printf("Inserir %d na posicao %d\n", c, pos);

	return inserir(c, &h[pos]);

}

int remover_hash(t_chave c, t_hash h) {

	int pos = f_hash(c);
	return remover(c, &h[pos]);

}

int vazia_hash(t_hash h) {

	for (int i = 0; i < M; i++)
		if (!vazia(&h[i]))
			return 0;
	return 1;

}

void testa_hash(t_hash h, int pos) {
	em_ordem(&h[pos]);
}

void distr_hash(t_hash h) {

	for (int i = 0; i < M; i++)
		printf("%d - %d elementos\n", i, tam(&h[i]));

}