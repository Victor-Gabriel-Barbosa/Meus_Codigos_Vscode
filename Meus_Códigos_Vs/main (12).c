// 13 – Faça um algoritmo que leia um vetor com cinquenta posições para números inteiros e mostre somente os números positivos

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main(void) {
  int vet[50], i;
  srand(time(0));
  for (i = 0; i < 50; i++) {
    vet[i] = (rand() % 201) - 100;
  }
  printf("\nNúmeros positivos:\n");
  for (i = 0; i < 50; i++) {
    if (vet[i] > 0) {
      if (i == 0)
        printf("%d", vet[i]);
      else 
        printf(", %d", vet[i]);
    }
  }
  printf("\n\nNúmeros negativos:\n");
  for (i = 0; i < 50; i++) {
    if (vet[i] < 0) {
      if (i == 0)
        printf("%d", vet[i]);
      else
        printf(", %d", vet[i]);
    }
  }
  return 0;
}