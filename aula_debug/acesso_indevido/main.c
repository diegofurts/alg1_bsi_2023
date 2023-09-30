#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main() {
    lista_t* l = nova_lista();

    for (int i = 0; i < 20; i++) {
        inserir(l, i);
    }

    imprimir(l);

    remover(l, 0);
    remover(l, 10);
    remover(l, 17);

    imprimir(l);

    libera_lista(l);
}