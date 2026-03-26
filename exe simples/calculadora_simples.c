/*
Exercício 1: Calculadora Simples (Nível: Básico)
Objetivo: Criar um programa que funcione como uma calculadora básica, 
realizando as quatro operações aritméticas (soma, subtração, multiplicação e divisão).
*/

#include <stdio.h>

void menu();
float soma();
float sub();
float multi();
float divisao();

void menu(){

    printf("\n---------- Mini Calculadora ----------\n");
    printf("1.Soma\n");
    printf("2.Subtração\n");
    printf("3.Multiplicação\n");
    printf("4.Divisão\n");
    printf("0.Sair\n");
}

float soma(){
    float n1,n2;
    float resultado;

    printf("Digite 2 números: ");
    scanf("%f %f", &n1, &n2);

    resultado = n1 + n2;
    printf("Resultado: %.2f\n", resultado);

    return 0;
}


float sub(){
    float n1,n2;
    float resultado;

    printf("Digite 2 números: ");
    scanf("%f %f", &n1, &n2);

    resultado = n1 - n2;
    printf("Resultado: %.2f\n", resultado);

    return 0;
}


float multi(){
    float n1,n2;
    float resultado;

    printf("Digite 2 números: ");
    scanf("%f %f", &n1, &n2);

    resultado = n1 * n2;
    printf("Resultado: %.2f\n", resultado);

    return 0;
}


float divisao(){
    float n1,n2;
    float resultado;

    printf("Digite 2 números: ");
    scanf("%f %f", &n1, &n2);

    if (n2 == 0){
        printf("Erro! Impossível realizar divisão por 0.\n");
    }else{
        resultado = n1 / n2;
        printf("Resultado: %.2f\n", resultado);
    }

    return 0;
}

int main(){
    int opcao;

    do
    {
        menu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        while (getchar() != '\n');

        switch (opcao)
        {
        case 1:
        soma();
            break;
        
        case 2:
        sub();
            break;
        
        case 3:
        multi();
            break;

        case 4:
        divisao();
            break;

        case 0:
        printf("Saindo....\n");
            break;
        
        
        default:
        printf("Entrada inválida, Tente novamente.\n");
            break;
        }
        if (opcao != 0) {
            printf("\nPressione Enter para continuar...");
            // O programa pausa aqui, esperando um "Enter", para que o usuário 
            // possa ler o resultado antes do menu ser impresso novamente.
            getchar(); 
        }

    } while(opcao != 0);
    return 0;
}