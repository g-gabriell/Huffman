#include <stdio.h>
#include <stdlib.h>

#include "heap.h"
#include "arvore.h"


struct arvore{
    sub_arvore_t* raiz;
};

struct sub_arvore{
    char*   id;
    int     freq;

    sub_arvore_t* pai;
    sub_arvore_t* f_esq;
    sub_arvore_t* f_dir;
};

sub_arvore_t* cria_folhas(caracter_t** lista, int tam){

    int i;
    sub_arvore_t* folhas;

    folhas = malloc(sizeof(sub_arvore_t)*tam);

    for(i=0;i<tam;i++){
        folhas[i].id = malloc(sizeof(char)*2);
        folhas[i].id[0] = get_simbolo(lista[i]);
        folhas[i].id[1] = '\0';
        folhas[i].freq = get_freq(lista[i]);
        folhas[i].pai = NULL;
        folhas[i].f_esq = NULL;
        folhas[i].f_dir = NULL;
    }

    return folhas;
}

int folha_get_freq(sub_arvore_t* folha, int i){

    return folha[i].freq;
}

char* folha_get_id(sub_arvore_t* folha, int i){

    return folha[i].id;
}

void swap_folhas(sub_arvore_t* folha, int i, int j){

    sub_arvore_t temp;
    temp = folha[i];
    folha[i] = folha[j];
    folha[j] = folha[i];
}



/*
arvore_t* cria_arvore()
{
    arvore_t *p = NULL;

	p = (arvore_t*) malloc(sizeof(arvore_t));

	if (p == NULL)	{
		perror("cria_arvore:");
		exit(EXIT_FAILURE);
	}

	p->raiz = NULL;

}
	return p;
*/
