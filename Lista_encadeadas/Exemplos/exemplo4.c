/*Exemplo 2: Inserção no Início (A Pilha)
Objetivo: Mostrar como a inserção "depois do nó cabeça" efetivamente adiciona elementos no início da lista, 
criando um comportamento de pilha (o último a entrar é o primeiro a sair).*/

#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int conteudo;
    struct celula* prox;
} celula;

// A função 'insere' do material do professor
void insere_depois(int x, celula *p) {
    celula *nova = malloc(sizeof(celula));
    nova->conteudo = x;
    nova->prox = p->prox;
    p->prox = nova;
}

void imprime(celula *le) {
    for (celula *p = le->prox; p != NULL; p = p->prox) {
        printf("%d -> ", p->conteudo);
    }
    printf("NULL\n");
}

int main() {
    // Cria o nó cabeça
    celula *lista = malloc(sizeof(celula));
    lista->prox = NULL;

    printf("Inserindo 10...\n");
    insere_depois(10, lista); // Insere DEPOIS do nó cabeça
    imprime(lista);

    printf("Inserindo 20...\n");
    insere_depois(20, lista); // Insere DEPOIS do nó cabeça (empurra o 10 para frente)
    imprime(lista);

    printf("Inserindo 30...\n");
    insere_depois(30, lista); // Insere DEPOIS do nó cabeça (empurra o 20 para frente)
    imprime(lista);

    // Liberar a memória será nosso próximo tópico!
    free(lista->prox->prox->prox);
    free(lista->prox->prox);
    free(lista->prox);
    free(lista);

    return 0;
}