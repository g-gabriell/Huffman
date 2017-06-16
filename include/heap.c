#include <stdio.h>
#include <stdlib.h>

#include "heap.h"
#include "arvore.h"


struct heap
{
    sub_arvore_t** A;
    int tam_heap;
};


heap_t* inicializa_heap(int tamanho_heap, sub_arvore_t** folhas)
{
    heap_t* heap;
    heap = malloc(sizeof(heap_t));

    heap->A = folhas;
    heap->tam_heap = tamanho_heap;

    printf("INICIALIZA HEAP\n");
    build_heap(heap);

    int i;

    printf("TAMANHO HEAP %d\n", heap->tam_heap);

    for(i=0;i<heap->tam_heap;i++)
        printf("%d : %c -- %d\n", i, sub_arvore__get_id(heap->A[i]), sub_arvore_get_freq(heap->A[i]));

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
    int menor = i;


    if ((e < heap->tam_heap) && (sub_arvore_get_freq(heap->A[e]) < sub_arvore_get_freq(heap->A[i])))
    {
        #ifdef DEBUG
        printf("\n %d troca %d", (get_freq(heap->A[e]), get_freq(heap->A[i])));
        printf("entrou %d, %d e %d\n", i, e, menor);
        printf("freq %d e %d",sub_arvore_get_freq(heap->A[e]), sub_arvore_get_freq(heap->A[i]));
        #endif // DEBUG
        menor = e;
    }

    if ((d < heap->tam_heap) && (sub_arvore_get_freq(heap->A[d]) < sub_arvore_get_freq(heap->A[menor]) ))
    {
        #ifdef DEBUG
        printf("entrou %d, %d e %d\n", i, d, menor);
        #endif // DEBUG
        menor = d;
    }

    if (menor != i)
    {
        swap_sub_arvore(&(heap->A[i]), &(heap->A[menor]));
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

//    build_heap(heap);

    for (i=tamanho; i > 0; i--)
    {

        swap_sub_arvore(&(heap->A[0]), &(heap->A[i]));

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

/*
void retira_menor(heap_t* heap){

    build_heap(heap);
    set_tamanho_heap(heap, heap->tam_heap-1);

//    return heap->A[heap->tam_heap];
}*/

