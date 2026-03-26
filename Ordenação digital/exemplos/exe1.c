#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int *arranjoCrescente(long long int tamanho) {
    long long int *vetor = (long long int *) malloc(tamanho * sizeof(long long int));
    for (long long int i = 0; i < tamanho; i++) {
        vetor[i] = i;
    }
    return vetor;
}

long long int *arranjoDecrescente(long long int tamanho) {
    long long int *vetor = (long long int *) malloc(tamanho * sizeof(long long int));
    for (long long int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - 1 - i;
    }
    return vetor;
}

long long int *arranjoAleatorio(long long int tamanho) {
    long long int *vetor = (long long int *) malloc(tamanho * sizeof(long long int));
    for (long long int i = 0; i < tamanho; i++) {
        vetor[i] = rand();
    }
    return vetor;
}

void insertionsort_instrumentado(long long int n, long long int v[], long long int *p_comparacoes) {
    *p_comparacoes = 0; 
    for (long long int j = 1; j < n; ++j) {
        long long int x = v[j]; 
        long long int i;  
        
        for (i = j - 1; i >= 0; --i) {
             (*p_comparacoes)++;
            if (v[i] > x) {
                v[i + 1] = v[i];
            } else {
                break;
            }
        }
        v[i + 1] = x;
    }
}

int main() {
    srand(time(NULL));

    const long long int n = 100000;
    clock_t inicio, fim;
    double tempo;
    long long int comparacoes; 

    long long int *vetor1 = arranjoCrescente(n);
    inicio = clock();
    insertionsort_instrumentado(n, vetor1, &comparacoes);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Ordenado Crescente -> Comparacoes: %lld | Tempo: %.4f s\n", comparacoes, tempo);
    free(vetor1);

    long long int *vetor2 = arranjoDecrescente(n);
    inicio = clock();
    insertionsort_instrumentado(n, vetor2, &comparacoes); 
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Ordenado Decrescente -> Comparacoes: %lld | Tempo: %.3f s\n", comparacoes, tempo);
    free(vetor2);

    long long int *vetor3 = arranjoAleatorio(n);
    inicio = clock();
    insertionsort_instrumentado(n, vetor3, &comparacoes); 
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Aleatorio -> Comparacoes: %lld | Tempo: %.3f s\n", comparacoes, tempo);
    free(vetor3);

    return 0;
}