/* 01 - Faça um programa que tenha um vetor de 10 posições e um ponteiro que
 * aponta para este vetor. Preencha este vetor com valores de 1 a 10 pelo
 * ponteiro */

#include <stdio.h>

int main(void) {
  int vet[10], *p, i;
  p = vet;
  for (i = 0; i < 10; i++) { // Preenche o vetor com valores de 1 a 10
    *p = i + 1;
    p++;
  }
  for (i = 0; i < 10; i++) { // Imprime o vetor
    printf(i == 0 ? "%d" : ", %d", vet[i]);
  }
  return 0;
}