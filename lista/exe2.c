/*
Inserção Ordenada
Implemente uma função que insira elementos de forma ordenada (crescente) em uma lista simplesmente encadeada.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no* prox;
} no;

no* criar_no(int valor){
    no* novo = (no*)malloc(sizeof(no));
    if (novo == NULL){
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    novo->dado = valor;
    novo->prox = NULL;
    return novo;
}

void inserir(no** inicio, int valor){
    no* novo = criar_no(valor);
    if (*inicio == NULL || (*inicio)->dado > valor){
        novo->prox = *inicio;
        *inicio = novo;
    } else {
        no* atual = *inicio;
        while (atual->prox != NULL && atual->prox->dado < valor){
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        atual->prox = novo;
    }
    printf("Elemento %d inserido com sucesso.\n", valor);
}

void imprimir_lista(no* inicio){
    printf("Lista: ");
    while (inicio != NULL){
        printf("%d -> ", inicio->dado);
        inicio = inicio->prox;
    }
    printf("NULL\n");
}

int main(){

    no* lista = NULL;
    inserir(&lista, 30);
    inserir(&lista, 10);
    inserir(&lista, 20);
    inserir(&lista, 40);

    imprimir_lista(lista);

    no* atual = lista;
    while (atual != NULL) {
        no* temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}