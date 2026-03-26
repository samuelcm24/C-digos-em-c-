/*
Exercício 1 — Ordenar um vetor pequeno
Tarefa:

Crie um vetor de 6 elementos: {4, 2, 7, 1, 3, 5}
Use Insertion Sort para ordenar
Imprima o vetor antes e depois da ordenação
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int vet[], int n){

    int i, j, aux;

    for(i = 1; i < n; i++){// Percorremos o vetor a partir do indice 1
        aux = vet[i];// Aqui guardarmos o elemento atual
        j = i - 1;// Começamos a comparação com o elemento anterior
        //While(Enquanto) houverem elementos antes e eles forem maiores que aux(no caso aux nesse momento é o valor que se encontra no indice 1)
        while (j >= 0 && vet[j] > aux){
            vet[j + 1] = vet[j];// Aqui deslocamos o elemento para a direita
            j--; // Compara os elementos antetiores
        }

        //Aqui inserimos o valor na posição correta
        vet[j + 1] = aux;
    }
}

void imprimir_lista(int vet[], int n){
    for(int i = 0; i < n; i++){
        printf("%d, ", vet[i]);
    }
    printf("\n");
}

void gerar_vetor(int vet[], int n) {
    for (int i = 0; i < n; i++) {
        vet[i] = rand() % 100;
    }
}


int main(){
    
    srand(time(NULL));

    int n = 10;
    int *vet = (int*) malloc(n * sizeof(int));

    printf("Vetor desordenado: ");
    gerar_vetor(vet, n);
    imprimir_lista(vet, n);

    printf("Vetor ordenado: ");
    insertion_sort(vet, n);
    imprimir_lista(vet, n);

    free(vet);
    return 0;

}