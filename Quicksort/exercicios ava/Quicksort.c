#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// FUnções dadas no anexo do AVA
int *arranjoCrescente(int tamanho) {
    int *vetor = (int *) malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i;
    }
    return vetor;
}

int *arranjoDecrescente(int tamanho) {
    int *vetor = (int *) malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - 1 - i;
    }
    return vetor;
}

int *arranjoAleatorio(int tamanho) {
    int *vetor = (int *) malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand();
    }
    return vetor;
}


//Função que separa os elementos menores que o pivo
int separa(int v[], int p, int r, long long int *p_comparacoes, long long int *p_trocas) {
    int c = v[r]; 
    int t, j = p;
    for (int k = p; k < r; ++k) {
        (*p_comparacoes)++;
        if (v[k] <= c) {
            t = v[j]; v[j] = v[k]; v[k] = t;
            (*p_trocas)++;   
            ++j; 
        } 
    }
    t = v[j]; v[j] = v[r]; v[r] = t;
    (*p_trocas)++;   
    return j; 
}

//Função do quicksort
void quickSort(int v[], int p, int r, long long int *p_comparacoes, long long int *p_trocas) {
    while (p < r) {      
        int j = separa(v, p, r, p_comparacoes, p_trocas);    
        if (j - p < r - j) {     
            quickSort(v, p, j-1, p_comparacoes, p_trocas);
            p = j + 1;            
        } else {                 
            quickSort(v, j+1, r, p_comparacoes, p_trocas);
            r = j - 1;
        }
    }
}

//Instancias para poder testar os valores
void instancia(int n) {
    clock_t inicio, fim;
    double tempo;
    long long int comparacoes, trocas;

    printf("\n=== Testando instância de tamanho %d ===\n", n);

    int *vetor1 = arranjoCrescente(n);
    comparacoes = 0; trocas = 0;
    inicio = clock();
    quickSort(vetor1, 0, n - 1, &comparacoes, &trocas);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("%-20s | Comparacoes: %lld | Trocas: %lld | Tempo: %.3f s\n", "Arranjo Crescente", comparacoes, trocas, tempo);
    free(vetor1);

    int *vetor2 = arranjoDecrescente(n);
    comparacoes = 0; trocas = 0;
    inicio = clock();
    quickSort(vetor2, 0, n - 1, &comparacoes, &trocas);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("%-20s | Comparacoes: %lld | Trocas: %lld | Tempo: %.3f s\n", "Arranjo Decrescente", comparacoes, trocas, tempo);
    free(vetor2);

    int *vetor3 = arranjoAleatorio(n);
    comparacoes = 0; trocas = 0;
    inicio = clock();
    quickSort(vetor3, 0, n - 1, &comparacoes, &trocas);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("%-20s | Comparacoes: %lld | Trocas: %lld | Tempo: %.3f s\n", "Arranjo Aleatorio", comparacoes, trocas, tempo);
    free(vetor3);
}

int main() {
    srand(time(NULL));
    //Instancia que irá testar 100000 elementos
    instancia(100000);
    //Para 500000 elementos
    instancia(500000);
    //Para 1000000 de elementos
    instancia(1000000);   

    return 0;
}