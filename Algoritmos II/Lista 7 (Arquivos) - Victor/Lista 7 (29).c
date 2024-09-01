/*29 - Codifique um programa que manipule um arquivo contendo registros descritos pelos seguintes campos: código vendedor, nome vendedor, valor da venda e mês. A manipulação do arquivo em questão é feita através da execução das operações disponibilizadas pelo seguinte menu:
  • Criar o arquivo de dados;
  • Incluir um determinado registro no arquivo;
  • Excluir um determinado vendedor no arquivo;
  • Alterar o valor de uma venda no arquivo;
  • Imprimir os registros na saída padrão;
  • Excluir o arquivo de dados;
  • Finalizar o programa.
  Os registros devem estar ordenados no arquivo, de forma crescente, de acordo com as informações contidas nos campos codigo vendedor e mês. Não deve existir mais de um registro no arquivo com mesmos valores nos campos código vendedor e mês.*/

#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct vendedores {
  int codigo;
  char nome[30];
  float valor;
  int mes;
} vendedor;

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

int escolh_menu() { // [FUNÇÃO DE ESCOLHA DO MENU]
  int op;
  do {
    limpa_tela();
    op = -1;
    barra("\n", "\n");
    printf("\033[38;5;201m[MENU]\033[0m");
    barra("\n", "\n");
    printf("|[\033[38;5;51m1\033[0m]> Criar arquivos\n");
    printf("|[\033[38;5;51m2\033[0m]> Cadastrar vendedor\n");
    printf("|[\033[38;5;51m3\033[0m]> Incluir registro\n");
    printf("|[\033[38;5;51m4\033[0m]> Excluir registro\n");
    printf("|[\033[38;5;51m5\033[0m]> Alterar registro\n");
    printf("|[\033[38;5;51m6\033[0m]> Imprimir registros\n");
    printf("|[\033[38;5;51m7\033[0m]> Excluir arquivos");
    barra("\n", "\n");
    printf("|[\033[38;5;51m0\033[0m]> Sair");
    barra("\n", "\n");
    printf("Opção\033[38;5;51m: ");
    scanf("%d", &op);
    __fpurge(stdin);
    barra("", "\n");
    if (op < 0 || op > 7) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (op < 0 || op > 7);
  return op;
}

void criar_arquivo(char *nome_arquivo) { // [FUNÇÃO DE CRIAR ARQUIVO]
  FILE *arq = fopen(nome_arquivo, "ab");
  if (!arq) {
    printf("\n\033[38;5;196m[Arquivo não encontrado!]\033[0m\n");
    exit(1);
  }
  fclose(arq);
  printf("\n\033[38;5;51m[Arquivo criado com sucesso!]\033[0m\n");
}

int ver_cod_repetido(vendedor *vend, int cod, int ct) { // [FUNÇÃO DE VERIFICAR SE O CÓDIGO JÁ EXISTE]
  for (int i = 0; i < ct; i++) {
    if (vend[i].codigo == cod) {
      return 1;
    }
  }
  return 0;
}

int ver_mes_repetido(vendedor *vend, int mes, int ct) { // [FUNÇÃO DE VERIFICAR SE O MÊS JÁ EXISTE]
  for (int i = 0; i < ct; i++) {
    if (vend[i].mes == mes) {
      return 1;
    }
  }
  return 0;
}

void cadastrar_vendedor(vendedor *aux, vendedor *vend, int *ct) { // [FUNÇÃO DE CADASTRAR VENDEDOR]
  do {
    limpa_tela();
    vend->codigo = -1;
    barra("\n", "\n");
    printf("\033[38;5;201m[CADASTRO DE VENDEDOR]\033[0m");
    barra("\n", "\n");
    printf("Código\033[38;5;51m: ");
    scanf("%d", &vend->codigo);
    __fpurge(stdin);
    barra("", "\n");
    if (vend->codigo <= 0) {
      printf("\n\033[38;5;196m[Código inválido! Tente novamente...]\033[0m\n");
    }
    if (ver_cod_repetido(aux, vend->codigo, *ct)) {
      printf("\n\033[38;5;196m[Código já cadastrado! Tente novamente...]\033[0m\n");
    }
  } while (vend->codigo <= 0 || ver_cod_repetido(aux, vend->codigo, *ct));
  do {
    limpa_tela();
    barra("\n", "\n");
    printf("\033[38;5;201m[CADASTRO DE VENDEDOR]\033[0m");
    barra("\n", "\n");
    printf("Nome\033[38;5;51m: ");
    scanf("%29[^\n]", vend->nome);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_str(vend->nome)) {
      printf("\n\033[38;5;196m[Nome inválido! Tente novamente...]\033[0m\n");
    } 
  } while (!ver_str(vend->nome));
  do {
    limpa_tela();
    vend->valor = -1;
    barra("\n", "\n");
    printf("\033[38;5;201m[CADASTRO DE VENDEDOR]\033[0m");
    barra("\n", "\n");
    printf("Valor vendido\033[38;5;51m$: ");
    scanf("%f", &vend->valor);
    __fpurge(stdin);
    barra("", "\n");
    if (vend->valor <= 0) {
      printf("\n\033[38;5;196m[Valor inválido! Tente novamente...]\033[0m\n");
    }
  } while (vend->valor <= 0);
  do {
    limpa_tela();
    vend->mes = -1;
    barra("\n", "\n");
    printf("\033[38;5;201m[CADASTRO DE VENDEDOR]\033[0m");
    barra("\n", "\n");
    printf("Mês\033[38;5;51m: ");
    scanf("%d", &vend->mes);
    __fpurge(stdin);
    barra("", "\n");
    if (vend->mes < 1 || vend->mes > 12) {
      printf("\n\033[38;5;196m[Mês inválido! Tente novamente...]\033[0m\n");
    }
    if (ver_mes_repetido(aux, vend->mes, *ct)) {
      printf("\n\033[38;5;196m[Mês já cadastrado! Tente novamente...]\033[0m\n");
    }
  } while (vend->mes < 1 || vend->mes > 12 || ver_mes_repetido(aux, vend->mes, *ct));
  (*ct)++;
  printf("\n\033[38;5;51m[Vendedor cadastrado com sucesso!]\033[0m\n");
}

