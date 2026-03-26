// Versão do codigo anterior com ordenação com vetor dinamico

#include <stdio.h>
#include <stdlib.h>

void insertionsort(int *lista, int tamanho) {
    int i, j, aux;
    for(i = 0; i < tamanho - 1; i++){
        if (lista[i] > lista[i + 1]){
            aux = lista[i + 1];
            lista[i + 1] = lista[i]; 
            lista[i] = aux;
            j = i - 1;
            while (j >=0){
                if(aux < lista[j]){
                    lista[j + 1] = lista[j]; 
                    lista[j] = aux;
                } else{
                    break;
                }
                j = j - 1;
            }
        }
    }
}

void printlist(int *lista, int tamanho) {
    for(int i = 0; i < tamanho; i++){
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main() {
    int tamanho = 6;

    // Alocação dinâmica do vetor
    int *lista = (int*) malloc(tamanho * sizeof(int));
    if(lista == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    // Preenchendo o vetor
    for(int i = 0; i < tamanho; i++) {
        lista[i] = rand() % 100;  // Números aleatórios entre 0 e 99
    }

    printf("Lista original: ");
    printlist(lista, tamanho);

    insertionsort(lista, tamanho);

    printf("Lista ordenada: ");
    printlist(lista, tamanho);

    // Liberar memória alocada
    free(lista);

    return 0;
}
