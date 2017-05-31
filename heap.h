#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include "tabela.h"

typedef struct heap heap_t;

heap_t* inicializa_heap(int tamanho_heap, caracterFreq_t** tabela);

void build_heap(heap_t* heap);

void min_heapify(heap_t* heap, int i);

int pai(int i);

#endif // HEAP_H_INCLUDED
