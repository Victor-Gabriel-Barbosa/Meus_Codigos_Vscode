/* 12 - Sabendo que a função strcat concatena duas strings, faça uma função que
 * imite-a */

#include <stdio.h>
#include <string.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void concatena(char *str1, char *str2) { // Função que concatena duas strings
  int i, len = strlen(str1);
  for (i = 0; str2[i] != '\0'; i++) { // Percorre a segunda string
    str1[len + i] = str2[i];
  }
  str1[len + strlen(str2)] = '\0'; // Adiciona o caractere nulo no final
}

int main(void) {
  char pal1[100] = " ", pal2[100] = " ";
  printf("Digite a primeira palavra: ");
  scanf("%99[^\n]", pal1);
  limpa_buffer();
  printf("Digite a segunda string: ");
  scanf("%99[^\n]", pal2);
  limpa_buffer();
  concatena(pal1, pal2);
  printf("A string concatenada é: %s", pal1);
  return 0;
}