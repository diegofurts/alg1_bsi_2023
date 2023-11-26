#ifndef HASH_H
#define HASH_H

#include "abb.h"

#define SUCESSO 1
#define NAO_EXISTE -1
#define JA_EXISTE -2
#define INVALIDO -3
#define CHEIA -4
#define VAZIA -5

#define M 97

typedef int t_chave;

typedef t_abb t_hash[M];


void limpar_hash(t_hash h);
void inicializar_hash(t_hash h);
t_chave pesquisar_hash(t_chave c, t_hash h);
int inserir_hash(t_chave c, t_hash h);
int remover_hash(t_chave c, t_hash h);
int vazia_hash(t_hash h);
void testa_hash(t_hash h, int pos);
void distr_hash(t_hash h);

// alterar

#endif