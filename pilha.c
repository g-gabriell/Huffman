#include <stdlib.h>
#include <stdio.h>
#include "lista_enc.h"
#include "pilha.h"

struct pilhas {
    lista_enc_t *lista;
};


//cria uma pilha para inteiros
pilha_t * cria_pilha (void)
{
    pilha_t *pilha = (pilha_t*)malloc(sizeof(pilha_t));

    pilha->lista = cria_lista_enc();

    return pilha;
}

//adiciona elemento
void push(void* dado, pilha_t* pilha)
{
    no_t* no = cria_no(dado);
    add_cabeca(pilha->lista, no);
    if(pilha == NULL)
    {
        fprintf(stderr,"pilha invalida!\n");
        exit(EXIT_FAILURE);
    }
}

//retira elemento do topo
void* pop(pilha_t* pilha)
{
    if (pilha == NULL) {
        fprintf(stderr, "pilha invalida!\n");
        return 0;
    }
    if (tamanho(pilha->lista)==0)
        fprintf(stderr,"pilha vazia!\n");
    return remove_cabeca(pilha->lista);
}

void* topo(pilha_t* pilha)
{
    return dado_cabeca(pilha->lista);
}

int tamanhop(pilha_t* pilha)
{
    return tamanho(pilha->lista);
}

int vazia(pilha_t* pilha)
{
    return !tamanho(pilha->lista);
}

void destroi_pilha(pilha_t* pilha)
{
    free (pilha->lista);
    free (pilha);
}


