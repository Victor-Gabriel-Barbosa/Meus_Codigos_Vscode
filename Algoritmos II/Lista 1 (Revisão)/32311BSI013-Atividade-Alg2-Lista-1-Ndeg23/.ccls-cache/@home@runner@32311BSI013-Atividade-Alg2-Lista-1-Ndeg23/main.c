/* 23 - Faça um programa que carregue uma matriz 6x4 com números inteiros,
 * calcule e mostre quantos elementos dessa matriz são maiores que 30 e, em
 * seguida, monte uma segunda matriz com os elementos diferentes de 30. No lugar
 * do número 30 da segunda matriz coloque o número zero */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int x = 6, y = 4, mat[x][y], mat_aux[x][y], i, j, cont = 0;
  srand(time(0));
  for (i = 0; i < x; i++) { // Preenche a matriz
    for (j = 0; j < y; j++) { // ...
      mat[i][j] = (rand() % 201) - 100; // Gera números aleatórios entre -100 e 100
    }
  }
  printf("\nMatriz Inicial: ");
  for (i = 0; i < x; i++) { // Imprime a matriz inicial
    printf("\n");
    for (j = 0; j < y; j++) { // ...
      printf("%d ", mat[i][j]);
    }
  }
  for (i = 0; i < x; i++) { // Preenche a matriz auxiliar
    for (j = 0; j < y; j++) { // ...
      if (mat[i][j] > 30) {   // Verifica se o elemento é maior que 30
        mat_aux[i][j] = mat[i][j];
        cont++;
      } else if (mat[i][j] == 30) { // Verifica se o elemento é igual a 30
        mat_aux[i][j] = 0;
      }
    }
  }
  printf("\n\nMatriz Final: ");
  for (i = 0; i < x; i++) { // Imprime a matriz auxiliar
    printf("\n");
    for (j = 0; j < y; j++) { // ...
      printf("%d ", mat_aux[i][j]);
    }
  }
  printf("\n\n%d elementos são maiores que 30", cont);
  return 0;
}