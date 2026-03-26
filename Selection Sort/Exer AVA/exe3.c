//.  Escreva uma função que ordene uma lista encadeada. Inspire-se no algoritmo Insertionsort para vetores.  (Sua função precisa devolver alguma coisa?).

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

No* insereOrdenado(No* inicio, No* novo) {
    if (inicio == NULL || novo->valor < inicio->valor) {
        novo->prox = inicio;
        return novo;
    }
    No* atual = inicio;
    while (atual->prox != NULL && atual->prox->valor <= novo->valor) {
        atual = atual->prox;
    }
    novo->prox = atual->prox;
    atual->prox = novo;
    return inicio;
}

No* insertionSortLista(No* lista) {
    No* ordenada = NULL;
    No* atual = lista;
    while (atual != NULL) {
        No* prox = atual->prox;
        ordenada = insereOrdenado(ordenada, atual);
        atual = prox;
    }
    return ordenada;
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

    lista = insertionSortLista(lista);

    printf("Lista ordenada: ");
    imprimeLista(lista);

    return 0;
}