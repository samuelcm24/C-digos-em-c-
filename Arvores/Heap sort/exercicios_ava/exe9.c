#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int chave;
    char id;  
} Item;

void troca(Item *a, Item *b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Item v[], int n, int i) {
    int maior = i;
    int esq = 2*i + 1;
    int dir = 2*i + 2;

    if (esq < n && v[esq].chave > v[maior].chave) maior = esq;
    if (dir < n && v[dir].chave > v[maior].chave) maior = dir;

    if (maior != i) {
        troca(&v[i], &v[maior]);
        heapify(v, n, maior);
    }
}

void heapSort(Item v[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) heapify(v, n, i);
    for (int i = n-1; i >= 1; i--) {
        troca(&v[0], &v[i]);
        heapify(v, i, 0);
    }
}

int main() {
    Item v[] = {{5,'A'}, {3,'B'}, {5,'C'}, {2,'D'}, {5,'E'}};
    int n = sizeof(v)/sizeof(v[0]);

    printf("Original:\n");
    for(int i=0;i<n;i++) printf("(%d,%c) ", v[i].chave, v[i].id);
    printf("\n");

    heapSort(v, n);

    printf("Após HeapSort:\n");
    for(int i=0;i<n;i++) printf("(%d,%c) ", v[i].chave, v[i].id);
    printf("\n");

    return 0;
}