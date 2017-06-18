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

void set_codes(caracter_t** lista_carcteres, int tam_lista);
void character_set_code(caracter_t* character, char* codigo);
char* get_code(caracter_t* caracter);

#endif // TABELA_H_INCLUDED
