/*Escreva uma função que receba vetores disjuntos x[0..m-1] e y[0..n-1], ambos em ordem crescente, 
e produza um vetor z[0..m+n-1] que contenha o resultado da intercalação dos dois vetores dados. 
Escreva duas versões da função: uma iterativa e uma recursiva.
*/

#include <stdio.h>

void mergeIterativo(int x[], int m, int y[], int n, int z[]) {
    int i = 0, j = 0, k = 0;

    // Enquanto houver elementos em ambos os vetores
    while (i < m && j < n) {
        if (x[i] <= y[j])
            z[k++] = x[i++];
        else
            z[k++] = y[j++];
    }

    // Copia o restante de x, se houver
    while (i < m)
        z[k++] = x[i++];

    // Copia o restante de y, se houver
    while (j < n)
        z[k++] = y[j++];
}


void mergeRecursivo(int x[], int m, int y[], int n, int z[]) {
    // Caso base: x vazio
    if (m == 0) {
        for (int i = 0; i < n; i++) z[i] = y[i];
        return;
    }

    // Caso base: y vazio
    if (n == 0) {
        for (int i = 0; i < m; i++) z[i] = x[i];
        return;
    }

    // Coloca o menor elemento no início de z
    if (x[0] <= y[0]) {
        z[0] = x[0];
        mergeRecursivo(x + 1, m - 1, y, n, z + 1);
    } else {
        z[0] = y[0];
        mergeRecursivo(x, m, y + 1, n - 1, z + 1);
    }
}


int main() {
    int x[] = {1, 3, 5};
    int y[] = {2, 4, 6};
    int m = sizeof(x)/sizeof(x[0]);
    int n = sizeof(y)/sizeof(y[0]);
    int z[m+n];

    // Iterativo
    mergeIterativo(x, m, y, n, z);
    printf("Merge iterativo: ");
    for (int i = 0; i < m+n; i++) printf("%d ", z[i]);
    printf("\n");

    // Recursivo
    mergeRecursivo(x, m, y, n, z);
    printf("Merge recursivo: ");
    for (int i = 0; i < m+n; i++) printf("%d ", z[i]);
    printf("\n");

    return 0;
}
