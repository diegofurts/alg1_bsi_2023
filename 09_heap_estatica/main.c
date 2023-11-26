#include <stdio.h>
#include <string.h>

#define MAX 128

typedef int t_heap[MAX+1];


void inicializa(t_heap h) {
	h[0] = 0;
}

int vazia(t_heap h) {
	return (h[0] == 0);
}

int cheia(t_heap h) {
	return (h[0] == MAX);
}

void bubble_up(t_heap h, int pos) {

	if (pos == 1)
		return;

	if (h[pos] < h[pos/2]) {

		// swap
		int aux;
		aux = h[pos];
		h[pos] = h[pos/2];
		h[pos/2] = aux;

		// chamo recursivo
		bubble_up(h, (int)pos/2);

	}

	return;

}

void bubble_down(t_heap h, int pos) {

	int menor = h[pos];
	int menor_pos = pos;

	// filho esq
	int fe = pos*2;

	if ( (fe <= h[0]) &&
		(h[fe] < menor) ) {
		menor = h[fe];
		menor_pos = fe;
	}

	// filho dir
	int fd = (pos*2) + 1;

	if ( (fd <= h[0]) &&
		(h[fd] < menor) ) {
		menor = h[fd];
		menor_pos = fd;
	}

	
	if (menor_pos != pos) { // troca e chama recursivo

		h[menor_pos] = h[pos];
		h[pos] = menor;

		bubble_down(h, menor_pos);

	}

	return;

}

void ins(t_heap h, int chave) {

	if (cheia(h)) {
		// posso fazer o realloc
		printf("Nao cabe mais nada, pra mim ja deu\n");
		return;
	}

	int pos = h[0] + 1;

	h[pos] = chave;
	h[0]++;
	bubble_up(h, h[0]);

	return;

}

void rem(t_heap h) {

	if (vazia(h)) {
		printf("Nao tem nada mais para remover\n");
		return;
	}

	int pos = h[0];

	// raiz recebe valor do ultimo
	h[1] = h[pos];
	h[0]--;
	bubble_down(h, 1);

}

int proximo(t_heap h) {

	if (!vazia(h)) {
		return h[1];
	} else {
		printf("Esta vazia, nao tem ngm aqui\n");
		return -5162537;
	}

}

int main() {

	t_heap h;
	inicializa(h);

	//crie uma heap a partir das inserções de chaves 1, 9, 3, 5, 7, 8, 2, 6, 4
	ins(h, 9);
	ins(h, 1);

	printf("O tamanho está 2? %d\n", h[0]);
	printf("O proximo eh o 1? %d\n", h[1]);

	ins(h, 3);
	ins(h, 5);

	printf("O tamanho está 4? %d\n", h[0]);

	ins(h, 7);
	ins(h, 8);
	ins(h, 2);
	ins(h, 6);
	ins(h, 4);
	printf("O tamanho está 9? %d\n", h[0]);

	rem(h);
	printf("O proximo eh o ...? %d\n", proximo(h));
	rem(h);
	printf("O proximo eh o ...? %d\n", proximo(h));
	rem(h);
	printf("O proximo eh o ...? %d\n", proximo(h));
	rem(h);
	printf("O proximo eh o ...? %d\n", proximo(h));
	rem(h);
	printf("O proximo eh o ...? %d\n", proximo(h));
	rem(h);
	printf("O proximo eh o ...? %d\n", proximo(h));
	rem(h);
	printf("O proximo eh o ...? %d\n", proximo(h));
	rem(h);
	printf("O proximo eh o ...? %d\n", proximo(h));
	rem(h);
	printf("O proximo eh o ...? %d\n", proximo(h));
	rem(h);
	printf("O proximo eh o ...? %d\n", proximo(h));
	rem(h);
	printf("O proximo eh o ...? %d\n", proximo(h));

}