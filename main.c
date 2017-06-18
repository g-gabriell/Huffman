#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/tabela.h"
#include "include/heap.h"
#include "include/arvore.h"
#include "include/pilha.h"
#include "include/lista_enc.h"

#define DEBUG

int main()
{
    caracter_t** tabela;
    arvore_t* arvore;
    int tam_tabela;

    tabela = ContaFreq("arquivo.txt", &tam_tabela);
    arvore = cria_arvore_huffman(tabela, tam_tabela);
//    imprime_binario( caracter_t** tabela, arvore_t* arvore, char* nome_arquivo_entrada, char* nome_arquivo_binario);

    #ifdef DEBUG
    int i;
    printf("  %d caracteres \n", tam_tabela);
    for(i=0;i<tam_tabela;i++)
        printf("%c -- %d\n", get_simbolo(tabela[i]), get_freq(tabela[i]));

    for(i=0;i<tam_tabela;i++)
        printf(" %c -- %s    \n ", get_simbolo(tabela[i]), get_code(tabela[i]));//        cria_binario(character_get_folha(tabela[i])));
    #endif

 //   destroi_arvore(arvore);
 //   destroi_tabela(tabela);

    return 0;
}
