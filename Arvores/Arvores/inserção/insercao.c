#include <stdio.h>
#include <stdlib.h>


typedef struct No
{
    int valor;
    struct No *esq;
    struct No *dir;
} No;

No *cria_no(int valor){
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

No* insere(No* raiz, int valor){
    
    if(raiz == NULL){
        return cria_no(valor);
    }

    if(valor < raiz->valor){
        raiz->esq = insere(raiz->esq, valor);
    } else if(valor > raiz->valor){
        raiz->dir = insere(raiz->dir, valor);
    }

    return raiz;
}

void imprimir_em_ordem(No* raiz){
    if(raiz != NULL){
        imprimir_em_ordem(raiz->esq);
        printf("%d -> ", raiz->valor);
        imprimir_em_ordem(raiz->dir);
    }
}

int main(){
    No* raiz = NULL;

    raiz = insere(raiz, 10);
    raiz = insere(raiz, 5);
    raiz = insere(raiz, 17);
    raiz = insere(raiz, 33);
    raiz = insere(raiz, 2);
    
    printf("Árvore em ordem: ");
    imprimir_em_ordem(raiz);
    printf("\n");

    return 0;
}