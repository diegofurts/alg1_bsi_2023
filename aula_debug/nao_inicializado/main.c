#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

int main() {
    pilha_t* p = nova_pilha();

    for (int i = 0; i < 20; i++) {
        empilhar(p, i);
    }

    imprimir(p);

    for (int i = 0; i < 10; i++) {
        desempilhar(p);
    }

    imprimir(p);

    libera_pilha(p);
}