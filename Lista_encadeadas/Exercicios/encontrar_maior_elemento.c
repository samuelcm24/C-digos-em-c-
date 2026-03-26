/*
Exercício 2: 
Encontrar o Maior Elemento 
Escreva uma função chamada int encontrar_maior(celula *le) que recebe o ponteiro para o nó cabeça de uma lista e retorna 
o maior valor encontrado entre todos os elementos. 
Se a lista estiver vazia, a função deve retornar 0 (ou um outro valor que indique erro, como INT_MIN 
da biblioteca <limits.h>).
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct celula
{
    int conteudo;
    struct celula *prox;
} celula;

int maior_valor(celula *ele){

    if (ele->prox == NULL){
        return INT_MIN;
    }

    int maior = ele->prox->conteudo;
    celula *p;

        // Percorre a lista A PARTIR DO SEGUNDO elemento, pois o primeiro já foi verificado.
    for (p = ele->prox->prox; p != NULL; p = p->prox) {
        // Se o conteúdo do nó atual for maior que o maior que já encontramos...
        if (p->conteudo > maior) {
            // ...ele se torna o novo maior.
            maior = p->conteudo;
        }
    }

    return maior;
}


int main(){
    

    celula *lista = malloc(sizeof(celula));
    lista->prox = malloc(sizeof(celula));
    lista->prox->conteudo = 10;
    lista->prox->prox = malloc(sizeof(celula));
    lista->prox->prox->conteudo = 23;
    lista->prox->prox->prox = malloc(sizeof(celula));
    lista->prox->prox->prox->conteudo = 201;
    lista->prox->prox->prox->prox = NULL;

    int maior_numero = maior_valor(lista);

    printf("O maior valor da lista é: %d\n", maior_numero);


    free(lista->prox->prox->prox);
    free(lista->prox->prox);
    free(lista->prox);
    free(lista);

    return 0;
    


}