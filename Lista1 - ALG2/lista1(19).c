/* 19 – Faça um algoritmo que preencha um vetor com dez elementos numérios e a
 * partir desse vetor faça um segundo vetor que receba os valores do primeiro
 * vetor de forma invertida */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int vet[10], vet_inv[10], i;
  srand(time(0));
  for (i = 0; i < 10; i++) { // Preenche o vetor inicial
    vet[i] = (rand() % 201) - 100; // Gera números entre -100 e 100
  }
  printf("Vetor Inicial: ");
  for (i = 0; i < 10; i++) { // Imprime o vetor inicial
    printf(i == 0 ? "%d" : ", %d", vet[i]);
  }
  for (i = 0; i < 10; i++) { // Inverte o vetor inicial
    vet_inv[i] = vet[9 - i];
  }
  printf("\nVetor Invertido: ");
  for (i = 0; i < 10; i++) { // Imprime o vetor invertido
    printf(i == 0 ? "%d" : ", %d", vet_inv[i]);
  }
  return 0;
}