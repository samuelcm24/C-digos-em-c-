#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int comparacoes = 0;

// Função Insertion Sort com contagem de comparações
void insertionSort(long long int *arr, long long int n) {
    for (long long int i = 1; i < n; i++) {
        long long int chave = arr[i];
        long long int j = i - 1;

        while (j >= 0) {
            comparacoes++;
            if (arr[j] > chave) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = chave;
    }
}

// Funções base fornecidas (corrigida a decrescente)
long long int *arranjoCrescente(long long int tamanho) {
    long long int *vetor = (long long int *)malloc(tamanho * sizeof(long long int));
    for (long long int i = 0; i < tamanho; i++)
        vetor[i] = i;
    return vetor;
}

long long int *arranjoDecrescente(long long int tamanho) {
    long long int *vetor = (long long int *)malloc(tamanho * sizeof(long long int));
    for (long long int i = 0; i < tamanho; i++)
        vetor[i] = tamanho - i;
    return vetor;
}

long long int *arranjo(long long int tamanho) {
    long long int *vetor = (long long int *)malloc(tamanho * sizeof(long long int));
    srand(time(NULL));
    for (long long int i = 0; i < tamanho; i++)
        vetor[i] = rand();
    return vetor;
}

int main() {
    long long int n = 100000;  // tamanho do vetor
    clock_t inicio, fim;
    double tempo;

    // ---------- Crescente ----------
    long long int *vetC = arranjoCrescente(n);
    comparacoes = 0;
    inicio = clock();
    insertionSort(vetC, n);
    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Crescente:\nTempo: %.2f s | Comparacoes: %lld\n\n", tempo, comparacoes);
    free(vetC);

    // ---------- Decrescente ----------
    long long int *vetD = arranjoDecrescente(n);
    comparacoes = 0;
    inicio = clock();
    insertionSort(vetD, n);
    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Decrescente:\nTempo: %.2f s | Comparacoes: %lld\n\n", tempo, comparacoes);
    free(vetD);

    // ---------- Aleatório ----------
    long long int *vetA = arranjo(n);
    comparacoes = 0;
    inicio = clock();
    insertionSort(vetA, n);
    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Aleatorio:\nTempo: %.2f s | Comparacoes: %lld\n\n", tempo, comparacoes);
    free(vetA);

    return 0;
}
