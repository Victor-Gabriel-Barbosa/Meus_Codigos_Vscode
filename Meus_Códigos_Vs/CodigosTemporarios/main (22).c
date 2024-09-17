// 23 - Faça um programa que carregue uma matriz 6x4 com números inteiros, calcule e mostre quantos elementos dessa matriz são maiores que 30 e, em seguida, monte uma segunda matriz com os elementos diferentes de 30. No lugar do número 30 da segunda matriz coloque o número zero.

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define x 6
#define y 4
int main(void) {
  int mat[x][y], mat_aux[x][y], i, j, cont = 0;
  srand(time(0));
  printf("\nMatriz Inicial: ");
  for (i = 0; i < x; i++) {
    printf("\n");
    for (j = 0; j < y; j++) {
      mat[i][j] = (rand() % 201) - 100;
      if (j == 0)
        printf("%d",  mat[i][j]);
      else 
        printf(", %d",  mat[i][j]);
    }
  }
  printf("\n\n");
  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
      if (mat[i][j] > 30) {
        mat_aux[i][j] = mat[i][j];
        cont++;
      }
    }
  }
  printf("\nMatriz Final: ");
  for (i = 0; i < x; i++) {
    printf("\n");
    for (j = 0; j < y; j++) {
      if (j == 0)
        printf("%d",  mat_aux[i][j]);
      else
        printf(", %d",  mat_aux[i][j]);
    }
  }
  printf("\n\n%d elementos são maiores que 30", cont);
  return 0;
}