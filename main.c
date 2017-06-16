#include <stdio.h>
#include <stdlib.h>

#include "include/tabela.h"
#include "include/heap.h"
#include "include/arvore.h"
#include "include/fila.h"

int main()
{
    caracter_t** tabela;
    int tam_tabela;  // tamanho tabela

    arvore_t* arvore;
    int i;

    tabela = ContaFreq("arquivo.txt", &tam_tabela);
//
//printf("  %d caracteres \n", tam_tabela);
//
//    for(i=0;i<tam_tabela;i++)
//        printf("%c -- %d\n", get_simbolo(tabela[i]), get_freq(tabela[i]));
//



    arvore = cria_arvore_huffman(tabela, tam_tabela);



//
//    folhas = cria_folhas(tabela, tam_tabela);
//    heap = inicializa_heap(tam_tabela, folhas);




    return 0;
}
