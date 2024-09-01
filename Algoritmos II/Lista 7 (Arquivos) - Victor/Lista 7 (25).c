/*25 - Faça um programa gerenciar uma agenda de contatos. Para cada contato armazene o nome, o telefone e o aniversário (dia e mês). O programa deve permitir:
  (a) inserir contato
  (b) remover contato
  (c) pesquisar um contato pelo nome
  (d) listar todos os contatos
  (e) listar os contatos cujo nome inicia com uma dada letra
  (f) imprimir os aniversariantes do mês.
Sempre que o programa for encerrado, os contatos devem ser armazenados em um
arquivo binário. Quando o programa iniciar, os contatos devem ser inicializados com
os dados contidos neste arquivo binário.*/

#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct contatos {
  char nome[50];
  char telefone[20];
  int dia, mes, ano;
} contato;

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

int escolh_menu() { // [FUNÇÃO DE ESCOLHER MENU]
  int op;
  do {
    limpa_tela();
    op = -1;
    barra("\n", "\n");
    printf("\033[38;5;201m[AGENDA DE CONTATOS]\033[0m");
    barra("\n", "\n");
    printf("|[\033[38;5;51m1\033[0m]> Inserir contato\n");
    printf("|[\033[38;5;51m2\033[0m]> Remover contato\n");
    printf("|[\033[38;5;51m3\033[0m]> Pesquisar contato pelo nome\n");
    printf("|[\033[38;5;51m4\033[0m]> Listar todos os contatos\n");
    printf("|[\033[38;5;51m5\033[0m]> Listar contatos letra\n");
    printf("|[\033[38;5;51m6\033[0m]> Aniversariantes do mês");
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

void abrir_arquivo(char *nome_arquivo) { // [FUNÇÃO DE ABRIR ARQUIVO]
  FILE *arquivo = fopen(nome_arquivo, "ab");
  if (!arquivo) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  fclose(arquivo);
}

void inserir_contato(char *nome_arquivo, contato *contat, int *ct) { // [FUNÇÃO DE INSERIR CONTATO]
  do {
    limpa_tela();
    barra("\n", "\n");
    printf("\033[38;5;201m[INSERIR CONTATO]\033[0m");
    barra("\n", "\n");
    printf("Nome\033[38;5;51m: ");
    scanf("%49[^\n]", contat->nome);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_str(contat->nome)) {
      printf("\n\033[38;5;196m[Nome inválido! Tente novamente...]\033[0m\n");
    }
  } while (!ver_str(contat->nome));
  do {
    limpa_tela();
    barra("\n", "\n");
    printf("\033[38;5;201m[INSERIR CONTATO]\033[0m");
    barra("\n", "\n");  
    printf("Telefone\033[38;5;51m[10-12]: ");
    scanf("%19[^\n]", contat->telefone);
    __fpurge(stdin);
    barra("", "\n");
    if (strlen(contat->telefone) < 10 || strlen(contat->telefone) > 12) {
      printf("\n\033[38;5;196m[Telefone inválido! Tente novamente...]\033[0m\n");
    }
  } while (strlen(contat->telefone) < 10 || strlen(contat->telefone) > 12);
  do {
    limpa_tela();
    barra("\n", "\n");
    printf("\033[38;5;201m[INSERIR CONTATO]\033[0m");
    barra("\n", "\n");
    printf("Aniversário\033[38;5;51m[dd/mm/aaaa]: ");
    scanf("%d/%d/%d", &contat->dia, &contat->mes, &contat->ano);
    __fpurge(stdin);
    barra("", "\n");
    if (contat->dia < 1 || contat->dia > 31 || contat->mes < 1 || contat->mes > 12) {
      printf("\n\033[38;5;196m[Aniversário inválido! Tente novamente...]\033[0m\n");
    }
  } while (contat->dia < 1 || contat->dia > 31 || contat->mes < 1 || contat->mes > 12);
  FILE *arquivo = fopen(nome_arquivo, "ab");
  if (arquivo == NULL) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  fwrite(contat, sizeof(contato), 1, arquivo);
  fclose(arquivo);
  (*ct)++;
  printf("\n\033[38;5;51m[Contato inserido com sucesso!]\033[0m\n");
}

void listar_contatos(contato *contat, int ct) { // [FUNÇÃO DE LISTAR CONTATOS]
  for (int i = 0; i < ct; i++) {
    barra("\n", "\n");
    printf("\033[38;5;51m[%d]> Nome\033[0m\033[38;5;201m: %s\033[0m\n", i + 1, contat[i].nome);
    printf("\033[38;5;51mTelefone\033[0m\033[38;5;201m: %s\033[0m\n", contat[i].telefone);
    printf("\033[38;5;51mAniversário\033[0m\033[38;5;201m: %02d/%02d/%02d\033[0m", contat[i].dia, contat[i].mes, contat[i].ano);
    barra("\n", "\n");
  }
}

int escolh_contato(contato *contat, int ct) { // [FUNÇÃO DE ESCOLHER CONTATO]
  int posi;
  do {
    limpa_tela();
    posi = -1;
    barra("\n", "\n");
    printf("\033[38;5;201m[ESCOLHER CONTATO]\033[0m");
    barra("\n", "\n");
    listar_contatos(contat, ct);
    barra("\n", "\n");
    printf("Opção\033[38;5;51m: ");
    scanf("%d", &posi);
    __fpurge(stdin);
    barra("", "\n");
    if (posi < 1 || posi > ct) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (posi < 1 || posi > ct);
  return --posi;
}

char escolh_letra(contato *contat, int ct) { // [FUNÇÃO DE ESCOLHER LETRA]
  char letra;
  do {
    limpa_tela();
    barra("\n", "\n");
    printf("\033[38;5;201m[ESCOLHER LETRA]\033[0m");
    barra("\n", "\n");
    listar_contatos(contat, ct);
    barra("\n", "\n");
    printf("Letra\033[38;5;51m: ");
    scanf("%c", &letra);
    __fpurge(stdin);
    barra("", "\n");
    if (!isalpha(letra)) {
      printf("\n\033[38;5;196m[Letra inválida! Tente novamente...]\033[0m\n");
    }
  } while (!isalpha(letra));
  return letra;
}

void listar_contatos_letra(contato *contat, int ct) { // [FUNÇÃO DE LISTAR CONTATOS POR LETRA]
  char letra = escolh_letra(contat, ct);
  for (int i = 0; i < ct; i++) {
    if (tolower(contat[i].nome[0]) == tolower(letra)) {
      barra("\n", "\n");
      printf("\033[38;5;51m[%d]> Nome\033[0m\033[38;5;201m: %s\033[0m\n", i + 1, contat[i].nome);
      printf("\033[38;5;51mTelefone\033[0m\033[38;5;201m: %s\033[0m\n", contat[i].telefone);
      printf("\033[38;5;51mAniversário\033[0m\033[38;5;201m: %02d/%02d/%04d\033[0m", contat[i].dia, contat[i].mes, contat[i].ano);
      barra("\n", "\n");
    }
  }  
}

int escolher_mes(contato *contat, int ct) { // [FUNÇÃO DE ESCOLHER MÊS]
  int mes;
  do {
    limpa_tela();
    mes = -1;
    barra("\n", "\n");
    printf("\033[38;5;201m[ESCOLHER MÊS]\033[0m");
    barra("\n", "\n");
    listar_contatos(contat, ct);
    barra("\n", "\n");
    printf("Mês\033[38;5;51m: ");
    scanf("%d", &mes);
    __fpurge(stdin);
    barra("", "\n");
    if (mes < 1 || mes > 12) {
      printf("\n\033[38;5;196m[Mês inválido! Tente novamente...]\033[0m\n");
    }
  } while (mes < 1 || mes > 12);
  return mes;
}

void listar_aniversario(contato *contat, int ct) { // [FUNÇÃO DE LISTAR ANIVERSÁRIOS]
  int mes = escolher_mes(contat, ct);
  for (int i = 0; i < ct; i++) {
    if (contat[i].mes == mes) {
      barra("\n", "\n");
      printf("\033[38;5;51m[%d]> Nome\033[0m\033[38;5;201m: %s\033[0m\n", i + 1, contat[i].nome);
      printf("\033[38;5;51mTelefone\033[0m\033[38;5;201m: %s\033[0m\n", contat[i].telefone);
      printf("\033[38;5;51mAniversário\033[0m\033[38;5;201m: %02d/%02d/%04d\033[0m", contat[i].dia, contat[i].mes, contat[i].ano);
      barra("\n", "\n");   
    }
  }
}

void remover_contato(char *nome_arquivo, contato *contat, int *ct) { // [FUNÇÃO DE REMOVER CONTATO]
  FILE *arquivo = fopen(nome_arquivo, "wb");
  if (!arquivo) {
    printf("\n[Erro ao abrir o arquivo!]\n");
    exit(1);
  }
  int posi = escolh_contato(contat, *ct);
  if (sim_nao()) {
    for (int i = posi; i < *ct - 1; i++) {
      contat[i] = contat[i + 1];
    }
    (*ct)--;
    fwrite(contat, sizeof(contato), *ct, arquivo);
    printf("\n\033[38;5;51m[Contato removido com sucesso!]\033[0m\n");
  }
    else {
      printf("\n\033[38;5;51m[Remoção cancelada!]\033[0m\n");
    }
  fclose(arquivo);
}

void carregar_contatos(char *nome_arquivo, contato **contat, int *ct) { // [FUNÇÃO DE CARREGAR CONTATOS]
  FILE *arquivo = fopen(nome_arquivo, "rb");
  if (!arquivo) {
    printf("\n[Erro ao abrir o arquivo!]\n");
    exit(1);
  }
  int aux = 0;
  contato temp;
  while (fread(&temp, sizeof(contato), 1, arquivo)) {
    aux++;
  }
  rewind(arquivo);
  if (aux > 0) {
    *ct = aux;
    *contat = (contato *) realloc(*contat, *ct * sizeof(contato));
    fread(*contat, sizeof(contato), *ct, arquivo);
    printf("\n\033[38;5;51m[Contatos carregados com sucesso!]\033[0m\n");
  }
    else {
      printf("\n\033[38;5;51m[Nenhum contato carregado!]\033[0m\n");
    }
  fclose(arquivo);
}
  
int main(void) {
  int opcao, ct_contato = 0, loop = 1;
  contato *contat = (contato *) calloc(1, sizeof(contato));
  abrir_arquivo("agenda.bin");
  carregar_contatos("agenda.bin", &contat, &ct_contato);
  if (!contat) {
    printf("\n[Erro ao alocar memória!]\n");
    exit(1);
  }
  while (loop) { 
    opcao = escolh_menu();
    if (opcao == 0) {
      if (sim_nao()) {
        printf("\n\033[38;5;51m[Programa encerrado com sucesso!]\033[0m\n");
        loop = 0;
      }
        else {
          printf("\n\033[38;5;196m[Você cancelou a operação!]\033[0m\n");
        }
    }
      else if (opcao == 1) {
        if (sim_nao()) { 
          contat = (contato *) realloc(contat, (ct_contato + 1) * sizeof(contato));
          inserir_contato("agenda.bin", contat, &ct_contato);
        }
          else {
            printf("\n\033[38;5;196m[Você cancelou a operação!]\033[0m\n");
          }
      }
        else if (opcao == 2) {
          if (ct_contato > 0) {
            remover_contato("agenda.bin", contat, &ct_contato);
          }
            else {
              printf("\n\033[38;5;196m[Não há contatos para remover!]\033[0m\n");
            }     
        }
          else if (opcao == 3) {
            if (ct_contato > 0) {
              int posi = escolh_contato(contat, ct_contato);
              barra("\n", "\n");
              printf("\033[38;5;51mNome\033[0m\033[38;5;201m: %s\033[0m\n", contat[posi].nome);
              printf("\033[38;5;51mTelefone\033[0m\033[38;5;201m: %s\033[0m\n", contat[posi].telefone);
              printf("\033[38;5;51mAniversário\033[0m\033[38;5;201m: %02d/%02d/%04d\033[0m", contat[posi].dia, contat[posi].mes, contat[posi].ano);
              barra("\n", "\n");
            }
              else {
                printf("\n\033[38;5;196m[Não há contatos para pesquisar!]\033[0m\n");
              }
          }
            else if (opcao == 4) {
              if (ct_contato > 0) {
                limpa_tela();
                barra("\n", "\n");
                printf("\033[38;5;201m[LISTA DE CONTATOS]\033[0m");
                barra("\n", "\n");
                listar_contatos(contat, ct_contato);
                barra("\n", "\n");
              }
                else {
                  printf("\n\033[38;5;196m[Não há contatos para listar!]\033[0m\n");
                }
            }
              else if (opcao == 5) {
                if (ct_contato > 0) {
                  listar_contatos_letra(contat, ct_contato);
                }
                  else {
                    printf("\n\033[38;5;196m[Não há contatos para listar!]\033[0m\n");
                  }
              }
                else if (opcao == 6) {
                  if (ct_contato > 0) {
                    listar_aniversario(contat, ct_contato);
                  }
                    else {
                      printf("\n\033[38;5;196m[Não há contatos para listar!]\033[0m\n");
                    }
                }
  }
  free(contat);
  return 0;
}