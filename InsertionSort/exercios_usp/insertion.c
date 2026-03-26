#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void imprimir_lista(int vet[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void gerar_vetor(int vet[], int n){
    for(int i = 0; i < n; i++){
        vet[i] = rand() % 100;
    }
}

int main(){
    srand(time(NULL));
    int n = 10;
    int *vet = (int*) malloc(n * sizeof(int));

    printf("Vetor desordenado: \n");
    gerar_vetor(vet, n);
    imprimir_lista(vet, n);

    printf("Vetor ordenado em ordem descrecente: \n");
    insertion_sort(vet, n);
    imprimir_lista(vet, n);

    return 0;
}