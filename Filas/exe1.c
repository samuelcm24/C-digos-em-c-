#include <stdio.h>
#include <stdlib.h> // Necessário para usar malloc e free

// Estrutura do Nó (cada "caixa" da nossa lista)
typedef struct No {
    char valor;           // O dado que o nó armazena (ex: 'A', 'B', etc.)
    struct No* proximo;   // Ponteiro para o próximo nó na fila
} No;

// Estrutura da Fila (controla o início, o fim e o tamanho)
typedef struct Fila {
    No* inicio;     // Ponteiro para o início da fila (de onde sai o próximo elemento)
    No* fim;        // Ponteiro para o fim da fila (onde entra o novo elemento)
    int tamanho;    // A quantidade de elementos na fila
} Fila;

// Função para criar e inicializar uma nova Fila vazia
Fila* criar_fila() {
    Fila* f = (Fila*) malloc(sizeof(Fila)); // Aloca memória para a estrutura da Fila
    if (f == NULL) {
        perror("Erro ao alocar memoria para a fila");
        exit(1); // Encerra o programa se não conseguir alocar memória
    }
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
    return f;
}

// Função para exibir o estado atual da fila (ajuda a visualizar)
void imprimir_fila(Fila* f) {
    printf("Fila: [");
    No* atual = f->inicio;
    while (atual != NULL) {
        printf("%c", atual->valor);
        // Adiciona uma vírgula se não for o último elemento
        if (atual->proximo != NULL) {
            printf(", ");
        }
        atual = atual->proximo;
    }
    printf("] | Tamanho: %d\n", f->tamanho);
}

// Operação ENQUEUE: adiciona um elemento no final da fila
void enqueue(Fila* f, char valor) {
    // Cria o novo nó e aloca memória para ele
    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        perror("Erro ao alocar memoria para o no");
        return;
    }
    novo_no->valor = valor;
    novo_no->proximo = NULL; // O novo nó é o último, então aponta para NULL

    // Conecta o novo nó à fila
    if (f->fim == NULL) { // Se a fila está vazia
        f->inicio = novo_no;
        f->fim = novo_no;
    } else { // Se a fila já tem elementos
        f->fim->proximo = novo_no; // O antigo fim aponta para o novo nó
        f->fim = novo_no;          // O novo nó se torna o novo fim
    }

    // Atualiza o tamanho da fila
    f->tamanho++;
}

// Operação DEQUEUE: remove um elemento do início da fila
char dequeue(Fila* f) {
    if (f->inicio == NULL) {
        printf("A fila esta vazia. Nao e possivel remover.\n");
        return '\0'; // Retorna um caractere nulo para indicar que nada foi removido
    }

    // Guarda o nó a ser removido e seu valor
    No* no_removido = f->inicio;
    char valor_retornado = no_removido->valor;

    // O início da fila agora passa a ser o próximo elemento
    f->inicio = f->inicio->proximo;

    // Se a fila ficou vazia após a remoção, o ponteiro 'fim' também deve ser NULL
    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    // Libera a memória do nó que foi removido para evitar vazamentos
    free(no_removido);

    // Atualiza o tamanho da fila
    f->tamanho--;

    return valor_retornado;
}

// Operação SIZE: retorna o tamanho atual da fila
int size(Fila* f) {
    return f->tamanho;
}

// Função para liberar toda a memória alocada pela fila ao final do uso
void liberar_fila(Fila* f) {
    while(f->inicio != NULL) {
        dequeue(f);
    }
    free(f); // Libera a própria estrutura da fila
}


// Função principal para demonstrar o uso do código
int main() {
    // 1. Cria a fila
    Fila* minha_fila = criar_fila();
    
    printf("--- Demonstracao do Codigo da Fila ---\n");
    imprimir_fila(minha_fila);

    // 2. Executa algumas operações de exemplo
    printf("\nAdicionando 'A', 'B', 'C'...\n");
    enqueue(minha_fila, 'A');
    enqueue(minha_fila, 'B');
    enqueue(minha_fila, 'C');
    imprimir_fila(minha_fila);

    printf("\nRemovendo um elemento...\n");
    char removido = dequeue(minha_fila);
    printf("Elemento removido do inicio: %c\n", removido);
    imprimir_fila(minha_fila);
    
    printf("\nVerificando o tamanho...\n");
    printf("Tamanho atual: %d\n", size(minha_fila));

    printf("\nAdicionando 'D'...\n");
    enqueue(minha_fila, 'D');
    imprimir_fila(minha_fila);

    // 3. Libera a memória alocada antes de encerrar o programa
    liberar_fila(minha_fila);
    printf("\nMemoria da fila liberada com sucesso.\n");

    return 0;
}