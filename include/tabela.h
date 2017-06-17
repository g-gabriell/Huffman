#ifndef TABELA_H_INCLUDED
#define TABELA_H_INCLUDED

typedef struct caracter caracter_t;

#include "arvore.h"

caracter_t** ContaFreq(const char* filename, int* num);

int get_freq(caracter_t* p);
char get_simbolo(caracter_t* p);
sub_arvore_t* character_get_folha(caracter_t* character);

void set_freq(caracter_t* p, int value);
void set_folha(caracter_t* p, sub_arvore_t* folha);
void character_set_code(caracter_t* character, char* codigo);

void imprime_binario(caracter_t** tabela, arvore_t* arvore,char* filename_input,char* filename_output);

#endif // TABELA_H_INCLUDED
