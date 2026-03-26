/*Suponha que sua biblioteca tem uma função  mrg (p, q, r, v)  que recebe um vetor v tal que  
v[p..q] e v[q+1..r-1] são crescentes e rearranja o vetor de modo que v[p..r-1] fique crescente.  
Use mrg para implementar o algoritmo Mergesort.
*/

#include <stdio.h>

// Protótipo da função mrg (já fornecida)
void mrg(int p, int q, int r, int v[]);

// Função MergeSort usando mrg
void mergesort(int p, int r, int v[]) {
    if (r - p > 1) {          // mais de 1 elemento
        int q = (p + r) / 2;  // ponto médio
        mergesort(p, q, v);   // ordena primeira metade
        mergesort(q, r, v);   // ordena segunda metade
        mrg(p, q - 1, r, v);  // intercala v[p..q-1] e v[q..r-1]
    }
}

// Função auxiliar para imprimir vetor
void imprime(int v[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", v[i]);
    printf("\n");
}

// Exemplo de teste
int main() {
    int v[] = {12, 4, 2, 6, 11, 7, 21};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Vetor original: ");
    imprime(v, n);

    mergesort(0, n, v);

    printf("Vetor ordenado: ");
    imprime(v, n);

    return 0;
}
