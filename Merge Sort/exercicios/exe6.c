/*  O número de inversões de um vetor v[0..n-1] é o número de pares ordenados (i,j) tais que  
0 ≤ i < j < n  e  v[i] > v[j].  Escreva uma função que calcule o número de inversões de um vetor dado. 
O consumo de tempo de sua função deve ser proporcional a n log n no pior caso.
*/
#include <stdio.h>
#include <stdlib.h>

// Função que intercala dois subvetores e conta inversões
long long mergeCount(int v[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int* L = (int*) malloc(n1 * sizeof(int));
    int* R = (int*) malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = v[p + i];
    for (int i = 0; i < n2; i++) R[i] = v[q + 1 + i];

    long long inversoes = 0;
    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k++] = L[i++];
        } else {
            v[k++] = R[j++];
            inversoes += n1 - i; // L[i..n1-1] são maiores que R[j]
        }
    }

    while (i < n1) v[k++] = L[i++];
    while (j < n2) v[k++] = R[j++];

    free(L);
    free(R);
    return inversoes;
}

// Função recursiva que conta inversões em v[p..r]
long long countInversions(int v[], int p, int r) {
    long long inversoes = 0;
    if (p < r) {
        int q = (p + r) / 2;
        inversoes += countInversions(v, p, q);
        inversoes += countInversions(v, q + 1, r);
        inversoes += mergeCount(v, p, q, r);
    }
    return inversoes;
}

// Exemplo de uso
int main() {
    int v[] = {2, 3, 8, 6, 1};
    int n = sizeof(v) / sizeof(v[0]);

    long long inversoes = countInversions(v, 0, n - 1);
    printf("Número de inversões: %lld\n", inversoes);

    return 0;
}