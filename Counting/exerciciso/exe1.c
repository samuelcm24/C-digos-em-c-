// Implementação do algoritmo de ordenação counting sort com valores fixos

#include <stdio.h>
#include <stdlib.h>

// Função Counting Sort
void countingSort(int vetor[], int tamanho) {
    if (tamanho <= 0) return; // Caso base: vetor vazio ou inválido

    // 1. Descobrir o valor máximo do vetor
    int max = vetor[0];  // inicializa com o primeiro elemento
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > max) {
            max = vetor[i];  // atualiza o máximo
        }
    }

    // 2. Criar o array de contagem, inicializado com zeros
    int *contagem = (int*) calloc(max + 1, sizeof(int));
    // calloc já inicializa todos os elementos com 0

    // 3. Contar quantas vezes cada valor aparece
    for (int i = 0; i < tamanho; i++) {
        contagem[vetor[i]]++;
    }

    // 4. Reescrever o vetor em ordem crescente
    int indice = 0;
    for (int i = 0; i <= max; i++) {
        while (contagem[i] > 0) {  // enquanto houver ocorrências
            vetor[indice++] = i;   // coloca o valor no vetor
            contagem[i]--;         // decrementa a contagem
        }
    }

    free(contagem);  // libera a memória alocada
}


void imprimir_vetor(int vet[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}


// Função principal para teste
int main() {
    int vetor[] = {4, 2, 2, 8, 3, 3, 1};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original:\n");
    imprimir_vetor(vetor, tamanho);

    countingSort(vetor, tamanho);
    printf("Vetor ordenado:\n");
    imprimir_vetor(vetor, tamanho);

    return 0;
}