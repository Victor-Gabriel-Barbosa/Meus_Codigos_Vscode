/* 16 – Faça um algoritmo que preencha dois vetores de dez posições cada um,
 * determine e mostre o terceiro contendo a soma das posições dos dois vetores
 * anteriores */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int vet1[10], vet2[10], vet3[10], i;
  for (i = 0; i < 10; i++) { // Preenche os vetores
    vet1[i] = (rand() % 201) - 100; // Gera números aleatórios entre -100 e 100
    vet2[i] = (rand() % 201) - 100; // Gera números aleatórios entre -100 e 100
  }
  printf("Vetor [1]: ");
  for (i = 0; i < 10; i++) { // Imprime o vetor 1
    printf(i == 0 ? "%d" : ", %d", vet1[i]);
  }
  printf("\nVetor [2]: ");
  for (i = 0; i < 10; i++) { // Imprime o vetor 2
    printf(i == 0 ? "%d" : ", %d", vet2[i]);
  }
  for (i = 0; i < 10; i++) { // Soma os elementos dos vetores 1 e 2 e armazena no vetor 3
    vet3[i] = vet1[i] + vet2[i];
  }
  printf("\nVetor [3]: ");
  for (i = 0; i < 10; i++) { // Imprime o vetor 3
    printf(i == 0 ? "%d" : ", %d", vet3[i]);
  }
  return 0;
}