/* 11 - Crie uma função que receba dois nomes e retorne quantas letras são
 * vogais. Use uma outra função que verifica se é uma vogal.*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

bool verVogais(char letra) { // Função que verifica se a letra é vogal
  char vogais[] = "aeiouAEIOU";
  if (strchr(vogais, letra) != NULL) { // Verifica se a letra estiver na string vogais
    return true;
  }
  return false;
}

int qtdeVogais(char *nome1, char *nome2) { // Função que conta as vogais
  int cont = 0, i;
  for (i = 0; i < strlen(nome1); i++) { // Percorre o primeiro nome
    if (verVogais(nome1[i])) { // Verifica se a letra é vogal
      cont++;
    }
  }
  for (i = 0; i < strlen(nome2); i++) { // Percorre o segundo nome
    if (verVogais(nome2[i])) { // Verifica se a letra é vogal
      cont++;
    }
  }
  return cont;
}

int main(void) {
  char nome1[20], nome2[20];
  int qtd;
  printf("Digite o primeiro nome: ");
  scanf("%19[^\n]", nome1);
  limpa_buffer();
  printf("Digite o segundo nome: ");
  scanf("%19[^\n]", nome2);
  limpa_buffer();
  qtd = qtdeVogais(nome1, nome2);
  printf("\n[Qtd de vogais: %d]", qtd);
  return 0;
}