//Escreva uma função que rearranje um vetor v[0..n-1] de modo que ele 
//fique em ordem estritamente crescente.

/*
#include <stdio.h>

void ordenarCrescente(int v[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                // troca os elementos
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

void printVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int v[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Vetor original: ");
    printVetor(v, n);

    ordenarCrescente(v, n);

    printf("Vetor ordenado (estritamente crescente): ");
    printVetor(v, n);

    return 0;
}
*/

//Escreva uma função que rearranje um vetor v[0..n-1] de modo que ele 
//fique em ordem estritamente crescente.

#include <stdio.h>

void ordenar_vetor(int v[], int tamanho){
    int i, j, aux;

    for(i = 0; i < tamanho - 1; i++){
        for(j = 0; j < tamanho - i - 1; j++){
            if (v[j] > v[j + 1]){
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

void imprimir_lista(int vet[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d, ", vet[i]);
    }

    printf("\n");
}

int main(){
    int vet[] = {5, 2, 9, 1, 5, 6};
    int tamanho = sizeof(vet) / sizeof(vet[0]);

    printf("Vetor original: ");
    imprimir_lista(vet, tamanho);

    ordenar_vetor(vet, tamanho);

    printf("Vetor ordenado: ");
    imprimir_lista(vet, tamanho);

    return 0;
}