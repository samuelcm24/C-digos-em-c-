#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

No* criar_no(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    novo->dado = valor;
    novo->prox = NULL;
    return novo;
}

void inserir_final(No** inicio, int valor) {
    No* novo = criar_no(valor);
    if (*inicio == NULL) {
        *inicio = novo;
    } else {
        No* temp = *inicio;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}

void imprimir_lista(No* inicio) {
    printf("Lista: ");
    while (inicio != NULL) {
        printf("%d -> ", inicio->dado);
        inicio = inicio->prox;
    }
    printf("NULL\n");
}

void liberar_lista(No* inicio) {
    No* temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->prox;
        free(temp);
    }
}

No* concatenar_listas(No* l1, No* l2) {
    No* nova_lista = NULL;
    No* cauda = NULL;
    No* temp;

    No* p1 = l1;
    while (p1 != NULL) {
        temp = criar_no(p1->dado);
        if (nova_lista == NULL) {
            nova_lista = temp;
            cauda = temp;
        } else {
            cauda->prox = temp;
            cauda = cauda->prox;
        }
        p1 = p1->prox;
    }

    No* p2 = l2;
    while (p2 != NULL) {
        temp = criar_no(p2->dado);
        if (nova_lista == NULL) {
            nova_lista = temp;
            cauda = temp;
        } else {
            cauda->prox = temp;
            cauda = cauda->prox;
        }
        p2 = p2->prox;
    }
    
    return nova_lista;
}

int main() {
    No* lista1 = NULL;
    No* lista2 = NULL;
    
    inserir_final(&lista1, 1);
    inserir_final(&lista1, 2);
    
    inserir_final(&lista2, 3);
    inserir_final(&lista2, 4);

    printf("Lista 1: ");
    imprimir_lista(lista1);
    
    printf("Lista 2: ");
    imprimir_lista(lista2);

    No* lista_concatenada = concatenar_listas(lista1, lista2);

    printf("Lista Concatenada (Nova): ");
    imprimir_lista(lista_concatenada);

    liberar_lista(lista1);
    liberar_lista(lista2);
    liberar_lista(lista_concatenada);

    return 0;
}