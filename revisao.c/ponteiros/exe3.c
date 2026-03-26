/*
Objetivo: Implemente uma função encontrarChar que recebe um ponteiro para uma string (um vetor de char) 
e um caractere para buscar. A função deve retornar um ponteiro para a 
primeira ocorrência do caractere na string. Se o caractere não for encontrado, a função deve retornar NULL.
*/

#include <stdio.h>

char* encontrarChar(char *str, char c) {
    while (*str != '\0') {
        if (*str == c) {
            return str;
        }
        str++;
    }
    return NULL;
}

int main() {
    char texto[] = "Hello, World!";
    char *resultado = encontrarChar(texto, 'W');

    if (resultado != NULL) {
        printf("Caractere encontrado: %c\n", *resultado);
    } else {
        printf("Caractere não encontrado.\n");
    }
    if (resultado != NULL) {
        printf("Caractere encontrado: %c\n", *resultado);
    } else {
        printf("Caractere não encontrado.\n");
    }

    return 0;
}