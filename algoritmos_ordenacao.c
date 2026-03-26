#include <stdio.h>
#include <stdlib.h>

void imprimir_lista(int vet[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

// ---------------- Insertion Sort ----------------
void insertion_sort(int vet[], int n){
    int i, j, aux;
    for(i = 1; i < n; i++){
        aux = vet[i];
        j = i - 1;
        while (j >= 0 && vet[j] > aux){
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = aux;
    }
}

// ---------------- Selection Sort ----------------
void seletion_sort(int vet[], int n){
    int i, j, min, aux;
    for(i = 0; i < n - 1; i++){
        min = i;
        for(j = i + 1; j < n; j++){
            if(vet[j] < vet[min]){
                min = j;
            }
        }
        aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
    }
}

// ---------------- Merge Sort ----------------
void merge(int vetor[], int inicio, int meio, int fim){
    int tamanho_esq = meio - inicio + 1;
    int tamanho_dir = fim - meio;

    int *esquerda = (int*) malloc(tamanho_esq * sizeof(int));
    int *direita = (int*) malloc(tamanho_dir * sizeof(int));

    for(int i = 0; i < tamanho_esq; i++)
        esquerda[i] = vetor[inicio + i];
    for(int j = 0; j < tamanho_dir; j++)
        direita[j] = vetor[meio + 1 + j];

    int i=0, j=0, k=inicio;
    while(i < tamanho_esq && j < tamanho_dir){
        if(esquerda[i] <= direita[j])
            vetor[k++] = esquerda[i++];
        else
            vetor[k++] = direita[j++];
    }
    while(i < tamanho_esq) vetor[k++] = esquerda[i++];
    while(j < tamanho_dir) vetor[k++] = direita[j++];

    free(esquerda);
    free(direita);
}

void merge_sort(int vetor[], int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio + fim)/2;
        merge_sort(vetor, inicio, meio);
        merge_sort(vetor, meio+1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

// ---------------- Quick Sort ----------------
int Particiona(int vet[], int inicio, int fim){
    int pivo = vet[fim];
    int indice_menor = inicio;

    for(int i = inicio; i < fim; i++){
        if(vet[i] <= pivo){
            int temp = vet[i];
            vet[i] = vet[indice_menor];
            vet[indice_menor] = temp;
            indice_menor++;
        }
    }
    int temp = vet[indice_menor];
    vet[indice_menor] = vet[fim];
    vet[fim] = temp;

    return indice_menor;
}

void Quick_sort(int vet[], int inicio, int fim){
    if(inicio < fim){
        int indicePivo = Particiona(vet, inicio, fim);
        Quick_sort(vet, inicio, indicePivo - 1);
        Quick_sort(vet, indicePivo + 1, fim);
    }
}

// ---------------- Counting Sort ----------------
void counting_sort(int vet[], int tamanho) {
    if (tamanho <= 0) return;  // Se o vetor estiver vazio, retorna

    // 1️⃣ Descobre o valor máximo do vetor
    int max = vet[0];
    for (int i = 0; i < tamanho; i++) {
        if (vet[i] > max) max = vet[i];
    }

    // 2️⃣ Cria o vetor de contagem, inicializado com 0
    int *contagem = (int*) calloc(max + 1, sizeof(int));

    // 3️⃣ Conta quantas vezes cada elemento aparece
    for (int i = 0; i < tamanho; i++) {
        contagem[vet[i]]++;
    }

    // 4️⃣ Reconstrói o vetor original em ordem crescente
    int indice = 0;            // índice para preencher o vetor original
    for (int j = 0; j <= max; j++) { // percorre todos os valores possíveis
        while (contagem[j]-- > 0) {  // enquanto houver ocorrências
            vet[indice++] = j;       // coloca o valor no vetor original
        }
    }

    // 5️⃣ Libera a memória do vetor de contagem
    free(contagem);
}

// ---------------- Radix Sort ----------------
int getMax(int vet[], int n){
    int Max = vet[0];
    for(int i=1; i<n; i++)
        if(vet[i] > Max) Max = vet[i];
    return Max;
}

void countingSort_radix(int v[], int n, int exp){
    int *saida = (int*) malloc(n * sizeof(int));
    int count[10] = {0};

    for(int i=0;i<n;i++)
        count[(v[i]/exp)%10]++;
    for(int i=1;i<10;i++)
        count[i] += count[i-1];
    for(int i=n-1;i>=0;i--){
        int digito = (v[i]/exp)%10;
        saida[count[digito]-1] = v[i];
        count[digito]--;
    }
    for(int i=0;i<n;i++)
        v[i] = saida[i];
    free(saida);
}

void radix_sort(int vet[], int n){
    int max = getMax(vet, n);
    for(int exp=1; max/exp >0; exp*=10)
        countingSort_radix(vet, n, exp);
}

// ---------------- Bucket Sort ----------------
#define N 10
typedef struct {
    int count;
    float values[N];
} Bucket;

void insertionSort_float(float arr[], int n){
    for(int i=1;i<n;i++){
        float key = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void bucketSort(int vet[], int n){
    int i;
    // encontra o maximo
    int max = vet[0];
    for(i=1;i<n;i++)
        if(vet[i]>max) max = vet[i];

    // normaliza para [0,1)
    float arr[n];
    for(i=0;i<n;i++)
        arr[i] = (float)vet[i]/(max+1);

    Bucket buckets[10] = {0};

    for(i=0;i<n;i++){
        int index = (int)(arr[i]*10);
        buckets[index].values[buckets[index].count++] = arr[i];
    }

    for(i=0;i<10;i++)
        insertionSort_float(buckets[i].values, buckets[i].count);

    int idx=0;
    for(i=0;i<10;i++)
        for(int j=0;j<buckets[i].count;j++)
            vet[idx++] = (int)(buckets[i].values[j]*(max+1));
}

// ---------------- MAIN ----------------
int main(){
    int vet[] = {22,33, 1, 992, 21, 9, 222, 1021};
    int tamanho = sizeof(vet)/sizeof(vet[0]);
    int vet_copy[tamanho];

    printf("Vetor original: ");
    imprimir_lista(vet, tamanho);

    // ---------------- Testa todos os algoritmos ----------------
    // Insertion Sort
    for(int i=0;i<tamanho;i++) vet_copy[i]=vet[i];
    insertion_sort(vet_copy, tamanho);
    printf("Insertion Sort: ");
    imprimir_lista(vet_copy, tamanho);

    // Selection Sort
    for(int i=0;i<tamanho;i++) vet_copy[i]=vet[i];
    seletion_sort(vet_copy, tamanho);
    printf("Selection Sort: ");
    imprimir_lista(vet_copy, tamanho);

    // Merge Sort
    for(int i=0;i<tamanho;i++) vet_copy[i]=vet[i];
    merge_sort(vet_copy,0,tamanho-1);
    printf("Merge Sort: ");
    imprimir_lista(vet_copy, tamanho);

    // Quick Sort
    for(int i=0;i<tamanho;i++) vet_copy[i]=vet[i];
    Quick_sort(vet_copy,0,tamanho-1);
    printf("Quick Sort: ");
    imprimir_lista(vet_copy, tamanho);

    // Counting Sort
    for(int i=0;i<tamanho;i++) vet_copy[i]=vet[i];
    Counting_sort(vet_copy, tamanho);
    printf("Counting Sort: ");
    imprimir_lista(vet_copy, tamanho);

    // Radix Sort
    for(int i=0;i<tamanho;i++) vet_copy[i]=vet[i];
    radix_sort(vet_copy, tamanho);
    printf("Radix Sort: ");
    imprimir_lista(vet_copy, tamanho);

    // Bucket Sort
    for(int i=0;i<tamanho;i++) vet_copy[i]=vet[i];
    bucketSort(vet_copy, tamanho);
    printf("Bucket Sort: ");
    imprimir_lista(vet_copy, tamanho);

    return 0;
}