//Implementação do selection sort

#include <stdio.h>
#include <stdlib.h>

void seletion_sort(int vet[], int tamanho){
    int i, j, min, aux;

    for(i = 0; i < tamanho - 1; i++){
        min = i;
        for(j = i + 1; j < tamanho; j++){
            if(vet[j] < vet[min]){
                min = j;
            }
        }
        if(min != i){
            aux = vet[i];
            vet[i] = vet[min];
            vet[min] = aux;
        }
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

    printf("Vetor original: ");
    imprimir_vet(vet, n);

    seletion_sort(vet, n);
    printf("Vetor ordenado: ");
    imprimir_vet(vet, n);

    return 0;
}