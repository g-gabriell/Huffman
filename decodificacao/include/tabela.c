#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tabela.h"
#include "arvore.h"

#define set_bit(num,index)  num |= (1 << (7-index))
#define clr_bit(num,index)  num &= ~(1 << (7-index))
#define tst_bit(num, index) ((num >> (7 -index)) & 00000001)

#define DEBUG
#define ESQUERDA 0
#define DIREITA 1

struct caracter{

    char simbolo;
    int freq;
    sub_arvore_t* folha;
    char* codigo;
};


caracter_t** ContaFreq(const char* filename, int* num, int* num_caracteres){

    FILE *file;
    caracter_t** tabela;
    int i;
    char aux;

    *num = 0;
    *num_caracteres = 0;
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

    while(fread(&aux, 1, 1, file)){


        (*num_caracteres)++;
        for(i=0; i<*num; i++){
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
    }

    fclose(file);

    return tabela;
}

int get_freq(caracter_t* p){

    return p->freq;
}

void set_freq(caracter_t* p, int value){

    p->freq = value;
}

char get_simbolo(caracter_t* p){

    return p->simbolo;
}

char* get_code(caracter_t* caracter){

    return caracter->codigo;
}


void set_folha(caracter_t* p, sub_arvore_t* folha){

    p->folha = folha;
}


sub_arvore_t* character_get_folha(caracter_t* character){

    return character->folha;
}

void character_set_code(caracter_t* character, char* codigo){

    character->codigo = codigo;
}


//------------------------------------------------


/*


unsigned long binario_decimal(char* binario, int tamanho){

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

void binario_texto(char* binario, int tam_bin, char* text, int num_simbolos){

    int i;
    for(i = 0; i < tam_bin; i+=8, binario += 8){

        char *byte = binario;
        byte[8] = '\0';
        *text++ = binario_decimal(byte, 8);
    }
    text -= num_simbolos;
}
*/
void set_codes(caracter_t** lista_carcteres, int tam_lista){

    int i;
    for(i=0; i<tam_lista; i++)
        character_set_code(lista_carcteres[i], cria_binario(lista_carcteres[i]->folha));
}

void imprime_binario(caracter_t** tabela, arvore_t* arvore,char* filename_input,char* filename_output, int num_caracteres){

    FILE* input = fopen(filename_input, "r");
    FILE* output = fopen(filename_output, "w");

    char buffer[4000];
    int indice = 0;
    int i;
    int tamanho_buffer;
    sub_arvore_t* raiz;

    raiz = arvore_get_raiz(arvore);
    i = imprime_preordem(raiz, buffer, indice);
    buffer[i] = '\0';

    tamanho_buffer = strlen(buffer);

 //   fprintf(output, "%d%d%s", tamanho_buffer, num_caracteres, buffer);
    fwrite(&tamanho_buffer, 4, 1, output);      //Escreve o tamanho da arvore
    fwrite(&num_caracteres, 4, 1, output);      //Escreve o numero de caracteres a ser lido
    fwrite(buffer, 1,strlen(buffer), output);   //Escreve a arvore

    int index = 0;
    char c;
    int tam_code;
    int m;
    int j;
    unsigned char buffer_escrita;

    while(fread(&c, 1, 1, input)){

        for(j=0; c != tabela[j]->simbolo; j++);
        tam_code = strlen(tabela[j]->codigo);

        for(m = 0; m < tam_code; m++)
        {
            if(tabela[j]->codigo[m] == '1')
                set_bit(buffer_escrita, index++);
            if(tabela[j]->codigo[m] == '0')
                clr_bit(buffer_escrita, index++);
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


void destroi_tabela(caracter_t** tabela, int tam_tabela){

    int i;

    for(i=0;i<tam_tabela;i++){

        free(tabela[i]->codigo);
        free(tabela[i]);
    }
    free(tabela);
}

void le_arquivo_binario(char* filename){

    FILE* binario = fopen(filename, "r");
    FILE* output = fopen("decodificado.txt", "w");

    int tam_arvore;
    int num_caracteres;


    fread(&tam_arvore, sizeof(int), 1, binario);
    fread(&num_caracteres, sizeof(int), 1, binario);

#ifdef DEBUG
    printf("tam_arvore: %d\n caracteres no arquivo: %d", tam_arvore, num_caracteres);
#endif // DEBUG

    char buffer_arvore[tam_arvore];

    fread(buffer_arvore, sizeof(char), tam_arvore, binario);

//    arvore_t* arvore = malloc(sizeof(arvore_t));

    sub_arvore_t* raiz;// arvore_get_raiz;

    cria_arvore_pre_ordem(buffer_arvore, 1, 0, NULL, &raiz);    //Função recursiva que reconstroi a árvore

#ifdef DEBUG
    char buffer_temp[tam_arvore+1];
    imprime_preordem(raiz, buffer_temp, 0);
    buffer_temp[tam_arvore] = '\0';
    printf(" arvore:\n %s \n", buffer_temp);
#endif // DEBUG

    sub_arvore_t* pai;
    sub_arvore_t* f_esq;
    sub_arvore_t* f_dir;
    char byte;
    char letra;
    int index;

    pai = raiz;

    while(fread(&byte, sizeof(char), 1, binario)){
        for(index = 0; (index < 8)  && (num_caracteres > 0); index++){

            if(tst_bit(byte, index)){
                pai = sub_arvore_get_filho(pai, DIREITA);
            }
            else{
                pai = sub_arvore_get_filho(pai, ESQUERDA);
            }

            f_esq = sub_arvore_get_filho(pai, ESQUERDA);
            f_dir = sub_arvore_get_filho(pai, DIREITA);

            if((f_esq == NULL) && (f_dir == NULL)){
                num_caracteres--;
                letra = sub_arvore_get_id(pai);
                fwrite(&letra, 1, 1, output);
                pai = raiz;
#ifdef DEBUG
                printf("%c", letra);
#endif // DEBUG
            }
        }
    }

    free_posordem(raiz);

    fclose(binario);
    fclose(output);
}

int cria_arvore_pre_ordem(char* buffer_arvore,int i, int esq_dir, sub_arvore_t* pai, sub_arvore_t** raiz){

    sub_arvore_t* sub_arvore = cria_sub_arvore(0, buffer_arvore[i++], NULL, NULL);

    if(pai != NULL){

        if(esq_dir == 0)
            sub_arvore_set_f_esq(sub_arvore,pai);
        else
            sub_arvore_set_f_dir(sub_arvore,pai);
    }else
        *raiz = sub_arvore;

    i++;
    if(buffer_arvore[i++] == '{')
        i = cria_arvore_pre_ordem(buffer_arvore, i, ESQUERDA, sub_arvore, NULL);
    if(buffer_arvore[i++] == '{')
        i = cria_arvore_pre_ordem(buffer_arvore, i, DIREITA,sub_arvore, NULL);
    i++;

    return i;
}
