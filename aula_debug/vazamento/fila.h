#ifndef FILA_H
#define FILA_H

typedef struct no no_t;

no_t* novo_no(int valor);

typedef struct fila fila_t;

fila_t* nova_fila();
void libera_fila(fila_t* f);
void enfileirar(fila_t* f, int valor);
void desenfileirar(fila_t* f);
int vazia(fila_t* f);
void imprimir(fila_t* f);

#endif