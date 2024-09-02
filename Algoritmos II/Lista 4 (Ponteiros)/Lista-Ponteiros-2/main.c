/* 02 - Faça um programa que tenha um vetor de 50 posições e um ponteiro que
 * aponte para este vetor. Mostre o conteúdo pelo ponteiro da terceira posição
 * do vetor */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL));
  int vet[50], *p, i;
  p = vet;
  for (i = 0; i < 50; i++) { // Preenche o vetor com números aleatórios
    vet[i] = rand() % 100; // Gera números aleatórios de 0 a 99
  }
  printf("[VETOR]: ");
  for (i = 0; i < 50; i++) { // Imprime o vetor
    printf(i == 0 ? "%d" : ", %d", vet[i]);
  }
  printf("\n\n[O conteúdo da terceira posição do vetor é: %d]", *(p + 2));
  return 0;
}