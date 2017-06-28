#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "include/tabela.h"
#include "include/heap.h"
#include "include/arvore.h"
#include "include/pilha.h"
#include "include/lista_enc.h"


//#define DEBUG

int main()
{
    clock_t start, end;
    double cpu_time_used;

    printf("digite o nome do arquivo a ser descompactado\n");
    char arquivo[200];
    scanf("%s",arquivo);

    start = clock();
    le_arquivo_binario(arquivo);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\n%lf", cpu_time_used);

    return 0;
}
