//Implementação do seletionsort;

void selectionSort(int vet[], int n){
    int i, j, Min, aux;

    for(i = 0; i < n - 1; i++){
        Min = i;
        for(j = i + 1; j < n; j++){
            if(vet[j] < vet[Min]){
                Min = j;
            }
        }
        aux = vet[i];
        vet[i] = vet[Min];
        vet[Min] = aux;
    }
}

void imprimrirVetor(int vet[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main(){
    int vet[] = {29, 10, 14, 37, 13};
    int n = sizeof(vet) / sizeof(vet[0]);

    printf("Vetor desordenado: ");
    imprimrirVetor(vet, n);

    printf("Vetor ordenado: ");
    selectionSort(vet, n);
    imprimrirVetor(vet, n);

    return 0;
}