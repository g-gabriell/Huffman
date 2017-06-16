#include <stdio.h>
#include <stdlib.h>

#include "heap.h"
#include "arvore.h"

#define DEBUG

struct arvore{
    sub_arvore_t* raiz;
};

struct sub_arvore{
    char   id;
    int     freq;

    sub_arvore_t* pai;
    sub_arvore_t* f_esq;
    sub_arvore_t* f_dir;
};


arvore_t* cria_arvore_huffman(caracter_t** lista_carcteres,int tam_lista){

    arvore_t* arvore;
    sub_arvore_t** folhas;
    heap_t* heap;

    arvore = malloc(sizeof(arvore_t));
    folhas = cria_folhas(lista_carcteres, tam_lista);

    int i;
    for(i=0;i<tam_lista;i++)
        printf("%c -- %d\n", sub_arvore__get_id(folhas[i]), sub_arvore_get_freq(folhas[i]));

    heap = inicializa_heap(tam_lista, folhas);

    sub_arvore_t* filho_e;
    sub_arvore_t* filho_d;
    sub_arvore_t* pai;

    while(get_tam_heap(heap) > 1){

        filho_e = retira_menor(heap);
        filho_d = retira_menor(heap);

        pai = cria_sub_arvore(sub_arvore_get_freq(filho_e) + sub_arvore_get_freq(filho_d), '+', filho_e, filho_d);
        sub_arvore_set_pai(filho_e, pai);
        sub_arvore_set_pai(filho_d, pai);

        heap_insere(heap, pai);
    }

    arvore->raiz = retira_menor(heap);

    destroi_heap(heap);

/*

    int n = tam_lista;



    for(i = 1;i <= n-1; i++){
        sub_arvore_t* z = cria_sub_arvore()

        z->f_esq = x = retira_menor()
        z->f_dir = y = retira_menor
        z.freq = x.freq + y.freq

        enqueue(z, q)
    }
*/
    return arvore;
}

sub_arvore_t** cria_folhas(caracter_t** lista, int tam){

    int i;
    sub_arvore_t** folhas;

    folhas = malloc(sizeof(sub_arvore_t*)*tam);

    for(i=0;i<tam;i++){
        folhas[i] = cria_sub_arvore(get_freq(lista[i]), get_simbolo(lista[i]), NULL, NULL);
    }
    return folhas;
}

sub_arvore_t* cria_sub_arvore(int frequencia, char nome, sub_arvore_t* f_esq, sub_arvore_t* f_dir){

    sub_arvore_t* sub_arvore;

    sub_arvore = malloc(sizeof(sub_arvore_t));

    sub_arvore->freq = frequencia;
    sub_arvore->id = nome;
    sub_arvore->pai = NULL;
    sub_arvore->f_esq = f_esq;
    sub_arvore->f_dir = f_dir;

    return sub_arvore;
}



void sub_arvore_set_pai(sub_arvore_t* filho, sub_arvore_t* pai)
{
    filho->pai = pai;
}



int sub_arvore_get_freq(sub_arvore_t* sub_arvore){

    return sub_arvore->freq;
}


char sub_arvore__get_id(sub_arvore_t* sub_arvore){

    return sub_arvore->id;
}


void swap_sub_arvore(sub_arvore_t** A, sub_arvore_t** B){

#ifdef DEBUG
printf("\nswap %d  e  %d\n", sub_arvore_get_freq(*A), sub_arvore_get_freq(*B));
#endif

    sub_arvore_t* temp;
    temp = *A;
    *A = *B;
    *B = temp;

#ifdef DEBUG
printf(" %d  e  %d\n", sub_arvore_get_freq(*A), sub_arvore_get_freq(*B));
#endif
}
