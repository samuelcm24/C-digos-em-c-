/*Exercício 1 — Ordenar um vetor pequeno
Tarefa:

Crie um vetor de 6 elementos: {4, 2, 7, 1, 3, 5}
Use Insertion Sort para ordenar
Imprima o vetor antes e depois da ordenação
*/

#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int vet[], int tamanho){
    int aux, j;

    for(int i = 1; i < tamanho; i++){
        aux = vet[i];
        j = i - 1;
        while (j >= 0 && vet[j] >= aux){
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = aux;
    }
}

void imprimir_lista(int vet[], int n){
    for(int i = 0; i < n; i++){
        printf("%d, ", vet[i]);
    }
    printf("\n");
}

int main(){
    int vet[] = {99, 112,1, 43, 32, 6, 12, 54, 22, 73};
    int tamanho = sizeof(vet) / sizeof(vet[0]);

    printf("Vetor original: ");
    imprimir_lista(vet, tamanho);

    printf("Vetor ordenado: ");
    insertion_sort(vet, tamanho);
    imprimir_lista(vet, tamanho);

    return 0;
}