/*
Exemplo 3: Alocando um array de inteiros com tamanho definido pelo usuário
Este exemplo mostra o verdadeiro poder da alocação dinâmica. O programa vai perguntar o tamanho 
do array e alocar memória exatamente para aquela quantidade.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p_array;
    int n_elementos;

    printf("Quantos numeros inteiros voce quer armazenar? ");
    scanf("%d", &n_elementos);

    printf("Ok, alocando memoria para %d inteiros...\n", n_elementos);

    // A mágica acontece aqui: usamos uma VARIÁVEL para definir o tamanho da alocação!
    p_array = (int*) malloc(n_elementos * sizeof(int));

    if (p_array == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    // Preenche o array dinâmico com valores
    for (int i = 0; i < n_elementos; i++) {
        p_array[i] = i * 10; // Acesso como um array normal
    }

    printf("Valores armazenados no array dinamico:\n");
    for (int i = 0; i < n_elementos; i++) {
        printf("p_array[%d] = %d\n", i, p_array[i]);
    }

    // Libera TODA a memória do array de uma vez
    free(p_array);
    p_array = NULL;
    printf("Memoria do array liberada.\n");

    return 0;
}

/*
O que este exemplo demonstra: A capacidade de criar arrays de tamanho flexível, decidido durante a execução do programa, 
que é a principal razão de existir da alocação dinâmica.

Note que o padrão é sempre o mesmo: Ponteiro -> malloc -> Checagem de NULL -> Uso -> free. O que muda é o tipo do ponteiro, 
o cálculo dentro do sizeof e a forma como usamos a memória alocada.
*/