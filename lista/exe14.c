/* Remoção Duplicados
Crie uma função que percorra uma lista simplesmente encadeada e remova os nós duplicados (assuma que a lista está ordenada).*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

void removerDuplicados(No* cabeca) {
    No* atual = cabeca;
    
    while (atual != NULL && atual->prox != NULL) {
        if (atual->dado == atual->prox->dado) {
            No* duplicado = atual->prox;
            atual->prox = duplicado->prox;
            free(duplicado);
        } else {
            atual = atual->prox;
        }
    }
}


void inserirFinal(No** cabeca, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;

    if (*cabeca == NULL) {
        *cabeca = novo;
        return;
    }

    No* temp = *cabeca;
    while (temp->prox != NULL)
        temp = temp->prox;
    temp->prox = novo;
}

void exibirLista(No* cabeca) {
    No* temp = cabeca;
    while (temp != NULL) {
        printf("%d ", temp->dado);
        temp = temp->prox;
    }
    printf("\n");
}

int main() {
    No* lista = NULL;

    inserirFinal(&lista, 1);
    inserirFinal(&lista, 2);
    inserirFinal(&lista, 2);
    inserirFinal(&lista, 3);
    inserirFinal(&lista, 3);
    inserirFinal(&lista, 3);
    inserirFinal(&lista, 4);

    printf("Lista original: ");
    exibirLista(lista);

    removerDuplicados(lista);

    printf("Lista sem duplicados: ");
    exibirLista(lista);

    return 0;
}