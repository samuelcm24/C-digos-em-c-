/*
Objetivo: Criar um programa que armazene as notas de múltiplos alunos. O programa deve primeiro perguntar quantos alunos serão 
registrados. Em seguida, para cada aluno, deve perguntar quantas notas ele possui e alocar espaço para elas. Por fim, 
deve calcular e exibir a média de cada aluno.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct Aluno
{
    float n1;
    float n2;
    char nome[50];
} Aluno;

Aluno* notas(float n1, float n2, const char* nome){
    Aluno* novas_notas = (Aluno*) malloc(sizeof(Aluno));

    if (novas_notas == NULL){
        printf("Erro ao alocar memória...\n");
        exit(1);
    }

    strcpy(novas_notas->nome, nome);
    novas_notas->n1 = n1;
    novas_notas->n2 = n2;

    return novas_notas;
}

float calcular_media(const Aluno* aluno){
    
    return (aluno->n1 + aluno->n2) / 2;
}

void imprimir_aluno(const Aluno* lista, float media){
    printf("\n========== Dados Dos Alunos ==========\n");
    printf("Nome: %s\n", lista->nome);
    printf("Nota 1: %.2f\n", lista->n1);
    printf("Nota 2: %.2f\n", lista->n2);
    printf("Média: %.2f\n", media);
    printf("\n-----------------------------------------------\n");

}

int main(){
    Aluno* aluno1;
    Aluno* aluno2;

    printf("Coletando dados do primerio aluno(a)...\n");
    aluno1 = notas(5.6, 5.9, "Samuel");

    printf("Calculando a média do aluno...\n");
    float media = calcular_media(aluno1);

    printf("Coletando dados do 2 aluno(a)...\n");
    aluno2 = notas(7.6, 3.8, "Gabriel");

    printf("Calculando a média do aluno..\n");
    float media2 = calcular_media(aluno2);

if (aluno1 != NULL && aluno2 != NULL){
        imprimir_aluno(aluno1, media);
        imprimir_aluno(aluno2, media2);

        printf("Liberando a memoria...\n");

        free(aluno1);
        free(aluno2);
        aluno1 = NULL;
        aluno2 = NULL;
        printf("Memoria liberada com sucesso....\n");
    } else{
        printf("Erro: Falha criar 1 ou mais alunos....\n");

        free(aluno1);
        free(aluno2);
    }

}