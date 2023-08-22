#include <stdio.h>
#include "conjunto.h"

int main() {

	t_conjunto A, B, C;

	inicializar(A);

	inserir(50, A);
	inserir(13, A);
	inserir(22, A);
	inserir(17, A);

	inicializar(B);

	inserir(246, B);
	inserir(759, B);
	inserir(12, B);
	inserir(50, B);

	interseccao(A, B, C);
	imprimir(C);

	uniao(A, B, C);
	imprimir(C);

	// inserir(50, A);
	// inserir(13, A);
	// inserir(22, A);
	// inserir(17, A);
	// inserir(50, A);
	// inserir(1000, A);
	// inserir(5000, A);
	// inserir(-5, A);

	// imprimir(A);

	// remover(1000, A);
	// remover(-5, A);
	// remover(17, A);
	// remover(22, A);
	// remover(13, A);
	// remover(2, A);

	// imprimir(A);

}

