#ifndef TABELA_H_INCLUDED
#define TABELA_H_INCLUDED

typedef struct caracterFreq caracterFreq_t;

caracterFreq_t** ContaFreq(const char* filename, int* num);
int get_freq(caracterFreq_t* p);
void set_freq(caracterFreq_t* p, int value);
char get_character(caracterFreq_t* p);

#endif // TABELA_H_INCLUDED
