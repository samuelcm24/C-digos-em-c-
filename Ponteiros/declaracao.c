/*
Exercício 1: Declaração, Atribuição e Leitura
Objetivo: Entender como declarar um ponteiro, fazê-lo apontar para uma variável e ler tanto 
o endereço quanto o valor.
*/

#include <stdio.h>

int main(){
    
    int num = 43;
    int *p;

    p = &num;

    printf("Valor da variavel: %d\n", num);
    printf("Valor que o ponteiro armazena: %p\n", &num);
    printf("Valor do ponteiro(o endereço que ele aramazena): %p\n", p);
    printf("Valor a qual o ponteiro aponta: %d\n", *p);


    return 0;
}