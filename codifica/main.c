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
    int num_caracteres;

    tabela = ContaFreq("arquivo.txt", &tam_tabela, &num_caracteres);
    arvore = cria_arvore_huffman(tabela, tam_tabela);

#ifdef DEBUG
    int i;
    printf("  %d caracteres totais\n", num_caracteres);
    printf("  %d caracteres diferentes\n", tam_tabela);
    for(i=0;i<tam_tabela;i++)
        printf("%c -- %d -- %02x -- %s \n", get_simbolo(tabela[i]), get_freq(tabela[i]), character_get_folha(tabela[i]), get_code(tabela[i]));
#endif

    imprime_binario(tabela, arvore, "arquivo.txt", "arvore.txt", num_caracteres);

    destroi_arvore(arvore);
    destroi_tabela(tabela, tam_tabela);

    return 0;
}
