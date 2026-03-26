/*
Exercício 3: "Fábrica" de Alunos
Este exercício testa o uso de funções com alocação dinâmica.

Defina uma struct Aluno que tenha os campos: int matricula e char nome[100].

Crie uma função chamada cria_aluno. Esta função deve:

Receber como parâmetros uma matricula e um nome.

Alocar dinamicamente memória para uma struct Aluno.

Preencher os campos da struct alocada com os dados recebidos.

Retornar o ponteiro para a struct Aluno recém-criada (Aluno*).

Na função main:

    Chame a função cria_aluno duas vezes para criar dois alunos diferentes (ex: "Ana", 123 e "Beto", 456).
    Armazene os ponteiros retornados em duas variáveis Aluno*.

    Use os ponteiros para imprimir os dados dos dois alunos.

    Libere a memória de cada um dos alunos usando free().
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int matricula;
    char nome[100];
}Aluno;

Aluno* cria_aluno(int matricula, const char* nome){
    


    Aluno* Novos_alunos = (Aluno*) malloc(sizeof(Aluno));

    if (Novos_alunos == NULL){
        printf("Erro: Não foi possível alocar a memoria necessaria.\n");
        return NULL;
    }

    Novos_alunos->matricula = matricula;
    strcpy(Novos_alunos->nome, nome);

    return Novos_alunos;
}

int main() {
    Aluno *aluno1, *aluno2;

    printf("Criando 1 aluno....\n");
    aluno1 = cria_aluno(123, "Samuel");

    printf("Criando 2 aluno....\n");
    aluno2 = cria_aluno(321, "Karla");


    if (aluno1 != NULL && aluno2 != NULL){
        printf("\n---------- Dados dos alunos ----------\n");
        printf("Aluno 1 -> Matricula: %d, Nome: %s\n",aluno1->matricula, aluno1->nome);
        printf("Aluno 2 -> Matricula: %d, Nome: %s\n", aluno2->matricula, aluno2->nome);

        printf("\n----- Liberando memoria -----\n");

        printf("Aguarde.....\n");
        free(aluno1);
        free(aluno2);
        aluno1 = NULL;
        aluno2 = NULL;
        printf("Memoria liberada com sucesso.......\n");
    }else{
        printf("Falha ao criar 1 ou mais alunos!!\n");
        free(aluno1);
        free(aluno2);
    }

    return 0;
}