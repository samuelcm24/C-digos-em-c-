/*Inversão da Lista
Implemente uma função que inverta a ordem dos elementos da lista simplesmente encadeada sem usar vetor auxiliar.

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

void inverter_lista(no  **inicio){
    no* anterior = NULL;
    no* atual = *inicio;
    no* proximo = NULL;

    while (atual != NULL){
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }
    *inicio = anterior;
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
    lista = criar_no(10);
    lista->prox = criar_no(20);
    lista->prox->prox = criar_no(30);
    lista->prox->prox->prox = criar_no(40);

    printf("Lista original:\n");
    imprimir_lista(lista);

    inverter_lista(&lista);

    printf("Lista invertida:\n");
    imprimir_lista(lista);

    // Liberar memória
    no* atual = lista;
    while (atual != NULL){
        no* temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}