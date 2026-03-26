/*
Objetivo: Crie uma função criarAluno que recebe o nome e a matrícula de um aluno. A função deve alocar dinamicamente 
memória para uma struct Aluno, preencher os campos com os dados recebidos e 
retornar um ponteiro para essa struct alocada. A função main deve chamar criarAluno, imprimir os dados e liberar a memória.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- ALTERAÇÃO 1: A STRUCT AGORA TEM O PONTEIRO ---
// Esta struct agora define um "Nó" da lista.
// Cada nó contém os dados do aluno E um ponteiro para o próximo nó.
typedef struct Aluno {
    char nome_escola[100];
    char nome[50];
    int matricula;
    struct Aluno* proximo; // A MUDANÇA ESSENCIAL ESTÁ AQUI!
} Aluno;

// A função de criação agora inicializa o ponteiro 'proximo' como NULL.
// Isso garante que todo novo aluno seja, inicialmente, o último da lista.
Aluno* criar_aluno(const char* nome_escola, const char* nome, int matricula) {
    Aluno* novo_aluno = (Aluno*) malloc(sizeof(Aluno));

    if (novo_aluno == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    strcpy(novo_aluno->nome_escola, nome_escola);
    strcpy(novo_aluno->nome, nome);
    novo_aluno->matricula = matricula;
    novo_aluno->proximo = NULL; // Importante: o novo nó ainda não aponta para ninguém.

    return novo_aluno;
}

// --- ALTERAÇÃO 2: FUNÇÃO PARA IMPRIMIR A LISTA INTEIRA ---
// Em vez de imprimir um único aluno, esta função recebe o início da lista
// e a percorre, imprimindo cada aluno até encontrar o final (NULL).
void imprimir_lista(const Aluno* inicio_da_lista) {
    const Aluno* aluno_atual = inicio_da_lista; // Ponteiro para percorrer a lista

    printf("\n========== LISTA DE ALUNOS MATRICULADOS ==========\n");
    if (aluno_atual == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }
    
    // Loop "while" percorre a lista enquanto o aluno atual não for NULL
    while (aluno_atual != NULL) {
        printf("----------------------------------------\n");
        printf("Nome da escola: %s\n", aluno_atual->nome_escola);
        printf("Nome do aluno: %s\n", aluno_atual->nome);
        printf("N° da matricula: %d\n", aluno_atual->matricula);
        
        // Pula para o próximo aluno da lista
        aluno_atual = aluno_atual->proximo;
    }
    printf("----------------------------------------\n");
    printf("Fim da lista.\n");
}

// --- ALTERAÇÃO 3: FUNÇÃO PARA LIBERAR A MEMÓRIA DA LISTA ---
// É crucial ter uma função que percorra a lista e libere a memória de CADA nó.
void liberar_lista(Aluno* inicio_da_lista) {
    Aluno* aluno_atual = inicio_da_lista;
    Aluno* proximo_aluno;

    while (aluno_atual != NULL) {
        proximo_aluno = aluno_atual->proximo; // Guarda o endereço do próximo
        free(aluno_atual);                    // Libera o aluno atual
        aluno_atual = proximo_aluno;          // Move para o próximo
    }
}

// --- ALTERAÇÃO 4: A MAIN AGORA MONTA E GERENCIA A LISTA ---
int main() {
    // 'lista' será o ponteiro para o primeiro aluno. Começa como NULL (lista vazia).
    Aluno* lista = NULL; 
    Aluno* aluno1, *aluno2, *aluno3;

    // Criando os nós individualmente
    printf("Realizando a matricula do primeiro aluno....\n");
    aluno1 = criar_aluno("Arthur Da Costa E Silva", "Samuel Campos Martins", 2005);

    printf("Realizando a matricula do segundo aluno..\n");
    aluno2 = criar_aluno("Raquel Arbues", "Myllena Queiroz", 19);

    printf("Realizando a matricula do terceiro aluno..\n");
    aluno3 = criar_aluno("Escola Central", "Joao Pedro", 101);

    // Agora, vamos "encadear" ou "ligar" os nós para formar a lista
    lista = aluno1;             // O aluno1 é o início (cabeça) da lista
    aluno1->proximo = aluno2;   // O aluno1 aponta para o aluno2
    aluno2->proximo = aluno3;   // O aluno2 aponta para o aluno3
    // O aluno3->proximo já é NULL, indicando o fim da lista.

    // A mágica acontece aqui: passamos apenas o início da lista
    // e a função 'imprimir_lista' percorre todos os elementos.
    imprimir_lista(lista);

    // Libera a memória de todos os nós da lista de forma segura
    printf("\nLiberando a memoria da lista...\n");
    liberar_lista(lista);
    lista = NULL; // Boa prática: define o ponteiro como NULL após liberar a memória.
    printf("Memoria liberada com sucesso.\n");

    return 0;
}