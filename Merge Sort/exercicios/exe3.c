/*Invente um função de intercalação tão eficiente quanto intercala que resolva
 o problema in loco, ou seja, sem usar um vetor auxiliar.*/

#include <stdio.h>

void mergeInPlace(int x[], int m, int y[], int n) {
    int i = m - 1;        // último elemento real de x
    int j = n - 1;        // último elemento de y
    int k = m + n - 1;    // posição final disponível em x

    // copia o maior para o final
    while (i >= 0 && j >= 0) {
        if (x[i] > y[j])
            x[k--] = x[i--];
        else
            x[k--] = y[j--];
    }

    // se sobrar elementos em y, copiar para x
    while (j >= 0)
        x[k--] = y[j--];
}

int main() {
    int x[10] = {1, 3, 5}; // espaço extra no final
    int y[] = {2, 4, 6};
    int m = 3, n = 3;

    mergeInPlace(x, m, y, n);

    printf("Vetor intercalado: ");
    for (int i = 0; i < m + n; i++)
        printf("%d ", x[i]);
    printf("\n");

    return 0;
}