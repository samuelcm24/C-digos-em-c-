/*Escreva uma versão recursiva do algoritmo de ordenação por inserção.
*/
/*
#include <stdio.h>
void insertion_sort_recursivo(int vet[], int tamanho) {
    // Caso base: vetor com 1 elemento já está ordenado
    if (tamanho <= 1) 
        return;

    // Ordena os primeiros (tamanho-1) elementos
    insertion_sort_recursivo(vet, tamanho - 1);

    // Insere o último elemento na posição correta
    int ultimo = vet[tamanho - 1];
    int j = tamanho - 2;

    while (j >= 0 && vet[j] > ultimo) {
        vet[j + 1] = vet[j];
        j--;
    }
    vet[j + 1] = ultimo;
}
// Função para imprimir vetor
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

    insertion_sort_recursivo(v, n);

    printf("Vetor ordenado: ");
    printVetor(v, n);

    return 0;
}
*/
// Insertion sort recursivo

#include <stdio.h>

void insertion_sort_recursivo(int vet[], int tamanho){
    if(tamanho <= 1){
        return;
    }
    insertion_sort_recursivo(vet, tamanho - 1);
    int ultimo = vet[tamanho - 1];
    int j = tamanho - 2;

    while( j >= 0 && vet[j] > ultimo){
        vet[j + 1] = vet[j];
        j--;
    }
    vet[j + 1] = ultimo;
    
}



void imprimir(int vet[], int n){
    for(int i = 0; i < n; i++){
        printf("%d, ", vet[i]);
    }
    printf("\n");
}

int main(){
    int vet[] = {43, 1, 4, 66, 23, 67, 44, 12, 2};
    int tamanho = sizeof(vet) / sizeof(vet[0]);

    printf("Vetor original: ");
    imprimir(vet, tamanho);

    insertion_sort_recursivo(vet, tamanho);
    printf("Vetor ordenado: ");
    imprimir(vet, tamanho);

    return 0;
}