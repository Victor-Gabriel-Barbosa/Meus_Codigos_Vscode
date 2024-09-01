/*27 - Faça um programa para gerenciar as notas dos alunos de uma turma salva em um arquivo. O programa deverá ter um menu contendo as seguintes opcões:
  (a) Definir informações da turma;
  (b) Inserir aluno e notas;
  (c) Exibir alunos e medias;
  (d) Exibir alunos aprovados;
  (e) Exibir alunos reprovados;
  (f) Salvar dados em Disco;
  (g) Sair do programa (fim).
  Faça a rotina que gerencia o menu dentro do main, e para cada uma das opções deste menu, crie uma função específica.*/

#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct estudantes {
  char nome[50];
  int turma, matricula;
  float notas[3];
} estudante;

void limpa_tela() { // [FUNÇÃO DE LIMPAR TELA]
  printf("\033[0m\nAperte [\033[38;5;39mENTER\033[0m] para continuar...");
  getchar();
  __fpurge(stdin);
  system("clear");
}

void barra(char *ini, char *fin) {
  printf("%s\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m%s", ini, fin);
}

int sim_nao() { // [FUNÇÃO DE SIM OU NÃO]
  int opcao;
  do { // [LOOP P/ VALIDAÇÃO]
    limpa_tela();
    opcao = -1;
    barra("\n", "\n");
    printf("\033[38;5;201m[TEM CERTEZA?]\033[0m");
    barra("\n", "\n");
    printf("|[\033[38;5;51m1\033[0m]> Sim\n");
    printf("|[\033[38;5;51m0\033[0m]> Não");
    barra("\n", "\n");
    printf("Opção\033[38;5;51m: ");
    scanf("%d", &opcao);
    __fpurge(stdin);
    barra("", "\n");
    if (opcao < 0 || opcao > 1) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (opcao < 0 || opcao > 1);
  return opcao;
}

int ver_acentos(char c) { // [FUNÇÃO DE VERIFICAR CARACTERES ACCENTUADOS]
  char c_acentos[] = "áéíóúàèìòùâêîôûãõäëïöüçÁÉÍÓÚÀÈÌÒÙÂÊÎÔÛÃÕÄËÏÖÜÇ";
  for (int i = 0; i < strlen(c_acentos); i++) {
    if (c == c_acentos[i]) {
      return 1;
    }
  }
  return 0;
}

int ver_str(char *str) { // [FUNÇÃO DE VERIFICAR SE UM NOME É VÁLIDO]
  int espaco = 1;
  for (int i = 0; str[i] != '\0'; i++) {
    if (!isspace(str[i])) {
      espaco = 0;
      break;
    }
  }
  if (espaco) {
    return 0;
  }
  for (int i = 0; str[i] != '\0'; i++) {
    if (!isalpha(str[i]) && !isspace(str[i]) && !ver_acentos(str[i])) {
      return 0;
    }
  }
  return 1;
}

void abrir_arquivo(char *nome_arquivo) { // [FUNÇÃO DE ABRIR ARQUIVO]
  FILE *arquivo = fopen(nome_arquivo, "ab");
  if (!arquivo) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  fclose(arquivo);
}

void cadastrar_turma(estudante **alun, int *qtd) { // [FUNÇÃO DE CADASTRAR TURMA]
  do {
    limpa_tela();
    *qtd = -1;
    barra("\n", "\n");
    printf("\033[38;5;51m[Definir informações da turma]\033[0m");
    barra("\n", "\n");
    printf("Quantidade de alunos\033[38;5;51m: ");
    scanf("%d", qtd);
    __fpurge(stdin);
    barra("", "\n");
    if (*qtd <= 0) {
      printf("\n\033[38;5;196m[Quantidade inválida! Tente novamente...]\033[0m\n");
    }
  } while (*qtd <= 0);
  *alun = (estudante *) realloc(*alun, *qtd * sizeof(estudante));
}

void cadastrar_aluno(estudante *alun, int *ct_a, int qtd_n) { // [FUNÇÃO DE CADASTRAR ALUNO]
  int opcao;
  do {
    limpa_tela();
    barra("\n", "\n");
    printf("\033[38;5;201m[CADASTRAR ALUNO]\033[0m");
    barra("\n", "\n");
    printf("Nome do aluno\033[38;5;51m: ");
    scanf("%49[^\n]", alun->nome);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_str(alun->nome)) {
      printf("\n\033[38;5;196m[Nome inválido! Tente novamente...]\033[0m\n");
    }
  } while (!ver_str(alun->nome));
  do {
    limpa_tela();
    alun->matricula = -1;
    barra("\n", "\n");
    printf("\033[38;5;201m[CADASTRAR ALUNO]\033[0m");
    barra("\n", "\n");
    printf("Código do aluno\033[38;5;51m: ");
    scanf("%d", &alun->matricula);
    __fpurge(stdin);
    barra("", "\n");
    if (alun->matricula <= 0) {
      printf("\n\033[38;5;196m[Código inválido! Tente novamente...]\033[0m\n");
    }
  } while (alun->matricula <= 0);
  for (int i = 0; i < qtd_n; i++) {
    do {
      limpa_tela();
      alun->notas[i] = -1;
      barra("\n", "\n");
      printf("\033[38;5;201m[CADASTRAR ALUNO]\033[0m");
      barra("\n", "\n");
      printf("Nota[%d]\033[38;5;51m[0-100]: ", i + 1);
      scanf("%f", &alun->notas[i]);
      __fpurge(stdin);
      barra("", "\n");
      if (alun->notas[i] < 0 || alun->notas[i] > 100) {
        printf("\n\033[38;5;196m[Nota inválida! Tente novamente...]\033[0m\n");
      }
    } while (alun->notas[i] < 0 || alun->notas[i] > 100);
  }
  (*ct_a)++;
  printf("\n\033[38;5;51m[Aluno cadastrado com sucesso!]\033[0m\n");
}

