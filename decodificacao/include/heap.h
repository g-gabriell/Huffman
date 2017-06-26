#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include "tabela.h"
#include "arvore.h"

typedef struct heap heap_t;

heap_t* inicializa_heap(int tamanho_heap, sub_arvore_t** folhas);

void build_heap(heap_t* heap);

void min_heapify(heap_t* heap, int i);

void heapSort(heap_t * heap);

int pai(int i);

int get_tam_heap(heap_t* heap);

sub_arvore_t* retira_menor(heap_t* heap);
void heap_insere(heap_t* heap, sub_arvore_t* sub_arvore);

void destroi_heap(heap_t* heap);

#endif // HEAP_H_INCLUDED
