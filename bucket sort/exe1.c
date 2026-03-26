//Implementação do bucket sort

#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct {
    int count;
    float values[N];
} Bucket;

void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void bucketSort(float arr[], int n) {
    Bucket buckets[10] = {0};

    // Distribui nos baldes
    for (int i = 0; i < n; i++) {
        int index = (int)(arr[i] * 10); // assume valores em [0,1)
        buckets[index].values[buckets[index].count++] = arr[i];
    }

    // Ordena cada balde
    for (int i = 0; i < 10; i++)
        insertionSort(buckets[i].values, buckets[i].count);

    // Concatena os baldes
    int idx = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < buckets[i].count; j++)
            arr[idx++] = buckets[i].values[j];
}

int main() {
    float arr[] = {0.78,0.17,0.39,0.26,0.72,0.94,0.21,0.12,0.23,0.68};
    int n = sizeof(arr)/sizeof(arr[0]);

    bucketSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");

    return 0;
}
