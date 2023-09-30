#ifndef PILHA_H
#define PILHA_H

typedef struct no no_t;

no_t* novo_no(int valor);

typedef struct pilha pilha_t;

pilha_t* nova_pilha();
void libera_pilha(pilha_t* f);
void empilhar(pilha_t* f, int valor);
void desempilhar(pilha_t* f);
int vazia(pilha_t* f);
void imprimir(pilha_t* f);

#endif