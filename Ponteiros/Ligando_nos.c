/*
Exercício 5: Ligando os Pontos (Nós)
Objetivo: Criar dois nós e ligá-los usando o ponteiro proximo.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int dado;
    struct lista *prox;
}lista;

int main(){

    lista *no1 = NULL;
    lista *no2 = NULL;

    no1 = (lista*) malloc(sizeof(lista));
    no1->dado = 25;

    no2 = (lista*) malloc(sizeof(lista));
    no2->dado = 45;

    no1->prox = no2;
    no2->prox = NULL;

    printf("Dados do primeiro nó: %d\n", no1->dado);
    printf("Endereço do primeiro nó: %p\n", no1->prox);
    printf("Endereço do proprio no2: %p\n", no2);
    printf("\n");
    printf("Dados do segundo nó (no1->proximo->dados): %d\n", no1->prox->dado);
  
    free(no1);
    free(no2);

    return 0;

}
