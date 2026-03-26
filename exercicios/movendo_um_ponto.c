/*
Exercício 3: Funções e Ponteiros - Movendo um Ponto
Ainda usando a struct Ponto, crie uma função void moverPonto(Ponto *p, int deltaX, int deltaY).
Esta função deve receber um ponteiro para um Ponto e alterar suas coordenadas x e y, somando os valores de deltaX e deltaY, 
respectivamente.

Na função main, crie um Ponto, imprima suas coordenadas iniciais, 
chame a função moverPonto para alterá-lo e imprima as novas coordenadas.
*/

#include <stdio.h>

typedef struct{
    float x;
    float y;
}pontos;

void moverPonto(pontos *p, int deltaX,int deltaY){
    // Usa o operador SETA (->) para acessar e modificar os membros do ponto original
    // Essa parte ela soma os valores antigos com os novos
    p->x += deltaX; // += é a mesma coisa que x + y;
    p->y += deltaY;
}

int main(){

    pontos C = {5, 10};

    printf("Coodernadas sem alteração: %.2f %.2f\n", C.x, C.y);

    moverPonto(&C, 3, -5);

    printf("Novas coodernadas: (%.2f, %.2f)\n)", C.x, C.y);
    return 0;
    
}