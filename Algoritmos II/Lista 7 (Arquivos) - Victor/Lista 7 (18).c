/*18 – Faça um programa que leia um arquivo contendo o nome e o preço de diversos produtos (separados por linha), e calcule o total da compra. */

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

float ler_arquivo(char *nome_arquivo) { // [FUNÇÃO DE LER ARQUIVO]
  FILE *arquivo = fopen(nome_arquivo, "r");
  if (arquivo == NULL) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  char lixo[100];
  float preco = 0, total = 0;
  while (fscanf(arquivo, "%s", lixo) != EOF) {
    fscanf(arquivo, "%f", &preco);
    total += preco;
  }
  fclose(arquivo);
  return total;
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
  abrir_arquivo("precos.txt");
  printf("Arquivo:\n");
  mostrar_arquivo("precos.txt");
  float total = ler_arquivo("precos.txt");
  printf("\n\nTotal: $%.2f\n", total);
  return 0;
}