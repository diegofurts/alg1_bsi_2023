#include <stdio.h>
#include <string.h>

#include "hash.h"

int main() {

	t_hash H;

	inicializar_hash(H);

	// inserir_hash(15, H);
	// inserir_hash(150, H);
	// inserir_hash(105, H);
	// inserir_hash(321, H);
	// inserir_hash(123, H);
	// inserir_hash(5, H);
	// inserir_hash(15, H);

	for (int i = 0; i < 555; i++) 
		inserir_hash(i, H);

	// printf("%d\n", pesquisar_hash(234235, H));
	// testa_hash(H, 0);

	distr_hash(H);

	// remover_hash(12, H);
	// remover_hash(557, H);
	// remover_hash(12, H);

	limpar_hash(H);

}