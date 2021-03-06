#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha.h"
#include "heap.h"
#include "arvore.h"

//#define DEBUG

struct arvore{
    sub_arvore_t* raiz;
};

struct sub_arvore{
    char   id;
    int    freq;

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

#ifdef DEBUG
    int i;
    for(i=0;i<tam_lista;i++)
        printf("%c -- %d\n", sub_arvore__get_id(folhas[i]), sub_arvore_get_freq(folhas[i]));
#endif // DEBUG

    heap = inicializa_heap(tam_lista, folhas);

    sub_arvore_t* filho_e;
    sub_arvore_t* filho_d;
    sub_arvore_t* pai;

    while(get_tam_heap(heap) > 1){

        filho_e = retira_menor(heap);
        filho_d = retira_menor(heap);

        pai = cria_sub_arvore(sub_arvore_get_freq(filho_e) + sub_arvore_get_freq(filho_d), '+', filho_e, filho_d, NULL);
        sub_arvore_set_pai(filho_e, pai);
        sub_arvore_set_pai(filho_d, pai);

        heap_insere(heap, pai);
    }

    arvore->raiz = retira_menor(heap);

//------ATRIBUI CODIGOS BIN�RIOS NA LISTA DE CARACTERES
    set_codes(lista_carcteres, tam_lista);

    destroi_heap(heap);
    free(folhas);

    return arvore;
}

sub_arvore_t** cria_folhas(caracter_t** lista, int tam){

    int i;
    sub_arvore_t** folhas;

    folhas = malloc(sizeof(sub_arvore_t*)*tam);

    for(i=0;i<tam;i++){
        folhas[i] = cria_sub_arvore(get_freq(lista[i]), get_simbolo(lista[i]), NULL, NULL, NULL);
        set_folha(lista[i], folhas[i]);
    }

    return folhas;
}

sub_arvore_t* cria_sub_arvore(int frequencia, char nome, sub_arvore_t* f_esq, sub_arvore_t* f_dir, sub_arvore_t* pai){

    sub_arvore_t* sub_arvore;

    sub_arvore = malloc(sizeof(sub_arvore_t));

    sub_arvore->freq = frequencia;
    sub_arvore->id = nome;
    sub_arvore->pai = pai;
    sub_arvore->f_esq = f_esq;
    sub_arvore->f_dir = f_dir;

    return sub_arvore;
}

sub_arvore_t* sub_arvore_get_pai(sub_arvore_t* filho){

    if(filho == NULL){
        printf("sub_arvore_get_pai: filho invalido");
        exit(1);
    }

    return filho->pai;
}

void sub_arvore_set_pai(sub_arvore_t* filho, sub_arvore_t* pai){

    filho->pai = pai;
}


void sub_arvore_set_f_esq(sub_arvore_t* filho, sub_arvore_t* pai){

    pai->f_esq = filho;
}

void sub_arvore_set_f_dir(sub_arvore_t* filho, sub_arvore_t* pai){

    pai->f_dir = filho;
}

sub_arvore_t* sub_arvore_get_filho(sub_arvore_t* pai, int esq_dir){

    if(esq_dir)
        return pai->f_dir;
    else
        return pai->f_esq;
}

int sub_arvore_get_freq(sub_arvore_t* sub_arvore){

    return sub_arvore->freq;
}


char sub_arvore_get_id(sub_arvore_t* sub_arvore){

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

}

void free_posordem(sub_arvore_t* vertice){

    if(vertice == NULL)
        return;

    free_posordem(vertice->f_esq);
    free_posordem(vertice->f_dir);
    free(vertice);
}

void destroi_arvore(arvore_t* arvore){

    if (arvore == NULL){
        perror("destroi_arvore:");
        exit(EXIT_FAILURE);
    }

    sub_arvore_t* raiz = arvore->raiz;
    free_posordem(raiz);
    free(arvore);
}

char* cria_binario(sub_arvore_t* folha){

    if (folha == NULL){
        perror("cria_binario:");
        exit(EXIT_FAILURE);
    }

    char* code;

    pilha_t* pilha = cria_pilha();
    sub_arvore_t* filho = folha;
    sub_arvore_t* pai = sub_arvore_get_pai(filho);

    push('\0',pilha);       //fim da string

    while(pai != NULL){

        if(pai->f_esq == filho)
            push('0', pilha);
        if(pai->f_dir == filho)
            push('1', pilha);

        filho = pai;
        pai = sub_arvore_get_pai(pai);
    }

    int i, tam_pilha;

    tam_pilha = tamanho_pilha(pilha);
    code = malloc(sizeof(char)*tam_pilha);

    for(i=0;i<tam_pilha;i++)
        code[i] = (char)pop(pilha);

    destroi_pilha(pilha);

    return code;
   }

int imprime_preordem(sub_arvore_t* vertice, char* buffer,int indice){

    int i = indice;
    if (vertice == NULL)
        return i;

    buffer[i] = '{';
    i++;
    buffer[i] = vertice->id;
    i++;
    buffer[i] = ',';
    i++;
    i = imprime_preordem(vertice->f_esq, buffer, i);
    buffer[i] = ',';
    i++;
    i = imprime_preordem(vertice->f_dir, buffer, i);
    buffer[i] = '}';
    i++;

    return i;
}

sub_arvore_t* arvore_get_raiz(arvore_t* arvore){
    if (arvore == NULL){
        perror("destroi_arvore:");
        exit(EXIT_FAILURE);
    }
    return arvore->raiz;
}

arvore_t* cria_arvore(sub_arvore_t* raiz){

    arvore_t* arvore = malloc(sizeof(arvore_t));
    arvore->raiz = raiz;
    return arvore;
}
