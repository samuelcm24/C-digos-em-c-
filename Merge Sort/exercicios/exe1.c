//Implementando o merge sort

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

// Função que mescla (merge) duas partes já ordenadas do vetor
void merge(int array[], int inicio, int meio, int fim) {
    // Calcula o tamanho das duas metades
    int tamanhoEsq = meio - inicio + 1;
    int tamanhoDir = fim - meio;

    // Cria vetores auxiliares para esquerda e direita
    int *esquerda = (int*) malloc(tamanhoEsq * sizeof(int));
    int *direita  = (int*) malloc(tamanhoDir * sizeof(int));

     // Copia os elementos da metade esquerda
    for (int i = 0; i < tamanhoEsq; i++)
        esquerda[i] = array[inicio + i];

    // Copia os elementos da metade direita
    for (int j = 0; j < tamanhoDir; j++)
        direita[j] = array[meio + 1 + j];

    // Índices para percorrer os vetores auxiliares e o vetor principal
    int indiceEsq = 0;       // começa no início da metade esquerda
    int indiceDir = 0;       // começa no início da metade direita
    int indiceMerge = inicio; // posição no vetor principal

    // Intercala os elementos comparando os menores de cada metade
    while (indiceEsq < tamanhoEsq && indiceDir < tamanhoDir) {
        if (esquerda[indiceEsq] <= direita[indiceDir]) {
            array[indiceMerge++] = esquerda[indiceEsq++];
        } else {
            array[indiceMerge++] = direita[indiceDir++];
        }
    }

    // Se ainda restarem elementos na metade esquerda, copia para o array
    while (indiceEsq < tamanhoEsq) {
        array[indiceMerge++] = esquerda[indiceEsq++];
    }

    // Se ainda restarem elementos na metade direita, copia para o array
    while (indiceDir < tamanhoDir) {
        array[indiceMerge++] = direita[indiceDir++];
    }

    // Libera memória usada pelos vetores auxiliares
    free(esquerda);
    free(direita);
}

// Função principal do Merge Sort
void merge_sort(int array[], int inicio, int fim) {
    if (inicio < fim) {
        // Encontra o ponto do meio para dividir o vetor
        int meio = (inicio + fim) / 2;

        // Ordena a metade esquerda
        merge_sort(array, inicio, meio);

        // Ordena a metade direita
        merge_sort(array, meio + 1, fim);

        // Junta as duas metades ordenadas
        merge(array, inicio, meio, fim);
    }
}

void imprimir_lista(int vet[], int n) {
    printf("\n=== Lista ===\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void gerar_vetor(int vet[], int n) {
    for (int i = 0; i < n; i++) {
        vet[i] = rand() % 100;
    }
}

void Gerar_vetorCrescente(int vet[], int n) {
    for (int i = 0; i < n; i++) {
        vet[i] = i;
    }
}

void Gerar_vetorDecrescente(int vet[], int n) {
    for (int i = 0; i < n; i++) {
        vet[i] = n - i - 1;
    }
}

int main() {
    int n = 10;
    int *vet = (int*) malloc(n * sizeof(int));

    gerar_vetor(vet, n);
    printf("Vetor aleatorio:");
    imprimir_lista(vet, n);

    merge_sort(vet, 0, n - 1);
    printf("Vetor ordenado:");
    imprimir_lista(vet, n);

    printf("Vetor decrescente:");
    Gerar_vetorDecrescente(vet, n);
    imprimir_lista(vet, n);

    merge_sort(vet, 0, n - 1);
    printf("Vetor ordenado:");
    imprimir_lista(vet, n);

    printf("Vetor crescente:");
    Gerar_vetorCrescente(vet, n);
    imprimir_lista(vet, n);

    merge_sort(vet, 0, n - 1);
    printf("Vetor ordenado:");
    imprimir_lista(vet, n);


    free(vet);
    return 0;
}
