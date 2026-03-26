/*
Exemplo 1: Alocando um único número inteiro (int)
Este é o caso mais simples possível. Em vez de uma struct complexa, vamos alocar espaço para apenas um int.
*/

#include <stdio.h>
#include <stdlib.h> // Para malloc e free

int main() {
    int *p_numero; // Ponteiro para um inteiro

    printf("Alocando memoria para um inteiro...\n");

    // Pede memória suficiente para armazenar UM inteiro
    p_numero = (int*) malloc(sizeof(int));

    // Checa se a alocação funcionou
    if (p_numero == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    // Para atribuir um valor, usamos o operador de "desreferência" (*)
    // Isso significa: "guarde o valor 100 na memória para a qual p_numero aponta"
    *p_numero = 100;

    printf("O valor armazenado eh: %d\n", *p_numero);

    // Libera a memória
    free(p_numero);
    p_numero = NULL;

    printf("Memoria liberada.\n");

    return 0;
}

/*O que este exemplo demonstra: O ciclo malloc/free na sua forma mais pura e o uso do operador * para acessar 
o valor de um ponteiro para um tipo simples.
*/