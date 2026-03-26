//Escreva uma versão recursiva do algoritmo de ordenação por seleção.

/*
// Função auxiliar: encontra o índice do menor elemento em vet[inicio..n-1]
int indiceMinimo(int vet[], int inicio, int n) {
    int min = inicio;
    for (int i = inicio + 1; i < n; i++) {
        if (vet[i] < vet[min])
            min = i;
    }
    return min;
}

// Selection Sort recursivo
void selectionSortRecursivo(int vet[], int inicio, int n) {
    // Caso base: vetor de tamanho 0 ou 1 já está ordenado
    if (inicio >= n - 1) return;

    // Encontra o menor elemento a partir de "inicio"
    int min = indiceMinimo(vet, inicio, n);

    // Troca vet[inicio] com vet[min]
    if (min != inicio) {
        int temp = vet[inicio];
        vet[inicio] = vet[min];
        vet[min] = temp;
    }

    // Chamada recursiva para o restante do vetor
    selectionSortRecursivo(vet, inicio + 1, n);
}

// Função para imprimir vetor
void imprimir(int vet[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", vet[i]);
    printf("\n");
}

int main() {
    int vet[] = {64, 25, 12, 22, 11};
    int n = sizeof(vet) / sizeof(vet[0]);

    printf("Vetor original: ");
    imprimir(vet, n);

    selectionSortRecursivo(vet, 0, n);

    printf("Vetor ordenado: ");
    imprimir(vet, n);

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

void indiceMinimo(int vet[], int n, int inicio){
    int min = inicio;
    for(int i = inicio + 1; i < n; i++){
        if(vet[i] < vet[min]){
            min = i;
        }
    }
}