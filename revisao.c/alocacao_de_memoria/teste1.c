/* Criando um Vetor de Tamanho Variável
Objetivo: Peça ao usuário para digitar um número inteiro N. Em seguida, aloque dinamicamente um vetor de N inteiros. 
Preencha este vetor com os números de 0 a N-1. Por fim, imprima os valores do vetor e, o mais importante, 
libere a memória alocada.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vetor;
    int tamanho;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    vetor = (int*) malloc(tamanho * sizeof(int));

    if (vetor == NULL){
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    for (int i = 0; i < tamanho; i++){
        vetor[i] = i * 10;
        printf("Número: %d\n", vetor[i]);
    }
    printf("\n");

    free(vetor);
    return 0;
}