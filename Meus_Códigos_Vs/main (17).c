// 18 – Faça um algoritmo que preencha dois vetores de dez elementos numéricos cada um e mostre o vetor resultante da intercalação deles. 


#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main(void) {
  int vet[8], vet2[8], vet3[16], i;
  srand(time(0));
  for (i = 0; i < 8; i++) {
    vet[i] = (rand() % 201) - 100;
    vet2[i] = (rand() % 201) - 100;
  }
  for (i = 0; i < 8; i++) {
    vet3[i] = vet[i];
    vet3[i + 8] = vet2[i];
  }
  printf("Vetor 1: ");
  for (i = 0; i < 8; i++) {
    if (i == 0)
      printf("%d ", vet[i]);
    else
      printf(", %d ", vet[i]);
  }
  printf("\n\nVetor 2: ");
  for (i = 0; i < 8; i++) {
    if (i == 0)
      printf("%d ", vet2[i]);
    else
      printf(", %d ", vet2[i]);
  }
  printf("\n\nVetor resultante 3: ");
  for (i = 0; i < 16; i++) {
    if (i == 0)
      printf("%d ", vet3[i]);
    else
      printf(", %d ", vet3[i]);
  }
  return 0;
}