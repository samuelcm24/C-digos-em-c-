//Função Heapify

#include <stdio.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int v[], int n, int i) {
    int esq = 2 * i;       
    int dir = 2 * i + 1;   
    int maior = i;        

    if (esq <= n && v[esq] > v[maior]) {
        maior = esq;
    }

    if (dir <= n && v[dir] > v[maior]) {
        maior = dir;
    }

    if (maior != i) {
        troca(&v[i], &v[maior]);
        heapify(v, n, maior);
    }
}

int main() {
    int v[] = {0, 41, 161, 101, 141, 71, 91, 31, 21, 81, 17, 16};
    int n = 11;
    printf("Antes do heapify:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    heapify(v, n, 1);

    printf("Depois do heapify na raiz:\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
