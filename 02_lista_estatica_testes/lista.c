#include <stdio.h>
#include "lista.h"

int inicializar(t_lista *l) {
	l->ultimo = -1;
}

int inserir(t_elemento e, t_lista *l) {

	if (cheia(l)) {
		printf("Erro, lista cheia\n");
		return CHEIA;
	}

	// if (pesquisar(e.chave, l) >= 0) {
	// 	printf("Chave ja existe\n");
	// 	return JA_EXISTE;
	// }

	l->ultimo++;
	l->lista[l->ultimo] = e;

	return SUCESSO;

}


int remover(t_chave chave, t_lista *l) {

	int pos = pesquisar(chave, l);

	if (pos < 0) {
		printf("Chave nao existe\n");
		return NAO_EXISTE;
	}

	l->lista[pos] = l->lista[l->ultimo];
	l->ultimo--;

	// for (int i = pos;i < l->ultimo; i++)
	// 	l->lista[i] = l->lista[i+1];


	return SUCESSO;

}

int pesquisar(t_chave chave, t_lista *l){

	for (int i = 0; i <= l->ultimo; i++) {
		if (l->lista[i].chave  == chave) {
			return i;
		}
	}

	return NAO_EXISTE;

} 

int vazia(t_lista *l) {
	if (l->ultimo == -1)
		return 1;
	else	
		return 0;
}

int cheia(t_lista *l) {

	if (l->ultimo == MAX-1)
		return 1;
	else	
		return 0;

}

void imprimir(t_lista *l) {

	for (int i = 0; i <= l->ultimo; i++) {
		printf("%d, ", 
			l->lista[i].chave);
	}
	printf("\n");

}

int concatenar(t_lista *l1, t_lista *l2) {

	if ( (l1->ultimo + l2->ultimo + 2) > MAX) {
		printf("Nao da certo! Nao cabe! Pare com isso!\n");
		return CHEIA;
	}

	// testar se vazia a l2, não precisa, mas...

	for (int i = 0; i <= l2->ultimo; i++) {

		// l1->ultimo++;
		// l1->lista[l1->ultimo] = l2->lista[i];
		inserir(l2->lista[i], l1);

	}

	return SUCESSO;

}

int split(t_lista *l1, t_chave chave, t_lista *l2) {

	int pos = pesquisar(chave, l1);

	if (pos == NAO_EXISTE) {
		printf("Nao achou essa chave\n");
		return NAO_EXISTE;
	}

	// pensar em primeiro e ultimo

	inicializar(l2); //just in case
	for (int i = pos+1; i <= l1->ultimo; i++)
		inserir(l1->lista[i], l2);

	l1->ultimo = pos;

}
