#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

typedef struct arvore arvore_t;
typedef struct sub_arvore sub_arvore_t;

arvore_t* cria_arvore(sub_arvore_t* raiz);
arvore_t* cria_arvore_huffman(caracter_t** lista_carcteres, int tam_lista);
sub_arvore_t** cria_folhas(caracter_t** lista, int tam);
sub_arvore_t* cria_sub_arvore(int frequencia, char nome, sub_arvore_t* f_esq, sub_arvore_t* f_dir, sub_arvore_t* pai);
char* cria_binario(sub_arvore_t* folha);

sub_arvore_t* arvore_get_raiz(arvore_t* arvore);
sub_arvore_t* sub_arvore_get_pai(sub_arvore_t* filho);
sub_arvore_t* sub_arvore_get_filho(sub_arvore_t* pai, int esq_dir);

int sub_arvore_get_freq(sub_arvore_t* sub_arvore);
char sub_arvore_get_id(sub_arvore_t* sub_arvore);

void sub_arvore_set_pai(sub_arvore_t* filho, sub_arvore_t* pai);
void sub_arvore_set_f_esq(sub_arvore_t* filho, sub_arvore_t* pai);
void sub_arvore_set_f_dir(sub_arvore_t* filho, sub_arvore_t* pai);

void swap_sub_arvore(sub_arvore_t** A, sub_arvore_t** B);

int imprime_preordem(sub_arvore_t* vertice, char* buffer,int indice);

void free_posordem(sub_arvore_t* vertice);
void destroi_arvore(arvore_t* arvore);

#endif // ARVORE_H_INCLUDED
