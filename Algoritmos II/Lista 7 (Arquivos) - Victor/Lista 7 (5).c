/*5 - Faça um programa que receba do usuário um arquivo texto e um caracter. Mostre na tela quantas vezes aquele caractere ocorre dentro do arquivo. */

#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>

void abrir_arquivo(char *nome_arquivo) { // [FUNÇÃO DE ABRIR ARQUIVO]
  FILE *arquivo = fopen(nome_arquivo, "a");
  if (!arquivo) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  fclose(arquivo);
}

int contar_caracter(char *nome_arquivo, char caract) { // [FUNÇÃO DE CONTAR CARACTERES EM ARQUIVO]
  FILE *arquivo;
  char c;
  int cont = 0;
  arquivo = fopen(nome_arquivo, "r");
  if (arquivo == NULL) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  while ((c = fgetc(arquivo)) != EOF) {
    if (c == caract) {
      cont++;
    }
  }
  fclose(arquivo);
  return cont;
}

int main(void) {
  char letra;
  abrir_arquivo("contar.txt");
  printf("\nDigite o caractere que será buscado: ");
  scanf("%c", &letra);
  __fpurge(stdin);
  int temp = contar_caracter("contar.txt", letra);
  printf("\nO caractere [%c] aparece %d vezes no arquivo", letra, temp);
  return 0;
}