/* 15 – Faça um algoritmo que preencha um vetor com seis elementos inteiros, calcule e mostre:
 Todos os números pares;
 A quantidade de números pares;
 Todos os números impares;
 A quantidade de números impares */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
  int vet[6], i, cont_pos = 0, cont_neg = 0;
  srand(time(0));
  for (i = 0; i < 6; i++) { // Preenche o vetor
    vet[i] = (rand() % 201) - 100; // Gera números entre -100 e 100
  }
  printf("Vetor: ");
  for (i = 0; i < 6; i++) { // Imprime o vetor
    printf(i == 0 ? "%d" : ", %d", vet[i]);
  }
  printf("\n\nNúmeros positivos:\n");
  for (i = 0; i < 6; i++) { // Imprime os números positivos
    if (vet[i] > 0) { // ...
      cont_pos++;
      printf(i == 0 ? "%d" : ", %d", vet[i]);
    }
  }
  printf("\nA quantidade de números positivos é: %d", cont_pos);
  printf("\n\nNúmeros negativos:\n");
  limpa_buffer();
  for (i = 0; i < 6; i++) { // Imprime os números negativos
    if (vet[i] < 0) { // ...
      cont_neg++;
      printf(i == 0 ? "%d" : ", %d", vet[i]);
    }
  }
  printf("\nA quantidade de números negativos é: %d", cont_neg);
  return 0;
}