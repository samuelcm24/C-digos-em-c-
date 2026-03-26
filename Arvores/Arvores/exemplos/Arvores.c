//Código atualizado para pré-ordem, em-ordem, pós-ordem

//Implementação arvore binaria

#include <stdio.h>
#include <stdlib.h>

typedef struct arv_bin {
    int valor;
    struct arv_bin *esq;
    struct arv_bin *dir;
} arv_bin;

// Prototipos
arv_bin *aloca_Novo_no_arv(int valor);
void Insere_arvoreBin(arv_bin **arv, int valor);
void percurso_pre_ordem(arv_bin *arv);
void percurso_in_ordem(arv_bin *arv);
void percurso_pos_ordem(arv_bin *arv);

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
    } else {
        if(valor < (*arv)->valor){
            Insere_arvoreBin( &(*arv)->esq, valor);
        } else {
            Insere_arvoreBin( &(*arv)->dir, valor);
        }
    }
}

// Percurso pré-ordem (raiz -> esq -> dir)
void percurso_pre_ordem(arv_bin *arv){
    if(arv != NULL){
        printf("%d ", arv->valor);
        percurso_pre_ordem(arv->esq);
        percurso_pre_ordem(arv->dir);
    }
}

// Percurso in-ordem (esq -> raiz -> dir)
void percurso_in_ordem(arv_bin *arv){
    if(arv != NULL){
        percurso_in_ordem(arv->esq);
        printf("%d ", arv->valor);
        percurso_in_ordem(arv->dir);
    }
}

// Percurso pos-ordem (esq -> dir -> raiz)
void percurso_pos_ordem(arv_bin *arv){
    if(arv != NULL){
        percurso_pos_ordem(arv->esq);
        percurso_pos_ordem(arv->dir);
        printf("%d ", arv->valor);
    }
}

int main(){
     arv_bin *arvore = NULL;

     Insere_arvoreBin(&arvore, 10);
     Insere_arvoreBin(&arvore, 2);
     Insere_arvoreBin(&arvore, 9);
     Insere_arvoreBin(&arvore, 13);
     Insere_arvoreBin(&arvore, 22);
     Insere_arvoreBin(&arvore, 25);

     printf("Pre-ordem: ");
     percurso_pre_ordem(arvore);
     printf("\n");

     printf("In-ordem: ");
     percurso_in_ordem(arvore);
     printf("\n");

     printf("Pos-ordem: ");
     percurso_pos_ordem(arvore);
     printf("\n");

     return 0;
}