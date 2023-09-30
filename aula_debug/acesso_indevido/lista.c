#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

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

void libera_no(no_t* n) {
    free(n);
}

struct lista {
    no_t* inicio;
    no_t* fim;
};

lista_t* nova_lista() {
    lista_t* l = malloc(sizeof(lista_t));

    l->inicio = l->fim = NULL;

    return l;
}

void libera_lista(lista_t* l) {
    no_t* n = l->inicio;

    while (n != NULL) {
        no_t* prox = n->proximo;
        libera_no(n);
        n = prox;
    }
    
    free(l);
}

int vazia(lista_t* l) {
    return l->inicio == NULL;
}

void inserir(lista_t* l, int valor) {
    no_t* n = novo_no(valor);

    if (vazia(l)) {
        l->inicio = n;
    } else {
        l->fim->proximo = n;
    }

    l->fim = n;
}

void remover(lista_t* l, int indice) {
    if (vazia(l)) {
        return;
    }

    no_t* n = l->inicio;
    no_t* anterior = NULL;
    for (int i = 0; i < indice; i++) {
        anterior = n;
        n = n->proximo;

        if (n == NULL) {
            return;
        }
    }

    if (l->inicio == l->fim) {
        l->inicio = NULL;
        l->fim = NULL;
    } else {
        anterior->proximo = n->proximo;
    }

    libera_no(n);
}

void imprimir(lista_t* l) {
    no_t* n = l->inicio;

    printf("[");
    while (n != NULL) {
        printf("%d", n->valor);
        n = n->proximo;

        if (n != NULL) printf(", ");
    }
    printf("]\n");
}