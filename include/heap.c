#include <stdio.h>
#include <stdlib.h>

#include "heap.h"


struct heap
{
    caracter_t** A;
    int tam_heap;
};


heap_t* inicializa_heap(int tamanho_heap, caracter_t** tabela)
{
    heap_t* heap;
    heap = malloc(sizeof(heap_t));

    heap->A = tabela;
    heap->tam_heap = tamanho_heap;

    build_heap(heap);

    return heap;
}

int pai(int i)
{
    return (i-1)/2;
}

int esquerda(int i)
{
    return 2*i + 1;
}

int direita(int i)
{
    return 2*i + 2;
}

void min_heapify(heap_t* heap, int i)
{
    int e = esquerda(i);
    int d = direita(i);
    caracter_t* temp;

    int menor = i;

    if ((e < heap->tam_heap) && (get_freq(heap->A[e]) < get_freq(heap->A[i])))
    {
//        printf("\n %d troca %d", (get_freq(heap->A[e]), get_freq(heap->A[i])));
        menor = e;
    }

    if ((d < heap->tam_heap) && (get_freq(heap->A[d]) < get_freq(heap->A[menor])))
    {
//        printf("\n %d troca %d", (get_freq(heap->A[d]), get_freq(heap->A[menor])));
        menor = d;
    }

    if (menor != i)
    {
//printf("entrou %d  %d  %d\n",i, get_freq(heap->A[i]),get_freq(heap->A[menor]) );
        temp = heap->A[i];
        heap->A[i] = heap->A[menor];
        heap->A[menor] = temp;
        min_heapify(heap,menor);
    }
}

void build_heap(heap_t* heap)
{
    int i;
    for (i = ((heap->tam_heap/2) - 1); i>=0; i--)
        min_heapify(heap,i);
}

void heapSort(heap_t * heap)
{
    int tamanho = heap->tam_heap-1;
    int i;
    caracter_t* temp;

 //   build_heap(heap);

    for (i=tamanho; i > 0; i--)
    {
        temp = heap->A[0];
        heap->A[0] = heap->A[i];
        heap->A[i] = temp;

        heap->tam_heap--;
        min_heapify(heap, 0);
    }
}

void set_tamanho_heap(heap_t* heap, int tamanho)
{
    heap->tam_heap = tamanho;
}

int tamanho_heap(heap_t* heap)
{
    return heap->tam_heap;
}



