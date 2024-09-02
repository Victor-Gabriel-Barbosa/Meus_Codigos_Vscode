/*24 - Faça um programa que carregue uma matriz 15x5 com números inteiros,
 * calcule e mostre quais os elementos da matriz que se repetem e quantas vezes
 * cada um está repetido */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int x = 15, y = 5, matriz[x][y], cont[100], i, j;
  srand(time(0));
  for (i = 0; i < 100; i++) { // Inicializa o vetor cont
    cont[i] = 0;
  }
  for (i = 0; i < x; i++) { // Preenche a matriz
    for (j = 0; j < y; j++) { // ...
      matriz[i][j] = rand() % 100; // Gera números aleatórios de 0 a 99
    }
  }
  printf ("Matriz gerada: ");
  for (i = 0; i < x; i++) { // Imprime a matriz
    printf ("\n");
    for (j = 0; j < y; j++) { // ...
      printf ("%d ", matriz[i][j]);
    }
  }
  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
      cont[matriz[i][j]]++;
    }
  }
  printf("\n");
  for (i = 0; i < 100; i++) { // Imprime a qtde de repetições
    if (cont[i] > 1) { // Se houver pelo menos 1 repetição
      printf("\nO número %d se repete %d vezes", i, cont[i]);
    }
  }
  return 0;
}
