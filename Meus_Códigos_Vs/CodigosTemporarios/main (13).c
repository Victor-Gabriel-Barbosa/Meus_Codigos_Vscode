// 14 – Faça um algoritmo que preencha um vetor com dez números inteiros, calcule e mostre a quantidade de números negativos e a soma dos números positivos. 

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main(void) {
  int vet[10], i, soma_pos=0, qtd_neg=0;
  srand(time(0));
  for (i = 0; i < 10; i++) {
    vet[i] = (rand() % 201) - 100;
  }
  
  for (i = 0; i < 10; i++) {
    if (vet[i] > 0)
      soma_pos += vet[i];
    else if (vet[i] < 0)
      qtd_neg++;
  }
  printf("\nSoma dos números positivos: %d", soma_pos);
  printf("\nQuantidade de números negativos: %d", qtd_neg);
  return 0;
}