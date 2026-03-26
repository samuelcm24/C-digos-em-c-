/*Escreva uma função que receba um inteiro x e um vetor v[0..n-1] de inteiros em ordem 
crescente e insira x no vetor de modo a manter a ordem crescente.
*/
#include <stdio.h>

// Função para inserir x em vetor ordenado v[0..n-1]
void inserir_ordenado(int v[], int *n, int x) {
    int i = *n - 1;

    // Desloca elementos maiores que x para a direita
    while (i >= 0 && v[i] > x) {
        v[i + 1] = v[i];
        i--;
    }

    // Insere x na posição correta
    v[i + 1] = x;

    // Atualiza o tamanho do vetor
    (*n)++;
}

// Função para imprimir vetor
void imprimir_lista(int v[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main() {
    int v[10] = {1, 3, 5, 7}; // vetor já ordenado
    int n = 4;                 // tamanho atual
    int x = 4;                 // elemento a inserir

    printf("Vetor original: ");
    imprimir_lista(v, n);

    inserir_ordenado(v, &n, x);

    printf("Vetor após inserir %d: ", x);
    imprimir_lista(v, n);

    return 0;
}
