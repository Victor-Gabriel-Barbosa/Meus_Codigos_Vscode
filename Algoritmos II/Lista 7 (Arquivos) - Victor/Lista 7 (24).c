/*24 - Implemente um controle simples de mercadorias em uma despensa doméstica. Para cada produto armazene um código numérico, descrição e quantidade atual. O programa deve ter opções para entrada e retirada de produtos, bem como um relatório geral e um de produtos não disponíveis. Armazene os dados em arquivo binário.*/

#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct produtos {
  int cod;
  char desc[100];
  int qtd;
} produt;

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

void mostrar_arquivo(char *nome_arquivo) { // [FUNÇÃO DE MOSTRAR ARQUIVO]
  FILE *arquivo;
  produt prdt;
  arquivo = fopen(nome_arquivo, "rb");
  if (arquivo == NULL) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  while (fread(&prdt, sizeof(produt), 1, arquivo) == 1) {
    printf("\nCódigo: %d\n", prdt.cod);
    printf("Descrição: %s\n", prdt.desc);
    printf("Quantidade: %d\n", prdt.qtd);
  }
  fclose(arquivo);
}

void prdt_disponiveis(char *nome_arquivo) { // [FUNÇÃO DE PRODUTOS DISPONÍVEIS]
  produt prdt;
  FILE *arquivo = fopen(nome_arquivo, "rb");
  if (arquivo == NULL) {
    printf("\n[Erro ao abrir o arquivo]\n");
    exit(1);
  }
  barra("\n", "\n");
  printf("Relatório de Produtos Disponíveis");
  barra("\n", "\n");
  int aux = 0;
  while (fread(&prdt, sizeof(produt), 1, arquivo) == 1) {
    if (prdt.qtd > 0) {
      printf("\nCódigo: %d\n", prdt.cod);
      printf("Descrição: %s\n", prdt.desc);
      printf("Quantidade: %d\n", prdt.qtd);
      aux = 1;
    }
  }
  if (!aux) {
    printf("\nNão há produtos disponíveis\n");
  }
  fclose(arquivo);   
}

void prdt_indisponiveis(char *nome_arquivo) { // [FUNÇÃO DE PRODUTOS INDISPONÍVEIS]
  produt prdt;
  FILE *arquivo = fopen(nome_arquivo, "rb");
  if (arquivo == NULL) {
    printf("\n[Erro ao abrir o arquivo]\n");
    exit(1);
  }
  barra("\n", "\n");
  printf("Relatório de Produtos Indisponíveis");
  barra("\n", "\n");
  int aux = 0;
  while (fread(&prdt, sizeof(produt), 1, arquivo) == 1) {
    if (prdt.qtd == 0) {
      printf("\nCódigo: %d\n", prdt.cod);
      printf("Descrição: %s\n", prdt.desc);
      printf("Quantidade: %d\n", prdt.qtd);
      aux = 1;
    }
  }
  if (!aux) {
    printf("\nNão há produtos indisponíveis\n");
  }
  fclose(arquivo);   
}

int escolh_menu() { // [FUNÇÃO DE ESCOLHA DE MENU]
  int op;
  do {
    limpa_tela();
    op = -1;
    barra("\n", "\n");
    printf("\033[38;5;201m[MENU PRINCIPAL]\033[0m");
    barra("\n", "\n");
    printf("|[\033[38;5;51m1\033[0m]> Cadastrar Produto\n");
    printf("|[\033[38;5;51m2\033[0m]> Retirar Produto\n");
    printf("|[\033[38;5;51m3\033[0m]> Produtos Disponíveis\n");
    printf("|[\033[38;5;51m4\033[0m]> Produtos Indisponíveis");
    barra("\n", "\n");
    printf("|[\033[38;5;51m0\033[0m]> Sair");
    barra("\n", "\n");
    printf("Opção\033[38;5;51m: ");
    scanf("%d", &op);
    __fpurge(stdin);
    barra("", "\n");
    if (op < 0 || op > 4) {
      printf("\n\033[38;5;51m[Opção inválida!]\033[0m\n");
    }
  } while (op < 0 || op > 4);
  return op;
}

