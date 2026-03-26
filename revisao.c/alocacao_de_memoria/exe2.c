/*
Objetivo: Crie uma função criarAluno que recebe o nome e a matrícula de um aluno. A função deve alocar dinamicamente 
memória para uma struct Aluno, preencher os campos com os dados recebidos e 
retornar um ponteiro para essa struct alocada. A função main deve chamar criarAluno, imprimir os dados e liberar a memória.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int matricula;
    char nome[50];
    int idade;
} Aluno;


Aluno* CriarAluno(const char* nome, int matricula, int idade){

    Aluno* novos_alunos = (Aluno*) malloc(sizeof(Aluno));

    if(novos_alunos == NULL){
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    novos_alunos->matricula = matricula;
    strcpy(novos_alunos->nome, nome);
    novos_alunos->idade = idade;

    return novos_alunos;
}


void imprimir_alunos(const Aluno* aluno){

    printf("\n========== Dados Do Aluno ==========\n");
        printf("Nome do aluno: %s\n", aluno->nome );
        printf("Idade: %d\n", aluno->idade);
        printf("N° matricula: %d\n", aluno->matricula);
    
}

int main(){

    Aluno *aluno1;
    Aluno *aluno2;

    printf("Criando primeiro aluno....\n");
    aluno1 = CriarAluno("SAMUEL", 15, 19);

    printf("Criando segundo aluno....\n");
    aluno2 = CriarAluno("MYLENA", 212, 19);

    if (aluno1 != NULL && aluno2 != NULL){
        imprimir_alunos(aluno1);
        imprimir_alunos(aluno2);

        printf("Liberando a memoria...\n");

        free(aluno1);
        free(aluno2);
        aluno1 = NULL;
        aluno2 = NULL;
        printf("Memoria liberada com sucesso....\n");
    } else{
        printf("Erro: Falha criar 1 ou mias alunos....\n");

        free(aluno1);
        free(aluno2);
    }

    return 0;
}
