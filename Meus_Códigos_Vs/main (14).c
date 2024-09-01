/* 
15 – Faça um algoritmo que preencha um vetor com seis elementos inteiros, calcule e mostre:
 Todos os números pares;
 A quantidade de números pares;
 Todos os números impares;
 A quantidade de números impares;
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main(void) {
  int vet[6], i, cont_pos = 0, cont_neg = 0;;
  srand(time(0));
  for (i = 0; i < 6; i++) {
    vet[i] = (rand() % 201) - 100;
  }
  printf("\nNúmeros positivos:\n");
  for (i = 0; i < 6; i++) {
    if (vet[i] > 0) {
      cont_pos++;
      if (i == 0)
        printf("%d", vet[i]);
      else 
        printf(", %d", vet[i]);
    }
  }
  printf("\nA quantidade de números positivos é: %d", cont_pos);
  printf("\n\nNúmeros negativos:\n");
  __fpurge(stdin);
  for (i = 0; i < 6; i++) {
    if (vet[i] < 0) {
      cont_neg++;
      if (i == 0)
        printf("%d", vet[i]);
      else
        printf(", %d", vet[i]);
    }
  }
  printf("\nA quantidade de números negativos é: %d", cont_neg);
  
  return 0;
}