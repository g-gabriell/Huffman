#include <stdio.h>
#include <stdlib.h>

#include "include/tabela.h"
#include "include/heap.h"
#include "include/arvore.h"
#include "include/fila.h"

int main()
{
    caracterFreq_t** tabela;
    int n;  // tamanho tabela
    int i;

    heap_t* heap;

    tabela = ContaFreq("arquivo.txt", &n);

    printf("  %d caracteres \n", n);

    for(i=0;i<n;i++)
        printf("%c -- %d\n", get_character(tabela[i]), get_freq(tabela[i]));

    heap = inicializa_heap(n, tabela);

    heapSort(heap);

    printf("\n\n ");
    for(i=0;i<n;i++)
        printf("%c -- %d\n", get_character(tabela[i]), get_freq(tabela[i]));




    return 0;
}
