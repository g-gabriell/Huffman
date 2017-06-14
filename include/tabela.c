#include <stdio.h>
#include <stdlib.h>

#include "tabela.h"


struct caracter{
    char simbolo;
    int freq;
//    sub_arvore_t* folha;
//    char* codigo;
};


caracter_t** ContaFreq(const char* filename, int* num)
{
    FILE *file;

    *num = 0;
    int i;
    char aux;

    caracter_t** tabela;

    tabela = malloc(sizeof(caracter_t*));

    if(tabela == NULL)
    {
        perror("malloc_tabela:");
		exit(EXIT_FAILURE);
    }

    file = fopen(filename, "r");

    if(file == NULL)
    {
        perror("fopen:");
		exit(EXIT_FAILURE);
    }
//--------------------------------------------------------------

    while((aux = fgetc(file)) != EOF){

        for(i=0;i<*num;i++){
            if(aux == tabela[i]->simbolo){
                tabela[i]->freq++;
                break;
            }
        }
        if(i == *num) {
            tabela = realloc(tabela, sizeof(caracter_t*)*((*num)+1));
            tabela[*num] = malloc(sizeof(caracter_t));
            if( tabela[*num] == NULL || tabela == NULL){
                perror("realloc_num:");
                exit(EXIT_FAILURE);
            }
            tabela[*num]->simbolo = aux;
            tabela[*num]->freq = 1;
            (*num)++;
        }
    };

    fclose(file);

    return tabela;
}

int get_freq(caracter_t* p)
{
    return p->freq;
}

void set_freq(caracter_t* p, int value)
{
    p->freq = value;
}

char get_simbolo(caracter_t* p)
{
    return p->simbolo;
}

