#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cadastro
{
    double valor;
    int quantidade;
    char nome[50];

} cadastro;

cadastro* Produto(double valor, int quantidade, const char* nome){

    cadastro* novo_produto = (cadastro*) malloc(sizeof(cadastro));

    if (novo_produto == NULL){
        printf("Erro ao alocar memoria...\n");
        exit(1);
    }

    novo_produto->valor = valor;
    novo_produto->quantidade = quantidade;
    strcpy(novo_produto->nome, nome);

    return novo_produto;
}

void imprimir_lista(cadastro* lista){
    printf("\n========== Lista De Produtos ==========\n");
    printf("Nome produto: %s\n", lista->nome);
    printf("Valor: %.3lf\n", lista->valor);
    printf("Quantidade em estoque: %d\n", lista->quantidade);
}

int main(){
    cadastro* produto1;
    cadastro* produto2;

    printf("Cadastrando 1 produto...\n");
    produto1 = Produto(1.994, 5, "Geladeira");
    printf("Produto cadastrado com sucesso!!\n");

    printf("Cadastrando 2 produto...\n");
    produto2 = Produto(1.725, 7, "Tv Samsumg");
    printf("Produto cadastrado com sucesso!!\n");

    if (produto1 != NULL && produto2 != NULL){
        imprimir_lista(produto1);
        imprimir_lista(produto2);

        printf("Liberando memoria...\n");
        free(produto1);
        free(produto2);
        produto1 = NULL;
        produto2 = NULL;
        printf("Memoria liberada com sucesso...\n");
    }else{
        printf("Erro ao imprimir lista..\n");
        printf("Liberando memoria...\n");
        free(produto1);
        free(produto2);
        produto1 = NULL;
        produto2 = NULL;
    }
    return 0;
}
