/* 17 – Faça um algoritmo que preencha um vetor com oito números inteiros,
 * calcule e mostre dois vetores resultantes. O primeiro vetor resultante deve
 * conter os números positivos; o segundo deve conter os números negativos. Cada
 * vetor resultante vai ter, no máximo, oito posições, que poderão não ser
 * completamente utilizadas */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int i, vet[8], positivo[8], negativo[8];
  for (i = 0; i < 8; i++) { // Preenche os vetores
    vet[i] = (rand() % 201) - 100;
    positivo[i] = 0;
    negativo[i] = 0;
  }
  printf("Vetor Original: ");
  for (i = 0; i < 8; i++) { // Imprime o vetor original
    printf(i == 0 ? "%d" : ", %d", vet[i]);
  }
  for (i = 0; i < 8; i++) { // Separa os positivos e negativos
    if (vet[i] > 0)
      positivo[i] = vet[i];
    if (vet[i] < 0)
      negativo[i] = vet[i];
  }
  printf("\nVetor Positivo: ");
  for (i = 0; i < 8; i++) { // Imprime o vetor de positivos
    printf(i == 0 ? "%d" : ", %d", positivo[i]);
  }
  printf("\nVetor Negativo: ");
  for (i = 0; i < 8; i++) { // Imprime o vetor de negativos
    printf(i == 0 ? "%d" : ", %d", negativo[i]);
  }
  return 0;
}