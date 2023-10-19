#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

void limpar(t_abb *t) { // limpar memoria (free em tudo)

	if ((*t) == NULL)
		return;

	limpar(&(*t)->esq);
	limpar(&(*t)->dir);
	free((*t));

}

void inicializar(t_abb *t) {
	*t = NULL;
}

t_chave pesquisar(t_chave c, t_abb *t) {

	if ((*t) == NULL) {
		printf("NAO!\n");
		return NAO_EXISTE;
	}

	if (c == (*t)->chave) {

		printf("Chave encontrada\n");
		return (*t)->chave; // eu retornaria o elemento todo

	} else {

		if(c < (*t)->chave) {
			return pesquisar(c, &(*t)->esq);
		} else {
			return pesquisar(c, &(*t)->dir);
		}

	}

}

static int cria_raiz(t_chave c, t_abb *t) {

	(*t) = (t_abb) malloc(sizeof(t_no));
	if (*t == NULL) {
		printf("Memoria cheia\n");
		return CHEIA;
	}

	(*t)->chave = c;
	(*t)->dir = NULL;
	(*t)->esq = NULL;

	return SUCESSO;

}

int inserir(t_chave c, t_abb *t) {

	if ((*t) == NULL) {
		return cria_raiz(c, t);
	}

	if (c == (*t)->chave) {

		printf("Chave já inserida\n");
		return JA_EXISTE;

	} else {

		if(c < (*t)->chave) {
			return inserir(c, &(*t)->esq);
		} else {
			return inserir(c, &(*t)->dir);
		}

	}

}

static void achaMaiorEsqTroca(t_abb *t, t_abb *sub_t) {

	if ((*sub_t)->dir == NULL) {
		
		t_apontador p = *sub_t;
		(*t)->chave = (*sub_t)->chave;
		
		(*sub_t) = (*sub_t)->esq;

		free(p);

		return;
	}

	achaMaiorEsqTroca(t, &(*sub_t)->dir);

}

int remover(t_chave c, t_abb *t) {

	if ((*t) == NULL) {
		printf("Nao pode remover o que nao existe. Reflitao!\n");
		return NAO_EXISTE;
	}

	// tratar quando acha
	if (c == (*t)->chave) {

		t_apontador p;

		//caso 1
		if ((*t)->esq == NULL &&
			(*t)->dir == NULL) {

			p = *t;
			*t = NULL;
			free(p);

			return SUCESSO;
		}

		//caso 2 (esq)
		if ((*t)->dir == NULL) {

			p = *t;
			*t = p->esq;
			free(p);

			return SUCESSO;
		} 
		//caso 2 (dir)
		if ((*t)->esq == NULL) {

			p = *t;
			*t = p->dir;
			free(p);

			return SUCESSO;
		}

		//caso 3
		achaMaiorEsqTroca(&(*t), &(*t)->esq);
		return SUCESSO;

	}

	if(c < (*t)->chave) {
		return remover(c, &(*t)->esq);
	} else {
		return remover(c, &(*t)->dir);
	}

}


int vazia(t_abb *t);

void em_ordem(t_abb *t) {

	if ((*t) == NULL)
		return;

	em_ordem(&(*t)->esq);
	printf("%d ", (*t)->chave);
	em_ordem(&(*t)->dir);

}
