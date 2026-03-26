#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No* esq;
    struct No* dir;
}No;

No* minimo(No* raiz) {
    No* atual = raiz;
    while (atual && atual->esq != NULL) {
        atual = atual->esq;
    }
    return atual;
}
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


No* removeNo(No* raiz, int valor) {
    if (raiz == NULL) {
        return raiz; // árvore vazia ou valor não encontrado
    }

    if (valor < raiz->valor) {
        raiz->esq = removeNo(raiz->esq, valor);
    }
    else if (valor > raiz->valor) {
        raiz->dir = removeNo(raiz->dir, valor);
    }
    else {
        // Encontrou o nó a remover

        // Caso 1: nó sem filhos
        if (raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);
            return NULL;
        }

        // Caso 2: só tem um filho
        else if (raiz->esq == NULL) {
            No* temp = raiz->dir;
            free(raiz);
            return temp;
        }
        else if (raiz->dir == NULL) {
            No* temp = raiz->esq;
            free(raiz);
            return temp;
        }

        // Caso 3: dois filhos
        No* sucessor = minimo(raiz->dir);
        raiz->valor = sucessor->valor;
        raiz->dir = removeNo(raiz->dir, sucessor->valor);
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


int main() {
    No* raiz = NULL;

    // Inserindo valores
    raiz = insere(raiz, 10);
    raiz = insere(raiz, 5);
    raiz = insere(raiz, 15);
    raiz = insere(raiz, 3);
    raiz = insere(raiz, 7);
    raiz = insere(raiz, 12);
    raiz = insere(raiz, 20);

    printf("Árvore em ordem antes da remoção: ");
    imprimir_em_ordem(raiz);
    printf("\n");

    // Remoções
    raiz = removeNo(raiz, 5);   // remove folha
    raiz = removeNo(raiz, 15);  // remove nó com 2 filhos

    printf("Árvore em ordem depois da remoção: ");
    imprimir_em_ordem(raiz);
    printf("\n");

    return 0;
}
