#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int vet[], int n){
    int i, j, aux;
    for(i = 1; i < n; i++){
        aux = vet[i];
        j = i - 1;
        while (j >= 0 && vet[j] > aux){
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = aux;
    }
}

int contarDistintos(int v[], int n){
    if(n == 0) return 0;

    insertion_sort(v, n);

    int count = 1; // o primeiro elemento é sempre distinto
    for(int i = 1; i < n; i++){
        if(v[i] != v[i - 1]) count++;
    }
    return count;
}


void gerar_vet(int vet[], int n){
    for(int i = 0; i < n; i++){
        vet[i] = rand() % 5;
    }
}

void imprimir(int vet[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main(){
    srand(time(NULL));
    int n = 5;
    int *vet = (int*) malloc(n * sizeof(int));

    gerar_vet(vet, n);
    printf("Vetor: \n");
    imprimir(vet, n);    
    int distintos = contarDistintos(vet, n);
    printf("Números distintos: %d\n", distintos);


    return 0;
}