//Implementação do insertion sort
/*
#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int vet[], int n){
    int i, j, aux;

    for(i = 1; i < n; i++){
        aux = vet[i];
        j = i - 1;
        while(j >= 0 && vet[j] > aux){
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = aux;
    }
}

void imprimir_vet(int vet[], int n){
    for(int i = 0; i < n; i++){
        printf("%d, ", vet[i]);
    }
    printf("\n");
}

int main(){

    int vet[] = {5, 4, 3, 2, 1};
    int n = sizeof(vet) / sizeof(vet[0]);

    printf("Vetor oirginal: ");
    imprimir_vet(vet, n);

    insertion_sort(vet, n);
    printf("Vetor ordenado: ");
    imprimir_vet(vet, n);

    return 0;
}
*/
