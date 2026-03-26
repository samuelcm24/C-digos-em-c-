/*
Fazendo troca de valores por ponteiros
*/
#include <stdio.h>

void trocar_valores(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a = 6;
    int b = 10;
    int *ptr_a;
    int *ptr_b;

    ptr_a = &a;
    ptr_b = &b;

    printf("a = %d, b = %d\n", a, b);
    trocar_valores(ptr_a, ptr_b);

    printf("a = %d, b = %d\n", a, b);
    return 0;
}