/*Importante.  Escreva uma versão do algoritmo Insertionsort que rearranje em ordem crescente 
um vetor v[p..r] e tenha o seguinte invariante: no início de cada iteração, o vetor v[k+1..r] 
é crescente.
*/
/*
#include <stdio.h>

// InsertionSort que mantém o invariante v[k+1..r] crescente
void insertionSortDireita(int v[], int p, int r) {
    for (int k = r - 1; k >= p; k--) {
        int x = v[k];   // elemento a ser inserido
        int i = k + 1;

        // desloca os elementos maiores que x para a esquerda
        while (i <= r && v[i] < x) {
            v[i - 1] = v[i];
            i++;
        }

        v[i - 1] = x;  // insere x na posição correta
    }
}

void printVet(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int v[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Original: ");
    printVet(v, n);

    insertionSortDireita(v, 0, n - 1);

    printf("Ordenado: ");
    printVet(v, n);

    return 0;
}
    */

/*Importante.  Escreva uma versão do algoritmo Insertionsort que rearranje em ordem crescente 
um vetor v[p..r] e tenha o seguinte invariante: no início de cada iteração, o vetor v[k+1..r] 
é crescente.
*/

#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int vet[], int p, int r){
    for(int k = r; k >= p; k--){
        int x = vet[k];
        int i = k + 1;

        while(i <= r && vet[i] < x){
            vet[i - 1] = vet[i];
            i++;
        }
        vet[i - 1] = x;
    }
}

void imprimir_vetor(int vet[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d, ", vet[i]);
    }
    printf("\n");
}

int main(){
    int vet[] = {3, 5, 1, 6, 99};
    int n = sizeof(vet) / sizeof(vet[0]);

    printf("Vetor original:");
    imprimir_vetor(vet, n);

    printf("Vetor ordenado: ");
    insertion_sort(vet,0, n - 1);
    imprimir_vetor(vet, n);

    return 0;
}