//Implementando o Radix sort

#include <stdio.h>
#include <stdlib.h>

// Encontra o maior valor (para saber quantos dígitos há)
int getMax(int v[], int n) {
    int max = v[0];
    for (int i = 1; i < n; i++)
        if (v[i] > max)
            max = v[i];
    return max;
}

// Counting Sort aplicado a um dígito específico (exp = 1, 10, 100...)
void countingSort(int v[], int n, int exp) {
    int *saida = (int *)malloc(n * sizeof(int));
    int count[10] = {0};

    // Conta ocorrências do dígito atual
    for (int i = 0; i < n; i++)
        count[(v[i] / exp) % 10]++;

    // Ajusta count para armazenar posição estável
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Constrói vetor de saída
    for (int i = n - 1; i >= 0; i--) {
        int digito = (v[i] / exp) % 10;
        saida[count[digito] - 1] = v[i];
        count[digito]--;
    }

    // Copia de volta para o original
    for (int i = 0; i < n; i++)
        v[i] = saida[i];

    free(saida);
}

// Função principal do Radix Sort
void radixSort(int v[], int n) {
    int max = getMax(v, n);

    // Aplica Counting Sort para cada dígito
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(v, n, exp);
}

// Teste
int main() {
    int v[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(v) / sizeof(v[0]);

    radixSort(v, n);

    printf("Ordenado:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}