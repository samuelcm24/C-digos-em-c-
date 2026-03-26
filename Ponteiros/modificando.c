/*
Exercício 2: Modificando um Valor Através de um Ponteiro
Objetivo: Usar o ponteiro para alterar o conteúdo da variável original.
*/

#include <stdio.h>

int main(){

    int valor = 150;
    int *p;
    p = &valor;

    printf("Valor Original: %d\n", *p);

    *p = 123;

    printf("Valor novo(modificado atraves do ponteiro): %d\n", *p);
    return 0;
    
}