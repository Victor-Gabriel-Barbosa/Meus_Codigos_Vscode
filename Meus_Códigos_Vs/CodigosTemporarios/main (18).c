// 19 – Faça um algoritmo que preencha um vetor com dez elementos numérios e a partir desse vetor faça um segundo vetor que receba os valores do primeiro vetor de forma invertida.

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main(void) {
  int vet[10], vet_inv[10], i;
  srand(time(0));
  for (i = 0; i < 10; i++) {
    vet[i] = (rand() % 201) - 100;
    if (i == 0) {
      printf("\nVetor Inicial: ");
      printf("%d", vet[i]);
    }
    else
      printf(", %d", vet[i]);
  }
  for (i = 0; i < 10; i++) {
    vet_inv[i] = vet[9 - i];
    if (i == 0) {
      printf("\n\nVetor Invertido: ");
      printf("%d", vet_inv[i]);
    }
    else
      printf(", %d", vet_inv[i]);
  }
  return 0;
}