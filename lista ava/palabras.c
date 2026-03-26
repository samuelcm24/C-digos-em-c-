#include <stdio.h>
#include <string.h>

int compare(const char *a, const char *b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    if (lenA != lenB) return lenA - lenB;
    return strcmp(a, b); 
}

void insertionSort(char *arr[], int n) {
    for (int i = 1; i < n; i++) {
        char *key = arr[i];
        int j = i - 1;

        while (j >= 0 && compare(arr[j], key) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    char *vet[] = {"casa", "arvore", "rio", "gato", "sol", "paz", "amor"};
    int n = sizeof(vet) / sizeof(vet[0]);

    insertionSort(vet, n);

    for (int i = 0; i < n; i++) {
        printf("%s ", vet[i]);
    }
    printf("\n");

    return 0;
}