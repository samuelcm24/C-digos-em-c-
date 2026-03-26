//Casos de Entrada

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int comparacoes = 0;
long long int trocas = 0;

int* arranjoCrescente(int n) {
    int* v = (int*) malloc((n+1) * sizeof(int));
    for (int i = 1; i <= n; i++) v[i] = i;
    return v;
}

int* arranjoDecrescente(int n) {
    int* v = (int*) malloc((n+1) * sizeof(int));
    for (int i = 1; i <= n; i++) v[i] = n - i + 1;
    return v;
}

int* arranjoAleatorio(int n) {
    int* v = (int*) malloc((n+1) * sizeof(int));
    srand(time(NULL));
    for (int i = 1; i <= n; i++) v[i] = rand();
    return v;
}

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    trocas++;
}

void heapify(int v[], int n, int i) {
    int esq = 2 * i;
    int dir = 2 * i + 1;
    int maior = i;

    if (esq <= n) {
        comparacoes++;
        if (v[esq] > v[maior]) maior = esq;
    }

    if (dir <= n) {
        comparacoes++;
        if (v[dir] > v[maior]) maior = dir;
    }

    if (maior != i) {
        troca(&v[i], &v[maior]);
        heapify(v, n, maior);
    }
}

void buildHeap(int v[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        heapify(v, n, i);
    }
}

void heapSort(int v[], int n) {
    buildHeap(v, n);
    for (int i = n; i >= 2; i--) {
        troca(&v[1], &v[i]);
        heapify(v, i - 1, 1);
    }
}

void testar(int n, char* desc, int* (*gerador)(int)) {
    int* v = gerador(n);
    comparacoes = 0;
    trocas = 0;
    clock_t inicio = clock();

    heapSort(v, n);

    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("%s | Tamanho: %d | Comparações: %lld | Trocas: %lld | Tempo: %.5f s\n",
           desc, n, comparacoes, trocas, tempo);

    free(v);
}

int main() {
    int tamanhos[] = {100000, 1000000, 10000000, 100000000}; 
    int numTamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    for (int i = 0; i < numTamanhos; i++) {
        int n = tamanhos[i];
        testar(n, "Crescente", arranjoCrescente);
        testar(n, "Decrescente", arranjoDecrescente);
        testar(n, "Aleatorio", arranjoAleatorio);
        printf("---------------------------------------------------\n");
    }

    return 0;
}
