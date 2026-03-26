/*
Busca
Implemente uma função que busque um valor na lista e retorne o ponteiro para o nó correspondente (ou NULL se não existir).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no* prox;
} no;

no* criar_no(int valor){
    no* novo = (no*)malloc(sizeof(no));
    if (novo == NULL){
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    novo->dado = valor;
    novo->prox = NULL;
    return novo;
}

no* buscar(no* inicio, int valor){
    no* atual = inicio;
    while (atual != NULL){
        if (atual->dado == valor){
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

void imprimir(no* inicio){
    printf("Lista: ");
    while (inicio != NULL){
        printf("%d -> ", inicio->dado);
        inicio = inicio->prox;
    }
    printf("NULL\n");
}

int main(){
    no* lista = NULL;
    lista = criar_no(10);
    lista->prox = criar_no(20);
    lista->prox->prox = criar_no(30);

    imprimir(lista);

    int valor_busca = 20;
    no* resultado = buscar(lista, valor_busca);
    if (resultado != NULL){
        printf("Valor %d encontrado na lista.\n", resultado->dado);
    } else {
        printf("Valor %d não encontrado na lista.\n", valor_busca);
    }

    // Liberar memória
    no* atual = lista;
    while (atual != NULL) {
        no* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    
    printf("Memória liberada!\n");
    return 0;
}
