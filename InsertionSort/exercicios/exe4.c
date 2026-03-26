//Implimentando um algoritmo insertion sort
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int vet[], int tamanho){

    int i, j, aux;
    for (i = 1; i < tamanho; ++i){
        aux = vet[i]; // guarda o elemento a ser inserido
        j = i - 1;
        while(j >= 0 && vet[j] > aux){// desloca os maiores para a direita
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = aux;// insere na posição correta
    }
}

void imprimir_vetor(int vet[], int tamanho){
    
    for(int i = 0; i < tamanho; i++){
        printf("%d, ", vet[i]);
        
    }
    printf("\n");
}


int main(){
    int vet[] = {9,5,1,6,7,99,23};
    int tamanho = sizeof(vet) / sizeof(vet[0]);

    printf("Vetor original: ");
    imprimir_vetor(vet, tamanho);

    insertionSort(vet, tamanho);

    printf("Vetor ordenado: ");
    imprimir_vetor(vet, tamanho);

    return 0;

}