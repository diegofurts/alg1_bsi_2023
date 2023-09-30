#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

struct no {
    int valor;
    no_t* proximo;
};

no_t* novo_no(int valor) {
    no_t* n = malloc(sizeof(no_t));

    n->proximo = NULL;

    return n;
}

void libera_no(no_t* n) {
    free(n);
}

struct pilha {
    no_t* inicio;
    no_t* fim;
};

pilha_t* nova_pilha() {
    pilha_t* p = malloc(sizeof(pilha_t));
    p->inicio = NULL;
    p->fim = NULL;

    return p;
}

void libera_pilha(pilha_t* p) {
    no_t* n = p->inicio;

    while (n != NULL) {
        no_t* prox = n->proximo;
        libera_no(n);
        n = prox;
    }
    
    free(p);
}

int vazia(pilha_t* p) {
    return p->inicio == NULL;
}

void empilhar(pilha_t* p, int valor) {
    no_t* n = novo_no(valor);

    if (vazia(p)) {
        p->inicio = n;
    } else {
        p->fim->proximo = n;
    }

    p->fim = n;
}

void desempilhar(pilha_t* p) {
    if (vazia(p))
        return;

    no_t* n = p->fim;

    if (p->inicio == p->fim) {
        p->inicio = NULL;
        p->fim = NULL;
    } else {
        no_t* temp = p->inicio;

        while (temp->proximo != p->fim) {
            temp = temp->proximo;
        }

        p->fim = temp;
        temp->proximo = NULL;
    }

    libera_no(n);
}

void imprimir(pilha_t* p) {
    no_t* n = p->inicio;

    printf("[");
    while (n != NULL) {
        printf("%d", n->valor);
        n = n->proximo;

        if (n != NULL) printf(", ");
    }
    printf("]\n");
}