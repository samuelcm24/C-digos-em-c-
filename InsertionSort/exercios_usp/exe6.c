/*Busca binária.  O papel do for interno na função insertionsort é encontrar o ponto onde v[j] 
deve ser inserido em v[0..j-1]. Considere fazer isso com uma busca binária. Analise o resultado.
*/

#include <stdio.h>

// Busca binária para encontrar posição correta
int buscaBinaria(int v[], int x, int inicio, int fim) {
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (x < v[meio])
            fim = meio - 1;
        else
            inicio = meio + 1;
    }
    return inicio; // posição onde x deve ser inserido
}

void insertionSortBinario(int v[], int n) {
    for (int j = 1; j < n; j++) {
        int x = v[j];
        // encontra posição correta no subvetor ordenado v[0..j-1]
        int pos = buscaBinaria(v, x, 0, j - 1);

        // desloca os elementos maiores que x para a direita
        for (int k = j - 1; k >= pos; k--) {
            v[k + 1] = v[k];
        }

        v[pos] = x; // insere x na posição
    }
}

void printVet(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int v[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Original: ");
    printVet(v, n);

    insertionSortBinario(v, n);

    printf("Ordenado: ");
    printVet(v, n);

    return 0;
}
