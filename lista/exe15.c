#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

No* criaNo(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;
    return novo;
}

void inserirFinal(No** cabeca, int valor) {
    No* novo = criaNo(valor);
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

No* intercalarListas(No* l1, No* l2) {
    No* novaLista = NULL;
    No** ult = &novaLista;

    while (l1 != NULL && l2 != NULL) {
        if (l1->dado < l2->dado) {
            *ult = criaNo(l1->dado);
            l1 = l1->prox;
        } else {
            *ult = criaNo(l2->dado);
            l2 = l2->prox;
        }
        ult = &((*ult)->prox);
    }

    while (l1 != NULL) {
        *ult = criaNo(l1->dado);
        ult = &((*ult)->prox);
        l1 = l1->prox;
    }

    while (l2 != NULL) {
        *ult = criaNo(l2->dado);
        ult = &((*ult)->prox);
        l2 = l2->prox;
    }

    return novaLista;
}

int main() {
    No* lista1 = NULL;
    No* lista2 = NULL;

    inserirFinal(&lista1, 1);
    inserirFinal(&lista1, 3);
    inserirFinal(&lista1, 5);

    inserirFinal(&lista2, 2);
    inserirFinal(&lista2, 4);
    inserirFinal(&lista2, 6);

    exibirLista(lista1);
    exibirLista(lista2);

    No* listaIntercalada = intercalarListas(lista1, lista2);
    exibirLista(listaIntercalada);

    return 0;
}