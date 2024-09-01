// 21 - Faça um algoritmo para apagar valores de um vetor de no máximo cem valores numéricos. O usuário digita um valor e o algoritmo deve apagar e reorganizar o vetor. 


#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main(void) {
  int vet[10], i, j, n, loop, tam_vet = 10;
  srand(time(0));
  for (i = 0; i < tam_vet; i++) {
    vet[i] = (rand() % 201) - 100;
    if (i == 0)
      printf("\nVetor Inicial: %d", vet[i]);
    else 
      printf(", %d", vet[i]);
  }
  do {
    loop = 1;
    printf("\n\nDigite um número para excluir: ");
    scanf("%d", &n);
    for (i = 0; i < tam_vet; i++) {
      if (vet[i] == n) {
        loop = 0;
      }
    }
    if (loop)
      printf("\nNúmero não encontrado no vetor! Digite um número que esteja no vetor...");
  } while (loop);
  for (i = 0; i < tam_vet; i++) {
    if (vet[i] == n) {
      tam_vet--;
      for (j = i; j < tam_vet; j++) {
        vet[j] = vet[j + 1];
      }
    }
  }
  for (i = 0; i < tam_vet; i++) {
    if (i == 0)
      printf("\nVetor Final: %d", vet[i]);
    else
      printf(", %d", vet[i]);
  }
  return 0;
}