/*
Exercício 1: Inserindo em Ordem
Objetivo: Criar uma lista que contenha os números 10, 20, 30, nesta ordem exata.

Instruções:

Usando o "molde" acima, modifique apenas a função main.

Use a função insere para adicionar os números 10, 20 e 30 na lista.

Chame a função imprime no final para que a saída seja: Lista: 10 -> 20 -> 30 -> NULL.

Dica: Lembre-se que nossa função insere(x, lista) sempre insere no início. Pense em qual ordem você 
precisa chamar a função para que o resultado final fique ordenado de forma crescente.
*/

#include <stdio.h>
#include <stdlib.h>

// A struct celula
typedef struct celula {
    int conteudo;
    struct celula *prox;
} celula;

// A função insere
void insere(int x, celula *p) {
    celula *nova = malloc(sizeof(celula));
    nova->conteudo = x;
    nova->prox = p->prox;
    p->prox = nova;
}

// A função imprime
void imprime(celula *le) {
    celula *p;
    printf("Lista: ");
    for (p = le->prox; p != NULL; p = p->prox) {
        printf("%d -> ", p->conteudo);
    }
    printf("NULL\n");
}
// Função para contar os elementos
int contar_elementos(celula *le) {
    int contador = 0;
    celula *p;

    // O laço começa em le->prox para pular o nó cabeça
    for (p = le->prox; p != NULL; p = p->prox) {
        // Para cada célula real que visitamos, incrementamos o contador
        contador++;
    }

    return contador;
}


// Função principal para testar
int main() {
    celula *lista = malloc(sizeof(celula));
    lista->prox = NULL;

    printf("Inserindo30..\n");
    insere(30, lista);
    imprime(lista);

    printf("Inserindo 20...\n");
    insere(20, lista);
    imprime(lista);

    printf("Inserindo 10...\n");
    insere(10, lista);
    imprime(lista);

    free(lista->prox->prox->prox);
    free(lista->prox->prox);
    free(lista->prox);
    free(lista);

    return 0;
}