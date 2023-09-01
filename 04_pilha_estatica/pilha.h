#ifndef PILHA_H
#define PILHA_H

#define SUCESSO 1
#define NAO_EXISTE -1
#define JA_EXISTE -2
#define INVALIDO -3
#define CHEIA -4
#define VAZIA -5

#define MAX 128

typedef struct {
	int topo;
	int pilha[MAX];
} t_pilha;

void inicializar(t_pilha *P);
int push(int e, t_pilha *P);
int pop(t_pilha *P);
int vazia(t_pilha *P);
int cheia(t_pilha *P);
int topo(t_pilha *P);
int contar(t_pilha *P);

#endif