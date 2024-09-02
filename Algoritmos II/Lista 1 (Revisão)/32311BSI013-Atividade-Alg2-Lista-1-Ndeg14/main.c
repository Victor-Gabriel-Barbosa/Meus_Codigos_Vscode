/* 14 – Faça um algoritmo que preencha um vetor com dez números inteiros,
 * calcule e mostre a quantidade de números negativos e a soma dos números
 * positivos */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int vet[10], i, soma_pos = 0, qtd_neg = 0;
  srand(time(0));
  for (i = 0; i < 10; i++) { // Preenche o vetor
    vet[i] = (rand() % 201) - 100;
  }
  printf("Vetor: ");
  for (i = 0; i < 10; i++) { // Imprime o vetor
    printf(i == 0 ? "%d" : ", %d", vet[i]);
  }
  for (i = 0; i < 10; i++) { // Soma os positivos e conta os negativos
    if (vet[i] > 0) // Soma os positivos
      soma_pos += vet[i];
    else if (vet[i] < 0) // Conta os negativos
      qtd_neg++;
  }
  printf("\n\nSoma dos números positivos: %d", soma_pos);
  printf("\nQuantidade de números negativos: %d", qtd_neg);
  return 0;
}