#include <stdio.h>
#include <stdlib.h>

#include "heap.h"


cria_arvore_huffman(sub_arvore_t* folhas,int tam_folhas){
    int n = tam_folhas;
    fila_t* q = malloc(sizeof(fila_t));
    inicializa_heap(n, )

    for(i = 1;i <= n-1; i++){
        sub_arvore_t* z = cria_sub_arvore()

        z->f_esq = x = min_heapify()
        z->f_dir = y = min
        z.freq = x.freq + y.freq

        enqueue(z, q)
    }

    }
/*
struct arvore{
    sub_arvore* raiz;
};

struct sub_arvore{
    char*   grupo;
    int     tam_grupo;
    int     freq;

    sub_arvore_t* f_esq;
    sub_arvore_t* f_dir;
};

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
