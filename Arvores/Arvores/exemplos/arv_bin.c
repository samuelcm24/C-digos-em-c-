//Implementação arvore binaria

#include <stdio.h>
#include <stdlib.h>

typedef struct arv_bin
{
    int valor;
    struct arv_bin *esq;
    struct arv_bin *dir;
}arv_bin;

//Prototicos
arv_bin *aloca_Novo_no_arv(int valor);
void Insere_arvoreBin(arv_bin **arv, int valor);
void percurso_pre_ordem(arv_bin *arv);
void libera_arvore(arv_bin *avr);

arv_bin *aloca_Novo_no_arv(int valor){
    arv_bin *novo_no;
    novo_no = (arv_bin*) malloc(sizeof(arv_bin));
    novo_no->valor = valor;
    novo_no->esq = NULL;
    novo_no->dir = NULL;

    return novo_no;
}

void Insere_arvoreBin(arv_bin **arv, int valor){
    if(*arv == NULL){
        (*arv) = aloca_Novo_no_arv(valor);
    } else{
        if(valor < (*arv)->valor){
            Insere_arvoreBin( &(*arv)->esq, valor);
        } else{
            Insere_arvoreBin( &(*arv)->dir, valor);
        }
    }
}

//Função que percorrer em pré ordem
void percurso_pre_ordem(arv_bin *arv){

    if(arv != NULL){
        printf("%d ", arv->valor);
        percurso_pre_ordem(arv->esq);
        percurso_pre_ordem(arv->dir);
    }
    
}

void libera_arvore(arv_bin *arv) {
    if (arv != NULL) {
        libera_arvore(arv->esq);
        libera_arvore(arv->dir);
        free(arv);
    }
}


int main(){
     arv_bin *arvore;
     arvore = NULL;

     Insere_arvoreBin(&arvore, 10);
     Insere_arvoreBin(&arvore, 2);
     Insere_arvoreBin(&arvore, 9);
     Insere_arvoreBin(&arvore, 13);
     Insere_arvoreBin(&arvore, 22);
     Insere_arvoreBin(&arvore, 25);

     percurso_pre_ordem(arvore);
     printf("\n");

     return 0;
}