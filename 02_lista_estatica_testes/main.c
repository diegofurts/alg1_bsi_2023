#include <stdio.h>
#include <string.h>

#include "lista.h"

int main() {

	t_lista l1, l2;
	t_elemento e;
	int n, m;

	inicializar(&l1);
	inicializar(&l2);

	scanf("%d ", &n);
	for (int i=0; i < n; i++) {
		scanf("%d ", &e.chave);
		inserir(e, &l1);
	}

	imprimir(&l1);

	scanf("%d ", &m);
	split(&l1, m, &l2);

	imprimir(&l1);
	imprimir(&l2);

}