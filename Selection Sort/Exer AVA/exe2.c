/* Escreva uma função que permute os elementos de um vetor inteiro v[0..n-1] 
de modo que eles fiquem 
em ordem decrescente. Inspire-se no algoritmo Selectionsort*/

#include <stdio.h>

void selectionSortDecrescente(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max = i; // índice do maior elemento
        for (int j = i + 1; j < n; j++) {
            if (v[j] > v[max]) {
                max = j;
            }
        }
        // troca v[i] com v[max]
        if (max != i) {
            int temp = v[i];
            v[i] = v[max];
            v[max] = temp;
        }
    }
}

void imprimir(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int v[] = {5, 1, 9, 3, 7, 2};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Vetor original: ");
    imprimir(v, n);

    selectionSortDecrescente(v, n);

    printf("Vetor em ordem decrescente: ");
    imprimir(v, n);

    return 0;
}
