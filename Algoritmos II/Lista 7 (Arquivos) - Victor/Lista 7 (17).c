/*17. Faça um programa que leia um arquivo que contenha as dimensões de uma matriz (linha ˜ e coluna), a quantidade de posições que serão anuladas, e as posições a serem anuladas (linha e coluna). O programa lê esse arquivo e, em seguida, produz um novo arquivo com a matriz com as dimensões dadas no arquivo lido, e todas as posições especificadas no arquivo ZERADAS e o restante recebendo o valor 1. Ex: arquivo “matriz.txt”
  3 3 2 (3 e 3 dimensões da matriz e 2 posições que serão anuladas)
  1 0
  1 2 (Posições da matriz que serão anuladas)
  arquivo “matriz saida.txt” saída:
  1 1 1
  0 1 0
  1 1 1*/

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

void escrever_arquivo(char *nome_arquivo) { // [FUNÇÃO DE ESCREVER ARQUIVO]
  FILE *file = fopen(nome_arquivo, "w");
  if (file == NULL) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  int linhas, colunas, qtd, x, y;
  printf("\nDigite o tamanho das linhas da matriz: ");
  scanf("%d", &linhas);
  __fpurge(stdin);
  fprintf(file, "%d ", linhas);
  printf("\nDigite o tamanho das colunas da matriz: ");
  scanf("%d", &colunas);
  __fpurge(stdin);
  fprintf(file, "%d\n", colunas);
  printf("\nDigite a quantidade de posições que serão anuladas: ");
  scanf("%d", &qtd);
  __fpurge(stdin);
  fprintf(file, "%d\n", qtd);
  for (int i = 0; i < qtd; i++) {
    printf("\nDigite a posição da linha a ser anulada: ");
    scanf("%d", &x);
    __fpurge(stdin);
    fprintf(file, "%d ", x);
    printf("Digite a posição da coluna a ser anulada: ");
    scanf("%d", &y);
    __fpurge(stdin);
    fprintf(file, "%d ", y);
  }
  rewind(file);
  fclose(file);
}

void ler_arquivo(char *arqv_inicial, char *arqv_final) { // [FUNÇÃO DE LER ARQUIVO]
  FILE *arquivo_inicial = fopen(arqv_inicial, "r");
  FILE *arquivo_final = fopen(arqv_final, "w");
  if (arquivo_inicial == NULL || arquivo_final == NULL) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  int i, j, k, linhas, colunas, qtd;
  fscanf(arquivo_inicial, "%d %d %d", &linhas, &colunas, &qtd);
  int x[qtd], y[qtd], aux;
  for (i = 0; i < qtd; i++) {
    fscanf(arquivo_inicial, "%d %d", &x[i], &y[i]);
  }
  for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {
      aux = 0;
      for (k = 0; k < qtd; k++) {
        if (i == x[k] && j == y[k]) {
          aux = 1;
        }
      }
        if (aux == 1) {
          fprintf(arquivo_final, "0 ");
        }
          else {
            fprintf(arquivo_final, "1 ");
          }
    }
    fprintf(arquivo_final, "\n");
  }
  fclose(arquivo_inicial);
  fclose(arquivo_final);
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
  abrir_arquivo("matriz.txt");
  abrir_arquivo("nova_matriz.txt");
  escrever_arquivo("matriz.txt");
  printf("\nArquivo Inicial:\n");
  mostrar_arquivo("matriz.txt");
  ler_arquivo("matriz.txt", "nova_matriz.txt");
  printf("\n\nArquivo Final:\n");
  mostrar_arquivo("nova_matriz.txt");
  return 0;
}