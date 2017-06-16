#include <stdio.h>
#include <stdlib.h>

#include "heap.h"
#include "arvore.h"

struct arvore{
    sub_arvore_t* raiz;
};

<<<<<<< HEAD
cria_arvore_huffman(sub_arvore_t* folhas,int tam_folhas){
    int n = tam_folhas;
=======
struct sub_arvore{
    char*   id;
    int     freq;

    sub_arvore_t* pai;
    sub_arvore_t* f_esq;
    sub_arvore_t* f_dir;
};



cria_arvore_huffman(heap_t* heap,int tam_heap){

    int n = tam_heap;
>>>>>>> 3c11f18f900e2ec7ba8fc16f2e08cc7456d1420e
    fila_t* q = malloc(sizeof(fila_t));


    build_heap(heap);


    for(i = 1;i <= n-1; i++){
        sub_arvore_t* z = cria_sub_arvore()

        z->f_esq = x = retira_menor()
        z->f_dir = y = retira_menor
        z.freq = x.freq + y.freq

        enqueue(z, q)
    }

    }

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
