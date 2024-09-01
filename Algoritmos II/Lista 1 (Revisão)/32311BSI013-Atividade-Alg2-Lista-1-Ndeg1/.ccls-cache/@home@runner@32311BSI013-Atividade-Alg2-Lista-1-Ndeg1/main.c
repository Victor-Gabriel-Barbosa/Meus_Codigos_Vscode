// 1 - Faça uma algoritmo que leia a idade de uma pessoa expressa em anos, meses e dias e mostre-a expressa apenas em dias. (Defina que todos os meses têm 30 dias).

// Bibliotecas:
#include <stdio.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
  int anos, meses, dias, idade;
  printf("Digite a idade da pessoa em anos: ");
  scanf("%d", &anos);
  limpa_buffer();
  printf("Digite a idade da pessoa em meses: ");
  scanf("%d", &meses);
  limpa_buffer();
  printf("Digite a idade da pessoa em dias: ");
  scanf("%d", &dias);
  limpa_buffer();
  idade = (anos * 360) + (meses * 30) + dias;
  printf("A idade da pessoa em dias é: %d dias", idade);
  return 0;
}