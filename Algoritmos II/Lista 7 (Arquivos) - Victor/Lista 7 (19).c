/*19 - Faça um programa que receba do usuário um arquivo que contenha o nome e a nota de diversos alunos (da seguinte forma: NOME: JOAO NOTA: 8), um aluno por linha. Mostre na tela o nome e a nota do aluno que possui a maior nota*/

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

void maior_nota(char *nome_arquivo) { // [FUNÇÃO DE VERIFICAR MAIOR NOTA]
  FILE *arquivo = fopen(nome_arquivo, "r");
  if (arquivo == NULL) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  char nome[100];
  float nota, maior_nota = -1;
  char nome_maior_nota[100];
  while (fscanf(arquivo, "NOME: %s NOTA: %f", nome, &nota)) {
    if (nota > maior_nota) {
      maior_nota = nota;
      strcpy(nome_maior_nota, nome);
    }
  }
  fclose(arquivo);
  printf("\n\nO aluno com a maior nota é: %s", nome_maior_nota);
  printf("\nA nota do aluno é: %.2f\n", maior_nota);
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
  abrir_arquivo("nota.txt");
  printf("Arquivo:\n");
  mostrar_arquivo("nota.txt");
  maior_nota("nota.txt");
  return 0;
}