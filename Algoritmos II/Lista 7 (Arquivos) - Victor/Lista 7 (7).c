/*7 - Faça um programa que receba do usuário um arquivo texto. Crie outro arquivo texto contendo o texto do arquivo de entrada, mas com as vogais substituídas por ‘*’.*/

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

void substituir_vogais(char *arq_entrada, char *arq_saida) {
  FILE *entrada, *saida;
  char c;
  char vogais_aux[] = "aeiou";
  entrada = fopen(arq_entrada, "r");
  saida = fopen(arq_saida, "w");
  if (entrada == NULL || saida == NULL) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  while (fscanf(entrada, "%c", &c) != EOF) {
    if (strchr(vogais_aux, tolower(c)) != NULL) {
      fprintf(saida, "*");
    }
      else {
        fprintf(saida, "%c", c);
      }  
  }
  rewind(entrada);
  rewind(saida);
  fclose(entrada);
  fclose(saida);
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
  fclose(arquivo);
}

int main(void) {
  abrir_arquivo("entrada.txt");
  abrir_arquivo("saida.txt");
  printf("Arquivo de entrada: \n");
  print_arquivo("entrada.txt");
  substituir_vogais("entrada.txt", "saida.txt");
  printf("\n\nArquivo de saída: \n");
  print_arquivo("saida.txt");
  return 0;
}