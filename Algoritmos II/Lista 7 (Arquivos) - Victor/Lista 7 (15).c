/*15 - Faça um programa que receba como entrada o ano corrente e o nome de dois arquivos: um de entrada e outro de saída. Cada linha do arquivo de entrada contém o nome de uma pessoa (ocupando 40 caracteres) e o seu ano de nascimento. O programa deverá ler o arquivo de entrada e gerar um arquivo de saída onde aparece o nome da pessoa seguida por uma string que representa a sua idade.
  • Se a idade for menor do que 18 anos, escreva “menor de idade”
  • Se a idade for maior do que 18 anos, escreva “maior de idade”
  • Se a idade for igual a 18 anos, escreva “entrando na maior idade”*/

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

void escrever_arquivo(char *arqv_entrada, char *arqv_saida) { // [FUNÇÃO DE ESCREVER ARQUIVO]
  FILE *arquivo_entrada = fopen(arqv_entrada, "r");
  FILE *arquivo_saida = fopen(arqv_saida, "w");
  if (arquivo_entrada == NULL || arquivo_saida == NULL) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  char nome[40];
  int ano_nascimento;
  while (fscanf(arquivo_entrada, "%s %d", nome, &ano_nascimento) != EOF) {
    int idade = 2024 - ano_nascimento;
    if (idade < 18) {
      fprintf(arquivo_saida, "%s - menor de idade\n", nome);
    }
      else if (idade > 18) {
        fprintf(arquivo_saida, "%s - maior de idade\n", nome);
      }
        else if (idade == 18) {
          fprintf(arquivo_saida, "%s - entrando na maior idade\n", nome);
        }
  }
  fclose(arquivo_entrada);
  fclose(arquivo_saida);
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
  rewind(arquivo);
  fclose(arquivo);
}

int main(void) {
  abrir_arquivo("entrada.txt");
  abrir_arquivo("saida.txt");
  printf("Arquivo Inicial:\n");
  mostrar_arquivo("entrada.txt");
  printf("\n\nArquivo Final:\n");
  escrever_arquivo("entrada.txt", "saida.txt");
  mostrar_arquivo("saida.txt");
  return 0;
}