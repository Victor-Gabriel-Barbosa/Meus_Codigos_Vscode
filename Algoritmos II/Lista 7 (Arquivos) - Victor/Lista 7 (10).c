/*10 - Faça um programa que receba o nome de um arquivo de entrada e outro de saída. O arquivo de entrada contém em cada linha o nome de uma cidade (ocupando 40 caracteres) e o seu número de habitantes. O programa deverá ler o arquivo de entrada e gerar um arquivo de saída onde aparece o nome da cidade mais populosa seguida pelo seu número de habitantes. */

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

void ler_arquivo(char *nome_arqv) { // [FUNÇÃO DE LER ARQUIVO E ENCONTRAR A CIDADE MAIS POPULOSA]
  FILE *arqv_cidade, *arqv_maior;
  char cidade[40], maior_cidade[40];
  int habitantes, maior_habitantes = 0;
  arqv_cidade = fopen(nome_arqv, "r");
  arqv_maior = fopen("final.txt", "w");
  if (arqv_cidade == NULL) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  while (fscanf(arqv_cidade, "%s %d", cidade, &habitantes) != EOF) {
    if (habitantes > maior_habitantes) {
      maior_habitantes = habitantes;
      strcpy(maior_cidade, cidade);
    }
  }
  fprintf(arqv_maior, "%s %d", maior_cidade, maior_habitantes);
  fclose(arqv_cidade);
  fclose(arqv_maior);
}

void print_arquivo(char *nome_arquivo) { // [FUNÇÃO DE PRINTAR ARQUIVO]
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
  abrir_arquivo("cidades.txt");
  abrir_arquivo("final.txt");
  printf("Cidades:\n");
  print_arquivo("cidades.txt");
  ler_arquivo("cidades.txt");
  printf("\n\nCidade mais populosas:\n");
  print_arquivo("final.txt");
  return 0;
}