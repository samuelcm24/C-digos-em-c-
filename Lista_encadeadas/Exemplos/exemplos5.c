/*Etapa 1 de nosso plano de aula: A Fundação (Estrutura e Inserção)

Nosso objetivo agora é construir, do zero, o esqueleto funcional de uma lista ligada. Ao final desta etapa, 
teremos um programa que pode criar uma lista, inserir elementos nela e exibi-la na tela.

Vamos dividir em três partes:

A definição da struct celula.

A função imprime, para podermos ver nosso progresso.

A função insere, o coração da nossa operação de hoje.

Aqui está o código completo para esta etapa. Peço que você o leia com atenção e, logo abaixo, vamos dissecar as partes mais 
importantes.

*/

#include <stdio.h>
#include <stdlib.h>

// PARTE 1: A definição da nossa "célula" (o nó da lista)
// Todo elemento da nossa lista seguirá este molde.
typedef struct celula {
    int conteudo;        // O dado que queremos armazenar.
    struct celula *prox; // O ponteiro que "liga" esta célula à próxima.
} celula;


// PARTE 2: A função de inserção
// Ela insere um novo elemento com conteúdo 'x' logo APÓS a célula apontada por 'p'.
void insere(int x, celula *p) {
    // 1. Aloca memória para a nova célula que vai entrar na lista.
    celula *nova = malloc(sizeof(celula));
    if (nova == NULL) return; // Se não houver memória, não faz nada.

    // 2. Preenche o conteúdo da nova célula com o valor 'x'.
    nova->conteudo = x;
    
    // 3. A nova célula deve apontar para o mesmo lugar que 'p' apontava.
    //    É assim que ligamos o 'rabo' da lista à nossa nova célula.
    nova->prox = p->prox;

    // 4. Agora, 'p' passa a apontar para a nova célula.
    //    É assim que ligamos a 'cabeça' da lista à nossa nova célula.
    p->prox = nova;
}

// PARTE 3: A função de impressão
// Recebe o ponteiro para o NÓ CABEÇA e imprime todos os elementos reais.
void imprime(celula *le) {
    celula *p;
    printf("Lista: ");
    // O laço começa em le->prox para PULAR o nó cabeça, que não tem conteúdo útil.
    for (p = le->prox; p != NULL; p = p->prox) {
        printf("%d -> ", p->conteudo);
    }
    printf("NULL\n");
}


// NOSSO LABORATÓRIO DE TESTES
int main() {
    // Inicializa a lista criando o nó cabeça.
    // 'lista' é um ponteiro que aponta para o nó cabeça.
    celula *lista = malloc(sizeof(celula));
    lista->prox = NULL; // A lista começa vazia (cabeça aponta para NULL).

    imprime(lista); // Mostra a lista vazia.

    // Usando nossa função para inserir elementos.
    // Como queremos inserir no início, sempre passamos 'lista' (o nó cabeça) como parâmetro.
    printf("\nInserindo 3...\n");
    insere(3, lista);
    imprime(lista);

    printf("\nInserindo 7...\n");
    insere(7, lista);
    imprime(lista);

    printf("\nInserindo 1...\n");
    insere(1, lista);
    imprime(lista);

    // No final, precisamos liberar toda a memória alocada.
    // Veremos a forma correta de fazer isso na Etapa 5.
    // Por enquanto, vamos liberar manualmente para evitar memory leaks.
    free(lista->prox->prox->prox);
    free(lista->prox->prox);
    free(lista->prox);
    free(lista);

    return 0;
}

/*Análise Detalhada
O ponto mais importante para entender é a lógica da função insere:

Imagine que a lista está assim: p -> C
E queremos inserir nova entre p e C.

nova->prox = p->prox;

Esta linha faz a nova célula apontar para C. Agora temos:

p -> C

nova -> C

p->prox = nova;

Esta linha faz p parar de apontar para C e apontar para nova. O resultado final é:

p -> nova -> C

Conseguimos inserir o elemento no meio sem perder o resto da lista.

*/