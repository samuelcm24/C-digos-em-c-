//Comparação com Outros Algoritmos

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comparacoes = 0;
long long trocas = 0;

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

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    trocas++;
}

void heapify(int v[], int n, int i) {
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;
    int maior = i;

    if (esq < n) {
        comparacoes++;
        if (v[esq] > v[maior]) maior = esq;
    }

    if (dir < n) {
        comparacoes++;
        if (v[dir] > v[maior]) maior = dir;
    }

    if (maior != i) {
        troca(&v[i], &v[maior]);
        heapify(v, n, maior);
    }
}

void buildHeap(int v[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(v, n, i);
    }
}

void heapSort(int v[], int n) {
    buildHeap(v, n);
    for (int i = n - 1; i >= 1; i--) {
        troca(&v[0], &v[i]);
        heapify(v, i, 0);
    }
}

void insertionSort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = v[i];
        int j = i - 1;
        while (j >= 0) {
            comparacoes++;
            if (v[j] > chave) {
                v[j+1] = v[j];
                trocas++;
            } else break;
            j--;
        }
        v[j+1] = chave;
    }
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
        trocas++;
    }
    while (i < n1) v[k++] = L[i++];
    while (j < n2) v[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int p, int r, int v[]) {
    if (p < r - 1) {
        int q = (p + r) / 2;
        mergeSort(p, q, v);
        mergeSort(q, r, v);
        intercala(p, q, r, v);
    }
}

void mergeSortWrapper(int v[], int n) {
    mergeSort(0, n, v);
}

void testar(int n, char* desc, int* (*gerador)(int), void (*algoritmo)(int*, int)) {
    int* v = gerador(n);
    comparacoes = 0;
    trocas = 0;
    clock_t inicio = clock();

    algoritmo(v, n);

    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("%s | Tamanho: %d | Comparações: %lld | Trocas: %lld | Tempo: %.5f s\n",
           desc, n, comparacoes, trocas, tempo);

    free(v);
}

int main() {
    int tamanhos[] = {1000, 10000, 100000};
    int numTamanhos = sizeof(tamanhos)/sizeof(tamanhos[0]);

    for (int i = 0; i < numTamanhos; i++) {
        int n = tamanhos[i];

        printf("------ HeapSort ------\n");
        testar(n, "Crescente", arranjoCrescente, heapSort);
        testar(n, "Decrescente", arranjoDecrescente, heapSort);
        testar(n, "Aleatorio", arranjoAleatorio, heapSort);

        printf("\n------ InsertionSort ------\n");
        testar(n, "Crescente", arranjoCrescente, insertionSort);
        testar(n, "Decrescente", arranjoDecrescente, insertionSort);
        testar(n, "Aleatorio", arranjoAleatorio, insertionSort);

        printf("\n------ MergeSort ------\n");
        testar(n, "Crescente", arranjoCrescente, mergeSortWrapper);
        testar(n, "Decrescente", arranjoDecrescente, mergeSortWrapper);
        testar(n, "Aleatorio", arranjoAleatorio, mergeSortWrapper);

        printf("---------------------------------------------------\n");
    }

    return 0;
}