/*20 - Crie um programa que receba como entrada o número de alunos de uma disciplina. Aloque dinamicamente dois vetores para armazenar as informações a respeito desses alunos. O primeiro vetor contém o nome dos alunos e o segundo contém suas notas finais. Crie um arquivo que armazene, a cada linha, o nome do aluno e sua nota final. Use nomes com no máximo 40 caracteres. Se o nome não contiver 40 caracteres, complete com espaços em branco.*/

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

void escrever_arquivo(char *nome_arquivo, int qtd, char **nome, float *nota) { // [FUNÇÃO DE ESCREVER NO ARQUIVO]
  FILE *arquivo_final;
  arquivo_final = fopen(nome_arquivo, "w");
  if (arquivo_final == NULL) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  for (int i = 0; i < qtd; i++) {
    fprintf(arquivo_final, "|Nome: %s|Nota: %.2f|\n", nome[i], nota[i]);
  }
  fclose(arquivo_final);
}

void cadastrar_aluno(int qtd, char **nome, float *nota) { // [FUNÇÃO DE CADASTRAR ALUNO]
  for (int i = 0; i < qtd; i++) {
    nome[i] = (char *) calloc(40, sizeof(char));
    if (!nome[i]) {
      printf("\nErro ao alocar memória\n");
      exit(1);
    }
    printf("\nDigite o nome do aluno %d: ", i + 1);
    scanf("%39[^\n]", nome[i]);
    __fpurge(stdin);
    printf("Digite a nota do aluno %d: ", i + 1);
    scanf("%f", &nota[i]);
    __fpurge(stdin);
  }
}

int main(void) {
  int i, qtd;
  float *notas;
  char **nomes;
  abrir_arquivo("arquivo_final.txt");
  printf("Digite a quantidade de alunos: ");
  scanf("%d", &qtd);
  __fpurge(stdin);
  nomes = (char **) calloc(qtd, sizeof(char *));
  notas = (float *) calloc(qtd, sizeof(float));
  if (!nomes || !notas) {
    printf("\nErro ao alocar memória\n");
    exit(1);
  }
  cadastrar_aluno(qtd, nomes, notas);
  escrever_arquivo("arquivo_final.txt", qtd, nomes, notas);
  printf("\n\nArquivo:\n");
  mostrar_arquivo("arquivo_final.txt");
  free(nomes);
  free(notas);
  return 0;
}