/*Exemplo 1: A Lista Mais Simples (Criar e Inserir 1 Elemento)
Objetivo: Ver o "nó cabeça" em ação e como um único elemento é ligado a ele.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int conteudo;
    struct celula *prox;
} celula;

// Imprime a lista a partir do nó cabeça 'le'
void imprime(celula *le) {
    // p começa no primeiro elemento REAL (o que vem depois da cabeça)
    for (celula *p = le->prox; p != NULL; p = p->prox) {
        printf("%d -> ", p->conteudo);
    }
    printf("NULL\n");
}

int main() {
    // 1. Cria o nó cabeça. A lista "existe", mas está vazia.
    celula *lista = malloc(sizeof(celula));
    lista->prox = NULL;

    printf("Acabei de criar a lista. Ela esta assim: ");
    imprime(lista);

    // 2. Criando a primeira célula REAL
    celula *nova = malloc(sizeof(celula));
    nova->conteudo = 42;
    nova->prox = NULL; // Ela ainda não está ligada a ninguém

    // 3. Ligando a nova célula à lista
    // O 'prox' do nó cabeça agora aponta para a nova célula
    lista->prox = nova;

    printf("Depois de inserir o elemento 42: ");
    imprime(lista);

    // Liberando a memória
    free(nova);
    free(lista);

    return 0;
}