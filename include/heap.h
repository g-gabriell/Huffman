#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include "tabela.h"
#include "arvore.h"

typedef struct heap heap_t;

sub_arvore_t* heap_get_sub_arvore(heap_t* heap,int tamanho);

heap_t* inicializa_heap(int tamanho_heap, sub_arvore_t* folhas);

void build_heap(heap_t* heap);

void min_heapify(heap_t* heap, int i);

void heapSort(heap_t * heap);

int pai(int i);

#endif // HEAP_H_INCLUDED
