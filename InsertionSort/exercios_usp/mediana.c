#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Insertion Sort para ordenar o vetor
void seletion_sort(int vet[], int n){
    int i, j, min, aux;
    for(i = 0; i < n - 1; i++){
        min = i;
        for(j = i + 1; j < n; j++){
            if(vet[j] < vet[min]){
                min = j;
            }
        }
        aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
    }
}

// Função que retorna a mediana
int mediana(int v[], int n) {
    seletion_sort(v, n);
    return v[n/2]; // como os elementos são distintos, pega o elemento do meio
}


void imprimir(int vet[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main() {
    int v[] = {2, 3, 1, 7, 9};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Vetor: \n");
    imprimir(v, n);
    int m = mediana(v, n);
    printf("Mediana: %d\n", m);

    return 0;
}
