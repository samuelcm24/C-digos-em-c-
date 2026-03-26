/*
Distância tau de Kendall.  Suponha dadas duas permutações, digamos x[0..n-1] e y[0..n-1], de um mesmo conjunto 
de números.  A distância tau entre x e y é o número de pares de elementos do conjunto que estão em ordem 
diferente em x e y, ou seja, a cardinalidade do conjunto X − Y onde X é o conjunto de todos os pares (x[i],x[j])
 tais que i < j e Y é o conjunto de todos os pares (y[i],y[j]) tais que i < j.  (A definição não é assimétrica 
 como parece pois os conjuntos X − Y e Y − X têm a mesma cardinalidade.)  Escreva uma função eficiente que 
 calcule a distância tau entre x e y.
*/

#include <stdio.h>
#include <stdlib.h>

// Merge e contagem de inversões
long long mergeCount(int v[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int* L = (int*) malloc(n1 * sizeof(int));
    int* R = (int*) malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) L[i] = v[p + i];
    for (int i = 0; i < n2; i++) R[i] = v[q + 1 + i];

    long long inv = 0;
    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k++] = L[i++];
        } else {
            v[k++] = R[j++];
            inv += n1 - i; // elementos restantes em L são maiores que R[j]
        }
    }
    while (i < n1) v[k++] = L[i++];
    while (j < n2) v[k++] = R[j++];
    free(L);
    free(R);
    return inv;
}

long long countInversions(int v[], int p, int r) {
    long long inv = 0;
    if (p < r) {
        int q = (p + r) / 2;
        inv += countInversions(v, p, q);
        inv += countInversions(v, q + 1, r);
        inv += mergeCount(v, p, q, r);
    }
    return inv;
}

// Função que calcula a distância de Kendall tau
long long kendallTau(int x[], int y[], int n) {
    int* posY = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        posY[y[i]] = i; // mapeia valor para posição em y
    }

    int* xMapped = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        xMapped[i] = posY[x[i]];
    }

    long long tau = countInversions(xMapped, 0, n - 1);

    free(posY);
    free(xMapped);
    return tau;
}

// Exemplo de uso
int main() {
    int x[] = {0, 1, 2, 3};
    int y[] = {1, 0, 3, 2};
    int n = sizeof(x) / sizeof(x[0]);

    long long tau = kendallTau(x, y, n);
    printf("Distância Kendall tau: %lld\n", tau);

    return 0;
}