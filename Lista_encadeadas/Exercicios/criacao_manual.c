/*
Exercício 1: Criação Manual
Escreva uma função main que cria "manualmente" (sem usar uma função de inserção) uma 
lista ligada com 3 elementos, contendo os valores 5, 10 e 15. Ao final, o ponteiro lista deve apontar para 
o nó cabeça, e a sequência de nós deve ser 5 -> 10 -> 15 -> NULL.

Dica: Você precisará usar malloc 4 vezes (1 para o nó cabeça e 3 para os nós de dados) e ajustar os ponteiros 
prox um a um.
*/

#include <stdio.h>
#include <stdlib.h>

// Estrutura base;
typedef struct celula
{
    int conteudo;
    struct celula *prox;
} celula;

void imprimi(celula *elementos){
    celula *p;
    printf("Lista: ");
    for (p = elementos->prox; p != NULL; p = p->prox) {
        printf("%d -> ", p->conteudo);
    }
    printf("\n");
}

int main(){

    //Alocando memoria para cada nó necessario

    celula *lista = malloc(sizeof(celula));
    celula *n1 = malloc(sizeof(celula));
    celula *n2 = malloc(sizeof(celula));
    celula *n3 = malloc(sizeof(celula));

    n1->conteudo = 5;
    n2->conteudo = 10;
    n3->conteudo = 15;

        // 3. Conecta os ponteiros na ordem correta
    lista->prox = n1;  // Cabeça aponta para o primeiro nó real (5)
    n1->prox = n2;    // Nó 1 (5) aponta para o nó 2 (10)
    n2->prox = n3;    // Nó 2 (10) aponta para o nó 3 (15)
    n3->prox = NULL;   // Nó 3 (15) é o último, então aponta para NULL

    imprimi(lista);

    //liberando memoria;
    free(n3);
    free(n2);
    free(n1);
    free(lista);

    return 0;

    
}