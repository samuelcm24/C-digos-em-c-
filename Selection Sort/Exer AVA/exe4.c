// Escreva um função para ordenar uma lista encadeada. Imite o algoritmo Selectionsort para vetores.  (Sua função precisa devolver alguma coisa?).

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

No* criaNo(int valor) {
    No* novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

void imprimeLista(No* lista) {
    while (lista != NULL) {
        printf("%d ", lista->valor);
        lista = lista->prox;
    }
    printf("\n");
}

int main() {
    No* lista = criaNo(4);
    lista->prox = criaNo(3);
    lista->prox->prox = criaNo(1);
    lista->prox->prox->prox = criaNo(2);

    printf("Lista original: ");
    imprimeLista(lista);

    lista = selectionSortLista(lista);

    printf("Lista ordenada: ");
    imprimeLista(lista);

    return 0;
}