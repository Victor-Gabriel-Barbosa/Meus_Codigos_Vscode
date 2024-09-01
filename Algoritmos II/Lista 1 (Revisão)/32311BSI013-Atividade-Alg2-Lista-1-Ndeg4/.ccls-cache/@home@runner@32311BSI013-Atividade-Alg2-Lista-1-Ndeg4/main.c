/* Um motorista deseja colocar no seu tanque X reais de gasolina. Escreva um algoritmo para ler o preço do litro da gasolina e o valor do pagamento, e exibir quantos litros ele conseguiu colocar no tanque */

#include <stdio.h>

int main(void) {
  int gasolina = 0, pagamento = 0, litros = 0;
  printf("Digite o preço da gasolina: ");
  scanf("%d", &gasolina);
  printf("Digite o valor do pagamento: ");
  scanf("%d", &pagamento);
  litros = pagamento / gasolina;
  printf("O motorista conseguiu colocar %d litros no tanque", litros);
  return 0;
}