/*
Exercício 4: Array de Structs - Cadastro de Produtos
Defina uma struct Produto com os seguintes campos: int codigo, char nome[50] e float preco.

Na função main, crie um array de 3 produtos.

Preencha este array com dados de três produtos diferentes.

Crie uma função chamada imprimeProdutos que recebe o array de produtos e seu tamanho, e 
imprime os dados de todos os produtos de forma organizada.

Chame essa função a partir da main.
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[50];
    float preco;
}Cadastro;


void imprimeProdutos(Cadastro lista[], int tamanho){
    printf("\n===== Lista de produtos =====\n");
    for (int i = 0; i < tamanho; i++){
        printf("Código: %d\n", lista[i].codigo);
        printf("Nome: %s\n",lista[i].nome);
        printf("Preço: R$: %.3f", lista[i].preco);
        printf("\n===============================\n");
    }
}

Cadastro encontraProdutoMaisCaro(Cadastro lista[], int tamanho){

    Cadastro mais_caro = lista[0];
    for(int i = 1; i < tamanho; i++){
        if(lista[i].preco > mais_caro.preco){
            mais_caro = lista[i];
        }
    }
    return mais_caro;

}



int main(){
    Cadastro catalogo[3];
    int n_produtos = 3;

    // Preenchendo a lista;
    catalogo[0].codigo = 123321;
    strcpy(catalogo[0].nome, "Iphone");
    catalogo[0].preco = 2.543;

    catalogo[1].codigo = 211105;
    strcpy(catalogo[1].nome, "Celular");
    catalogo[1].preco = 1.546;

    catalogo[2].codigo = 210511;
    strcpy(catalogo[2].nome, "Geladeira");
    catalogo[2].preco = 3.253;

    imprimeProdutos(catalogo, n_produtos);

    Cadastro Produtomaiscaro;
    Produtomaiscaro = encontraProdutoMaisCaro(catalogo, n_produtos);
    
    printf("\n====== Produdo mais caro ======\n");
    printf("Código: %d\n", Produtomaiscaro.codigo);
    printf("Nome: %s\n", Produtomaiscaro.nome);
    printf("Preço: R$ %.4f\n", Produtomaiscaro.preco);

    return 0;
}