/*Seja v[0 . . n−1] um vetor de números inteiros, todos diferentes entre si.  A mediana do vetor é um
 elemento do vetor que seja maior que metade dos elementos do vetor e menor que (a outra) metade dos 
 elementos.  Mais exatamente, a mediana de v[0 . . n−1] é um número m que seja igual a algum elemento do
 vetor e estritamente maior que exatamente ⌊(n−1)/2⌋ elementos do vetor.  (Não confunda mediana com média. 
 Por exemplo, a média de  1 2 99  é  51, enquanto a mediana é 2.)  Escreva um algoritmo que encontre a mediana 
 de um vetor v[0 . . n−1] de inteiros distintos dois a dois.*/

#include <stdio.h>
#include <stdlib.h>

int partition(int v[], int l, int r) {
    int pivot = v[r];
    int i = l;
    for (int j = l; j < r; j++) {
        if (v[j] < pivot) {
            int temp = v[i]; v[i] = v[j]; v[j] = temp;
            i++;
        }
    }
    int temp = v[i]; v[i] = v[r]; v[r] = temp;
    return i;
}

int quickSelect(int v[], int l, int r, int k) {
    if (l == r) return v[l];
    int pi = partition(v, l, r);
    if (k == pi) return v[pi];
    else if (k < pi) return quickSelect(v, l, pi - 1, k);
    else return quickSelect(v, pi + 1, r, k);
}

int mediana(int v[], int n) {
    return quickSelect(v, 0, n - 1, n / 2);
}

int main() {
    int v[] = {7, 2, 5};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Mediana: %d\n", mediana(v, n));

    return 0;
}