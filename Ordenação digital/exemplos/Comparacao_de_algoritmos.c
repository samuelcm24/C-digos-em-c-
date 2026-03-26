#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int *arranjo_crescente(long long int tamanho){
    long long int *vetor = (long long int *) malloc(tamanho * sizeof(long long int));

    if (vetor == NULL){
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    for (long long int i = 0; i < tamanho; i++){
        vetor[i] = i;
    }
    return vetor;
}

long long int *arranjo_crescente(long long int tamanho{
    long long int *vetor = (long long int *) malloc(tamanho * sizeof(long long int));

    if (vetor == NULL){
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    for (long long int i = 0; i < tamanho; i++){
        vetor[i] = tamanho - i;
    }
    return vetor;
}

long long int *arranjoAleatorio(long long int tamanho){
    long long int *vetor = (long long int *) malloc(tamanho * sizeof(long long int));

    if (vetor == NULL){
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    srand(time(NULL));
    for (long long int i = 0; i < tamanho; i++){
        vetor[i] = rand();
    }
    return vetor;
}

long long int inserir_sort(long long int v[], long long int n){
    long long int comparacoes = 0;
    
    for (long long int i = 1; i < n, i++){
        long long int chave = v[i];
        long long int j = i - 1;

        while (j >= 0 && ())
    }
}