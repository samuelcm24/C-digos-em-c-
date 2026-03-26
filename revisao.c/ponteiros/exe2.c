/*
Objetivo: Escreva uma função somarVetor que recebe um ponteiro para o primeiro elemento de um vetor de inteiros e o 
tamanho do vetor. 
A função deve usar aritmética de ponteiros para percorrer o vetor e retornar a soma de todos os seus elementos.
*/

#include <stdio.h>

int somaVetor(int *vector, int tamanho){
    int soma = 0;

    for (int i = 0 ; i < tamanho; i++){
        soma += vector[i];
    }
    return soma;
}

int main(){

    // Definindo um vetor de inteiros e seu tamanho
    // Inicializando o vetor com valores de 25
    // Tamanho do vetor é 5
    int vetor[] = {25, 25, 25, 25, 25};
    int tamanho = 5;

    int resultado = somaVetor(vetor, tamanho);
    printf("A soma dos elementos do vetor é: %d\n", resultado);

    return 0;
}