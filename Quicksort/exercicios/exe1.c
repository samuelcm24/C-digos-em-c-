

//Implementação do QuickSort com geração de vetor aleatorio
// A função do quicksort e a mesma do exemplo do site, do adicionando a função de gerar vetor aleatorio e imprimir o vetor
// em vez de usar um vetor com valores fixos
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <stdio.h>

// Função que particiona o vetor em torno de um pivô
int particiona(int vet[], int inicio, int fim) {
    int pivo = vet[fim];        // escolhe o último elemento como pivô
    int indiceMenor = inicio;   // posição do menor elemento encontrado

    // percorre o subvetor de inicio até fim-1
    for (int i = inicio; i < fim; i++) {
        if (vet[i] <= pivo) {   // se o elemento atual é menor ou igual ao pivô
            // troca vet[i] com vet[indiceMenor]
            int temp = vet[i];
            vet[i] = vet[indiceMenor];
            vet[indiceMenor] = temp;
            indiceMenor++;      // avança a posição do "menor"
        }
    }

    // coloca o pivô na posição correta (no meio dos dois grupos)
    int temp = vet[indiceMenor];
    vet[indiceMenor] = vet[fim];
    vet[fim] = temp;

    return indiceMenor; // retorna a posição final do pivô
}

// Função principal do QuickSort
void quicksort(int vet[], int inicio, int fim) {
    if (inicio < fim) {
        // particiona o vetor e obtém o índice do pivô
        int indicePivo = particiona(vet, inicio, fim);

        // ordena recursivamente a metade esquerda (menores que o pivô)
        quicksort(vet, inicio, indicePivo - 1);

        // ordena recursivamente a metade direita (maiores que o pivô)
        quicksort(vet, indicePivo + 1, fim);
    }
}

void gerar_vetor(int vet[], int n){
    for(int i = 0; i < n; i++){
        vet[i] = rand() % 100;
    }
}

void imprimir_lista(int vet[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main(){
    srand(time(NULL));

    int n = 5;
    int vet[n];

    printf("Vetor desordenado: \n");
    gerar_vetor(vet, n);
    imprimir_lista(vet, n);

    printf("Vetor ordenado: \n");
    quicksort(vet, 0, n - 1);
    imprimir_lista(vet, n);

    return 0;
}
