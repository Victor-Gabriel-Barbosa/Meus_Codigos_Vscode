/* 8 - Desenvolva um programa que leia a dimensão MxN de uma matriz e os valores
 * min e max. Em seguida, o programa principal utiliza uma função para gerar a
 * matriz MxN com valores aleatórios dentro de um intervalo [min, max]. Uma
 * outra função deve receber a matriz gerada e retornar o maior elemento da
 * matriz, o menor elemento da matriz e o valor médio das entradas da matriz */

#include <stdio.h>
#include <stdlib.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void limpa_tela() {
  printf("\033[0m\nAperte [\033[38;5;39mENTER\033[0m] para continuar...");
  limpa_buffer();
  #ifdef _WIN32 // Verifica se o sistema é Windows
    system("cls");
  #else // Caso contrário, assume que é um sistema Unix
    system("clear");
  #endif 
}

float manipular_matriz(int x, int y, int mat[][y], int *maior, int *menor) { // [FUNÇÃO DE MANIPULAÇÃO DA MATRIZ]
  float media = 0;
  int i, j;
  *maior = mat[0][0];
  *menor = mat[0][0];
  for (i = 0; i < x; i++) { // [LAÇO PARA PERCORRER A MATRIZ]
    for (j = 0; j < y; j++) { // [...]
      if (mat[i][j] > *maior) { // [VERIFICAÇÃO DO MAIOR VALOR]
        *maior = mat[i][j];
      }
      if (mat[i][j] < *menor) { // [VERIFICAÇÃO DO MENOR VALOR]
        *menor = mat[i][j];
      }
      media += mat[i][j];
    }
  }
  return (media /= (x * y));
}

void gerar_matriz(int x, int y, int mat[x][y]) { // [FUNÇÃO QUE GERA A MATRIZ]
  int i, j, min, max;
  do { // [LAÇO PARA VALIDAR O VALOR MIN E MAX]
    limpa_tela();
    printf("\n===========[ VALORES MIN/MAX ]===========\n");
    printf("\nDigite o valor minimo da matriz: ");
    scanf("%d", &min);
    limpa_buffer();
    printf("Digite o valor maximo da matriz: ");
    scanf("%d", &max);
    limpa_buffer();
    printf("\n========================================\n");
    if (min > max) { // [VERIFICAÇÃO DA ORDEM DOS VALORES]
      printf("\n[Valores Inválidos! Tente novamente...]\n");
    }
  } while (min > max);
  for (i = 0; i < x; i++) { // [LAÇO PARA PERCORRER A MATRIZ]
    for (j = 0; j < y; j++) { // [...]
      mat[i][j] = min + rand() % (max - min + 1); // [GERAÇÃO DOS VALORES ALEATÓRIOS NO INTERVALO MIN-MAX]
    }
  }
}

int main(void) {
  int i, j, m, n, mai, men;
  float med;
  do { // [LAÇO PARA VALIDAR A DIMENSÃO DA MATRIZ]
    limpa_tela();
    printf("\n============[ CRIAR MATRIZ ]============\n");
    printf("\nDigite a qtd de linhas da matriz: ");
    scanf("%d", &m);
    limpa_buffer();
    printf("Digite a qtd de colunas da matriz: ");
    scanf("%d", &n);
    limpa_buffer();
    printf("\n========================================\n");
    if (m <= 0 || n <= 0) { // [VERIFICAÇÃO DA DIMENSÃO DA MATRIZ]
      printf("\n[Valores Inválidos! Tente novamente...]\n");
    }
  } while (m < 1 || n < 1);
  int matriz[m][n];
  gerar_matriz(m, n, matriz);
  med = manipular_matriz(m, n, matriz, &mai, &men);
  printf("\n============[ MATRIZ ]============\n\n");
  for (i = 0; i < m; i++) { // [LAÇO PARA PERCORRER A MATRIZ]
    for (j = 0; j < n; j++) { // [...]
      printf("\033[0;32m%4d\033[0m", matriz[i][j]);
    }
    printf("\n");
  }
  printf("\n============[ RESULTADOS ]============\n");
  printf("\nMaior valor da matriz: \033[0;32m%d\033[0m", mai);
  printf("\nMenor valor da matriz: \033[0;32m%d\033[0m", men);
  printf("\nValor médio da matriz: \033[0;32m%.2f\033[0m", med);
  printf("\n\n======================================\n");
  return 0;
}