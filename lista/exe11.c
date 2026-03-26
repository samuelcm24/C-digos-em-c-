#include <stdio.h>
#include <stdbool.h>

#define CAPACIDADE 5

typedef struct {
    int itens[CAPACIDADE];
    int inicio;
    int fim;
    int tamanho;
} FilaCircular;

void inicializarFila(FilaCircular *f) {
    f->inicio = -1;
    f->fim = -1;
    f->tamanho = 0;
}

bool filaVazia(FilaCircular *f) {
    return f->tamanho == 0;
}

bool filaCheia(FilaCircular *f) {
    return f->tamanho == CAPACIDADE;
}

int tamanho(FilaCircular *f) {
    return f->tamanho;
}

void enfileirar(FilaCircular *f, int valor) {
    if (filaCheia(f)) {
        printf("Erro: A fila está cheia! (Overflow)\n");
        return;
    }
    if (filaVazia(f)) {
        f->inicio = 0;
    }
    f->fim = (f->fim + 1) % CAPACIDADE;
    f->itens[f->fim] = valor;
    f->tamanho++;
    printf("Valor %d enfileirado.\n", valor);
}

int desenfileirar(FilaCircular *f) {
    if (filaVazia(f)) {
        printf("Erro: A fila está vazia! (Underflow)\n");
        return -1;
    }
    int itemRemovido = f->itens[f->inicio];
    if (f->inicio == f->fim) {
        inicializarFila(f);
    } else {
        f->inicio = (f->inicio + 1) % CAPACIDADE;
        f->tamanho--;
    }
    printf("Valor %d desenfileirado.\n", itemRemovido);
    return itemRemovido;
}

int frente(FilaCircular *f) {
    if (filaVazia(f)) {
        printf("Erro: A fila está vazia!\n");
        return -1;
    }
    return f->itens[f->inicio];
}

void imprimirFila(FilaCircular *f) {
    if (filaVazia(f)) {
        printf("Fila: [] (vazia)\n");
        return;
    }
    printf("Fila: [ ");
    int i = f->inicio;
    for (int count = 0; count < f->tamanho; ++count) {
        printf("%d ", f->itens[i]);
        i = (i + 1) % CAPACIDADE;
    }
    printf("]\n");
    printf("(Início: %d, Fim: %d, Tamanho: %d)\n", f->inicio, f->fim, tamanho(f));
}

int main() {
    FilaCircular minhaFila;
    inicializarFila(&minhaFila);

    printf("--- Testando a Fila Circular ---\n");
    
    printf("\nFila está vazia? %s\n", filaVazia(&minhaFila) ? "Sim" : "Não");

    enfileirar(&minhaFila, 10);
    enfileirar(&minhaFila, 20);
    enfileirar(&minhaFila, 30);
    imprimirFila(&minhaFila);

    printf("\nElemento da frente: %d\n", frente(&minhaFila));

    desenfileirar(&minhaFila);
    imprimirFila(&minhaFila);

    enfileirar(&minhaFila, 40);
    enfileirar(&minhaFila, 50);
    enfileirar(&minhaFila, 60);
    imprimirFila(&minhaFila);
    
    printf("\nFila está cheia? %s\n", filaCheia(&minhaFila) ? "Sim" : "Não");

    desenfileirar(&minhaFila);
    desenfileirar(&minhaFila);
    desenfileirar(&minhaFila);
    desenfileirar(&minhaFila);
    desenfileirar(&minhaFila);
    imprimirFila(&minhaFila);

    return 0;
}