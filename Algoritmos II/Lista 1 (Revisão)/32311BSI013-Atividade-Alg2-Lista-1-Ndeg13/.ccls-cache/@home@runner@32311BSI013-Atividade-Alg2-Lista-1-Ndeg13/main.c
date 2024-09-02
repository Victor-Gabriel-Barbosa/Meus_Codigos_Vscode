/* 13 – Faça um algoritmo que leia um vetor com cinquenta posições 
para números inteiros e mostre somente os números positivos */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int vet[50], i;
  srand(time(0));
  for (i = 0; i < 50; i++) { // Preenchendo o vetor
    vet[i] = (rand() % 201) - 100;
  }
  printf("\nNúmeros positivos:\n");
  for (i = 0; i < 50; i++) { // Impre os números positivos
    if (vet[i] > 0) {
      printf(i == 0 ? "%d" : ", %d", vet[i]);
    }
  }
  // EXTRA:
  printf("\n\nNúmeros negativos:\n");
  for (i = 0; i < 50; i++) { // Impre os números negativos
    if (vet[i] < 0) {
      printf(i == 0 ? "%d" : ", %d", vet[i]);
    }
  }
  return 0;
}