/*14 - Dado um arquivo contendo um conjunto de nome e data de nascimento (DD MM AAAA, isto e, 3 inteiros em sequência), faça um programa que leia o nome do arquivo e a data de hoje e construa outro arquivo contendo o nome e a idade de cada pessoa do primeiro arquivo.*/

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

int calcular_idade(int dia_nac, int mes_nac, int ano_nac) { // [FUNÇÃO DE CALCULAR IDADE]
  time_t mytime;
  mytime = time(NULL);
  struct tm tm = *localtime(&mytime);
  int dia_atual = tm.tm_mday, mes_atual = tm.tm_mon + 1, ano_atual = tm.tm_year + 1900;
  int idade = ano_atual - ano_nac;
  if (mes_atual < mes_nac || (mes_atual == mes_nac && dia_atual < dia_nac)) {
    idade--;
  }
  return idade;
}

void escrever_arquivo(char *arqv_inicial, char *arqv_final) { // [FUNÇÃO DE ESCREVER ARQUIVO]
  FILE *arquivo_inicial = fopen(arqv_inicial, "r");
  FILE *arquivo_final = fopen(arqv_final, "w");
  if (arquivo_inicial == NULL || arquivo_final == NULL) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  char nome[100];
  int dia, mes, ano, idade;
  while (fscanf(arquivo_inicial, "%s %d %d %d", nome, &dia, &mes, &ano) != EOF) {
    idade = calcular_idade(dia, mes, ano);
    fprintf(arquivo_final, "%s %d\n", nome, idade);
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
  abrir_arquivo("pessoa.txt");
  abrir_arquivo("idade.txt");
  escrever_arquivo("pessoa.txt", "idade.txt");
  mostrar_arquivo("idade.txt");
  return 0;
}