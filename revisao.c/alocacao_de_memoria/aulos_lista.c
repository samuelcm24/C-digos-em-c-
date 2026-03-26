/*Versão do meu código em lista encadeada;*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno
{
    int matricula;
    char nome[50]; 
    struct Aluno* prox;
} Aluno;

Aluno* criar_aluno(int matricula, const char* nome){
    Aluno* novo_aluno = (Aluno*) malloc(sizeof(Aluno));

    if (novo_aluno == NULL){
        printf("Erro ao alocar memoria..\n");
        exit(1);
    }

    strcpy(novo_aluno->nome, nome);
    novo_aluno->matricula = matricula;
    novo_aluno->prox = NULL; // O novo nó ainda não aponda para niguem.
    
    return novo_aluno;
}

// A função imprimir tambem ira mudar;
// Em vez de imprimir um único aluno, esta função recebe o início da lista
// e a percorre, imprimindo cada aluno até encontrar o final (NULL).
void imprimir_lista(const Aluno* inicio_da_lista) {

    const Aluno* aluno_atual = inicio_da_lista;// Ponteiro para percorrer a lista
    printf("\n========== Dados Da Matricula do aluno ==========\n");

    if (aluno_atual == NULL){
        printf("A lista está vazia....\n");
        return;
    }

    while (aluno_atual != NULL){
        printf("-----------------------------------------------\n");
        printf("Nome do aluno: %s\n", aluno_atual->nome);
        printf("N° Da Matricula do aluno: %d\n", aluno_atual->matricula);

        // Caso haver mais que um aluno a proxima
        // função irá pular para o proximo aluno;
        aluno_atual = aluno_atual->prox;
    }

    printf("--------------------------------\n");
    printf("Fim da lista\n");
}

// Agora para poder liberar a memoria temos que ter uma função propria;

void liberar_memoria(Aluno* inicio_da_lista){
    Aluno* aluno_atual = inicio_da_lista;
    Aluno* prox_aluno;

    while(aluno_atual != NULL){
        prox_aluno = aluno_atual->prox; // Aqui ele guarda o endereço de prox;
        free(aluno_atual); // Libera a memoria do aluno atual;
        aluno_atual = prox_aluno; // Move para o proximo para realizar a liberação da memoria;
    }
}


//A main tambem ira ser modificada
int main(){
// 'lista' será o ponteiro para o primeiro aluno. Começa como NULL (lista vazia).
    Aluno* lista = NULL;
    Aluno* aluno1;

    printf("Realizando a matricula do primeiro aluno(a)...\n");
    aluno1 = criar_aluno(123, "Samuel Campos Martins");


    //Agora vamos encadear ou ligar os nós;

    lista = aluno1;
    aluno1->prox = NULL;
    // O aluno3->proximo já é NULL, indicando o fim da lista.

    imprimir_lista(lista);

    //LIberando a memoria;
    printf("Liberando a memoria da lista...\n");
    liberar_memoria(lista);
    lista = NULL;
    printf("Memoria liberada com sucesso!!\n");

    return 0;
}