void cadastrar_produto(char *nome_arquivo, produt prdt) { // [FUNÇÃO DE CADASTRAR PRODUTO]
  do {
    prdt.cod = -1;
    limpa_tela();
    barra("\n", "\n");
    printf("Cadastrar Produto");
    barra("\n", "\n");
    printf("Código\033[38;5;51m: ");
    scanf("%d", &prdt.cod);
    __fpurge(stdin);
    barra("", "\n");
    if (prdt.cod <= 0) {
      printf("\n\033[38;5;196m[Código inválido!]\033[0m\n");
    }
  } while (prdt.cod <= 0);
  do {
    prdt.desc[0] = ' ';
    limpa_tela();
    barra("\n", "\n");
    printf("Cadastrar Produto");
    barra("\n", "\n");
    printf("Descrição\033[38;5;51m: ");
    scanf("%99[^\n]", prdt.desc);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_str(prdt.desc)) {
      printf("\n\033[38;5;196m[Descrição inválida!]\033[0m\n");
    }
  } while (!ver_str(prdt.desc));
  do {
    prdt.qtd = -1;
    limpa_tela();
    barra("\n", "\n");
    printf("Cadastrar Produto");
    barra("\n", "\n");
    printf("Quantidade\033[38;5;51m: ");
    scanf("%d", &prdt.qtd);
    __fpurge(stdin);
    barra("", "\n");   
    if (prdt.qtd <= 0) {
      printf("\n\033[38;5;196m[Quantidade inválida!]\033[0m\n");
    }
  } while (prdt.qtd <= 0);
  FILE *arquivo = fopen("despensa.bin", "ab");
  if (arquivo == NULL) {
    printf("\n[Erro ao abrir o arquivo]\n");
    exit(1);
  }
  fwrite(&prdt, sizeof(produt), 1, arquivo);      
  fclose(arquivo);
}

void retirar_produto(char *nome_arquivo, produt prdt) { // [FUNÇÃO DE RETIRAR PRODUTO]
  int cod, temp, aux;
  do {
    limpa_tela();
    cod = -1;
    barra("\n", "\n");
    printf("Retirar Produto");
    barra("\n", "\n");
    mostrar_arquivo("despensa.bin");
    barra("\n", "\n");
    printf("Digite o código do produto que deseja retirar\033[38;5;51m: ");
    scanf("%d", &cod);
    __fpurge(stdin);
    barra("", "\n");
    if (cod <= 0) {
      printf("\n\033[38;5;196m[Código inválido!]\033[0m\n");
    }
  } while (cod <= 0);
  FILE *arquivo = fopen("despensa.bin", "rb+");
  if (arquivo == NULL) {
    printf("\n[Erro ao abrir o arquivo]\n");
    exit(1);
  }     
  aux = 0;
  while (fread(&prdt, sizeof(produt), 1, arquivo) == 1) {
    if (prdt.cod == cod) {
      aux = 1;
    }
  }   
  if (aux) {
    if (prdt.qtd > 0) {
      do {
        limpa_tela();
        barra("\n", "\n");
        printf("Retirar Produto");
        barra("\n", "\n");
        printf("Quantidade\033[38;5;51m[MAX.: %d]: ", prdt.qtd);
        scanf("%d", &temp);
        __fpurge(stdin);
        barra("", "\n");
        if (temp <= 0 || temp > prdt.qtd) {
          printf("\n\033[38;5;196m[Quantidade inválida!]\033[0m\n");
        }
      } while (temp <= 0 || temp > prdt.qtd);
      prdt.qtd -= temp; 
      fseek(arquivo, -sizeof(produt), SEEK_CUR);
      fwrite(&prdt, sizeof(produt), 1, arquivo);
      printf("\n\033[38;5;51m[Produto retirado com sucesso!]\033[0m\n");
      fclose(arquivo);   
    }
  }
}

int main(void) {
  abrir_arquivo("despensa.bin");
  produt prdt;
  int cod, aux, temp, loop = 1;
  while (loop) {
    int opcao = escolh_menu();
    if (opcao == 0) {
      if (sim_nao()) {
        loop = 0;
      }
    }
      else if (opcao == 1) { // [CADASTRAR PRODUTO]
        cadastrar_produto("despensa.bin", prdt);
      }
        else if (opcao == 2) { // [RETIRAR PRODUTO]
          retirar_produto("despensa.bin", prdt);
        }
          else if (opcao == 3) { // [PRODUTOS DISPONÍVEIS]
            limpa_tela();
            prdt_disponiveis("despensa.bin");
          }
            else if (opcao == 4) { // [PRODUTOS INDISPONÍVEIS]
              limpa_tela();
              prdt_indisponiveis("despensa.bin");
            }
  }
  return 0;
}