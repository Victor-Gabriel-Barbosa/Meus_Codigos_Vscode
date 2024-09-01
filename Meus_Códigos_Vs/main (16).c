// 17 – Faça um algoritmo que preencha um vetor com oito números inteiros, calcule e mostre dois vetores resultantes. O primeiro vetor resultante deve conter os números positivos; o segundo deve conter os números negativos. Cada vetor resultante vai ter, no máximo, oito posições, que poderão não ser completamente utilizadas. 

#define _GNU_SOURCE
#include <stdio.h>

int main(void) {
  int i, vet[8], positivo[8], negativo[8];
  for (i = 0; i < 8; i++) {
    vet[i] = (rand() % 201) - 100;
    positivo[i] = 0;
    negativo[i] = 0;
    if (i == 0) {
      printf("\nVetor original: ");
      printf("%d", vet[i]);
    }
    else 
      printf(", %d", vet[i]);
      
  }
  for (i = 0; i < 8; i++) {
    if (vet[i] > 0) {
      positivo[i] = vet[i];
    }
    if (vet[i] < 0) {
      negativo[i] = vet[i];
    }
  }
  for (i = 0; i < 8; i++) {
    if (i == 0) {
      printf("\n\nVetor positivo: ");
      printf("%d", positivo[i]);
    }
    else 
      printf(", %d", positivo[i]);
  }
  for (i = 0; i < 8; i++) {
    if (i == 0) {
      printf("\n\nVetor negativo: ");
      printf("%d", negativo[i]);
    }
    else 
      printf(", %d", negativo[i]);
  }
  return 0;
}