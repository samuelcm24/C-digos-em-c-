/*
Duplicando uma String
Objetivo: Escreva uma função duplicarString que recebe uma string como argumento. A função deve:

Calcular o tamanho da string de entrada.

Alocar dinamicamente memória suficiente para uma cópia da string (não se esqueça do caractere nulo \0 no final!).

Copiar a string original para a nova área de memória.

Retornar um ponteiro para a nova string duplicada.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void duplicarString(const char* original, char** copia) {
    // Calcula o tamanho da string original
    size_t tamanho = strlen(original);
    
    // Aloca memória para a nova string (incluindo o caractere nulo)
    *copia = (char*) malloc((tamanho + 1) * sizeof(char));
    
    if (*copia == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    
    // Copia a string original para a nova área de memória
    strcpy(*copia, original);
}

int main(){
    const char* original = "Exemplo de string";
    char* copia = NULL;

    // Chama a função para duplicar a string
    duplicarString(original, &copia);

    // Imprime a string original e a cópia
    printf("String original: %s\n", original);
    printf("String duplicada: %s\n", copia);

    // Libera a memória alocada para a cópia
    free(copia);

    return 0;
}
