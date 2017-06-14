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
        folhas[i].id = malloc(sizeof(char));
        folhas[i].id[0] = get_simbolo(lista[i]);
        folhas[i].freq = get_freq(lista[i]);
        folhas[i].pai = NULL;
        folhas[i].f_esq = NULL;
        folhas[i].f_dir = NULL;
    }

    return folhas;
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

	return p;
}
*/
