/*
Exercício 2: Contando os Elementos
Objetivo: Criar uma função que conta quantos elementos (reais) existem na lista.

Instruções:

Crie uma nova função com a seguinte assinatura: int contar_elementos(celula *le).

Esta função deve percorrer a lista e retornar o número de células (sem contar o nó cabeça).

Na função main, depois de inserir alguns elementos, chame a sua função contar_elementos e imprima o resultado na tela. 
Ex: printf("A lista tem %d elementos.\n", total);.

Dica: A lógica é muito parecida com a da função imprime. Você vai precisar de uma variável "contador" que começa em 0 e é 
incrementada a cada passo do laço.
*/

#include <stdio.h>
#include <stdlib.h>

// A struct celula
typedef struct celula {
    int conteudo;
    struct celula *prox;
} celula;

// A função insere
void insere(int x, celula *p) {
    celula *nova = malloc(sizeof(celula));
    nova->conteudo = x;
    nova->prox = p->prox;
    p->prox = nova;
}

// A função imprime
void imprime(celula *le) {
    celula *p;
    printf("Lista: ");
    for (p = le->prox; p != NULL; p = p->prox) {
        printf("%d -> ", p->conteudo);
    }
    printf("NULL\n");
}// ... (cabeçalhos e a struct celula) ...
// ... (funções insere e imprime) ...

// Função para somar os elementos
int somar_elementos(celula *le) {
    int soma = 0;
    celula *p;

    for (p = le->prox; p != NULL; p = p->prox) {
        // Em vez de incrementar, adicionamos o 'conteudo' da célula à soma
        soma = soma + p->conteudo;
        // ou de forma abreviada: soma += p->conteudo;
    }

    return soma;
}

int main() {
    celula *lista = malloc(sizeof(celula));
    lista->prox = NULL;
    
    insere(30, lista); // Lista: 30
    insere(20, lista); // Lista: 20 -> 30
    insere(10, lista); // Lista: 10 -> 20 -> 30

    imprime(lista);

    // Testando a nova função
    int resultado_soma = somar_elementos(lista);
    // A soma deve ser 10 + 20 + 30 = 60
    printf("A soma dos elementos da lista e: %d\n", resultado_soma);

    // ... (liberar memória) ...
    free(lista->prox->prox->prox);
    free(lista->prox->prox);
    free(lista->prox);
    free(lista);

    return 0;
}