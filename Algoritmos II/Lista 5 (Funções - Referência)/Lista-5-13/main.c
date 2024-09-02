/* 13 - Sabendo que a função strlen conta a quantidade de caracteres que a string
 * possui, faça uma função que imite-a */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

int qtdeCaracter(char *str) { // Função que conta a quantidade de caracteres de uma string
  int contador = 0;
  while (*str != '\0') { // Percorre a string até encontrar o caractere nulo
    contador++;
    str++;
  }
  return contador;
}

int main(void) {
  char pal[100] = "";
  printf("Digite uma palavra: ");
  scanf("%99[^\n]", pal);
  limpa_buffer();
  int qtd = qtdeCaracter(pal);
  printf("A palavra '%s' possui %d caracteres", pal, qtd);
  return 0;
}