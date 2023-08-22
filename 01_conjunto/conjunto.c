#include <stdio.h>
#include <string.h>

#include "conjunto.h"

void inicializar(t_conjunto A) {
	memset(A, 0 , sizeof(t_conjunto));
}

static char esta_nos_limites_essa_coisa(t_elemento e) {

	if (e < 0 || e > maximo) {
		printf("Valor %d invalido.\n", e);
		return 0;
	}

	return 1;

}

int pertence(t_elemento e, t_conjunto A) {

	if (!esta_nos_limites_essa_coisa(e)) 
		return INVALIDO;

	return A[e];
}

int inserir(t_elemento e, t_conjunto A) {

	if (!esta_nos_limites_essa_coisa(e))
		return INVALIDO;

	if (pertence(e, A)) {
		printf("Esse cara %d ja existe.\n", e);
		return JA_EXISTE;
	}

	A[e] = 1;
	return SUCESSO;

}

int remover(t_elemento e, t_conjunto A) {

	if (!esta_nos_limites_essa_coisa(e))
		return INVALIDO;

	if (!pertence(e, A)) {
		printf("Esse cara %d nao existe.\n", e);
		return NAO_EXISTE;
	}

	A[e] = 0;
	return SUCESSO;

}


void interseccao(t_conjunto A, t_conjunto  B, t_conjunto C) {

	for (int i = 0; i < maximo; i++) {
		C[i] = A[i] && B[i];
	}

}

void uniao(t_conjunto A, t_conjunto  B, t_conjunto C) {

	for (int i = 0; i < maximo; i++) {
		C[i] = A[i] || B[i];
	}

}

void imprimir(t_conjunto A) {

	printf("{");

	for (int i = 0; i < maximo; i++) {
		if (pertence(i, A)) {
			printf("%d, ", i);
		}
	}

	printf("}\n");

}