/* 04 – Faça uma função que leia uma matriz com 3 colunas por 2 linhas,
 * preencha-a com números inteiros, calcule e retorne a função principal a soma
 * de todos os valores pares da matriz */

#include <stdio.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

int somaVet() { // Função que lê uma matriz 2x3 e soma os valores pares
  int vet[2][3], soma = 0;
  for (int i = 0; i < 2; i++) {   // Lê a matriz
    for (int j = 0; j < 3; j++) { // ...
      printf("Digite o valor da posição [%d][%d]: ", i, j);
      scanf("%d", &vet[i][j]);
      limpa_buffer();
    }
  }
  for (int i = 0; i < 2; i++) {   // Soma os valores pares
    for (int j = 0; j < 3; j++) { // ...
      if (vet[i][j] % 2 == 0) {   // Verifica se o elemento é par
        soma += vet[i][j];
      }
    }
  }
  return soma;
}

int main(void) {
  printf("\n[A soma dos valores pares da matriz é: %d]", somaVet());
  return 0;
}