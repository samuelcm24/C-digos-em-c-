/*
Exercício 1: Simulador de Fila de Atendimento

Enunciado:
Escreva um programa em C que utilize a estrutura de fila estática com array (TAMANHO_MAX = 5) 
para gerenciar uma fila de atendimento.
O programa deve simular o seguinte cenário:

Chegada de 4 clientes, representados por senhas numéricas (ex: 101, 102, 103, 104).

Atendimento (desenfileiramento) dos 2 primeiros clientes.

Exibição de qual é o próximo cliente a ser atendido (sem removê-lo da fila).

Chegada de mais 2 clientes com senhas (ex: 105, 106). Um deles não conseguirá entrar na fila, pois ela estará cheia.

Atendimento de todos os clientes restantes até que a fila fique vazia.

Ao final, o programa deve informar que não há mais clientes na fila.
*/
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 5

// --- Estrutura da Fila com nomes corrigidos ---
typedef struct {
    int itens[TAMANHO_MAX]; // "itens" é mais claro que "tamanho"
    int inicio;
    int fim;
    int quantidade;
} Fila;

void inicializar(Fila *f){
    f->inicio = 0;
    f->fim = -1;
    f->quantidade = 0;
}

int estaVazia(Fila *f){ // Corrigido para "esta"
    return f->quantidade == 0;
}

int estaCheia(Fila *f){ // Corrigido para "esta"
    return f->quantidade == TAMANHO_MAX;
}

void enfileirar(Fila *f, int valor){ // Corrigido para "enfileirar"
    if (estaCheia(f)){
        // Mensagem de erro personalizada para o exercício
        printf("Cliente com senha %d nao pode entrar. Fila de espera lotada!\n", valor);
        return;
    }
    f->fim = (f->fim + 1) % TAMANHO_MAX;
    f->itens[f->fim] = valor;
    f->quantidade++;
    printf("Cliente com senha %d entrou na fila.\n", valor);
}

int desenfileirar(Fila *f){ // Corrigido para "desenfileirar"
    if (estaVazia(f)){
        printf("Nao ha clientes para atender.\n");
        return -1;
    }
    int item = f->itens[f->inicio]; // Usando "item" para mais clareza
    f->inicio = (f->inicio + 1) % TAMANHO_MAX;
    f->quantidade--;
    return item;
}

int espiar(Fila *f){
    if (estaVazia(f)){
        printf("Nao ha clientes na fila.\n");
        return -1;
    }
    return f->itens[f->inicio];
}

// --- MAIN CORRIGIDO PARA O EXERCÍCIO 1 ---
int main(){
    Fila fila_atendimento;
    inicializar(&fila_atendimento);

    printf("--- Iniciando a simulacao de atendimento ---\n\n");

    // 1. Chegada de 4 clientes
    printf("--- Fase 1: Chegada de clientes ---\n");
    enfileirar(&fila_atendimento, 101);
    enfileirar(&fila_atendimento, 102);
    enfileirar(&fila_atendimento, 103);
    enfileirar(&fila_atendimento, 104);
    printf("\n");

    // 2. Atendimento dos 2 primeiros clientes
    printf("--- Fase 2: Primeiros atendimentos ---\n");
    printf("Atendendo cliente com senha: %d\n", desenfileirar(&fila_atendimento));
    printf("Atendendo cliente com senha: %d\n", desenfileirar(&fila_atendimento));
    printf("\n");

    // 3. Exibição do próximo cliente
    printf("--- Fase 3: Verificando o proximo ---\n");
    printf("Proximo cliente a ser atendido tem a senha: %d\n", espiar(&fila_atendimento));
    printf("\n");

    // 4. Chegada de mais clientes para encher a fila
    printf("--- Fase 4: Chegada de mais clientes ---\n");
    enfileirar(&fila_atendimento, 105);
    enfileirar(&fila_atendimento, 106);
    // A fila agora tem 4 clientes (103, 104, 105, 106). Vamos tentar adicionar o 5º para encher.
    enfileirar(&fila_atendimento, 107);
    // Agora a fila está cheia (5 clientes). Vamos tentar adicionar mais um para mostrar o erro.
    enfileirar(&fila_atendimento, 108); // Esta chamada irá falhar, como pedido no exercício.
    printf("\n");

    // 5. Atendimento de todos os clientes restantes
    printf("--- Fase 5: Atendendo todos os clientes restantes ---\n");
    while(!estaVazia(&fila_atendimento)) {
        printf("Atendendo cliente com senha: %d\n", desenfileirar(&fila_atendimento));
    }
    printf("\n");

    // 6. Informar que a fila está vazia
    printf("--- Fim da simulacao ---\n");
    if(estaVazia(&fila_atendimento)) {
        printf("Fila de atendimento vazia!\n");
    }

    return 0;
}