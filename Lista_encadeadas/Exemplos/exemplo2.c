/*Exemplo 3: Busca por um Elemento
Objetivo: Percorrer a lista para encontrar um valor. 
É a base para operações de remoção e atualização.*/

#include <stdio.h>
#include <stdlib.h>

// ... (struct celula e a função imprime aqui) ...
typedef struct celula { int conteudo; struct celula *prox; } celula;
void imprime(celula *le) { /* ... */ }

// Função que busca por 'x' e retorna um ponteiro para a CÉLULA ANTERIOR.
// Retorna o ponteiro para a célula cujo 'prox' contém 'x'.
// Retorna NULL se não encontrar.
celula* busca(int x, celula *le) {
    celula *p;
    // Começamos da cabeça, pois queremos o ANTERIOR ao que contém 'x'
    for (p = le; p->prox != NULL; p = p->prox) {
        if (p->prox->conteudo == x) {
            return p; // Encontrei! Retorno o ponteiro para a célula ANTERIOR.
        }
    }
    return NULL; // Não encontrei, p->prox chegou a NULL.
}

int main() {
    celula *lista, *p;
    // ... (código para criar a lista 30 -> 20 -> 10 -> NULL aqui) ...
    
    // Teste 1: Buscar o 20
    printf("Buscando pelo 20...\n");
    p = busca(20, lista);
    if (p != NULL) {
        // p aponta para a célula com o 30, pois p->prox->conteudo é 20
        printf("Encontrei! O elemento anterior ao 20 tem o conteudo: %d\n", p->conteudo);
    } else {
        printf("Elemento 20 nao encontrado.\n");
    }

    // Teste 2: Buscar o 99 (não existe)
    printf("Buscando pelo 99...\n");
    p = busca(99, lista);
    if (p != NULL) {
        printf("Encontrei o 99 (isso nao deveria acontecer).\n");
    } else {
        printf("Elemento 99 nao encontrado, como esperado.\n");
    }
    
    // ... (código para liberar a memória aqui) ...
    return 0;
}