int escolh_vendedor(vendedor *vend, int ct) { // [FUNÇÃO DE ESCOLHER VENDEDOR]
  int posi;
  do {
    limpa_tela();
    posi = -1;
    barra("\n", "\n");
    printf("\033[38;5;201m[ESCOLHA O VENDEDOR]\033[0m");
    barra("\n", "\n");
    for (int i = 0; i < ct; i++) {
      printf("|[\033[38;5;51m%d\033[0m]> %s\n", i + 1, vend[i].nome);
    }
    barra("", "\n");
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

void salvar_vendedor(char *nome_arqv, vendedor *vend, int ct) { // [FUNÇÃO DE SALVAR VENDEDOR]
  FILE *arq = fopen(nome_arqv, "ab");
  if (!arq) {
    printf("\n\033[38;5;196m[Arquivo não encontrado!]\033[0m\n");
    exit(1);
  }
  int posi = escolh_vendedor(vend, ct);
  if (sim_nao()) {
    fwrite(&vend[posi], sizeof(vendedor), 1, arq);
    printf("\n\033[38;5;51m[Vendedor salvo com sucesso!]\033[0m\n");
  }
    else {
      printf("\n\033[38;5;51m[Vendedor não salvo!]\033[0m\n");
    }
  fclose(arq);
}

void excl_registro(char *nome_arqv, vendedor *vend, int *ct) { // [FUNÇÃO DE EXCLUIR REGISTRO]
  FILE *arq = fopen(nome_arqv, "wb");
  if (!arq) {
    printf("\n\033[38;5;196m[Arquivo não encontrado!]\033[0m\n");
    exit(1);
  }
  int posi = escolh_vendedor(vend, *ct);
  if (sim_nao()) {
    for (int i = posi; i < *ct - 1; i++) {
      vend[i] = vend[i + 1];
    }
    (*ct)--;
    fwrite(vend, sizeof(vendedor), *ct, arq);
    printf("\n\033[38;5;51m[Registro excluído com sucesso!]\033[0m\n");
  }
    else {
      printf("\n\033[38;5;51m[Registro não excluído!]\033[0m\n");
    }
  fclose(arq);
}

void alterar_venda(char *nome_arqv, vendedor *vend, int ct) { // [FUNÇÃO DE ALTERAR VENDA]
  FILE *arq = fopen(nome_arqv, "wb");
  if (!arq) {
    printf("\n\033[38;5;196m[Arquivo não encontrado!]\033[0m\n");
    exit(1);
  }
  int posi = escolh_vendedor(vend, ct);
  if (sim_nao()) {
    do {
      limpa_tela();
      vend[posi].valor = -1;
      barra("\n", "\n");
      printf("\033[38;5;201m[ALTERAR VALOR DA VENDA]\033[0m");
      barra("\n", "\n");
      printf("Valor vendido\033[38;5;51m$: ");
      scanf("%f", &vend[posi].valor);
      __fpurge(stdin);
      barra("", "\n");
      if (vend[posi].valor <= 0) {
        printf("\n\033[38;5;196m[Valor inválido! Tente novamente...]\033[0m\n");
      }
    } while (vend[posi].valor <= 0);
    fwrite(vend, sizeof(vendedor), ct, arq);
    printf("\n\033[38;5;51m[Valor alterado com sucesso!]\033[0m\n");
  }
    else {
      printf("\n\033[38;5;51m[Valor não alterado!]\033[0m\n");
    }
  fclose(arq);
}

void imprimir_registro(char *nome_arqv) { // [FUNÇÃO DE IMPRIMIR REGISTRO]
  FILE *arq = fopen(nome_arqv, "rb");
  vendedor temp;
  if (!arq) {
    printf("\n\033[38;5;196m[Arquivo não encontrado!]\033[0m\n");
    exit(1);
  }
  barra("\n", "\n");
  printf("\033[38;5;201m[REGISTROS]\033[0m");
  barra("\n", "\n");
  while (fread(&temp, sizeof(vendedor), 1, arq)) {
    barra("\n", "\n");
    printf("Código\033[38;5;51m: %d\033[0m\n", temp.codigo);
    printf("Nome\033[38;5;51m: %s\033[0m\n", temp.nome);
    printf("Valor vendido\033[38;5;51m$: %.2f\033[0m\n", temp.valor);
    printf("Mês\033[38;5;51m: %d\033[0m", temp.mes);
    barra("\n", "\n");
  }
  fclose(arq);
}

void carregar_registros(char *nome_arqv, vendedor **vend, int *ct) { // [FUNÇÃO DE CARREGAR REGISTROS]
  FILE *arq = fopen(nome_arqv, "rb");
  int aux = 0;
  if (!arq) {
    printf("\n\033[38;5;196m[Arquivo não encontrado!]\033[0m\n");
    exit(1);
  }
  vendedor temp;
  while (fread(&temp, sizeof(vendedor), 1, arq)) {
    aux++;   
  }
  rewind(arq);
  if (aux > 0) {
    *ct = aux;
    *vend = (vendedor *) realloc(*vend, *ct * sizeof(vendedor));
    for (int i = 0; i < *ct; i++) {
      fread(&(*vend)[i], sizeof(vendedor), 1, arq);
    }
    printf("\n\033[38;5;51m[Registros carregados com sucesso!]\033[0m\n");
  }
  fclose(arq); 
}

void excl_arquivo(char *nome_arqv) { // [FUNÇÃO DE EXCLUIR ARQUIVO]
  if (sim_nao()) {
    if (remove(nome_arqv) == 0) {
      printf("\n\033[38;5;51m[Arquivo excluído com sucesso!]\033[0m\n");
    }
      else {
        printf("\n\033[38;5;196m[Arquivo não encontrado!]\033[0m\n");
      }
  }
    else {
      printf("\n\033[38;5;51m[Arquivo não excluído!]\033[0m\n");
    }
}

int main(void) {
  vendedor *vend = (vendedor *) calloc(1, sizeof(vendedor));
  int opcao, ct_vend = 0, loop = 1;
  criar_arquivo("vendedores.bin");
  carregar_registros("vendedores.bin", &vend, &ct_vend);
  while (loop) {
    opcao = escolh_menu();
    if (opcao == 0) {
      if (sim_nao()) {
        printf("\n\033[38;5;196m[Programa finalizado com sucesso!]\033[0m\n");
        loop = 0;
      }
        else {
          printf("\n\033[38;5;196m[Voltando...]\033[0m\n");
        }
    }
      else if (opcao == 1) {
        if (sim_nao()) {
          criar_arquivo("vendedores.bin");
        }
          else {
            printf("\n\033[38;5;196m[Voltando...]\033[0m\n");
          }
      }
        else if (opcao == 2) {
          if (sim_nao()) {
            vend = (vendedor *) realloc(vend, (ct_vend + 1) * sizeof(vendedor));
            if (!vend) {
              printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
              exit(1);
            }
            cadastrar_vendedor(vend, &vend[ct_vend], &ct_vend);
          }
            else {
              printf("\n\033[38;5;196m[Voltando...]\033[0m\n");
            }
        }
          else if (opcao == 3) {
            if (ct_vend > 0) {
              salvar_vendedor("vendedores.bin", vend, ct_vend);
            }
              else {
                printf("\n\033[38;5;196m[Não há vendedores cadastrados!]\033[0m\n");
              }
          }
            else if (opcao == 4) {
              if (ct_vend > 0) {
                excl_registro("vendedores.bin", vend, &ct_vend);
              }
                else {
                  printf("\n\033[38;5;196m[Não há registros para excluir!]\033[0m\n");
                }
            }
              else if (opcao == 5) {
                if (ct_vend > 0) {
                  alterar_venda("vendedores.bin", vend, ct_vend);
                }
                  else {
                    printf("\n\033[38;5;196m[Não há registros para alterar!]\033[0m\n");
                  }
              }
                else if (opcao == 6) {
                  limpa_tela();
                  imprimir_registro("vendedores.bin");
                }
                  else if (opcao == 7) {
                    excl_arquivo("vendedores.bin");
                  }
  }
  free(vend);
  return 0;
}