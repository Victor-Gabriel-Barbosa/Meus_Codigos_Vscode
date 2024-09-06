/*2 - Faça um programa que receba do usuário um arquivo texto e mostre na tela quantas linhas esse arquivo possui. */

#include <stdio.h>
#include <stdlib.h>

void abrir_arquivo(char *nome_arquivo) { // [FUNÇÃO DE ABRIR ARQUIVO]
  FILE *arquivo = fopen(nome_arquivo, "a");
  if (!arquivo) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  fclose(arquivo);
}

int strlen_arquivo(char *nome_arquivo) { // [FUNÇÃO DE CONTAR LINHAS DE ARQUIVO]
  FILE *arquivo;
  int cont = 1;
  char c;
  arquivo = fopen(nome_arquivo, "r");
  if (!arquivo) {
    printf("\nErro ao abrir o arquivo!\n");
    exit(1);
  }
  while ((c = fgetc(arquivo)) != EOF) {
    if (c == '\n') {
      cont++;
    }
  }
  fclose(arquivo);
  return cont;
}

int main(void) {
  abrir_arquivo("arquivo.txt");
  int cont = strlen_arquivo("arquivo.txt");
  printf("\nO arquivo possui %d linhas", cont);
  printf("Tudo Certo");
  return 0;
}