/* 05 – Faça uma função que receba um número inteiro maior que 1, verifique se o
 * número fornecido é primo ou não e retorne o resultado ao programa principal.
 * Um número é primo quando é divisível apenas por 1 e por ele mesmo */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

bool VerPrimo(unsigned long long int n) { // Função que verifica se o número é primo
  for (unsigned long long int i = 2; i < n; i++) { // Laço que verifica se o número é primo
    if (n % i == 0) { // Se o número for divisível por i, então ele não é primo
      return false;
    }
  }
  return true;
}

int main(void) {
  unsigned long long int num;
  do { // Garante que o nº é maior que 1
    printf("\033[0m\nAperte [\033[38;5;39mENTER\033[0m] para continuar...");
    limpa_buffer();
    system("clear");
    printf("Digite um Nº maior que 1: ");
    scanf("%llu", &num);
    limpa_buffer();
    if (num <= 1) { // Exibe mensagem de erro caso o número seja menor ou igual a 1
      printf("\n[Número inválido!]\n");
    }
  } while (num <= 1);
  if (VerPrimo(num)) { // Se o nº for primo
    printf("\n[O número %llu é primo!]", num);
  } else { // Se o nº não for primo
    printf("\n[O número %llu não é primo!]", num);
  }
  return 0;
}