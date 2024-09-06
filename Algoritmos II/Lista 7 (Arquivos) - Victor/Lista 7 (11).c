/*11 - Faça um programa no qual o usuário informa o nome do arquivo e uma palavra, e retorne o número de vezes que aquela palavra aparece no arquivo.*/

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

int ler_arquivo(char *nome_arquivo, char *palavra) { // [FUNÇÃO DE LER ARQUIVO]
  FILE *arqv;
  int cont = 0;
  char string[100];
  arqv = fopen(nome_arquivo, "r");
  if (arqv == NULL) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  while (fscanf(arqv, "%s", string) != EOF) {
    if (strcasecmp(palavra, string) == 0) {
      cont++;
    }  
  }
  fclose(arqv);
  return cont;
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
  char palavra[50];
  int cont;
  abrir_arquivo("arquivo.txt");
  printf("Digite a palavra a ser procurada: ");
  scanf("%s", palavra);
  __fpurge(stdin);
  cont = ler_arquivo("arquivo.txt", palavra);
  printf("\nA palavra [%s] aparece %d vezes no arquivo", palavra, cont);
  return 0;
}