#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

struct heap{
    int* A;
    int tam_heap;
    int tamanhomaximo;
};

void inicializa_heap(heap_t* heap, int tamanho_max){
    heap->A = (int*) malloc(sizeof(int)*(tamanho_max+1));
    heap->tam_heap = 0;
    heap->tamanhomaximo = tamanho_max;
}

int pai(int i){
    if(i == 1)
        return NULL;
    return i/2;
}

int esquerda(int i){
    return 2*i;
}

int direita(int i){
    return 2*i+1;
}

void max_heapify(heap_t* heap, int i){
    int e = esquerda(i);
    int d = direita(i);
    int temp;

    int maior = i;

    if ((e <= heap->tam_heap) && (heap->A[e] > heap->A[i]))
        maior = e;

    if ((d <= heap->tam_heap) && (heap->A[d] > heap->A[maior]))
        maior = d;

    if (maior != i)
    {
        temp = heap->A[i];
        heap->A[i] = heap->A[maior];
        heap->A[maior] = temp;
        max_heapify(heap,maior);
    }
}

void build_heap(heap_t* heap){
    int i;
    for (i = (heap->tam_heap)/2; i>0; i--)
        max_heapify(heap,i);
}

void heapSort(heap_t * heap){
  int tamanho = heap->tam_heap;
  int i;
  int temp;

  build_heap(heap);

  for (i=tamanho; i > 1; i--){
     temp = heap->A[1];
     heap->A[1] = heap->A[i];
     heap->A[i] = temp;

     set_tamanho_heap(heap, tamanho_heap(heap) - 1);
     max_heapify(heap, 1);
  }
}

void set_tamanho_heap(heap_t* heap, int tamanho){
    heap->tam_heap = tamanho;
}

int tamanho_heap(heap_t* heap){
    return heap->tam_heap;
}
