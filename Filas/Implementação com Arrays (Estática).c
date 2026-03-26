/*Exemplo de Código (Fila de Inteiros com Array Circular):
*/

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 5

typedef struct {
    int itens[TAMANHO_MAX];
    int inicio;
    int fim;
    int quantidade;
} Fila;

// Inicializa a fila
void inicializar(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->quantidade = 0;
}

// Verifica se a fila está vazia
int estaVazia(Fila *f) {
    return f->quantidade == 0;
}

// Verifica se a fila está cheia
int estaCheia(Fila *f) {
    return f->quantidade == TAMANHO_MAX;
}

// Enfileira um elemento
void enfileirar(Fila *f, int valor) {
    if (estaCheia(f)) {
        printf("Erro: Fila cheia!\n");
        return;
    }
    f->fim = (f->fim + 1) % TAMANHO_MAX;
    f->itens[f->fim] = valor;
    f->quantidade++;
}

// Desenfileira um elemento
int desenfileirar(Fila *f) {
    if (estaVazia(f)) {
        printf("Erro: Fila vazia!\n");
        return -1; // Retorno de erro
    }
    int item = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % TAMANHO_MAX;
    f->quantidade--;
    return item;
}

// Mostra o elemento do início da fila
int espiar(Fila *f) {
    if (estaVazia(f)) {
        printf("Erro: Fila vazia!\n");
        return -1; // Retorno de erro
    }
    return f->itens[f->inicio];
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

    enfileirar(&minhaFila, 40);
    enfileirar(&minhaFila, 50);
    enfileirar(&minhaFila, 60); // Deve dar erro de fila cheia

    return 0;
}