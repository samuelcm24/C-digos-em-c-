/*
Objetivo: Crie um programa que leia números inteiros digitados pelo usuário, um por vez, e os armazene em um 
vetor dinâmico. O programa não sabe quantos números o usuário vai digitar. O usuário para de digitar ao inserir 
o número 0. O vetor deve "crescer" a cada novo número inserido usando realloc.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor = NULL;
    int tamanho = 0;
    int numero;

    while (1) {
        printf("Digite um numero (0 para sair): ");
        scanf("%d", &numero);

        if (numero == 0) {
            break;
        }

        // Aumenta o tamanho do vetor
        int *temp = realloc(vetor, (tamanho + 1) * sizeof(int));
        if (temp == NULL) {
            printf("ERRO: não foi possível alocar memoria.\n");
            free(vetor);
            exit(1);
        }
        vetor = temp;

        // Adiciona o novo numero ao vetor
        vetor[tamanho] = numero;
        tamanho++;
    }

    printf("Numeros digitados:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);
    return 0;
}