void exibir_alunos(estudante *alun, int ct_a, int qtd_n) { // [FUNÇÃO DE EXIBIR ALUNOS]
  barra("\n", "\n");
  printf("\033[38;5;51m[Alunos]\033[0m");
  barra("\n", "\n");
  for (int i = 0; i < ct_a; i++) {
    float media = 0;
    for (int j = 0; j < qtd_n; j++) {
      media += alun[i].notas[j];  
    }
    media /= qtd_n;
    barra("\n", "\n");
    printf("\033[38;5;51m[Aluno %d]\033[0m", i + 1);
    barra("\n", "\n");
    printf("\033[38;5;51mNome: %s\033[0m\n", alun[i].nome);
    printf("\033[38;5;51mMatrícula: %d\033[0m\n", alun[i].matricula);
    for (int j = 0; j < qtd_n; j++) {
      printf("\033[38;5;51mNota[%d]: %.2f\033[0m\n", j + 1, alun[i].notas[j]);
    }
    printf("\033[38;5;51mMédia: %.2f\033[0m", media);
    barra("\n", "\n");
  }
}

void exibir_alunos_aprovados(estudante *alun, int ct_a, int qtd_n) { // [FUNÇÃO DE EXIBIR ALUNOS APROVADOS]
  barra("\n", "\n");
  printf("\033[38;5;51m[Alunos Aprovados]\033[0m");
  barra("\n", "\n");
  for (int i = 0; i < ct_a; i++) {
    float media = 0;
    for (int j = 0; j < qtd_n; j++) {
      media += alun[i].notas[j];  
    }
    media /= qtd_n;
    if (media >= 60) {
      barra("\n", "\n");
      printf("\033[38;5;51m[Aluno %d]\033[0m", i + 1);
      barra("\n", "\n");
      printf("\033[38;5;51mNome: %s\033[0m\n", alun[i].nome);
      printf("\033[38;5;51mMatrícula: %d\033[0m\n", alun[i].matricula);
      for (int j = 0; j < qtd_n; j++) {
        printf("\033[38;5;51mNota[%d]: %.2f\033[0m\n", j + 1, alun[i].notas[j]);
      }
      printf("\033[38;5;51mMédia: %.2f\033[0m", media);
      barra("\n", "\n");
    }
  }
}

void exibir_alunos_reprovados(estudante *alun, int ct_a, int qtd_n) {
  barra("\n", "\n");
  printf("\033[38;5;51m[Alunos Reprovados]\033[0m");
  barra("\n", "\n");
  for (int i = 0; i < ct_a; i++) {
    float media = 0;
    for (int j = 0; j < qtd_n; j++) {
      media += alun[i].notas[j];  
    }
    media /= qtd_n;
    if (media < 60) {
      barra("\n", "\n");
      printf("\033[38;5;51m[Aluno %d]\033[0m", i + 1);
      barra("\n", "\n");
      printf("\033[38;5;51mNome: %s\033[0m\n", alun[i].nome);
      printf("\033[38;5;51mMatrícula: %d\033[0m\n", alun[i].matricula);
      for (int j = 0; j < qtd_n; j++) {
        printf("\033[38;5;51mNota[%d]: %.2f\033[0m\n", j + 1, alun[i].notas[j]);
      }
      printf("\033[38;5;51mMédia: %.2f\033[0m", media);
      barra("\n", "\n");
    }
  }
}

void salvar_alunos(char *arqv_nome, estudante *alun, int ct) { // [FUNÇÃO DE SALVAR ALUNOS]
  FILE *arquivo = fopen(arqv_nome, "wb");
  if (!arquivo) {
    printf("\n\033[38;5;196m[Erro ao abrir arquivo!]\033[0m\n");
    exit(1);
  }
  fwrite(alun, sizeof(estudante), ct, arquivo);
  rewind(arquivo);
  fclose(arquivo);
}

