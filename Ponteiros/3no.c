/*
Próximo Passo:
O próximo passo lógico seria criar um terceiro nó, ligar o segundo a ele, e depois criar um laço (while) que 
começa no primeiro nó e vai seguindo os ponteiros 
proximo até encontrar um NULL, imprimindo o dado de cada nó pelo caminho. Isso é "percorrer a lista".
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int dado;
    struct lista *prox;
} lista;

int main() {
    // Criação dos nós
    lista *no1 = (lista*) malloc(sizeof(lista));
    lista *no2 = (lista*) malloc(sizeof(lista));
    lista *no3 = (lista*) malloc(sizeof(lista));

    // Atribuição de valores
    no1->dado = 25;
    no2->dado = 45;
    no3->dado = 65;

    // Ligação dos nós
    no1->prox = no2;
    no2->prox = no3;
    no3->prox = NULL;

    // Percorrendo a lista
    lista *atual = no1;
    printf("Percorrendo a lista:\n");
    while (atual != NULL) {
        printf("Dado: %d\n", atual->dado);
        atual = atual->prox;
    }

    // Liberação da memória
    free(no1);
    free(no2);
    free(no3);

    return 0;
}
