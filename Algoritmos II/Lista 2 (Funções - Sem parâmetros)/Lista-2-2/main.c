/* 2 – O custo ao consumidor de um carro novo é a soma do custo de fábrica com
 * a percentagem do distribuidor e dos impostos (aplicados ao custo de fábrica).
 * Supondo que a percentagem do distribuidor seja de 28% e os impostos de 45%,
 * faça uma função que leia o custo de fábrica de um carro e retorne função
 * principal o custo ao consumidor */

#include <stdio.h>
#include <stdio_ext.h>

float custCons(float custFab) { // função que calcula o custo ao consumidor
  return (custFab + custFab * 0.28 + custFab * 0.45);
}

int main(void) {
  float custFab;
  printf("Digite o custo de fábrica do carro: ");
  scanf("%f", &custFab);
  __fpurge(stdin);
  printf("O custo ao consumidor é: R$%.2f", custCons(custFab));
  return 0;
}