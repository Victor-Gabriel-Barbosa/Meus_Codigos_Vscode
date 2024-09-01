/*26 - Crie um programa que declare uma estrutura para o cadastro de alunos.
  (a) Deverão ser armazenados, para cada aluno: matrícula, sobrenome (apenas um), e ano de nascimento.
  (b) Ao início do programa, o usuário deverá informar o número de alunos que serão armazenados
  (c) O programa devera alocar dinamicamente a quantidade necessária de memória para armazenar os registros dos alunos.
  (d) O programa deverá pedir ao usuário que entre com as informações dos alunos.
  (e) Em seguida, essas informações deverão ser gravadas em um arquivo
  (f) Ao final, mostrar os dados armazenados e liberar a memória alocada.
  Ao iniciar o programa, forneça ao usuário uma opção para carregar os registros do arquivo para a memória do computador alocando dinamicamente a quantidade de memória necessária
Dica: para que o usuário possa entrar com novos dados, além dos que foram obtidos a partir do arquivo, use a função realloc() para realocar a quantidade de memória usada.*/

#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct estudantes {
  int mat, ano;
  char sobrenome[50];
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

void cadastra_aluno(estudante *alunos, int *ct) { // [FUNÇÃO DE CADASTRAR ALUNO]
  do {
    limpa_tela();
    alunos->mat = -1;
    barra("\n", "\n");
    printf("\033[38;5;201m[CADASTRO DE ALUNOS]\033[0m");
    barra("\n", "\n");
    printf("Matrícula\033[38;5;51m: ");
    scanf("%d", &alunos->mat);
    __fpurge(stdin);
    barra("", "\n");
    if (alunos->mat <= 0) {
      printf("\n\033[38;5;196m[Matrícula inválida! Tente novamente...]\033[0m\n");
    }
  } while (alunos->mat <= 0);
  do {
    limpa_tela();
    barra("\n", "\n");
    printf("\033[38;5;201m[CADASTRO DE ALUNOS]\033[0m");
    barra("\n", "\n");
    printf("Sobrenome\033[38;5;51m: ");
    scanf("%49[^\n]", alunos->sobrenome);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_str(alunos->sobrenome)) {
      printf("\n\033[38;5;196m[Sobrenome inválido! Tente novamente...]\033[0m\n");
    }    
  } while (!ver_str(alunos->sobrenome));
  do {
    limpa_tela();
    alunos->ano = -1;
    barra("\n", "\n");
    printf("\033[38;5;201m[CADASTRO DE ALUNOS]\033[0m");
    barra("\n", "\n");
    printf("Ano de nascimento\033[38;5;51m: ");
    scanf("%d", &alunos->ano);
    __fpurge(stdin);
    barra("", "\n");
    if (alunos->ano <= 0 || alunos->ano > 2023) {
      printf("\n\033[38;5;196m[Ano inválido! Tente novamente...]\033[0m\n");
    }
  } while (alunos->ano <= 0 || alunos->ano > 2023);
  ++*ct;
  printf("\n\033[38;5;51m[Aluno cadastrado com sucesso!]\033[0m\n");
}

void listar_alunos(estudante *alunos, int ct) { // [FUNÇÃO DE LISTAR ALUNOS]
  barra("\n", "\n");
  printf("\033[38;5;201m[LISTA DE ALUNOS]\033[0m");
  barra("\n", "\n");
  for (int i = 0; i < ct; i++) {
    barra("\n", "\n");
    printf("\033[38;5;51mMatrícula: %d\033[0m\n", alunos[i].mat);
    printf("\033[38;5;51mSobrenome: %s\033[0m\n", alunos[i].sobrenome);
    printf("\033[38;5;51mAno de nascimento: %d\033[0m", alunos[i].ano);
    barra("\n", "\n");
  }
}

void carregar_arquivo(estudante **alunos, int *ct) { // [FUNÇÃO DE CARREGAR ARQUIVO]
  FILE *arquivo = fopen("alunos.bin", "rb");
  estudante temp;
  int i, aux = 0;
  if (arquivo == NULL) {
    printf("\n\033[38;5;196m[Arquivo não encontrado!]\033[0m\n");
    exit(1);
  }
  while (fread(&temp, sizeof(estudante), 1, arquivo) == 1) {
    aux++;
  }
  if (aux > 0) {
    *ct = aux;
    *alunos = (estudante *) realloc(*alunos, *ct * sizeof(estudante));
    rewind(arquivo);
    for (i = 0; i < aux; i++) {
      fread(&(*alunos)[i], sizeof(estudante), 1, arquivo);
    }
    printf("\n\033[38;5;51m[Arquivo carregado com sucesso!]\033[0m\n");
  }
    else {
      printf("\n\033[38;5;196m[Arquivo vazio!]\033[0m\n");
    }
  rewind(arquivo);
  fclose(arquivo);
}

int escolh_menu() { // [FUNÇÃO DE ESCOLHA DE MENU]
  int op;
  do {
    limpa_tela();
    op = -1;
    barra("\n", "\n");
    printf("\033[38;5;201m[MENU]\033[0m");
    barra("\n", "\n");
    printf("|[\033[38;5;51m1\033[0m]> Cadastrar Aluno\n");
    printf("|[\033[38;5;51m2\033[0m]> Listar Alunos\n");
    printf("|[\033[38;5;51m3\033[0m]> Carregar Alunos");
    barra("\n", "\n");
    printf("|[\033[38;5;51m0\033[0m]> Sair e Salvar");
    barra("\n", "\n");
    printf("Opção\033[38;5;51m: ");
    scanf("%d", &op);
    __fpurge(stdin);
    barra("", "\n");
    if (op < 0 || op > 3) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (op < 0 || op > 3);
  return op;
}

int main(void) {
  abrir_arquivo("alunos.bin");
  estudante *alunos = (estudante *) calloc(1, sizeof(estudante));
  int opcao, qtd, ct_aluno = 0, aux, loop = 1;
  while (loop) {
    opcao = escolh_menu();
    if (opcao == 0) {
      if (sim_nao()) {
        FILE *arquivo = fopen("alunos.bin", "wb");
        if (arquivo == NULL) {
          printf("\n\033[38;5;196m[Erro ao abrir o arquivo!]\033[0m\n");
          exit(1);
        }
        fwrite(alunos, sizeof(estudante), ct_aluno, arquivo);
        rewind(arquivo);
        fclose(arquivo);
        printf("\n\033[38;5;196m[Programa encerrado! Todos os dados foram salvos]\033[0m\n");
        exit(0);
      }
    }
      else if (opcao == 1) {
        if (sim_nao()) {
          alunos = (estudante *) realloc(alunos, (ct_aluno + 1) * sizeof(estudante));
          cadastra_aluno(&alunos[ct_aluno], &ct_aluno);
        }
          else {
            printf("\n\033[38;5;51m[Voltando ao menu...]\033[0m\n");
          }
      }
        else if (opcao == 2) {
          if (ct_aluno > 0) {
            limpa_tela();
            listar_alunos(alunos, ct_aluno);
          }        
        }
          else if (opcao == 3) {
            if (sim_nao()) {
              carregar_arquivo(&alunos, &ct_aluno);
            }
              else {
                printf("\n\033[38;5;51m[Voltando ao menu...]\033[0m\n");
              }
          }
  }
  free(alunos);
  return 0;
}