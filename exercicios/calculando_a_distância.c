/*
Exercício 2: Funções - Calculando a Distância
Aproveite a struct Ponto do exercício anterior. Crie uma função chamada calcularDistancia que recebe 
um Ponto como parâmetro (por valor) e retorna a distância euclidiana desse ponto até a origem (0,0).
A fórmula da distância é: 

D = sqrt x**2+y**2
*/

#include <stdio.h>
#include <math.h>

typedef struct{
    float x;
    float y;
}pontos;

float calcular_a_distancia(pontos p){

    float distancia = sqrt(pow(p.x, 2) + pow(p.y, 2));
    return distancia;

}

int main(){
    pontos meuPonto = {3, 4};
    float d;

    d = calcular_a_distancia(meuPonto);

    printf("Os pontos (%.2f e %.2f) estão a uma distância de %.2f da origem.\n",meuPonto.x, meuPonto.y, d);
    return 0;
}
