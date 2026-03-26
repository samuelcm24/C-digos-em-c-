/*
Exercício 3: Ponteiros e Funções
Objetivo: Entender como passar ponteiros para funções para permitir que a função modifique 
variáveis do "mundo exterior" (do escopo que a chamou).
*/

#include <stdio.h>

void Ponteiro_funcao(int *ponteiro){
    *ponteiro = (*ponteiro) *2;

}

int main(){
    int num;

    printf("Digite um número: ");
    scanf("%d", &num);

    printf("Valor antes de passar pela função criada: %d\n", num);
    Ponteiro_funcao(&num);

    printf("Novo valor após passar pela função: %d\n", num);
    
}