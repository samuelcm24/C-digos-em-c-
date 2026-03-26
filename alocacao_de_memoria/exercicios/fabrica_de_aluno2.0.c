/*
Versão atualizada e melhorada da versão anterior do programa, só que funcionando como uma ficha de cadastro para alunos
com seu nome, escola, n° da matricula, nome dos pais.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int matricula;
    char nome_escola[50];
    char nome_aluno[50];
    char nome_pai[50];
    char nome_mae[50];
}Registro;


void imprimirFicha(Registro Lista[], int tamanho){

    printf("\n=============== Ficha Escola Do Aluno ===============\n");
    for(int i = 0; i < tamanho; i++){
        printf("Escola: %s\n", Lista[i].nome_escola);
        printf("Aluno: %s\n", Lista[i].nome_aluno);
        printf("N° Matricula: %d\n", Lista[i].matricula);
        printf("Nome Do Pai: %s\n", Lista[i].nome_pai);
        printf("Nome Mãe: %s\n", Lista[i].nome_mae);
        printf("==============================================\n");
    }
}

// A função agora recebe ponteiros para alterar as variáveis da main
// Registro** -> ponteiro para um ponteiro
// int* -> ponteiro para um inteiro
void criando_ficha(Registro** ponteiro_para_lista, int* ponteiro_para_tamanho) {
    // Se já existir uma lista antiga, libera a memória dela primeiro
    if (*ponteiro_para_lista != NULL) {
        free(*ponteiro_para_lista);
        *ponteiro_para_lista = NULL;
    }

    int n_alunos_local;
    printf("Quantos alunos iremos cadastrar? ");
    scanf("%d", &n_alunos_local);

    // Aloca a memória e atribui ao ponteiro da main usando o desreferenciador (*)
    *ponteiro_para_lista = (Registro*) malloc(n_alunos_local * sizeof(Registro));

    if (*ponteiro_para_lista == NULL) {
        printf("Erro: Nao foi possivel alocar a memoria.\n");
        *ponteiro_para_tamanho = 0; // Garante que o tamanho seja 0 em caso de falha
        return;
    }

    // Atualiza o tamanho total de alunos na main
    *ponteiro_para_tamanho = n_alunos_local;
    
    // Usa um ponteiro local para facilitar a leitura do código no loop
    Registro* ficha_atual = *ponteiro_para_lista;

    for (int i = 0; i < n_alunos_local; i++) {
        printf("\n--- Cadastrando Aluno %d ---\n", i + 1);

        // Limpa o buffer APENAS UMA VEZ, após o scanf dos n_alunos
        while (getchar() != '\n'); 

        printf("Digite o nome da escola: ");
        fgets(ficha_atual[i].nome_escola, 50, stdin);

        printf("Digite o nome do aluno: ");
        fgets(ficha_atual[i].nome_aluno, 50, stdin);

        printf("Insira o numero da matricula: ");
        scanf("%d", &ficha_atual[i].matricula);
        
        // Limpa o buffer novamente após o scanf da matrícula
        while (getchar() != '\n');

        printf("Digite o nome do pai: ");
        fgets(ficha_atual[i].nome_pai, 50, stdin);

        printf("Digite o nome da mae: ");
        fgets(ficha_atual[i].nome_mae, 50, stdin);
    }
    printf("\nCadastro concluido!\n");
}


void menu(){

    printf("\n===== Menu =====\n");
    printf("1.Cadastrar aluno\n");
    printf("2.Alunos Matriculados\n");
    printf("0.Sair\n");
    printf("\n======================\n");
}

int main() {
    // 1. As variáveis que guardam os dados agora vivem na main
    Registro *lista_de_alunos = NULL;
    int total_alunos = 0;
    int opcao;

    do {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Passamos o ENDEREÇO das nossas variáveis para a função poder alterá-las
                criando_ficha(&lista_de_alunos, &total_alunos);
                break;
            case 2:
                // Agora a main CONHECE os dados e pode passá-los para a impressão
                imprimirFicha(lista_de_alunos, total_alunos);
                break;
            case 0:
                printf("Saindo....\n");
                break;
            default:
                printf("Erro! Entrada invalida.\n");
                break;
        }
        if (opcao != 0) {
            printf("\nPressione Enter para continuar...");
            while (getchar() != '\n'); // Limpa o buffer do scanf da opção
            getchar(); // Espera o Enter do usuário
        }

    } while (opcao != 0);

    // 2. Liberamos a memória aqui, no final do programa.
    if (lista_de_alunos != NULL) {
        free(lista_de_alunos);
    }

    return 0;
}