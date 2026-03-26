//Validação de Heap
#include <stdio.h>

int ehMaxHeap(int v[], int n) {
    for (int i = 2; i <= n; i++) {
        int pai = i / 2;
        if (v[pai] < v[i]) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    int v1[] = {0, 161, 41, 101, 141, 71, 91, 31, 21, 81, 17, 16}; 
    int n1 = 11;

    int v2[] = {0, 50, 100, 30}; 
    int n2 = 3;

    printf("v1 eh heap? %s\n", ehMaxHeap(v1, n1) ? "SIM" : "NAO");
    printf("v2 eh heap? %s\n", ehMaxHeap(v2, n2) ? "SIM" : "NAO");

    return 0;
}
