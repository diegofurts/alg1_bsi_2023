#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

struct no {
    no_t* proximo;
    int valor;
};

no_t* novo_no(int valor) {
    no_t* n = malloc(sizeof(no_t));

    n->proximo = NULL;
    n->valor = valor;

    return n;
}

struct fila {
    no_t* inicio;
    no_t* fim;
};

fila_t* nova_fila() {
    fila_t* f = malloc(sizeof(fila_t));

    f->inicio = f->fim = NULL;

    return f;
}

void libera_fila(fila_t* f) {
    free(f);
}

int vazia(fila_t* f) {
    return f->inicio == NULL;
}

void enfileirar(fila_t* f, int valor) {
    no_t* n = novo_no(valor);

    if (vazia(f)) {
        f->inicio = n;
    } else {
        f->fim->proximo = n;
    }

    f->fim = n;
}

void desenfileirar(fila_t* f) {
    if (vazia(f)) {
        return;
    }

    no_t* n = f->inicio;

    if (f->inicio == f->fim) {
        f->inicio = NULL;
        f->fim = NULL;
    } else {
        f->inicio = n->proximo;
    }
}

void imprimir(fila_t* f) {
    no_t* n = f->inicio;

    printf("[");
    while (n != NULL) {
        printf("%d", n->valor);
        n = n->proximo;

        if (n != NULL) printf(", ");
    }
    printf("]\n");
}