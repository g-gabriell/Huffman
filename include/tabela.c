#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tabela.h"
#include "arvore.h"

#define bitset(num,index) ((num) |= (1 << (7-index)))
#define bitclr(num,index) ((num) &= ~(1 << (7-index)))

#define DEBUG

struct caracter
{
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

    while(fread(&aux, 1, 1, file))
    {

        for(i=0; i<*num; i++)
        {
            if(aux == tabela[i]->simbolo)
            {
                tabela[i]->freq++;
                break;
            }
        }
        if(i == *num)
        {
            tabela = realloc(tabela, sizeof(caracter_t*)*((*num)+1));
            tabela[*num] = malloc(sizeof(caracter_t));
            if( tabela[*num] == NULL || tabela == NULL)
            {
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


void set_folha(caracter_t* p, sub_arvore_t* folha)
{
    p->folha = folha;
}


sub_arvore_t* character_get_folha(caracter_t* character)
{
    return character->folha;
}

void character_set_code(caracter_t* character, char* codigo)
{
    character->codigo = codigo;
}


//------------------------------------------------





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

void set_codes(caracter_t** lista_carcteres, int tam_lista)
{
    int i;
    for(i=0; i<tam_lista; i++)
        character_set_code(lista_carcteres[i], cria_binario(lista_carcteres[i]->folha));
}

char* get_code(caracter_t* caracter)
{
    return caracter->codigo;
}

void imprime_binario(caracter_t** tabela, arvore_t* arvore,char* filename_input,char* filename_output)
{

    FILE* input = fopen(filename_input, "r");
    FILE* output = fopen(filename_output, "w");

    char buffer[3073];
    int indice = 0;

    sub_arvore_t* raiz = arvore_get_raiz(arvore);
    int i = imprime_preordem(raiz, buffer, indice);
    buffer[i] = '\0';
    int tamanho_buffer = strlen(buffer);

    fprintf(output, "%d%s", tamanho_buffer, buffer);

    int index = 0;
    char c;
    int tam_code;
    int m;
    int j;
    unsigned char buffer_escrita;

    while(fread(&c, 1, 1, input))
    {

        for(j=0; c != tabela[j]->simbolo; j++);
        tam_code = strlen(tabela[j]->codigo);

        for(m = 0; m < tam_code; m++)
        {
            if(tabela[j]->codigo[m] == '1')
                bitset(buffer_escrita, index++);
            if(tabela[j]->codigo[m] == '0')
                bitclr(buffer_escrita, index++);
            if(index == 8)
            {
                #ifdef DEBUG
                printf(" %02x", buffer_escrita);
                #endif // DEBUG
                fwrite(&buffer_escrita, 1, 1,output);
                index = 0;
            }
        }
    }

    fwrite(&buffer_escrita, 1, 1,output);

    fclose(input);
    fclose(output);
}
