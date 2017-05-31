#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

struct heap{
    int* A;
};

void inicializa_heap(heap_t* heap, int tam_heap){
    heap->A = (int*) malloc(sizeof(int)*(tam_heap+1));
    heap->A[0] = tam_heap;
}

int pai(int i){
    return i/2;
}

int esquerda(int i){
    return 2*i;
}

int direita(int i){
    return 2*i+1;
}

void min_heapify(heap_t* heap, int i){
    int e = esquerda(i);
    int d = direita(i);
    int temp;

    int menor = i;

    if ((e <= heap->A[0]) && (heap->A[e] < heap->A[i]))
        menor = e;

    if ((d <= heap->A[0]) && (heap->A[d] < heap->A[menor]))
        menor = d;

    if (menor != i)
    {
        temp = heap->A[i];
        heap->A[i] = heap->A[menor];
        heap->A[menor] = temp;
        max_heapify(heap,menor);
    }
}

void build_heap(heap_t* heap){
    int i;
    for (i = (heap->A[0])/2; i>0; i--)
        max_heapify(heap,i);
}

void heapSort(heap_t * heap){
  int tamanho = heap->A[0];
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
    heap->A[0] = tamanho;
}

int tamanho_heap(heap_t* heap){
    return heap->A[0];
}
