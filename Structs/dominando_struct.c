/*
Neste arquivo teremos exemplos e alguns exercicios relacionados a Struct em C.

*/

// Abaixo um exemplo bem simples de como uma struct em C funciona;

/*
#include <stdio.h> 

// Definição de uma struct chamada 'dominando_struct'
// Uma struct é uma estrutura que permite agrupar diferentes tipos de dados sob um mesmo nome
struct dominando_struct
{
    int dado;       // Um campo do tipo inteiro chamado 'dado'
    float valor;    // Um campo do tipo float (número decimal) chamado 'valor'
};

int main() {
    // Declaração de uma variável chamada 'variavel' do tipo 'struct dominando_struct'
    struct dominando_struct variavel;

    // Atribuição de valores aos campos da struct
    variavel.dado = 10;         // Define o campo 'dado' com o valor inteiro 10
    variavel.valor = 22.22;     // Define o campo 'valor' com o valor decimal 22.22

    // Exibição dos valores armazenados na struct usando printf
    // %d é usado para imprimir inteiros
    // %.2f é usado para imprimir números decimais com duas casas após o ponto
    printf("Dado: %d \nValor: %.2f\n", variavel.dado, variavel.valor);

    return 0;  // Indica que o programa terminou corretamente
}
*/

// Exercicio 1;

/*Escreva uma função que receba um número inteiro que representa um intervalo de tempo medido 
em minutos e devolva o número equivalente de horas e minutos (por exemplo, 131 minutos equivalem a 2 horas e 11 minutos). 
Use uma struct como a seguinte:

struct hm {
   int horas, minutos;
};
*/

#include <stdio.h>

typedef struct {
    int horas;
    int minutos;
} relogio;

void converte(relogio *s, int tempo) {
    s->horas = tempo / 60;
    s->minutos = tempo % 60;
}

int main(){
    relogio s;
    int valor = 131;

    converte(&s, valor);

    printf("\n%d minutos em horas é: %d horas : %d minutos.\n", valor, s.horas, s.minutos);

    return 0;
}