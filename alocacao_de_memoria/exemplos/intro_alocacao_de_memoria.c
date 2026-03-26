/*
    Exemplo de alocação de memoria;
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *numeros;
    int n, i;

    printf("Quantidade de números: ");
    scanf("%d", &n);

    numeros = malloc(n*sizeof(int));

    for(i = 0; i < n; i++){
        printf("Número %d:", i);
        scanf("%d", &numeros[i]);
    }    
    printf("Números lidos: ");
    for (i = 0; i < n; i++){
        printf("%d, ", numeros[i]);
    }
    printf("\n");

    free(numeros);
    printf("\nMemoria liberada com free().\n");
    return 0;
}