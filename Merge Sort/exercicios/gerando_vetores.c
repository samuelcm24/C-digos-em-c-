//Implementação para gerar vetores em ordem aleatória, crescente e decrescente

#include <stdio.h>
#include <stdlib.h>

void merge(int vet[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int *L = (int*) malloc(n1 * sizeof(int));
    int *R = (int*) malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = vet[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = vet[q + 1 + j];

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vet[k++] = L[i++];
        } else {
            vet[k++] = R[j++];
        }
    }

    while (i < n1) vet[k++] = L[i++];
    while (j < n2) vet[k++] = R[j++];

    free(L);
    free(R);
}

void merge_sort(int vet[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(vet, p, q);
        merge_sort(vet, q + 1, r);
        merge(vet, p, q, r);
    }
}

void imprimir_lista(int vet[], int n) {
    printf("\n=== Lista ===\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void gerar_vetor(int vet[], int n) {
    for (int i = 0; i < n; i++) {
        vet[i] = rand() % 100;
    }
}

void Gerar_vetorCrescente(int vet[], int n) {
    for (int i = 0; i < n; i++) {
        vet[i] = i;
    }
}

void Gerar_vetorDecrescente(int vet[], int n) {
    for (int i = 0; i < n; i++) {
        vet[i] = n - i - 1;
    }
}

int main() {
    int n = 1000000;
    int *vet = (int*) malloc(n * sizeof(int));

    gerar_vetor(vet, n);
    printf("Vetor aleatorio:");
    imprimir_lista(vet, n);

    merge_sort(vet, 0, n - 1);
    printf("Vetor ordenado:");
    imprimir_lista(vet, n);

    printf("Vetor decrescente:");
    Gerar_vetorDecrescente(vet, n);
    imprimir_lista(vet, n);

    merge_sort(vet, 0, n - 1);
    printf("Vetor ordenado:");
    imprimir_lista(vet, n);

    printf("Vetor crescente:");
    Gerar_vetorCrescente(vet, n);
    imprimir_lista(vet, n);

    merge_sort(vet, 0, n - 1);
    printf("Vetor ordenado:");
    imprimir_lista(vet, n);


    free(vet);
    return 0;
}