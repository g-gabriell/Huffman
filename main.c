#include <stdio.h>
#include <stdlib.h>

#include "tabela.h"
#include "heap.h"

int main()
{
    caracterFreq_t** tabela;
    int i, n;

    tabela = ContaFreq("arquivo.txt", &n);

    printf("  %d caracteres \n", n);

    for(i=0;i<n;i++)
        printf("%c -- %d\n", get_character(tabela[i]), get_freq(tabela[i]));


    heap_t* heap;

    heap = inicializa_heap(n, tabela);


  //  min_heapify(heap, n/2);

  printf("\n\n ");

    for(i=0;i<n;i++)
        printf("%c -- %d\n", get_character(tabela[i]), get_freq(tabela[i]));

    return 0;
}
