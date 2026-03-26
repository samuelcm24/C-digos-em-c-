/*
Exercício 2: Média de Notas
Crie um programa que calcula a média de um conjunto de notas.

Pergunte ao usuário: "Quantas notas você vai inserir?".

Leia este número (vamos chamá-lo de N).

Aloque dinamicamente um array de float (ou double) com tamanho N.

Faça um laço que peça ao usuário para digitar cada uma das N notas e as armazene no array.

Calcule a média de todas as notas no array.

Imprima a média na tela.

Libere a memória alocada.

Dica/Desafio extra: Tente usar calloc() em vez de malloc(). A função calloc() faz o mesmo que malloc, mas inicializa toda 
a memória alocada com o valor 0. A sintaxe é um pouco diferente: ponteiro = (float*) calloc(N, sizeof(float));.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float nota1;
    float nota2;
    float media;
    char nome[50];
}Media_notas;

void Imprimir_notas(Media_notas lista[], int tamanho){

    printf("\n========= Media Notas =========\n");
    for(int i = 0; i < tamanho; i++){
        printf("Nome do aluno: %s\n", lista[i].nome);
        printf("Nota da primeirra prova: %.2f\n",lista[i].nota1);
        printf("Nota da segunda prova: %.2f\n", lista[i].nota2);
        printf("Média do aluno: %.2f\n", lista[i].media);
        printf("\n=====================================\n");
    }
}

float media(float nota1, float nota2) {
    return (nota1 + nota2) / 2.0;
}

int main(){
    Media_notas *notas;
    int n_alunos;

    printf("Quantos alunos você irá cadastrar? ");
    scanf("%d", &n_alunos);

    notas = (Media_notas*) malloc(n_alunos * sizeof(Media_notas));

    if (notas == NULL){
        printf("Erro! Falha ao alocar memória.\n");
        return 1;
    }

    for(int i = 0; i < n_alunos; i++){
        printf("Insira o nome do aluno: ");
        scanf("%s", notas[i].nome);

        printf("Digite a nota da primeira prova: ");
        scanf("%f", &notas[i].nota1);

        printf("Digite a nota da segunda prova: ");
        scanf("%f", &notas[i].nota2);

        notas[i].media = media(notas[i].nota1, notas[i].nota2);
    }
    Imprimir_notas(notas, n_alunos);

    free(notas);
    printf("Memoria libera com sucesso!\n");
    return 0;
}