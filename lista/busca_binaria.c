#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int* arranjoCrescente(long long int tamanho);
long long int* arranjoDecrescente(long long int tamanho);
long long int* arranjoAleatorio(long long int tamanho);
int busca_sequencial(long long int arr[], long long int n, long long int x, long long int *comparacoes);
int busca_binaria_crescente(long long int arr[], long long int n, long long int x, long long int *comparacoes);
int busca_binaria_decrescente(long long int arr[], long long int n, long long int x, long long int *comparacoes);



int main() {
    srand(time(NULL));

    long long int tamanhos[] = {10000, 100000, 1000000000000,};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    printf("| %-25s | %10s | %-28s | %12s | %12s | %15s |\n", 
           "Tipo de Arranjo", "Tamanho", "Algoritmo", "Resultado", "Tempo (s)", "Comparacoes");
    printf("|---------------------------|------------|------------------------------|--------------|--------------|-----------------|\n");

    for (int i = 0; i < num_tamanhos; i++) {
        long long int tamanho_atual = tamanhos[i];
        long long int *vetor = NULL;
        long long int valor_a_buscar = tamanho_atual / 2;

        long long int comp;
        clock_t inicio, fim;
        double tempo;
        int res;
        
        vetor = arranjoCrescente(tamanho_atual);
        inicio = clock();
        res = busca_sequencial(vetor, tamanho_atual, valor_a_buscar, &comp);
        fim = clock();
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("| %-25s | %10lld | %-28s | %12d | %12.6f | %15lld |\n", 
               "Crescente", tamanho_atual, "Sequencial", res, tempo, comp);
        inicio = clock();
        res = busca_binaria_crescente(vetor, tamanho_atual, valor_a_buscar, &comp);
        fim = clock();
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("| %-25s | %10lld | %-28s | %12d | %12.6f | %15lld |\n", 
               "Crescente", tamanho_atual, "Binaria (Crescente)", res, tempo, comp);
        free(vetor);

        vetor = arranjoDecrescente(tamanho_atual);
        inicio = clock();
        res = busca_sequencial(vetor, tamanho_atual, valor_a_buscar, &comp);
        fim = clock();
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("| %-25s | %10lld | %-28s | %12d | %12.6f | %15lld |\n", 
               "Decrescente", tamanho_atual, "Sequencial", res, tempo, comp);
        inicio = clock();
        res = busca_binaria_decrescente(vetor, tamanho_atual, valor_a_buscar, &comp);
        fim = clock();
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("| %-25s | %10lld | %-28s | %12d | %12.6f | %15lld |\n", 
               "Decrescente", tamanho_atual, "Binaria (Decrescente)", res, tempo, comp);
        free(vetor);

        vetor = arranjoAleatorio(tamanho_atual);
        inicio = clock();
        res = busca_sequencial(vetor, tamanho_atual, valor_a_buscar, &comp);
        fim = clock();
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("| %-25s | %10lld | %-28s | %12d | %12.6f | %15lld |\n", 
               "Aleatorio (Desordenado)", tamanho_atual, "Sequencial", res, tempo, comp);
        inicio = clock();
        res = busca_binaria_crescente(vetor, tamanho_atual, valor_a_buscar, &comp);
        fim = clock();
        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("| %-25s | %10lld | %-28s | %12d | %12.6f | %15lld |\n", 
               "Aleatorio (Desordenado)", tamanho_atual, "Binaria (FALHA ESPERADA)", res, tempo, comp);
        free(vetor);
        
        if (i < num_tamanhos - 1) {
            printf("|---------------------------|------------|------------------------------|--------------|--------------|-----------------|\n");
        }
    }
    return 0;
}


long long int *arranjoCrescente(long long int tamanho) {
    long long int *vetor = (long long int *)malloc(tamanho * sizeof(long long int));
    if (!vetor) return NULL;
    for (long long int i = 0; i < tamanho; i++) {
        vetor[i] = i;
    }
    return vetor;
}

long long int *arranjoDecrescente(long long int tamanho) {
    long long int *vetor = (long long int *)malloc(tamanho * sizeof(long long int));
    if (!vetor) return NULL;
    for (long long int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - 1 - i;
    }
    return vetor;
}

long long int *arranjoAleatorio(long long int tamanho) {
    long long int *vetor = (long long int *)malloc(tamanho * sizeof(long long int));
    if (!vetor) return NULL;
    for (long long int i = 0; i < tamanho; i++) {
        vetor[i] = rand();
    }
    return vetor;
}


int busca_sequencial(long long int arr[], long long int n, long long int x, long long int *comparacoes) {
    *comparacoes = 0;
    for (long long int i = 0; i < n; i++) {
        (*comparacoes)++;
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int busca_binaria_crescente(long long int arr[], long long int n, long long int x, long long int *comparacoes) {
    *comparacoes = 0;
    long long int esq = 0, dir = n - 1;
    while (esq <= dir) {
        long long int meio = esq + (dir - esq) / 2;
        (*comparacoes)++;
        if (arr[meio] == x) return meio;
        if (arr[meio] < x) esq = meio + 1;
        else dir = meio - 1;
    }
    return -1;
}

int busca_binaria_decrescente(long long int arr[], long long int n, long long int x, long long int *comparacoes) {
    *comparacoes = 0;
    long long int esq = 0, dir = n - 1;
    while (esq <= dir) {
        long long int meio = esq + (dir - esq) / 2;
        (*comparacoes)++;
        if (arr[meio] == x) return meio;
        if (arr[meio] > x) esq = meio + 1; // Lógica invertida
        else dir = meio - 1;
    }
    return -1;
}