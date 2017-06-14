#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

#include "fila.h"


typedef struct arvore arvore_t;
typedef struct sub_arvore sub_arvore_t;

sub_arvore_t* cria_folhas(caracter_t** lista, int tam);

//sub_arvore_t* cria_sub_arvore


int folha_get_freq(sub_arvore_t* folha, int i);
char* folha_get_id(sub_arvore_t* folha, int i);

void swap_folhas(sub_arvore_t* folha, int i, int j);

#endif // ARVORE_H_INCLUDED
