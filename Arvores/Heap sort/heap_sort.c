#include <stdio.h>
#include <stdlib.h>

void heapSort(int vetor[], int tamanho);
void construirHeap(int vetor[], int tamanho);
void peneira(int vetor[], int pai, int fim);
void trocar(int *a, int *b);
void imprimirVetor(int vetor[], int tamanho);


int main(void) {
    int vetor[] = {0, 12, 7, 1, 20, 15, 3, 8};
    int tamanho = 7; // número de elementos reais (desconsiderando vetor[0])

    printf("Vetor original:\n");
    imprimirVetor(vetor, tamanho);

    heapSort(vetor, tamanho);

    printf("\nVetor ordenado:\n");
    imprimirVetor(vetor, tamanho);

    return 0;
}

void trocar(int *a, int *b) {
    int temporario = *a;
    *a = *b;
    *b = temporario;
}

// Ajusta o vetor para manter a propriedade de heap (max-heap)
// O nó em "pai" pode estar fora do lugar, ajustamos até a posição correta
void peneira(int vetor[], int pai, int fim) {
    int valor = vetor[pai];
    int filho = 2 * pai; // filho esquerdo

    while (filho <= fim) {
        // escolhe o maior filho
        if (filho < fim && vetor[filho] < vetor[filho + 1]) {
            filho++;
        }
        // se o valor já é maior que os filhos, terminamos
        if (valor >= vetor[filho]) {
            break;
        }
        // sobe o filho maior
        vetor[pai] = vetor[filho];
        pai = filho;
        filho = 2 * pai;
    }
    vetor[pai] = valor;
}

// Constrói o heap (bottom-up)
void construirHeap(int vetor[], int tamanho) {
    for (int pai = tamanho / 2; pai >= 1; pai--) {
        peneira(vetor, pai, tamanho);
    }
}

// Ordena o vetor usando HeapSort
void heapSort(int vetor[], int tamanho) {
    construirHeap(vetor, tamanho);
    for (int fim = tamanho; fim >= 2; fim--) {
        trocar(&vetor[1], &vetor[fim]); // maior vai para o final
        peneira(vetor, 1, fim - 1);     // restaura a propriedade do heap
    }
}

// Impressão de vetor (desconsiderando vetor[0])
void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 1; i <= tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}