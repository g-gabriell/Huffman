#ifndef TABELA_H_INCLUDED
#define TABELA_H_INCLUDED

typedef struct caracter caracter_t;

#include "arvore.h"

caracter_t** ContaFreq(const char* filename, int* num, int* num_caracteres);

char get_simbolo(caracter_t* p);
int get_freq(caracter_t* p);
sub_arvore_t* character_get_folha(caracter_t* character);
char* get_code(caracter_t* caracter);

void set_freq(caracter_t* p, int value);
void set_folha(caracter_t* p, sub_arvore_t* folha);

void set_codes(caracter_t** lista_carcteres, int tam_lista);
void character_set_code(caracter_t* character, char* codigo);

void imprime_binario(caracter_t** tabela, arvore_t* arvore, char* filename_input, char* filename_output, int num_caracteres);

void destroi_tabela(caracter_t** tabela, int tam_tabela);

//--------------DECODIFICAÇÃO------------------------


void le_arquivo_binario(char* filename);
int cria_arvore_pre_ordem(char* buffer_arvore,int i, int esq_dir, sub_arvore_t* pai, sub_arvore_t** raiz);

#endif // TABELA_H_INCLUDED
