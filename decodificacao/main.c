#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/tabela.h"
#include "include/heap.h"
#include "include/arvore.h"
#include "include/pilha.h"
#include "include/lista_enc.h"

//#define DEBUG

int main()
{
    printf("digite o nome do arquivo a ser descompactado\n");
    char arquivo[200];
    scanf("%s",arquivo);

    le_arquivo_binario(arquivo);

    return 0;
}
