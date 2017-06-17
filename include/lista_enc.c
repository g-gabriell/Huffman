#include <stdio.h>
#include <stdlib.h>

#include "lista_enc.h"
#include "no.h"

//#define DEBUG

struct listas_enc {
    no_t *cabeca;
    no_t *cauda;
    int tamanho;
};

//cria uma lista vazia
lista_enc_t *cria_lista_enc (void) {

    lista_enc_t *p = malloc(sizeof(lista_enc_t));

    if (p == NULL){
        perror("cria_lista_enc:");
        exit(EXIT_FAILURE);
    }

    p->cabeca = NULL;
    p->cauda = NULL;
    p->tamanho = 0;

    return p;
}

void add_cauda(lista_enc_t *lista, no_t* elemento){

    if (lista == NULL || elemento == NULL){
        fprintf(stderr,"add_cauda: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

   #ifdef DEBUG
   printf("Adicionando na cauda %p --- tamanho: %d\n", elemento, lista->tamanho);
   #endif // DEBUG

   //lista vazia
   if (lista->tamanho == 0)
   {
        #ifdef DEBUG
        printf("add_cauda: add primeiro elemento: %p\n", elemento);
        #endif // DEBUG

        lista->cauda = elemento;
        lista->cabeca = elemento;
        lista->tamanho++;

        desliga_no(elemento);
   }
   else {
        // Remove qualquer ligacao antiga
        desliga_no(elemento);
        // Liga cauda da lista com novo elemento
        liga_nos(lista->cauda, elemento);

        lista->cauda = elemento;
        lista->tamanho++;
   }
}
/*

*/
void add_cabeca(lista_enc_t *lista, no_t* elemento){

    if (lista == NULL || elemento == NULL){
        fprintf(stderr,"add_cabeca: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

   #ifdef DEBUG
   printf("Adicionando na cabeca %p --- tamanho: %d\n", elemento, lista->tamanho);
   #endif // DEBUG

   //lista vazia
   if (lista->tamanho == 0)
   {
        #ifdef DEBUG
        printf("add_cabeca: add primeiro elemento: %p\n", elemento);
        #endif // DEBUG

        lista->cauda = elemento;
        lista->cabeca = elemento;
        lista->tamanho++;

        desliga_no(elemento);

   }
   else {

        liga_nos(elemento, lista->cabeca);

        lista->cabeca = elemento;
        lista->tamanho++;

    }
}

void* remove_cabeca(lista_enc_t *lista){

    if (lista == NULL){
        fprintf(stderr,"remove_cabeca: ponteiro invalido");
        exit(EXIT_FAILURE);
    }

    void* dado = obtem_dado(lista->cabeca);
    no_t* cabeca_antiga = lista->cabeca;

    #ifdef DEBUG
    printf("remove_cabeca: elemento anterior: %p\n", lista->cabeca);
    #endif // DEBUG



    lista->cabeca = obtem_proximo(lista->cabeca);

    lista->tamanho--;

    //desliga_no(cabeca_antiga);

    #ifdef DEBUG
    printf("remove_cabeca: proximo elemento : %p\n", lista->cabeca);
    #endif // DEBUG


    free(cabeca_antiga);

    return dado;
}

int tamanho( lista_enc_t *lista){

    return lista->tamanho;

}

int vazia( lista_enc_t *lista){

    if(lista->tamanho == 0)
        return 1;
    else
        return 0;

}
