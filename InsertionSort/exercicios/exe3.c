/*
Implemente o Insertion Sort em um vetor de 7 elementos:
Mostre na tela o vetor a cada iteração da ordenação (passo a passo).


#include <stdio.h>

void printlist(int *lista, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

void insertionsort(int *lista, int tamanho) {
    int i, j, chave, passo = 1;

    for (i = 1; i < tamanho; i++) {
        chave = lista[i];
        j = i - 1;

        // Move os elementos maiores que a chave para frente
        while (j >= 0 && lista[j] > chave) {
            lista[j + 1] = lista[j];
            j = j - 1;
        }
        lista[j + 1] = chave;

        // Mostra vetor a cada iteração
        printf("Iteração %d: ", passo++);
        printlist(lista, tamanho);
    }
}

int main() {
    int lista[] = {9, 3, 1, 5, 4, 8, 2};
    int tamanho = sizeof(lista) / sizeof(lista[0]);

    printf("Vetor original: ");
    printlist(lista, tamanho);

    insertionsort(lista, tamanho);

    printf("Vetor ordenado: ");
    printlist(lista, tamanho);

    return 0;
}
*/

/*
Implemente o Insertion Sort em um vetor de 7 elementos:
Mostre na tela o vetor a cada iteração da ordenação (passo a passo).
*/

#include <stdio.h>


void imprimir_lista(int vet[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d, ", vet[i]);
    }
    printf("\n");
}


void insertion_sort(int *lista, int tamanho){
    
    int i, j, aux;
    int passo = 1;

    for(i = 0; i < tamanho; i++){
        aux = lista[i];
        j = i - 1;
        while(j >= 0 && lista[j] > aux){
            lista[j + 1] = lista[j];
            j = j - 1;
        }
        lista[j + 1] = aux;

        printf("Iteração %d: ", passo++);
        imprimir_lista(lista, tamanho);
    }
}

int main(){
    
    int vet[] = {9, 6, 3, 1, 7, 8, 2};
    int tamanho = sizeof(vet) / sizeof(vet[0]);

    printf("Vetor original: ");
    imprimir_lista(vet, tamanho);

    insertion_sort(vet, tamanho);
    
}