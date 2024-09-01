// 1 - Fa�a uma algoritmo que leia a idade de uma pessoa expressa em anos, meses e dias e mostre-a expressa apenas em dias. (Defina que todos os meses t?m 30 dias).

// Bibliotecas:
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>

int calc_idade_dias(int anos, int meses, int dias) {
  return (anos * 360) + (meses * 30) + dias;;
}

int main() {
  setlocale(LC_ALL, "Portuguese");
  int anos, meses, dias, idade;
  printf("Digite a idade da pessoa em anos: ");
  scanf("%d", &anos);
  printf("Digite a idade da pessoa em meses: ");
  scanf("%d", &meses);
  printf("Digite a idade da pessoa em dias: ");
  scanf("%d", &dias);
  idade = calc_idade_dias(anos, meses, dias);
  printf("A idade da pessoa em dias �: %d dias", idade);
  return 0;
}