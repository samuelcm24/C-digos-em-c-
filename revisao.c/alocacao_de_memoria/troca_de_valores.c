#include <stdio.h>

void trocar_valores(int *a, int *b){

    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a, b;

    
    a = 5;
    b = 7;

    printf("Valores de a e b:\n");
    printf("A = %d, B = %d\n", a, b);

    printf("Trocando valores de A e B...\n");
    trocar_valores(&a, &b);

    printf("Valores de a e b após a troca: \n");
    printf("A = %d, B = %d\n", a, b);
    return 0;
    
}