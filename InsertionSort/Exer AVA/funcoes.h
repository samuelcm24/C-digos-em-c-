#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int *arranjoCrescente(long long int tamanho);
long long int *arranjoDecrescente(long long int tamanho);
long long int *arranjoAleatorio(long long int tamanho);

void insertionsort_instrumentado(long long int n, long long int v[], long long int *p_comparacoes);

#endif