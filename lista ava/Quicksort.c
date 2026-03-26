//Implementação do quick sort

#include <stdio.h>
#include <stdlib.h>

void quicksort(int v[], int esq, int dir){
    int i, j, pivo, aux;
    i = esq;
    j = dir;
    pivo = v[(esq + dir) / 2];
    do{
        while(v[i] < pivo) i++;
        while(v[j] > pivo) j--;
        if(i <= j){
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }while(i <= j);
    if(esq < j) quicksort(v, esq, j);
    if(i < dir) quicksort(v, i, dir);
}

void imprimir_vet(int vet[], int n){
    for(int i = 0; i < n; i++){
        printf("%d, ", vet[i]);
    }
    printf("\n");
}

int main(){
    int vet[] = {5, 4, 3, 2, 1};
    int n = sizeof(vet) / sizeof(vet[0]);

    printf("Vetor original: ");
    imprimir_vet(vet, n);

    quicksort(vet, 0, n - 1);
    printf("Vetor ordenado: ");
    imprimir_vet(vet, n);

    return 0;
}