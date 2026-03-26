/*
Objetivo: Escreva uma função somarVetor que recebe um ponteiro para o primeiro elemento de um vetor de inteiros e o 
tamanho do vetor. 
A função deve usar aritmética de ponteiros para percorrer o vetor e retornar a soma de todos os seus elementos.
*/

#include <stdio.h>

int somarVetor(int *vetor, int tamanho){

    int soma = 0;

    for (int i = 0; i < tamanho; i++){
        soma += vetor[i];
    }
    return soma;
}

int main(){
    int vetor[] = {21, 11, 20, 5};
    int tamanho = 4;

    int resultado = somarVetor(vetor, tamanho);
    printf("Resultado da soma dos elementos presentes dentro do vetor: %d\n", resultado);

    return 0;
}