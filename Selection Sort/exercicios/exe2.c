
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

void selectionSort_instrumentado(long long int n, long long int v[],
                                 long long int *p_comparacoes,
                                 long long int *p_trocas) {
    *p_comparacoes = 0; 
    *p_trocas = 0;      

    for (long long int i = 0; i < n - 1; i++) {
        long long int menor_idx = i;
        for (long long int j = i + 1; j < n; j++) {
            (*p_comparacoes)++;  
            if (v[j] < v[menor_idx]) {
                menor_idx = j;
            }
        }

        if (menor_idx != i) {
            long long int temp = v[i];
            v[i] = v[menor_idx];
            v[menor_idx] = temp;
            (*p_trocas)++;   // conta a troca
        }
    }
}

int main() {
    srand(time(NULL));

    const long long int n = 10000;
    clock_t inicio, fim;
    double tempo;
    long long int comparacoes, trocas;

    long long int *vetor1 = arranjoCrescente(n);
    inicio = clock();
    selectionSort_instrumentado(n, vetor1, &comparacoes, &trocas);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Arranjo Crescente   -> Comp: %lld | Trocas: %lld | Tempo: %.3f s\n", comparacoes, trocas, tempo);
    free(vetor1);

    long long int *vetor2 = arranjoDecrescente(n);
    inicio = clock();
    selectionSort_instrumentado(n, vetor2, &comparacoes, &trocas);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Arranjo Decrescente -> Comp: %lld | Trocas: %lld | Tempo: %.3f s\n", comparacoes, trocas, tempo);
    free(vetor2);

    long long int *vetor3 = arranjoAleatorio(n);
    inicio = clock();
    selectionSort_instrumentado(n, vetor3, &comparacoes, &trocas);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Arranjo Aleatorio   -> Comp: %lld | Trocas: %lld | Tempo: %.3f s\n", comparacoes, trocas, tempo);
    free(vetor3);

    return 0;
}
