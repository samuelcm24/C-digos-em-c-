
/*Teste de correção.  Escreva um programa para testar, experimentalmente, a correção de sua 
implementação do algoritmo Insertionsort. Faça testes com vetores inteiros aleatórios de vários tamanhos.
 Depois de cada teste, seu programa deve verificar se o resultado está, de fato, em ordem crescente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// ---------- Função de ordenação (Insertion Sort) ----------
void insertionSort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int aux = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > aux) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = aux;
    }
}

// ---------- Função que verifica se o vetor está ordenado ----------
bool verifica(int v[], int n) {
    for (int i = 1; i < n; i++) {
        if (v[i-1] > v[i]) return false; 
    }
    return true;
}

// ---------- Função auxiliar para imprimir o vetor ----------
void imprimeVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}



// ---------- Programa principal ----------
int main() {
    srand(time(NULL));

    int tamanhos[] = {5, 10}; // tamanhos de vetores para teste
    int numTestes = sizeof(tamanhos) / sizeof(tamanhos[0]);

    for (int t = 0; t < numTestes; t++) {
        int n = tamanhos[t];
        int *v = (int*) malloc(n * sizeof(int));

        // gera vetor aleatório
        for (int i = 0; i < n; i++) {
            v[i] = rand() % 100;  // números entre 0 e 99
        }

        printf("Vetor original (n=%d):\n", n);
        imprimeVetor(v, n);

        // ordena
        insertionSort(v, n);

        printf("Vetor ordenado:\n");
        imprimeVetor(v, n);

        // verifica se está em ordem crescente
        if (verifica(v, n)) {
            printf("Correto: vetor esta ordenado.\n\n");
        } else {
            printf("ERRO: vetor NAO esta ordenado!\n\n");
        }

        free(v);
    }

    return 0;
}