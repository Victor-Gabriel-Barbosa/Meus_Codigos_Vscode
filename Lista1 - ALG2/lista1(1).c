// 1 - Faça uma algoritmo que leia a idade de uma pessoa expressa em anos, meses e dias e mostre-a expressa apenas em dias. (Defina que todos os meses têm 30 dias).

// Bibliotecas:
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main() {
  int anos, meses, dias, idade;
  printf("Digite a idade da pessoa em anos: ");
  scanf("%d", &anos);
  printf("Digite a idade da pessoa em meses: ");
  scanf("%d", &meses);
  printf("Digite a idade da pessoa em dias: ");
  scanf("%d", &dias);
  idade = (anos * 360) + (meses * 30) + dias;
  printf("A idade da pessoa em dias é: %d dias", idade);
  return 0;
}