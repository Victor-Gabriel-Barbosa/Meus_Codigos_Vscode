/*16 - Faça um programa que recebe um vetor de 10 números, converta cada um desses ´números para binário e grave a sequência de 0s e 1s em um arquivo texto. Cada número ´ deve ser gravado em uma linha.*/

#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void abrir_arquivo(char *nome_arquivo) { // [FUNÇÃO DE ABRIR ARQUIVO]
  FILE *arquivo = fopen(nome_arquivo, "a");
  if (!arquivo) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  fclose(arquivo);
}

void converter_binario(char *nome_arquivo, int *vet) { // [FUNÇÃO DE CONVERTER P/ BINÁRIO]
  FILE *arquivo = fopen(nome_arquivo, "w");
  if (arquivo == NULL) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  for (int i = 0; i < 10; i++) {
    int num = vet[i];
    char bin[33];
    bin[32] = '\0';
    for (int j = 31; j >= 0; j--) {
      bin[j] = (num % 2) + '0';
      num /= 2;
    }
    fprintf(arquivo, "%s\n", bin);
  }
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
  srand(time(NULL));
  int i, vetor[10];
  for (i = 0; i < 10; i++) {
    vetor[i] = rand() % 10;
  }
  printf("Vetor:\n");
  for (i = 0; i < 10; i++) {
    printf("%d\n", vetor[i]);
  }
  printf("\n");
  abrir_arquivo("binario.txt");
  converter_binario("binario.txt", vetor);
  printf("\nArquivo com vetor convertido p/ binário:\n");
  mostrar_arquivo("binario.txt");
  return 0;
}