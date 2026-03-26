/*Exemplo de Código (Fila de Inteiros com Lista Encadeada):

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

// Inicializa a fila
void inicializar(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

// Verifica se a fila está vazia
int estaVazia(Fila *f) {
    return f->inicio == NULL;
}

// Enfileira um elemento
void enfileirar(Fila *f, int valor) {
    No *novoNo = (No*) malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro: Falha na alocacao de memoria!\n");
        return;
    }
    novoNo->dado = valor;
    novoNo->proximo = NULL;

    if (estaVazia(f)) {
        f->inicio = novoNo;
    } else {
        f->fim->proximo = novoNo;
    }
    f->fim = novoNo;
}

// Desenfileira um elemento
int desenfileirar(Fila *f) {
    if (estaVazia(f)) {
        printf("Erro: Fila vazia!\n");
        return -1; // Retorno de erro
    }
    No *temp = f->inicio;
    int item = temp->dado;
    f->inicio = f->inicio->proximo;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(temp);
    return item;
}

// Mostra o elemento do início da fila
int espiar(Fila *f) {
    if (estaVazia(f)) {
        printf("Erro: Fila vazia!\n");
        return -1; // Retorno de erro
    }
    return f->inicio->dado;
}

int main() {
    Fila minhaFila;
    inicializar(&minhaFila);

    enfileirar(&minhaFila, 10);
    enfileirar(&minhaFila, 20);
    enfileirar(&minhaFila, 30);

    printf("Elemento do inicio: %d\n", espiar(&minhaFila));

    printf("Desenfileirado: %d\n", desenfileirar(&minhaFila));
    printf("Novo elemento do inicio: %d\n", espiar(&minhaFila));

    while (!estaVazia(&minhaFila)) {
        printf("Desenfileirando: %d\n", desenfileirar(&minhaFila));
    }

    printf("Fila esta vazia? %s\n", estaVazia(&minhaFila) ? "Sim" : "Nao");

    return 0;
}