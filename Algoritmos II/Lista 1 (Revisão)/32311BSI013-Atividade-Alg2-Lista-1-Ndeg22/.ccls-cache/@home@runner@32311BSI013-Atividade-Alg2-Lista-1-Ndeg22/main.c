/* 22 - Faça um programa que carregue uma matriz 10x20 com números inteiros e
 * some cada uma das linhas, armazenando o resultado das somas em um vetor. A
 * seguir, multiplique cada elemento da matriz pela soma da linha e mostre a
 * matriz resultante */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int x = 10, y = 20, matriz[x][y], soma[x], i, j;
  srand(time(0));
  for (i = 0; i < x; i++) {   // Preenche a matriz com números aleatórios
    for (j = 0; j < y; j++) { // ...
      matriz[i][j] = (rand() % 201) - 100; // Gera números entre -100 e 100
    }
  }
  printf("Matriz:");
  for (i = 0; i < x; i++) { // Imprime a matriz
    printf("\n|");
    for (j = 0; j < y; j++) { // ...
      printf("%4d|", matriz[i][j]);
    }
  }
  for (i = 0; i < x; i++) { // Soma as linhas da matriz
    soma[i] = 0;
    for (j = 0; j < y; j++) { // ...
      soma[i] += matriz[i][j];
    }
  }
  printf("\n");
  for (i = 0; i < x; i++) {
    printf("\nSoma [Linha %d]: %d", i, soma[i]);
  }
  return 0;
}