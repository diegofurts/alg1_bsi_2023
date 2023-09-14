#ifndef LISTA_H
#define LISTA_H

#define SUCESSO 1
#define NAO_EXISTE -1
#define JA_EXISTE -2
#define INVALIDO -3
#define CHEIA -4
#define VAZIA -5

typedef struct t_no *t_apontador;

typedef struct t_no {
	int elemento;
	t_apontador proximo;
} t_no;


typedef struct {
	t_apontador topo;
	int count;
	// outras coisas como contador, ultimo, etc
} t_pilha;


int inicializar(t_pilha *P);
int push(int e, t_pilha *P);
int pop(t_pilha *P);
int vazia(t_pilha *P);
int cheia(t_pilha *P);
int topo(t_pilha *P);
int contar(t_pilha *P);

#endif