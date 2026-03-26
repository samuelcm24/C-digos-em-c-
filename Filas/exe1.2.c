/*
UFMT - UNIVERSIDADE DO VALE DO ARAGUAIA
DISCENTE: Samuel Campos Martins
DOCENTE: Thiago

MATERIA: Estruturas De Dados 1
*/


#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct No {
    int dado;
    struct No* prox;
} No;

// Função para criar um novo nó
No* criar_no(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo->dado = valor;
    novo->prox = NULL;
    return novo;
}

// Função para inserir no final da lista
void inserir_final(No** inicio, int valor) {
    No* novo = criar_no(valor);
    if (*inicio == NULL) {
        *inicio = novo;  // lista vazia, novo é o primeiro nó
    } else {
        No* temp = *inicio;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}

// Função para imprimir a lista
void imprimir_lista(No* inicio) {
    printf("Lista: ");
    while (inicio != NULL) {
        printf("%d -> ", inicio->dado);
        inicio = inicio->prox;
    }
    printf("NULL\n");
}

// Função principal
int main() {
    No* lista = NULL;

    // Inserção de elementos
    inserir_final(&lista, 10);
    inserir_final(&lista, 20);
    inserir_final(&lista, 30);
    inserir_final(&lista, 40);

    // Impressão da lista
    imprimir_lista(lista);
    free(lista);
    printf("memoria liberada!!\n");

    return 0;
}
