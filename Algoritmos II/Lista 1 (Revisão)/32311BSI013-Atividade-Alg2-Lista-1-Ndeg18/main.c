/* 18 – Faça um algoritmo que preencha dois vetores de dez elementos numéricos
 * cada um e mostre o vetor resultante da intercalação deles */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(0)); // inicializa o gerador de números aleatórios
  int vet1[8], vet2[8], vet3[16], i;
  for (i = 0; i < 8; i++) { // Preenche os vetores 1 e 2
    vet1[i] = (rand() % 201) - 100; // Gera números aleatórios entre -100 e 100
    vet2[i] = (rand() % 201) - 100; // Gera números aleatórios entre -100 e 100
  }
  for (i = 0; i < 8; i++) { // Preenche o vetor 3
    vet3[i] = vet1[i];
    vet3[i + 8] = vet2[i];
  }
  printf("Vetor [1]: ");
  for (i = 0; i < 8; i++) { // Imprime o vetor 1
    printf(i == 0 ? "%d" : ", %d", vet1[i]);
  }
  printf("\nVetor [2]: ");
  for (i = 0; i < 8; i++) { // Imprime o vetor 2
    printf(i == 0 ? "%d" : ", %d", vet2[i]);
  }
  printf("\nVetor resultante [3]: ");
  for (i = 0; i < 16; i++) { // Imprime o vetor 3
    printf(i == 0 ? "%d" : ", %d", vet3[i]);
  }
  return 0;
}