// O custo ao consumidor de um carro novo � a soma do custo de f�brica com a percentagem do distribuidor e dos impostos (aplicados ao custo de f�brica). Supondo que a percentagem do distribuidor seja de 28% e os impostos de 45%, escrever um algoritmo para ler o custo de f�brica de um carro e escrever o custo ao consumidor.
#include <stdio.h>

int main( ) {
  int custo = 0;
  float impostos = 0.28, distribuidor = 0.45, custo_final = 0;
  printf("Digite o custo de fabrica do carro:\n");
  scanf("%d", &custo);
  custo_final = custo + (custo * impostos) + (custo * distribuidor);
  printf("O custo final do carro: R$%.2f", custo_final);
  return 0;
}
