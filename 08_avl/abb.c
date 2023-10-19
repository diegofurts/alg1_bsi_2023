#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

static int max(int a, int b) {
	return a > b ? a : b;
}

static int retorna_h(t_abb *t) {
	if ((*t) == NULL)
		return -1;
	else
		return (*t)->h;
}

static int update_altura(t_abb *t) {
	return max(retorna_h(&(*t)->esq),
						retorna_h(&(*t)->dir)) + 1;
} 

static void rot_dir(t_abb *t) {

	t_apontador aux, A;

	aux = (*t)->esq;
	A = aux->dir;

	(*t)->esq = A;
	aux->dir = (*t);

	(*t)->h = update_altura(&(*t));
	aux->h = update_altura(&(aux));

	// mudar a raiz
	(*t) = aux;

}

static void rot_esq(t_abb *t) {

	t_apontador aux, A;

	aux = (*t)->dir;
	A = aux->esq;

	(*t)->dir = A;
	aux->esq = (*t);

	(*t)->h = update_altura(&(*t));
	aux->h = update_altura(&(aux));


	// mudar a raiz
	(*t) = aux;

}

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
	(*t)->h = 0;

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

		int ret;

		if(c < (*t)->chave)
			ret = inserir(c, &(*t)->esq);
		else
			ret = inserir(c, &(*t)->dir);

		// ajustar
		(*t)->h = update_altura(&(*t));

		int fb = retorna_h(&(*t)->esq) - retorna_h(&(*t)->dir);

		// tratar desbalanceamento
		if (fb > 1) {

			t_apontador esq = (*t)->esq; // com certeza esse no existe! reflitão
			int fb_esq = retorna_h(&(esq->esq)) - retorna_h(&(esq->dir));

			if (fb_esq < 0) { // rot. esq-dir
				printf("Esq-dir\n");
				rot_esq(&esq);
				rot_dir(&(*t));

			} else { // rot. dir
				printf("Dir\n");
				rot_dir(&(*t));
			}

			// if (fb_esq < 0) // rot. esq-dir
			// 	rot_esq(&esq);
			// rot_dir(&(*t));


		} else if (fb < -1) {

			t_apontador dir = (*t)->dir; // com certeza esse no existe! reflitão
			int fb_dir = retorna_h(&(dir->esq)) - retorna_h(&(dir->dir));

			if (fb_dir >= 0) { //rot. dir-esq
				printf("Dir-esq\n");

				rot_dir(&dir);
				rot_esq(&(*t));

			} else { //rot. esq
				printf("Esq\n");
				rot_esq(&(*t));
			}

			// if (fb_dir >= 0) //rot. dir-esq (faz a dir no filho)
			// 	rot_dir(&dir);
			// rot_esq(&(*t));


		}

		return ret;

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
	(*t)->h = update_altura(&(*t));

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

	int ret;

	if(c < (*t)->chave)
		ret = remover(c, &(*t)->esq);
	else
		ret = remover(c, &(*t)->dir);

	// ajustar
	(*t)->h = update_altura(&(*t));

	return ret;

}


int vazia(t_abb *t);

void em_ordem(t_abb *t) {

	if ((*t) == NULL)
		return;

	em_ordem(&(*t)->esq);
	printf("%d (%d);  ", (*t)->chave, (*t)->h);
	em_ordem(&(*t)->dir);

}
