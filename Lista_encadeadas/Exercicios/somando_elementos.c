/*Exercício 3: Somando os Elementos
Objetivo: Criar uma função que calcula a soma de todos os valores (conteudo) na lista.

Instruções:

Crie uma nova função: int somar_elementos(celula *le).

Esta função deve percorrer a lista, somar o campo conteudo de cada célula e retornar a soma total.

Teste sua função na main da mesma forma que fez com a de contar.

Dica: Similar ao exercício 2, mas em vez de incrementar um contador, você vai acumular os valores 
em uma variável "soma"
*/
// ... (cabeçalhos e a struct celula) ...
// ... (funções insere e imprime) ...

// Função para somar os elementos
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