/* 02 – Faça uma função que receba dois números e retorne o maior */

#include <stdio.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

int maior(int a, int b) { // Função que retorna o maior entre dois números
  return (a > b) ? a : b;
}

int main(void) {
  int num1, num2, maiorNum;
  printf("Digite o [1º] nº: ");
  scanf("%d", &num1);
  limpa_buffer();
  printf("Digite o [2º] nº: ");
  scanf("%d", &num2);
  limpa_buffer();
  maiorNum = maior(num1, num2);
  printf("\n[O maior nº é: %d]", maiorNum);
  return 0;
}