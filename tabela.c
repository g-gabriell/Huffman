#include <stdio.h>
#include <stdlib.h>

#include "tabela.h"


struct caracterFreq{
    char character;
    int freq;
};


caracterFreq_t** ContaFreq(const char* filename, int* num)
{
    FILE *file;

    *num = 0;
    int i;
    char aux;

    caracterFreq_t** tabela;

    tabela = malloc(sizeof(caracterFreq_t*));

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
            if(aux == tabela[i]->character){
                tabela[i]->freq++;
                break;
            }
        }
        if(i == *num) {
            tabela = realloc(tabela, sizeof(caracterFreq_t*)*((*num)+1));
            tabela[*num] = malloc(sizeof(caracterFreq_t));
            if( tabela[*num] == NULL || tabela == NULL){
                perror("realloc_num:");
                exit(EXIT_FAILURE);
            }
            tabela[*num]->character = aux;
            tabela[*num]->freq = 1;
            (*num)++;
        }
    };

    fclose(file);

    return tabela;
}

int get_freq(caracterFreq_t* p)
{
    return p->freq;
}

void set_freq(caracterFreq_t* p, int value)
{
    p->freq = value;
}

char get_character(caracterFreq_t* p)
{
    return p->character;
}

