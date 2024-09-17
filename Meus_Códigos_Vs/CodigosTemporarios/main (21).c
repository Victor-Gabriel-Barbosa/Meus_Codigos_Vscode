// 22 - Faça um programa que carregue uma matriz 10x20 com números inteiros e some cada uma das linhas, armazenando o resultado das somas em um vetor. A seguir, multiplique cada elemento da matriz pela soma da linha e mostre a matriz resultante.

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define x 10
#define y 20
int main(void) {
  int matriz[x][y], soma[x], i, j;
  srand(time(0));
  for (i = 0; i < x; i++) {
    printf("\n");
    for (j = 0; j < y; j++) {
      matriz[i][j] = (rand() % 201) - 100;
      if (j == 0)
        printf("%d", matriz[i][j]);
      else 
        printf(", %d", matriz[i][j]);
    }
  }
  for (i = 0; i < x; i++) {
    soma[i] = 0;
    for (j = 0; j < y; j++) {
      soma[i] += matriz[i][j];
    }
  }
  printf("\n");
  for (i = 0; i < x; i++)
    printf("\nSoma [Linha %d]: %d", i, soma[i]);

  return 0;
}