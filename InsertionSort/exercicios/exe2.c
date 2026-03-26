/*

🔹 Exercício 2 — Inserir um elemento no lugar certo
Tarefa:

Dado um vetor já ordenado {1, 3, 5, 7, 9}

Pegue um novo número 6

Insira ele na posição correta sem ordenar todo o vetor novamente

Imprima o vetor final

Esse exercício ajuda a entender a lógica central do Insertion Sort, que é “pegar um elemento e colocar no lugar certo”.



#include <stdio.h>
#include <stdlib.h>

void inserir_no_lugar_certo(int lista[], int tamanho, int novo_elemento) {
    int i = tamanho - 1;

    // Move os elementos maiores que o novo elemento uma posição à frente
    while (i >= 0 && lista[i] > novo_elemento) {
        lista[i + 1] = lista[i];
        i--;
    }
    // Insere o novo elemento na posição correta
    lista[i + 1] = novo_elemento;
}

int main() {
    int vet[] = {1, 3, 5, 7, 9};
    int tamanho = sizeof(vet) / sizeof(vet[0]);
    int novo_elemento = 6;

    printf("Vetor antes da insercao: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d, ", vet[i]);
    }
    printf("\n");

    inserir_no_lugar_certo(vet, tamanho, novo_elemento);

    printf("Vetor final: ");
    for (int i = 0; i < tamanho + 1; i++) {
        printf("%d, ", vet[i]);
    }
    printf("\n");

    return 0;
}

*/

/*
🔹 Exercício 2 — Inserir um elemento no lugar certo
Tarefa:

Dado um vetor já ordenado {1, 3, 5, 7, 9}

Pegue um novo número 6

Insira ele na posição correta sem ordenar todo o vetor novamente

Imprima o vetor final

Esse exercício ajuda a entender a lógica central do Insertion Sort, que é “pegar um elemento e colocar no lugar certo”.
*/

#include <stdio.h>
#include <stdlib.h>

void inserir_na_ordem(int lista[], int tamanho, int novo_valor){
    int i = tamanho - 1;

    while (i >= 0 && lista[i] > novo_valor){
        lista[i + 1] = lista[i];
        i--;
    }
    lista[i + 1] = novo_valor;
}

void imprimir_lista(int lista[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d, ", lista[i]);
    }
    printf("\n");
}

int main(){
    int vet[] = {1, 3, 5, 7, 9};
    int tamanho = sizeof(vet) / sizeof(vet[0]);
    int novo_elemento = 6;

    printf("Vetor antes da insercao: ");
    imprimir_lista(vet, tamanho);

    printf("Vetor com o novo elemento: ");
    inserir_na_ordem(vet, tamanho, novo_elemento);
    imprimir_lista(vet, tamanho + 1);

    return 0;
}