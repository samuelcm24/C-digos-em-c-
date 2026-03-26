// Exercicio 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSort(int *arr, int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int *arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int*) malloc(n1 * sizeof(int));
    int *R = (int*) malloc(n2 * sizeof(int));

    for(int i = 0; i < n1; i++) L[i] = arr[l + i];
    for(int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int *arr, int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void quickSort(int *arr, int k, int x) {
    int i = k, j = x;
    int pivot = arr[(k + x) / 2];

    while(i <= j) {
        while(arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;
        if(i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if(k < j) quickSort(arr, k, j);
    if(i < x) quickSort(arr, i, x);
}

void Sortear(int *arr, int n, const char *algoritmo) {
    if(strcmp(algoritmo, "insertion") == 0) {
        insertionSort(arr, n);
    } else if(strcmp(algoritmo, "merge") == 0) {
        mergeSort(arr, 0, n - 1);
    } else if(strcmp(algoritmo, "quick") == 0) {
        quickSort(arr, 0, n - 1);
    } else {
        printf("Algoritmo desconhecido!\n");
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    Sortear(arr, n, "quick");

    printf("Vetor ordenado: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}