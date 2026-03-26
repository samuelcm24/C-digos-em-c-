// Ordenando lista com insertion sort com vetor estatico  

#include <stdio.h>
#include <stdlib.h>

void insertionsort(int *lista, int tamanho){
    int i, j, aux;
    for(i = 0; i < tamanho - 1; i++){
        if (lista[i] > lista[i + 1]){
            aux = lista[i + 1];
            lista[i + 1] = lista[i]; lista[i] = aux;
            j = i - 1;
            while (j >=0){
                if(aux <lista[j]){
                    lista[j + 1] = lista[j]; lista[j] = aux;
                }else{
                    break;
                }
                j = j - 1;
            }
        }
    }
}


void printlist(int *lista, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main(){
    int lista[] = {5, 2, 9, 1, 5, 6};
    int tamanho = sizeof(lista) / sizeof(lista[0]);
    printf("Lista original: ");
    printlist(lista, tamanho);
    insertionsort(lista, tamanho);
    printf("Lista ordenada: ");
    printlist(lista, tamanho);
    return 0;
}
