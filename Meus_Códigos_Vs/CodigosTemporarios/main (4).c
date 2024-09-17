// 5 - A granja Frangotech possui um controle automatizado de cada frango da sua produção. No pé direito do frango há um anel com um chip de identificação; no pé esquerdo são dois anéis para indicar o tipo de alimento que ele deve consumir. Sabendo que o anel com chip custa R$ 4,00 e o anel de alimento custa R$ 3,50, faça um algoritmo para calcular o gasto total da granja para marcar todos os seus frangos.
#include <stdio.h>

int main(void) {
  int anel_chip = 4, qtd_frangos = 0;
  float anel_alimento = 3.5;
  printf("Digite a quantidade total de frangos da granja:\n");
  scanf("%d", &qtd_frangos);
  float gasto_total = (anel_chip * qtd_frangos) + (anel_alimento);
  printf("O gasto total da granja para marcar todos os seus frangos é de: R$ %.2f", gasto_total);
  return 0;
}