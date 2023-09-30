#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

int main() {
    fila_t* f = nova_fila();

    for (int i = 0; i < 20; i++) {
        enfileirar(f, i);
    }

    imprimir(f);

    for (int i = 0; i < 10; i++) {
        desenfileirar(f);
    }

    imprimir(f);

    libera_fila(f);
}