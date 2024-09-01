/*22 - Faça um programa que recebe como entrada o nome de um arquivo de entrada e o nome de um arquivo de saída. O arquivo de entrada contém o nome de um aluno ocupando 40 caracteres e três inteiros que indicam suas notas. O programa deverá ler o arquivo de entrada e gerar um arquivo de saída onde aparece o nome do aluno e as suas notas em ordem crescente.*/

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

void ordenar_arquivo(char *entrada, char *saida) { // [FUNÇÃO DE ORDENAR ARQUIVO]
  FILE *arq_entrada = fopen(entrada, "r");
  FILE *arq_saida = fopen(saida, "w");
  char nome[41] = "";
  int notas[3] = {0};
  int i, j, temp;
  while (fscanf(arq_entrada, "%s %d %d %d", nome, &notas[0], &notas[1], &notas[2]) != EOF) {
    for (i = 0; i < 2; i++) {
      for (j = i + 1; j < 3; j++) {
        if (notas[i] > notas[j]) {
          temp = notas[i];
          notas[i] = notas[j];
          notas[j] = temp;
        }
      }
    }
  }
  fprintf(arq_saida, "%s %d %d %d\n", nome, notas[0], notas[1], notas[2]);
  fclose(arq_entrada);
  fclose(arq_saida);
}

void mostrar_arquivo(char *nome_arquivo) { // [FUNÇÃO DE PRINTAR ARQUIVO]
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
  printf("Arquivo Desordenado:\n");
  mostrar_arquivo("entrada.txt");
  ordenar_arquivo("entrada.txt", "saida.txt");
  printf("\n\nArquivo em Ordem Crescente:\n");
  mostrar_arquivo("saida.txt");
  return 0;
}