//Implementar Heap Sort
#include <stdio.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int v[], int n, int i) {
    int esq = 2 * i;       
    int dir = 2 * i + 1;   
    int maior = i;

    if (esq <= n && v[esq] > v[maior]) {
        maior = esq;
    }

    if (dir <= n && v[dir] > v[maior]) {
        maior = dir;
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

int main() {
    int v[] = {0, 41, 161, 101, 141, 71, 91, 31, 21, 81, 17, 16};
    int n = 11;

    printf("Antes do HeapSort:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    heapSort(v, n);

    printf("Depois do HeapSort (ordenado):\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
