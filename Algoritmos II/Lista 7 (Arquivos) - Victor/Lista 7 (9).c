/*9 – Faça um programa que receba dois arquivos do usuário, e crie um terceiro arquivo com o conteúdo dos dois primeiros juntos (o conteúdo do primeiro seguido do conteúdo do segundo).*/

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

void fundir_arquivos(char *arquivo1, char *arquivo2, char *arquivo_final) { // [FUNÇÃO DE FUNDIR ARQUIVOS]
  FILE *arqv1, *arqv2, *arqv_final;
  char c;
  arqv1 = fopen(arquivo1, "r");
  arqv2 = fopen(arquivo2, "r");
  arqv_final = fopen(arquivo_final, "w");
  if (arqv1 == NULL || arqv2 == NULL || arqv_final == NULL) {
    printf("\nErro ao abrir os arquivos\n");
    exit(1);
  }
  while ((c = fgetc(arqv1)) != EOF) {
    fputc(c, arqv_final);
  }
  while ((c = fgetc(arqv2)) != EOF) {
    fputc(c, arqv_final);
  }
  fclose(arqv1);
  fclose(arqv2);
  fclose(arqv_final);
}

void print_arquivo(char *nome_arquivo) {
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
  rewind(arquivo);
  fclose(arquivo);
}

int main(void) {
  abrir_arquivo("arquivo1.txt");
  abrir_arquivo("arquivo2.txt");
  abrir_arquivo("final.txt");
  printf("Arquivo 1:\n");
  print_arquivo("arquivo1.txt");
  printf("\n\nArquivo 2:\n");
  print_arquivo("arquivo2.txt");
  fundir_arquivos("arquivo1.txt", "arquivo2.txt", "final.txt");
  printf("\n\nArquivo final:\n");
  print_arquivo("final.txt");
  return 0;
}