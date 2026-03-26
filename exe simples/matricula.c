/*Exercício 5: Cadastro de Alunos com Structs (Nível: Avançado)
Objetivo: Criar um sistema simples para cadastrar e listar dados de alunos usando structs e alocação dinâmica de memória.

Requisitos:

Defina uma struct chamada Aluno que contenha os seguintes campos: nome (string), matricula (inteiro) e mediaFinal (float).

Pergunte ao usuário quantos alunos ele deseja cadastrar.

Aloque dinamicamente um vetor de struct Aluno com o tamanho informado. Use malloc().

Crie um laço para preencher os dados de cada aluno (ler nome, matrícula e média).

Após o cadastro, crie outro laço para percorrer o vetor e exibir os dados de todos os alunos cadastrados de forma organizada.

Ao final do programa, não se esqueça de liberar a memória alocada com free().*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome_aluno[50];
    char nome_escola[50];
    char nome_pai[50];
    char nome_mae[50];
    int matricula;
    
}cadastro;

void imprimir_ficha(cadastro Lista[], int tamanho){
    printf("\n========== Fichar Escolar ==========\n");
    for(int i = 0; i < tamanho; i++){
        printf("Escola: %s\n", Lista[i].nome_aluno);
        printf("Aluno: %s\n", Lista[i].nome_aluno);
        printf("N° matricula: %d\n", Lista[i].matricula);
        printf("Nome do Pai: %s\n", Lista[i].nome_pai);
        printf("Nome da Mâe: %s\n", Lista[i].nome_mae);
        printf("\n============================================\n");
    }
}

void criando_ficha(cadastro** ponteiro_para_lista, int* ponteiro_para_tamanho){
    if(*ponteiro_para_lista != NULL){
        
    }
}