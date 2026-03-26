/*
Escreva uma função com protótipo  insertionsort1 (int v[], int n)  que rearranje um vetor v[1..n] 
(note os índices!) em ordem crescente. (Basta invocar insertionsort da maneira correta.)
*/


// Supõe que você já tenha a função insertionSort para índices 0..n-1
void insertionSort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

// ---------- Função wrapper para vetor indexado de 1..n ----------
void insertionsort1(int v[], int n) {
    // Desloca o vetor temporariamente para 0..n-1
    // v[1..n] passa a ser vTemp[0..n-1]
    int *vTemp = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        vTemp[i] = v[i+1]; // desloca os elementos
    }

    // Ordena com insertionSort
    insertionSort(vTemp, n);

    // Copia de volta para v[1..n]
    for (int i = 0; i < n; i++) {
        v[i+1] = vTemp[i];
    }

    free(vTemp);
}
