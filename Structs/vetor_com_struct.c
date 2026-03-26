// Arrays de Structs
// E se quisermos uma lista de vários dominando_struct? Podemos criar um array!

#include <stdio.h>

typedef struct {
    int id;
    char nome[50]; // Agora com um nome
} Produto;

int main() {
    // Declarando um array que pode conter 3 produtos
    Produto catalogo[3];

    // Preenchendo o primeiro produto
    catalogo[0].id = 1;
    sprintf(catalogo[0].nome, "Laptop"); // sprintf é como printf, mas para strings

    // Preenchendo o segundo produto
    catalogo[1].id = 2;
    sprintf(catalogo[1].nome, "Mouse");

    // Preenchendo o terceiro produto com inicialização direta
    catalogo[2] = (Produto){3, "Teclado"};


    // Imprimindo o catálogo
    for (int i = 0; i < 3; i++) {
        printf("Produto ID: %d, Nome: %s\n", catalogo[i].id, catalogo[i].nome);
    }

    return 0;
}
