#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produtos_encadeados
{
    double valor;
    char nome[50];
    struct produtos_encadeados* prox;
} produtos_encadeados;

produtos_encadeados* criar_produto(double valor, const char* nome){
    produtos_encadeados* novo_produto = (produtos_encadeados*) malloc(sizeof(produtos_encadeados));

    if (novo_produto == NULL){
        printf("Erro ao alocar memoria...\n");
        exit(1);
    }

    strcpy(novo_produto->nome, nome);
    novo_produto->valor = valor;
    novo_produto->prox = NULL;

    return novo_produto;
}

void imprimir_lista(const produtos_encadeados* inicio_lista){
    const produtos_encadeados* lista_atual = inicio_lista;
    
    printf("\n===== Dados Da Matricula =====\n");

    if(lista_atual == NULL){
        printf("A lista esta vazia...\n");
        return;
    }

    while(lista_atual != NULL){
        printf("------------------------------------------\n");
        printf("Nome do produto:  %s\n", lista_atual->nome);
        printf("Valor do produto: R$ %.3lf\n", lista_atual->valor);
        
        lista_atual = lista_atual->prox;
    }

    printf("----------------------------------------------\n");

    printf("Fim da lista.\n");
}

void liberar_meroria(produtos_encadeados* inicio_lista){
    produtos_encadeados* lista_atual = inicio_lista;
    produtos_encadeados* prox_produto;

    while (lista_atual != NULL)
    {
        prox_produto = lista_atual->prox;
        free(lista_atual);
        lista_atual = prox_produto;
    }
}

int main(){
    produtos_encadeados* lista = NULL;
    produtos_encadeados* produto1;
    produtos_encadeados* produto2;

    printf("Fazendo o cadastro do produtos...\n");
    produto1 = criar_produto(1.567, "Celular");

    produto2 = criar_produto(1.566, "Sofá");
    printf("Produtos cadastrados..\n");

    lista = produto1;
    produto1->prox = produto2;

    imprimir_lista(lista);

    printf("Liberando memoria...\n");

    liberar_meroria(lista);
    lista = NULL;
    printf("Memoria liberada com sucesso!\n");
    return 0;
}