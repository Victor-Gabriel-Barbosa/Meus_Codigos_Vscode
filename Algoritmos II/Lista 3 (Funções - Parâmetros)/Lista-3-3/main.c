/* 03 - Uma agência bancária possui dois tipos de investimentos, conforme o
 * quadro a seguir. Faça uma função que receba o tipo de investimento e seu
 * valor e que calcule e retorne o valor corrigido, de acordo com o tipo de
 * investimento */

#include <stdio.h>
#include <stdlib.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

float investCorrig(int tip, float val) { // Função p/ calcular o valor corrigido de acordo com o tipo de investimento
  return (tip == 1) ? val * 1.1 : val * 1.2;
}

int main(void) {
  int tipo;
  float valor, result;
  do { // Validação da entrada do tipo de investimento
    printf("\033[0m\nAperte [\033[38;5;39mENTER\033[0m] para continuar...");
    limpa_buffer();
    system("clear");
    printf("[TIPOS DE INVESTIMENTO]\n");
    printf("[1]> Poupança (3%%)\n");
    printf("[2]> Fundos de renda fixa (4%%)\n");
    printf("Digite o tipo de investimento: ");
    scanf("%d", &tipo);
    limpa_buffer();
    if (tipo != 1 && tipo != 2) { // Tipo inválido
      printf("\n[Tipo de investimento inválido!]\n");
    }
  } while (tipo != 1 && tipo != 2);
  printf("\nDigite o valor do investimento: R$");
  scanf("%f", &valor);
  limpa_buffer();
  result = investCorrig(tipo, valor);
  printf("\n[Valor corrigido: R$%.2f]", result);
  return 0;
}