int escolh_menu() { // [FUNÇÃO DE ESCOLHER OPÇÃO DO MENU]
  int op;
  do {
    limpa_tela();
    barra("\n", "\n");
    printf("\033[38;5;201m[MENU]\033[0m");
    barra("\n", "\n");
    printf("|[\033[38;5;51m1\033[0m]> Definir informações da turma\n");
    printf("|[\033[38;5;51m2\033[0m]> Inserir alunos e notas\n");
    printf("|[\033[38;5;51m3\033[0m]> Exibir alunos e medias\n");
    printf("|[\033[38;5;51m4\033[0m]> Exibir alunos aprovados\n");
    printf("|[\033[38;5;51m5\033[0m]> Exibir alunos reprovados\n");
    printf("|[\033[38;5;51m6\033[0m]> Salvar dados em Disco");
    barra("\n", "\n");
    printf("|[\033[38;5;51m0\033[0m]> Sair");
    barra("\n", "\n");
    printf("Opção\033[38;5;51m: ");
    scanf("%d", &op);
    __fpurge(stdin);
    barra("", "\n");
    if (op < 0 || op > 6) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (op < 0 || op > 6);
  return op;
}

void carregar_dados(char *nome_arqv, estudante **alun, int *ct) {
  FILE *arquivo = fopen(nome_arqv, "rb");
  int i, aux = 0;
  if (!arquivo) {
    printf("\n\033[38;5;196m[Arquivo não encontrado!]\033[0m\n");
    exit(1);
  }
  estudante temp;
  while (fread(&temp, sizeof(estudante), 1, arquivo)) {
    aux++;
  }
  if (aux > 0) {
    rewind(arquivo);
    *ct = aux;
    *alun = (estudante *) realloc(*alun, *ct * sizeof(estudante)); 
    if (!alun) {
      printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
      exit(1);
    }
    for (i = 0; i < *ct; i++) {
      fread(&(*alun)[i], sizeof(estudante), 1, arquivo);
    }
    printf("\n\033[38;5;51m[Arquivo de alunos carregado com sucesso!]\033[0m\n");
  }
  rewind(arquivo);
  fclose(arquivo);
}

int main(void) {
  abrir_arquivo("alunos.bin");
  estudante *alun = (estudante *) calloc(1, sizeof(estudante));
  if (!alun) {
    printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
    exit(1);
  }
  int aux, opcao, qtd_aluno = 0, qtd_notas = 3, ct_aluno = 0, loop = 1;
  carregar_dados("alunos.bin", &alun, &ct_aluno);
  while (loop) {
    opcao = escolh_menu();
    if (opcao == 0) {
      if (sim_nao()) {
        printf("\n\033[38;5;51m[Saindo...]\033[0m\n");
        loop = 0;
      }  
        else {
          printf("\n\033[38;5;51m[Voltando ao menu...]\033[0m\n");
        }
    }
      else if (opcao == 1) {
        if (sim_nao()) {
          cadastrar_turma(&alun, &qtd_aluno);
        }
          else {
            printf("\n\033[38;5;51m[Voltando ao menu...]\033[0m");
          }
      }
        else if (opcao == 2) {
          if (qtd_aluno > ct_aluno) {
            if (sim_nao()) {
                cadastrar_aluno(&alun[ct_aluno], &ct_aluno, qtd_notas);
              }
                else {
                  printf("\n\033[38;5;51m[Voltando ao menu...]\033[0m\n");
                }  
          }
            else {
              printf("\n\033[38;5;196m[Quantidade de máxima de alunos excedida!]\033[0m\n");
            } 
        }  
          else if (opcao == 3) {
            if (ct_aluno > 0) {
              limpa_tela();
              exibir_alunos(alun, ct_aluno, qtd_notas);
            }
              else {
                printf("\n\033[38;5;196m[Não há alunos cadastrados!]\033[0m\n");
              }
          }
            else if (opcao == 4) {
              if (ct_aluno > 0) {
                limpa_tela();
                exibir_alunos_aprovados(alun, ct_aluno, qtd_notas);
              }
                else {
                  printf("\n\033[38;5;196m[Não há alunos cadastrados!]\033[0m\n");
                }
            }
              else if (opcao == 5) {
                if (ct_aluno > 0) {
                  limpa_tela();
                  exibir_alunos_reprovados(alun, ct_aluno, qtd_notas);
                }
                  else {
                    printf("\n\033[38;5;196m[Não há alunos cadastrados!]\033[0m\n");
                  }
              }
                else if (opcao == 6) {
                  if (ct_aluno > 0) {
                    if (sim_nao()) {
                      salvar_alunos("alunos.bin", alun, ct_aluno);
                      printf("\n\033[38;5;51m[Dados salvos com sucesso!]\033[0m\n");
                    }
                      else {
                        printf("\n\033[38;5;51m[Voltando ao menu...]\033[0m\n");
                      }
                  }
                }
  }
  free(alun);
  return 0;
}