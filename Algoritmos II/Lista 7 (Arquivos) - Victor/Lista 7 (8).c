/*8 - Faça um programa que leia o conteúdo de um arquivo e crie um arquivo com o mesmo conteúdo, mas com todas as letras minúsculas convertidas para maiúsculas. Os nomes dos arquivos serão fornecidos, via teclado, pelo usuário. A função que converte maiúscula para minúscula é e o toupper(). Ela é aplicada em cada caracter da string.*/

#include <stdio.h>
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

void arquivo_maiusculo(char *arquivo_entrada, char *arquivo_saida) { // [FUNÇÃO DE CONVERTER CONTEÚDO DE ARQUIVO EM MAIÚSCULO]
  FILE *arqv_entrada = fopen(arquivo_entrada, "r");
  FILE *arqv_saida = fopen(arquivo_saida, "w");
  if (arqv_entrada == NULL || arqv_saida == NULL) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  char c;
  while ((c = fgetc(arqv_entrada)) != EOF) {
    fputc(toupper(c), arqv_saida);
  }
  fclose(arqv_entrada);
  fclose(arqv_saida);
}

void print_arquivo(char *nome_arquivo) { // [FUNÇÃO DE IMPRIMIR ARQUIVO]
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
  abrir_arquivo("inicial.txt");
  abrir_arquivo("final.txt");
  printf("Arquivo de entrada:\n");
  print_arquivo("inicial.txt");
  arquivo_maiusculo("inicial.txt", "final.txt");
  printf("\n\nArquivo de saída:\n");
  print_arquivo("final.txt");
  return 0;
}