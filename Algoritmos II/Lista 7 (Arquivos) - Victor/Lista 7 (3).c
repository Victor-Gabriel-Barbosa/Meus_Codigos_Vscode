/*3 - Faça um programa que receba do usuário um arquivo texto e mostre na tela quantas letras são vogais.*/

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

int contar_vogais(char *nome_arq) { // [FUNÇÃO DE CONTAR VOGAIS]
  FILE *arq;
  char c;
  int cont = 0;
  char vogais_aux[] = "aeiouAEIOU";
  arq = fopen(nome_arq, "r");
  if (arq == NULL) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  while (fscanf(arq, "%c", &c) != EOF) {
    if (strchr(vogais_aux, c) != NULL) {
      cont++;
    } 
  }
  fclose(arq);
  return cont;
}

int main(void) {
  abrir_arquivo("vogais.txt");
  int ct = contar_vogais("vogais.txt");
  printf("Quantidade de vogais no arquivo: %d", ct);
  return 0;
}