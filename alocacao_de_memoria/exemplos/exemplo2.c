/*
Exemplo 2: Alocando uma string (um array de char)
Um uso muito comum de malloc é criar strings cujo tamanho não conhecemos de antemão.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para strcpy

int main() {
    char *p_string;
    int tamanho_string = 50; // Queremos uma string de até 49 chars + char nulo '\0'

    printf("Alocando memoria para uma string...\n");

    // Pede memória para 50 caracteres
    // sizeof(char) é sempre 1, mas é boa prática incluir
    p_string = (char*) malloc(tamanho_string * sizeof(char));

    if (p_string == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    // Copia um texto para a memória que acabamos de alocar
    strcpy(p_string, "Alo mundo dinamicamente!");

    printf("A string armazenada eh: %s\n", p_string);

    // Libera a memória da string
    free(p_string);
    p_string = NULL;

    printf("Memoria da string liberada.\n");

    return 0;
}

/*
O que este exemplo demonstra: Como alocar um bloco de 
memória para um conjunto de caracteres e usar funções como strcpy para manipulá-lo.*/