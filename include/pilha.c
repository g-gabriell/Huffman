#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"
#include "lista_enc.h"
#include "no.h"


struct pilhas {
    lista_enc_t* lista;
};


pilha_t* cria_pilha (void)
{

    pilha_t* pilha = malloc(sizeof(pilha_t));// = NULL;
    if(pilha == NULL){
        perror("cria_pilha:");
        exit(EXIT_FAILURE);
    }
    pilha->lista = cria_lista_enc();

    return pilha;
}

void push(void* dado, pilha_t *pilha)
{
    no_t* elemento;
    elemento = cria_no(dado);
    add_cabeca( pilha->lista, elemento);

}

void* pop(pilha_t *pilha)
{
    void* dado;
    dado = remove_cabeca(pilha->lista);

    return dado;
}

int tamanho_pilha(pilha_t *pilha)
{
    return tamanho(pilha->lista);
}

int pilha_vazia(pilha_t *pilha)
{
    return vazia(pilha->lista);
}

void destroi_pilha(pilha_t* pilha)
{
    free (pilha->lista);
    free (pilha);
}
