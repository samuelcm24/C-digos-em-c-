//Implementação do seletion sort em ordem decrescente

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void seletion_sort(int vet[], int n){
    int i, j, min, aux;

    for(i = 0; i < n - 1; i++){
        min = i;
        for(j = i + 1; j < n; j++){
            if(vet[j] > vet[min]){
                min = j;
            }
        }
        aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
    }
}

void imprimir_vetor(int vet[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void gerar_valores(int vet[], int n){
    for(int i = 0; i < n; i++){
        vet[i] = rand() % 10;
    }
}

int main(){
    srand(time(NULL));

    int n = 10;
    int *vet = (int*) malloc(n* sizeof(int));

    printf("Vetor desordenado: \n");
    gerar_valores(vet, n);
    imprimir_vetor(vet, n);

    printf("Valores ordenados em ordem decrescente: \n");
    seletion_sort(vet, n);
    imprimir_vetor(vet, n);

    return 0;
}