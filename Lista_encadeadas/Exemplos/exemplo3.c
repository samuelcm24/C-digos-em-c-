/*Exemplo 4: Remoção de um Elemento
Objetivo: Usar a busca para encontrar um elemento e removê-lo, ajustando os ponteiros para "pular" a 
célula removida.*/

#include <stdio.h>
#include <stdlib.h>

// ... (struct celula, imprime, busca aqui) ...
typedef struct celula { int conteudo; struct celula *prox; } celula;
void imprime(celula *le) { /* ... */ }
celula* busca(int x, celula *le) { /* ... */ }
void insere_depois(int x, celula *p) { /* ... */ }


// Função para remover um elemento com conteúdo 'x'
void busca_e_remove(int x, celula *le) {
    // 1. Encontra a célula ANTERIOR à que queremos remover
    celula *p = busca(x, le);

    if (p != NULL) {
        // 2. 'morta' é a célula que queremos remover
        celula *morta = p->prox;
        
        // 3. O 'prox' da anterior agora pula a célula 'morta'
        p->prox = morta->prox;

        // 4. Libera a memória da célula removida
        free(morta);
    } else {
        printf("Elemento %d nao encontrado para remocao.\n", x);
    }
}
/*

int main() {
    // ... (cria a lista 30 -> 20 -> 10 -> NULL) ...

    printf("Lista original: ");
    imprime(lista);

    printf("\nRemovendo o 20...\n");
    busca_e_remove(20, lista);
    printf("Lista apos remocao: ");
    imprime(lista);

    printf("\nTentando remover o 99 (nao existe)...\n");
    busca_e_remove(99, lista);

    // ... (liberar memória) ...
    return 0;
}
*/