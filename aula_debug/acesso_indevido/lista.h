#ifndef LISTA_H
#define LISTA_H

typedef struct no no_t;

no_t* novo_no(int valor);
void libera_no(no_t* n);

typedef struct lista lista_t;

lista_t* nova_lista();
void libera_lista(lista_t* l);
void inserir(lista_t* l, int valor);
void remover(lista_t* l, int indice);
int vazia(lista_t* l);
void imprimir(lista_t* l);

#endif