/* Escreva uma versão recursiva do algoritmo Mergesort que rearranje um vetor v[p..r-1] em ordem decrescente.  
Sua função deve conter o código da intercalação 
(que deve começar com v[p..q-1] e v[q..r-1] decrescentes e terminar com v[p..r-1] decrescente).*/

#include <stdio.h>
#include <stdlib.h>

void mergeSortDecrescente(int v[], int p, int r) {
    if (r - p <= 1) return; // caso base: 0 ou 1 elemento

    int q = (p + r) / 2;

    // Ordena recursivamente as duas metades
    mergeSortDecrescente(v, p, q);
    mergeSortDecrescente(v, q, r);

    // Intercala v[p..q-1] e v[q..r-1] em ordem decrescente
    int n = r - p;
    int* temp = (int*) malloc(n * sizeof(int));
    int i = p;     // início da primeira metade
    int j = q;     // início da segunda metade
    int k = 0;     // índice do vetor temporário

    while (i < q && j < r) {
        if (v[i] >= v[j]) {
            temp[k++] = v[i++];
        } else {
            temp[k++] = v[j++];
        }
    }

    // Copia o restante da primeira metade
    while (i < q) temp[k++] = v[i++];
    // Copia o restante da segunda metade
    while (j < r) temp[k++] = v[j++];

    // Copia de volta para v[p..r-1]
    for (i = 0; i < n; i++) {
        v[p + i] = temp[i];
    }

    free(temp);
}

// Função auxiliar para imprimir vetor
void imprime(int v[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", v[i]);
    printf("\n");
}

// Exemplo de uso
int main() {
    int v[] = {12, 4, 2, 6, 11, 7, 21};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Vetor original: ");
    imprime(v, n);

    mergeSortDecrescente(v, 0, n);

    printf("Vetor decrescente: ");
    imprime(v, n);

    return 0;
}
