/*21 - Crie um programa que receba como entrada o número de alunos de uma disciplina. Aloque dinamicamente em uma estrutura para armazenar as informações a respeito desses alunos: nome do aluno e sua nota final. Use nomes com no máximo 40 caracteres. Em seguida, salve os dados dos alunos em um arquivo binário. Por fim, leia o arquivo é mostre o nome do aluno com a maior nota.*/

#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct aluno {
  char nome[40];
  float nota;
} alun;

void abrir_arquivo(char *nome_arquivo) { // [FUNÇÃO DE ABRIR ARQUIVO]
  FILE *arquivo = fopen(nome_arquivo, "ab");
  if (!arquivo) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  fclose(arquivo);
}

void cadastrar_alunos(alun *alunos, int qtd) { // [FUNÇÃO DE CADASTRAR ALUNOS]
  for (int i = 0; i < qtd; i++) {
    printf("\nDigite o nome do aluno %d: ", i + 1);
    scanf("%39[^\n]", alunos[i].nome);
    __fpurge(stdin);
    printf("Digite a nota do aluno %d: ", i + 1);
    scanf("%f", &alunos[i].nota);
    __fpurge(stdin);
  }
}

void escrever_arquivo(char *nome_arquivo, alun *alunos, int qtd) { // [FUNÇÃO DE ESCREVER NO ARQUIVO]
  FILE *arq = fopen(nome_arquivo, "wb");
  if (arq == NULL) {
    printf("\nErro ao abrir o arquivo!\n");
    exit(1);
  }
  fwrite(alunos, sizeof(alun), qtd, arq);
  fclose(arq);
}

int ler_arquivo(char *nome_arquivo, int qtd) { // [FUNÇÃO DE LER O ARQUIVO]
  FILE *arq = fopen(nome_arquivo, "rb");
  if (!arq) {
    printf("\nErro ao abrir o arquivo!\n");
    exit(1);
  }
  int i, posi = 0;
  alun maior, temp;
  fread(&maior, sizeof(alun), 1, arq);
  for (i = 1; i < qtd; i++) {
    fread(&temp, sizeof(alun), 1, arq);
    if (temp.nota > maior.nota) {
      maior = temp;
      posi = i;
    }
  }
  fclose(arq);
  return posi;
}

int escolh_qtd() { // [FUNÇÃO DE ESCOLHER A QUANTIDADE DE ALUNOS]
  int qtd;
  do {
    printf("\nDigite o número de alunos: ");
    scanf("%d", &qtd);
    __fpurge(stdin);
    if (qtd <= 0) {
      printf("\n[Número inválido!]\n");
    }
  } while (qtd <= 0);
  return qtd;
}

int main(void) {
  abrir_arquivo("alunos.bin");
  int qtd = escolh_qtd();
  alun *alunos = (alun *) calloc(qtd, sizeof(alun)); 
  cadastrar_alunos(alunos, qtd);
  escrever_arquivo("alunos.bin", alunos, qtd);
  int posi = ler_arquivo("alunos.bin", qtd);
  printf("\nO aluno com a maior nota é: %s\n", alunos[posi].nome);
  free(alunos);
  return 0;
}