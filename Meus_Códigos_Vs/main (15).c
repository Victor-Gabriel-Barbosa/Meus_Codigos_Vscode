// 16 – Faça um algoritmo que preencha dois vetores de dez posições cada um, determine e mostre o terceiro contendo a soma das posições dos dois vetores anteriores. 

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
int main(void) {
  int vet[10], vet2[10], vet3[10], i;
  for (i = 0; i < 10; i++) {
    vet[i] = (rand() % 201) - 100;
    vet2[i] = (rand() % 201) - 100;
  }
  for (i = 0; i < 10; i++) {
    if (i == 0)
      printf("\nVetor [1]: %d", vet[i]);
    else
      printf(", %d", vet[i]);
  }
  for (i = 0; i < 10; i++) {
    if (i == 0)
      printf("\n\nVetor [2]: %d", vet2[i]);
    else
      printf(", %d", vet2[i]);
  }
  for (i = 0; i < 10; i++) {
    vet3[i] = vet[i] + vet2[i];
    if (i == 0) {
      printf("\n\nResultado:");
      printf("\nVetor[3]: %d", vet3[i]);
    }
    else
      printf(", %d", vet3[i]);
  }
  return 0;
}