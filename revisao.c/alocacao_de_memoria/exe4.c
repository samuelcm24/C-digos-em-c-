/*
 Matriz Dinâmica (Vetor Bidimensional)
Objetivo: Peça ao usuário as dimensões de uma matriz (número de linhas e colunas). 
Aloque dinamicamente uma matriz de inteiros com essas dimensões. 
Preencha a matriz com valores (por exemplo, matriz[i][j] = i + j) e, no final, imprima a matriz e libere toda a memória alocada.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int **matriz;
    int linhas, colunas;

    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &linhas);

    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &colunas);

    matriz = (int**) malloc(sizeof(int*) * linhas);
    if (matriz == NULL){
        printf("ERRO: não foi possível alocar memoria.\n");
        exit(1);
    }

    for (int i = 0; i < linhas; i++){
        matriz[i] = (int*) malloc(sizeof(int) * colunas);
        if (matriz[i] == NULL){
            printf("ERRO: não foi possível alocar memoria.\n");
            exit(1);
        }
    }

    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            matriz[i][j] = i + j; // Preenchendo a matriz com valores
        }
    }

    printf("Conteudo da matriz:\n");

    for(int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("Liberando a memoria...\n");
    for (int i = 0; i < linhas; i++){
        free(matriz[i]); // Liberando cada linha da matriz
    }
    free(matriz); // Liberando o vetor de ponteiros

    return 0;
}