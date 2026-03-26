//Exercicio 10

#include <stdio.h>
#include <stdlib.h>

int compare(int a, int b) {
    if (a % 2 == 0 && b % 2 != 0) return -1; 
    if (a % 2 != 0 && b % 2 == 0) return 1;
    return a - b; 
}

void merge(int v[], int p, int q, int r){
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    int *L = (int *) malloc(n1 * sizeof(int));
    int *R = (int *) malloc(n2 * sizeof(int));

    for(i = 0; i < n1; i++) L[i] = v[p + i];
    for(j = 0; j < n2; j++) R[j] = v[q + 1 + j];

    i = 0; j = 0; k = p;
    while(i < n1 && j < n2){
        if(compare(L[i], R[j]) <= 0){
            v[k++] = L[i++];
        } else {
            v[k++] = R[j++];
        }
    }
    while(i < n1) v[k++] = L[i++];
    while(j < n2) v[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int v[], int p, int r){
    if(p < r){
        int q = (p + r) / 2;
        mergeSort(v, p, q);
        mergeSort(v, q + 1, r);
        merge(v, p, q, r);
    }
}

int main() {
    int vet[] = {5, 2, 8, 1, 4};
    int n = sizeof(vet)/sizeof(vet[0]);

    mergeSort(vet, 0, n-1);

    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;
}
