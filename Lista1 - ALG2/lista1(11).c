/* 11 – Criar um algoritmo que receba o valor e o código de várias mercadorias vendidas em um determinado dia. Os códigos obedecem à lista a seguir:
´L´ - Limpeza
´A´- Alimentação
´H´- Higiene
Calcule e imprima:
 O total vendido naquele dia, com todos os códigos juntos;
 O total vendido naquele dia em cada um dos códigos.
Para encerrar a entrada de dados, digite o valor da mercadoria zero */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main(void) {
  int tam = 100, total_venda = 0, total_limpeza = 0, total_alimentacao = 0, total_higiene = 0, i, j, valor[tam], cont = 0, sair = 1;
  char categoria[tam][tam];
  for (i = 0; i < tam; i++) 
    valor[i] = 0;
  while (sair != 0) { // Loop para receber os valores
    printf("\nDigite o valor da mercadoria:\n");
    scanf("%d", &valor[cont]);
    sair = valor[cont];
    do { // Loop para receber a categoria
      __fpurge(stdin);
      printf("\nDigite a categoria da mercadoria:");
      printf("\n[L - Limpeza]\n[A - Alimentação]\n[H - Higiene]\n:");
      fgets(categoria[cont], tam, stdin);
      __fpurge(stdin);
      categoria[cont][strlen(categoria[cont]) - 1] = '\0';
    } while (strcasecmp(categoria[cont], "L") != 0 && strcasecmp(categoria[cont], "A") != 0 && strcasecmp(categoria[cont], "H") != 0);
    total_venda += valor[i];
    if (strcasecmp(categoria[cont], "L") == 0)
      total_limpeza += valor[i];
    else if (strcasecmp(categoria[cont], "A") == 0)
      total_alimentacao += valor[i];
    else if (strcasecmp(categoria[cont], "H") == 0)
      total_higiene += valor[i];
    cont++;
  }
  printf("\nTotal vendido: %d\n", total_venda);
  for (i = 0; i < cont; i++) {
    if (strcasecmp(categoria[i], "L") == 0)
      printf("\nTotal vendido na categoria Limpeza: %d", total_limpeza);
    else if (strcasecmp(categoria[i], "A") == 0)
      printf("\nTotal vendido na categoria Alimentação: %d", total_alimentacao);
    else if (strcasecmp(categoria[i], "H") == 0)
      printf("\nTotal vendido na categoria Higiene: %d", total_higiene);
  }
  return 0;
}