#ifndef LISTA_H
#define LISTA_H

#define SUCESSO 1
#define NAO_EXISTE -1
#define JA_EXISTE -2
#define INVALIDO -3
#define CHEIA -4
#define VAZIA -5

typedef int t_chave;

typedef struct {
	t_chave chave;
	//char nome[50];
	//qqer outra coisa
} t_elemento;


typedef struct t_no *t_apontador;

typedef struct t_no {
	t_elemento elemento;
	t_apontador proximo;
} t_no;


typedef struct {
	t_apontador primeiro;
	// outras coisas como contador, ultimo, etc
} t_lista;

int inicializar(t_lista *l);
int inserir(t_elemento e, t_lista *l);
int remover(t_chave chave, t_lista *l);
t_elemento pesquisar(t_chave chave, t_lista *l);
int vazia(t_lista *l);
int cheia(t_lista *l);
void imprimir(t_lista *l);

#endif