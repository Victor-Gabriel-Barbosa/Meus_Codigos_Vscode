/*28 - Faça um programa que recebe como entrada o nome de um arquivo de entrada
  e o nome de um arquivo de saída. Cada linha do arquivo de entrada possui
  colunas de tamanho de 30 caracteres. No arquivo de saída deverá ser escrito o
  arquivo de entrada de forma inversa. Veja um exemplo: Arquivo de entrada: Hoje e dia de prova de Algoritmos II A prova está muito fácil Vou tirar uma boa nota Arquivo de saída: Aton aob amu rarit uov Licaf otium átse avorp A II somtiroglA ed avorp ed aid e ejoH*/

#include <ctype.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

void limpa_tela() { // [FUNÇÃO DE LIMPAR TELA]
  printf("\033[0m\nAperte [\033[38;5;39mENTER\033[0m] para continuar...");
  getchar();
  __fpurge(stdin);
  system("clear");
}

void barra(char *ini, char *fin) {
  printf("%s\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m%s", ini, fin);
}

void abrir_arquivo(char *nome_arquivo) { // [FUNÇÃO DE ABRIR ARQUIVO]
  FILE *arquivo = fopen(nome_arquivo, "a");
  if (!arquivo) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  fclose(arquivo);
}

void inverter_arquivo(char *nome_entrada, char *nome_saida) { // [FUNÇÃO DE INVERTER ARQUIVO]
  FILE *arq_entrada, *arq_saida;
  char linha[31], temp;
  int i, j, tam;
  arq_entrada = fopen(nome_entrada, "r");
  arq_saida = fopen(nome_saida, "w");
  if (!arq_entrada || !arq_saida) {
    printf("\n\033[38;5;9m[Arquivo não encontrado!]\033[0m");
    exit(1);
  }
  while (fgets(linha, 30, arq_entrada) != NULL) {
    tam = strlen(linha);
    for (i = 0, j = tam - 2; i < tam / 2; i++, j--) {
      temp = linha[i];
      linha[i] = linha[j];
      linha[j] = temp;
    }
    fprintf(arq_saida, "%s", linha);
  }
  rewind(arq_entrada);
  rewind(arq_saida);
  fclose(arq_entrada);
  fclose(arq_saida);
}

void printf_arqv(char *nome_arqv) {
  FILE *arqv = fopen(nome_arqv, "r");
  char c;
  while (fscanf(arqv, "%c", &c) != EOF) {
    printf("%c", c);
  }  
  fclose(arqv);
}

int main(void) {
  abrir_arquivo("entrada.txt");
  abrir_arquivo("saida.txt");
  inverter_arquivo("entrada.txt", "saida.txt");
  printf("Entrada:\n");
  printf_arqv("entrada.txt");
  printf("\n\nSaída:\n");
  printf_arqv("saida.txt");
  return 0;
}