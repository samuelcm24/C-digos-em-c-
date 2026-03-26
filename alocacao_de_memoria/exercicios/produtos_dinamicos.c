/*

Exercício 1: Catálogo de Produtos Dinâmico
Modifique o seu último exercício do "Catálogo de Produtos". Em vez de ter um array com tamanho fixo (Cadastro catalogo[3];), 
o seu programa deve:

Perguntar ao usuário: "Quantos produtos você deseja cadastrar?".

Ler o número digitado pelo usuário.

Alocar dinamicamente um array de struct Cadastro com o tamanho exato que o usuário pediu.

Fazer um laço para pedir os dados (código, nome, preço) de cada um dos produtos e armazená-los no array dinâmico.

No final, chamar a função imprimeProdutos (que você já tem) para mostrar todos os produtos cadastrados.

Muito importante: Liberar a memória alocada com free() antes de terminar o programa.

Dica: A linha de alocação será parecida com ponteiro = (Cadastro*) malloc(N * sizeof(Cadastro));.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[50];
    float preco;

} Cadastro;



void imprimeProdutos(Cadastro lista[], int tamanho){
    printf("\n===== Lista de produtos =====\n");
    for (int i = 0; i < tamanho; i++){
        printf("Código: %d\n", lista[i].codigo);
        printf("Nome: %s\n",lista[i].nome);
        printf("Preço: R$: %.3f", lista[i].preco);
        printf("\n===============================\n");
    }
}


int main(){
    Cadastro *catalogo;
    int n_produtos;

    printf("Quantos produtos você deseja cadastrar ? ");
    scanf("%d", &n_produtos);
    
    catalogo = (Cadastro*) malloc(n_produtos * sizeof(Cadastro));

    if(catalogo == NULL){
        printf("Erro ao alocar memoria!!!\n");
        return 1;
    }

    for (int i = 0; i < n_produtos; i++){
        printf("Digite o código do produto: ");
        scanf("%d", &catalogo[i].codigo);

        printf("Digite o nome do produto: ");
        scanf("%s", catalogo[i].nome);

        printf("Digite o preço do produto: ");
        scanf("%f", &catalogo[i].preco);
    }

    imprimeProdutos(catalogo, n_produtos);

    free(catalogo);
    printf("\nMemoria liberada com sucesso!\n");

    return 0;
}

