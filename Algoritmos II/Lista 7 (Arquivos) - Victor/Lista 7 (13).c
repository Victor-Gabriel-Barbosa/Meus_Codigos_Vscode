/*13 - Faça um programa que permita que o usuário entre com diversos nomes e telefones para um cadastro, e crie um arquivo com essas informações, uma por linha. O usuário finaliza a entrada com ‘0’ para o telefone.*/

#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>

void abrir_arquivo(char *nome_arquivo) { // [FUNÇÃO DE ABRIR ARQUIVO]
  FILE *arquivo = fopen(nome_arquivo, "a");
  if (!arquivo) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  fclose(arquivo);
}

void escrever_arquivo(char *nome_arquivo) { // [FUNÇÃO DE ESCREVER NO ARQUIVO]
  char conteudo[100];
  FILE *arquivo = fopen(nome_arquivo, "w");
  if (arquivo == NULL) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  printf("\nDigite o conteúdo do arquivo (digite '0' para encerrar):\n");
  do {
    fprintf(arquivo, "%s", fgets(conteudo, 100, stdin));
    __fpurge(stdin);
  } while (strcmp(conteudo, "0\n") != 0);
  fclose(arquivo);
}

void mostrar_arquivo(char *nome_arquivo) { // [FUNÇÃO DE MOSTRAR ARQUIVO]
  FILE *arquivo;
  char c;
  arquivo = fopen(nome_arquivo, "r");
  if (arquivo == NULL) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  while (fscanf(arquivo, "%c", &c) != EOF) {
    printf("%c", c);
  }
  fclose(arquivo);
}

int main(void) {
  abrir_arquivo("cadastro.txt");
  escrever_arquivo("cadastro.txt");
  printf("\n\nConteúdo do arquivo:\n");
  mostrar_arquivo("cadastro.txt");
  return 0;
}