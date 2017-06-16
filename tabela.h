#ifndef TABELA_H_INCLUDED
#define TABELA_H_INCLUDED

typedef struct caracter caracter_t;

caracter_t** ContaFreq(const char* filename, int* num);
int get_freq(caracter_t* p);
void set_freq(caracter_t* p, int value);
char get_simbolo(caracter_t* p);

#endif // TABELA_H_INCLUDED
