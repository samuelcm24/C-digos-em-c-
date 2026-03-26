//Representação de Heap em Vetor

#include <stdio.h>

void heapIndices(int i, int n) {
    int pai, esq, dir;

    if (i > 1){
        pai = i / 2;
    }else{
        pai = -1;
    }

    esq = 2 * i;
    if (esq > n){
        esq = -1;
    } 
    dir = 2 * i + 1;
    if (dir > n){
        dir = -1;
    }

    printf("No índice %d:\n", i);
    printf(" Pai: %d\n", pai);
    printf(" Filho esquerdo: %d\n", esq);
    printf(" Filho direito : %d\n", dir);
}

int main() {
    int n = 10; // tamanho do heap
    for (int i = 1; i <= n; i++) {
        heapIndices(i, n);
        printf("\n");
    }
    return 0;
}
