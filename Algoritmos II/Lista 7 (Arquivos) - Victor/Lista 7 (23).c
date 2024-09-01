/*23 - Escreva um programa que leia a profissão e o tempo de serviço (em anos) de cada um dos 5 funcionários de uma empresa e armazene-os no arquivo “emp.txt”. Cada linha do arquivo corresponde aos dados de um funcionário. Utilize o comando fprintf(). Em seguida, leia o mesmo arquivo utilizando fscanf(). Apresente os dados na tela.*/

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
  FILE *arq = fopen(nome_arquivo, "w");
  if (arq == NULL) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  char nome[100];
  char profissao[100];
  int i, anos_de_servico;
  for (i = 0; i < 5; i++) {
    printf("\nDigite o nome do funcionario %d: ", i + 1);
    scanf("%99[^\n]", nome);
    __fpurge(stdin);
    fprintf(arq, "|Nome: %s|", nome);
    printf("Digite a profissao do funcionario %d: ", i + 1);
    scanf("%99[^\n]", profissao);
    __fpurge(stdin);
    fprintf(arq, "Profissão: %s|", profissao);
    printf("Digite os anos de servico do funcionario %d: ", i + 1);
    scanf("%d", &anos_de_servico);
    __fpurge(stdin);
    fprintf(arq, "Anos de Serviço: %d|\n", anos_de_servico);
  }
  fclose(arq);
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
  abrir_arquivo("emp.txt");
  escrever_arquivo("emp.txt");
  printf("\n\nArquivo de funcionários:\n");
  mostrar_arquivo("emp.txt");
  return 0;
}