#include <stdio.h>
#include <stdbool.h>

bool estarCrescente(int vet[], int n){

    for(int i = 0; i < n - 1; i++){
        if (vet[i] > vet[i + 1]){
            return false;
        }
    }
    return true;
}

int main(){
    
    int v1[] = {1,2,3,4,5};
    int v2[] = {3,5,1,5,7};

    printf("A função está em ordem crescente ? %s\n", estarCrescente(v1, 5) ? "Sim" : "Não");
    printf("A função está em ordem crescente ? %s\n", estarCrescente(v2, 5) ? "Sim" : "Não");

    return 0;
}