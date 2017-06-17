#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include "lista_enc.h"

typedef struct pilhas pilha_t;

pilha_t * cria_pilha (void);
void destroi_pilha(pilha_t* pilha);

void push(void* dado, pilha_t *pilha);
void* pop(pilha_t *pilha);
int tamanho_pilha(pilha_t *pilha);
int pilha_vazia(pilha_t *pilha);

#endif // PILHA_H_INCLUDED
