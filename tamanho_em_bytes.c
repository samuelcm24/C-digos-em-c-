// Tamanho em bytes do meu computador, para cada elemento int, float, char, dooble,long, long long, short

#include <stdio.h>

int main() {
    // Tipos primitivos
    printf("Tamanho de char: %lu byte(s)\n", sizeof(char));
    printf("Tamanho de int: %lu byte(s)\n", sizeof(int));
    printf("Tamanho de float: %lu byte(s)\n", sizeof(float));
    printf("Tamanho de double: %lu byte(s)\n", sizeof(double));
    printf("Tamanho de long: %lu byte(s)\n", sizeof(long));
    printf("Tamanho de long long: %lu byte(s)\n", sizeof(long long));
    printf("Tamanho de short: %lu byte(s)\n", sizeof(short));


// Tamanho em bytes para os ponteiros;

    // Ponteiros
    printf("\n--- Tamanhos dos ponteiros ---\n");
    printf("Tamanho de char*: %lu byte(s)\n", sizeof(char*));
    printf("Tamanho de int*: %lu byte(s)\n", sizeof(int*));
    printf("Tamanho de float*: %lu byte(s)\n", sizeof(float*));
    printf("Tamanho de double*: %lu byte(s)\n", sizeof(double*));
    printf("Tamanho de void*: %lu byte(s)\n", sizeof(void*));

    return 0;
}

