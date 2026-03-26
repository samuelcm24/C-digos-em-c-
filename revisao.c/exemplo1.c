#include <stdio.h>

int main(){

    int a = 1233;

    int *p;
    p = &a;

    printf("%d\n", *p); // Valor armazenado no enderelo de memoria em p, no caso o valor de a
    printf("%p\n", p); 

    printf("%p\n", &p);

    *p = 2312; // atualiza o valor do ponteiro no caso o valor de A.
    printf("%d\n", *p);

    return 0;
}