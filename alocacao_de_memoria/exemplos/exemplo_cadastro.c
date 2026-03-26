
#include <stdio.h>
#include <stdlib.h> // Essencial para malloc() e free()
#include <string.h>

typedef struct {
    int codigo;
    char nome[50];
    float preco;
} Cadastro;

int main() {
    // 1. Declaramos um PONTEIRO. É ele que vai apontar para a memória
    //    que vamos alocar no Heap.
    Cadastro *produto_ptr;

    printf("Pedindo memoria para um novo produto...\n");

    // 2. A ALOCAÇÃO DINÂMICA ACONTECE AQUI!
    //   - sizeof(Cadastro): Calcula o n° de bytes necessários para UMA struct Cadastro.
    //   - malloc(...): Pede esse n° de bytes ao sistema. Retorna um ponteiro genérico (void*).
    //   - (Cadastro*): Convertemos (cast) o ponteiro genérico para o nosso tipo específico.
    produto_ptr = (Cadastro*) malloc(sizeof(Cadastro));

    // 3. VERIFICAÇÃO CRÍTICA: Checar se o malloc deu certo.
    //    Se não houver memória, ele retorna NULL.
    if (produto_ptr == NULL) {
        printf("Erro: Falha ao alocar memoria!\n");
        return 1; // Encerra o programa com um código de erro.
    }

    printf("Memoria alocada com sucesso!\n");

    // 4. USANDO A MEMÓRIA: Como 'produto_ptr' é um ponteiro,
    //    usamos o operador SETA (->) para acessar os membros.
    produto_ptr->codigo = 101;
    strcpy(produto_ptr->nome, "Headset Gamer");
    produto_ptr->preco = 350.75;

    // Imprimindo os dados para confirmar
    printf("\n--- Produto Alocado Dinamicamente ---\n");
    printf("Código: %d\n", produto_ptr->codigo);
    printf("Nome: %s\n", produto_ptr->nome);
    printf("Preço: R$ %.2f\n", produto_ptr->preco);
    printf("------------------------------------\n");

    // 5. DEVOLVENDO A MEMÓRIA: O passo mais importante!
    //    Depois de usar, liberamos a memória para evitar vazamentos.
    free(produto_ptr);
    printf("\nMemoria liberada com free().\n");

    // Boa prática: Apontar o ponteiro para NULL após o free para evitar
    // que ele seja usado acidentalmente (ponteiro pendurado ou "dangling pointer").
    produto_ptr = NULL;

    return 0;
}