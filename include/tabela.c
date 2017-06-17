#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tabela.h"
#include "arvore.h"

struct caracter{
    char simbolo;
    int freq;
    sub_arvore_t* folha;
    char* codigo;
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

//------------------------------------------------


void texto_binario(FILE* file,char* texto)
{
    int i;
    int j;
    int tamanho;
    int res;

    tamanho = strlen(texto);
    for(i=0;i<tamanho;i+=8) {
        res = 0;

        for(j=0;j<8;j++) {
            res *= 2;
            if (texto[i+j]=='1') res++;
        }

        fprintf(file,"%02X ",res);
    }
}


  unsigned long binario_decimal(char* binario, int tamanho)
    {
        int i;
        unsigned long decimal = 0;
        unsigned long peso = 1;
        binario += tamanho-1;
        peso = 1;
        for(i = 0; i < tamanho; ++i, --binario)
        {
            if(*binario == '1')
                decimal += peso;
            peso *= 2;
        }
        return decimal;
    }

void binario_texto(char* binario, int tam_bin, char* text, int num_simbolos)
{
    int i;
    for(i = 0; i < tam_bin; i+=8, binario += 8)
    {
        char *byte = binario;
        byte[8] = '\0';
        *text++ = binario_decimal(byte, 8);
    }
    text -= num_simbolos;
}

sub_arvore_t* character_get_folha(caracter_t* character){
    sub_arvore_t* folha = character->folha;
    return folha;
}

void character_set_code(caracter_t* character, char* codigo){
    character->codigo = codigo;
}
