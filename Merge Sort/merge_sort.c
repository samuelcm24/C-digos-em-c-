#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int comparacoes = 0;

int* arranjoCrescente(int n) {
    int* v = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) v[i] = i;
    return v;
}

int* arranjoDecrescente(int n) {
    int* v = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) v[i] = n - 1 - i;
    return v;
}

int* arranjoAleatorio(int n) {
    int* v = (int*) malloc(n * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < n; i++) v[i] = rand();
    return v;
}

void intercala(int p, int q, int r, int v[]) {
    int n1 = q - p;
    int n2 = r - q;
    int* L = (int*) malloc(n1 * sizeof(int));
    int* R = (int*) malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = v[p + i];
    for (int i = 0; i < n2; i++) R[i] = v[q + i];

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        comparacoes++;
        if (L[i] <= R[j]) v[k++] = L[i++];
        else v[k++] = R[j++];
    }
    while (i < n1) v[k++] = L[i++];
    while (j < n2) v[k++] = R[j++];

    free(L);
    free(R);
}

void mergesort(int p, int r, int v[]) {
    if (p < r-1) {
        int q = (p + r) / 2;
        mergesort(p, q, v);
        mergesort(q, r, v);
        intercala(p, q, r, v);
    }
}

void testar(int n, char* desc, int* (*gerador)(int)) {
    int* v = gerador(n);
    comparacoes = 0;
    clock_t inicio = clock();

    mergesort(0, n, v);

    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("%s | Tamanho: %d | Comparações: %lld | Tempo: %.5f s\n",
           desc, n, comparacoes, tempo);

    free(v);
}

int main() {
    int tamanhos[] = {10000000, 100000000, 200000000};
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