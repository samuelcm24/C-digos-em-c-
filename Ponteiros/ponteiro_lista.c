/*
Exercício 4: A Ponte Para Listas Encadeadas - O Nó (Node)
Objetivo: Definir a estrutura básica de um elemento de lista encadeada e criar um ponteiro para ela.

Uma lista encadeada é uma coleção de "nós". Cada nó contém duas coisas:

Um dado (um número, um nome, etc.).

Um ponteiro para o próximo nó da lista.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dado; //Valor a ser armazenado;
    struct lista *ponteiro;// Um ponteiro para o nó do mesmo tipo;
}lista;

int main(){

    // Declaramos um ponteiro que pode apontar para uma estrutura Node.
    // Ele começa apontando para nada;
    lista *cabeca = NULL;


    cabeca = (lista*) malloc(sizeof(lista));

    //Preenchendo o nó
    cabeca->dado = 25; // Atribui o valor ao campos 'dado' do nó;
    cabeca->ponteiro = NULL;// Este é o primeiro e unico nó, então ele não aponta para o próximo;

    printf("Dados do primeiro nó: %d\n", cabeca->dado);
    printf("Endereço do proximo nó: %p\n", cabeca->ponteiro);

    free(cabeca);

    return 0;

}