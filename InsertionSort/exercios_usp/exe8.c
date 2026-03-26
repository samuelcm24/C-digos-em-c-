/*
Ordem decrescente.  Escreva uma função que permute os elementos de um vetor v[0..n-1] de modo que eles fiquem em 
ordem decrescente. Inspire-se no algoritmo de ordenação por inseção.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void insertionSortDecrescente(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] < chave){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

void imprimir(int vet[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void gerar(int vet[], int n){
    for(int i = 0; i < n; i++){
        vet[i] = rand() % 100;
    }
}

int main(){
    int n = 10;
    int *vet = (int*) malloc(n * sizeof(int));

    printf("Vetor original: ");
    gerar(vet, n);
    imprimir(vet, n);

    printf("Vetor ordenado de forma decrescente: ");
    insertionSortDecrescente(vet, n);
    imprimir(vet, n);

    free(vet);

    return 0;
}