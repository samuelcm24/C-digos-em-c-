#include <stdio.h>

void trocar_valores(int *a, int *b){

    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    
    int a, b;
    int *ptr_a, *ptr_b;

    a = 5;
    b = 9;
    ptr_a = &a;
    ptr_b = &b;

    printf("Valores antes da troca:\na = %d, b = %d\n", a, b);

    trocar_valores(ptr_a, ptr_b);
    printf("a = %d, b = %d\n", a, b);
    
    return 0;

}