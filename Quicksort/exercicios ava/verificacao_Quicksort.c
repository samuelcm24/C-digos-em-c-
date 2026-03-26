#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int *arranjoCrescente(long long int tamanho) {
    long long int *vetor = (long long int *) malloc(tamanho * sizeof(long long int));
    for (long long int i = 0; i < tamanho; i++) {
        vetor[i] = i;
    }
    return vetor;
}

long long int *arranjoDecrescente(long long int tamanho) {
    long long int *vetor = (long long int *) malloc(tamanho * sizeof(long long int));
    for (long long int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - 1 - i;
    }
    return vetor;
}

long long int *arranjoAleatorio(long long int tamanho) {
    long long int *vetor = (long long int *) malloc(tamanho * sizeof(long long int));
    for (long long int i = 0; i < tamanho; i++) {
        vetor[i] = rand();
    }
    return vetor;
}

int separa(int v[], int p, int r, long long int *p_comparacoes) {
    int c = v[r];
    int t, j = p;
    for(int k = p; k < r; ++k){
        (*p_comparacoes)++;
        if(v[k] <= c){
            t = v[j], v[j] = v[k], v[k] = t;
            ++j;
        }
    }
    t = v[j], v[j] = v[r], v[r] = t;
    return j;
}

void quicksort(int v[], int p, int r, long long int *p_comparacoes) {
    while (p < r){
        int j = separa(v, p, r, p_comparacoes);
        if (j - p < r - j){
            quicksort(v, p, j-1, p_comparacoes);
            p = j + 1;
        }else{
            quicksort(v, j+1, r, p_comparacoes);
            r = j - 1;
        }
    }
}
 
void verifcar_instacias(int n){
    clock_t inicio, fim;
    double tempo;
    long long int comparacoes;

    printf("Instancia de tamanho %d: ",n);
    
    int *vetor1 = arranjoCrescente(n);
    comparacoes = 0;
    inicio = clock();
    quicksort(vetor1, 0, n - 1, &comparacoes);
    fim =  clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("%-20s | Comparacoes: %lld | Tempo: %.3f s\n", "Arranjo Crescente", comparacoes, tempo);
    free(vetor1);

    int *vetor2 = arranjoDecrescente(n);
    comparacoes = 0;
    inicio = clock();
    quicksort(vetor2, 0, n - 1, &comparacoes);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("%-20s | Comparacoes: %lld | Tempo: %.3f s\n", "Arranjo Decrescente", comparacoes, tempo);
    free(vetor2);

    int *vetor3 = arranjoAleatorio(n);
    comparacoes = 0;
    inicio = clock();
    quicksort(vetor3, 0, n - 1, &comparacoes);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("%-20s | Comparacoes: %lld | Tempo: %.3f s\n", "Arranjo Aleatorio", comparacoes, tempo);
    free(vetor3);
}

int main(){
    srand(time(NULL));

    verifcar_instacias(1000);      // Pequeno
    verifcar_instacias(50000);     // Médio
    verifcar_instacias(200000);    // Grande (>100k)

    return 0;
}