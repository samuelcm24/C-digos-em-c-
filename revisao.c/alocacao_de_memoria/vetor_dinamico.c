/*
Objetivo: Criar um programa que solicita ao usuário o tamanho de um vetor de inteiros, aloca memória dinamicamente para esse vetor,
preenche-o com valores fornecidos pelo usuário e, em seguida, imprime os valores armazenados e libera a memória.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int *vet;
    int tamanho;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    vet = (int*) malloc(tamanho * sizeof(int));

    if (vet == NULL){
        printf("Erro ao alocar memoria...\n");
        exit(1);
    }
    printf("Digite os valores que deseja armarzenar no vetor: \n");
    for(int i = 0; i < tamanho; i++){
        scanf("%d", &vet[i]);

    }

    printf("Valores armazenados no vetor: \n");
    for(int i = 0; i < tamanho; i++){
        printf("%d, ", vet[i]);
    }

    printf("\n");

    free(vet);
    vet = NULL;

    return 0;
}