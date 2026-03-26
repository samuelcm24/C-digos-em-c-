/*Crie uma struct chamada Ponto que armazene duas coordenadas: int x e int y. Na função main, 
crie uma variável do tipo Ponto, atribua os valores x = 10 e y = 20 e depois imprima os valores
na tela no formato "(x, y)".

*/
#include <stdio.h>

typedef struct
{
    int x;
    int y;

}Ponto;

int main(){

    Ponto meuPonto;

    meuPonto.x = 10;
    meuPonto.y = 20;

    printf("\nx = %d \nY = %d\n", meuPonto.x, meuPonto.y);
    return 0;
}
