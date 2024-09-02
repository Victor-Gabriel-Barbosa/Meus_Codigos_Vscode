/* 06 – Faça um programa que envie para uma função uma string e receba dela a
 * quantidade de palavras que aparecem */

#include <stdio.h>
#include <stdlib.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

int qtdePal(char *frase) { // Função que conta a quantidade de palavras
  int cont = 0;
  for (int i = 0; frase[i] != '\0'; i++) { // Percorre a string
    if (frase[i] != ' ' && (frase[i + 1] == ' ' || frase[i + 1] == '\0')) {
      cont++;
    }
  }
  return cont;
}

int main(void) {
  char frase[100] = " ";
  printf("Digite uma frase: ");
  scanf("%99[^\n]", frase);
  limpa_buffer();
  printf("\n[A frase '%s' tem %d palavras]", frase, qtdePal(frase));
  return 0;
}