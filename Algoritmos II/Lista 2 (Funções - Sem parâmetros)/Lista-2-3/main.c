/* 03 – Faça uma função que leia um vetor com oito números inteiros, calcule e
 * retorne a função principal a soma de todos os valores do vetor */

#include <stdio.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

int somaVet() { // Função que lê um vetor e soma os valores
  int i, vet[8], soma = 0;
  for (i = 0; i < 8; i++) { // Laço de repetição p/ ler os valores
    printf("Digite um número: ");
    scanf("%d", &vet[i]);
    limpa_buffer();
  }
  for (i = 0; i < 8; i++) { // Laço de repetição p/ somar os valores
    soma = soma + vet[i];
  }
  return soma;
}
int main(void) {
  printf("\nA soma de todos os números do vetor é: %d", somaVet());
  return 0;
}