/*3. Ponteiros para Structs (Muito Importante!)
Quando uma struct é muito grande, passá-la inteira para uma função (como no exemplo acima) cria uma 
cópia de todos os dados, o que pode ser ineficiente. É mais comum e eficiente passar um ponteiro para a struct.

Quando usamos um ponteiro, o operador para acessar os membros muda de . (ponto) para -> (seta).

*/

#include <stdio.h>
#include <stdlib.h> // Para malloc

typedef struct {
    int dado;
    float valor;
} DominandoStruct;

// A função agora recebe um PONTEIRO para a struct
void modificaStruct(DominandoStruct *s_ptr) {
    printf("Modificando a struct através do ponteiro...\n");
    // Usamos a 'seta' (->) para acessar membros através de um ponteiro
    s_ptr->dado = 99;
    s_ptr->valor = 77.77;
}

int main() {
    DominandoStruct variavel = {10, 22.22};

    printf("Valores Originais:\n");
    printf("Dado: %d \nValor: %.2f\n\n", variavel.dado, variavel.valor);

    // Passamos o ENDEREÇO (&) da nossa variável para a função
    modificaStruct(&variavel);

    printf("Valores Após a Função:\n");
    printf("Dado: %d \nValor: %.2f\n", variavel.dado, variavel.valor);

    return 0;
}

// Note que a função modificaStruct alterou a variável variavel original 
// da função main, porque ela recebeu o endereço de memória e trabalhou diretamente nele.