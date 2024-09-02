/* 3 - Codifique, compile e execute um programa em C que defina uma estrutura
 * para armazenar um cadastro de cliente: nome, idade e telefone. Pergunte ao
 * usuário o número de clientes e aloque dinamicamente na memória a quantidade
 * de estruturas necessárias. Em seguida, crie duas funções: a primeira deverá
 * ler os dados dos clientes e a segunda imprimir as informações cadastradas */

#include <stdio.h>
#include <stdlib.h>

typedef struct cliente { // Estrutura p/ armazenar os dados dos clientes
  char nome[50];
  int idade, telefone;
} client;

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void limpa_tela() { // [FUNÇÃO DE LIMPAR TELA]
  printf("\033[0m\nAperte [\033[38;5;39mENTER\033[0m] para continuar...");
  limpa_buffer();
  #ifdef _WIN32 // Verifica se o sistema é Windows
    system("cls");
  #else // Caso contrário, assume que é um sistema Unix
    system("clear");
  #endif 
}

void ler(client *c, int tam) { // [FUNÇÃO DE LER OS DADOS DOS CLIENTES]
  for (int i = 0; i < tam; i++) { // [LAÇO PARA LER OS DADOS DOS CLIENTES]
    limpa_tela();
    printf("Digite o nome do cliente %d: ", i + 1);
    scanf("%49[^\n]", c[i].nome);
    limpa_buffer();
    printf("Digite a idade do cliente %d: ", i + 1);
    scanf("%d", &c[i].idade);
    limpa_buffer();
    printf("Digite o telefone do cliente %d: ", i + 1);
    scanf("%d", &c[i].telefone);
    limpa_buffer();
  }
}

void imprimir(client *c, int tam) { // [FUNÇÃO DE IMPRIMIR OS DADOS DOS CLIENTES]
  limpa_tela();
  for (int i = 0; i < tam; i++) { // [LAÇO PARA IMPRIMIR OS DADOS DOS CLIENTES]
    printf("[Cliente %d]\n", i + 1);
    printf("Nome: %s\n", c[i].nome);
    printf("Idade: %d\n", c[i].idade);
    printf("Telefone: %d\n\n", c[i].telefone);
  }
}

int main(void) {
  int qtd, i, j;
  do { // [VALIDAÇÃO DA QUANTIDADE DE CLIENTES]
    limpa_tela();
    qtd = -1;
    printf("Digite a quantidade de clientes: ");
    scanf("%d", &qtd);
    limpa_buffer();
    if (qtd < 1) { // [MENSAGEM DE ERRO]
      printf("\n\033[0;31m[ERRO]\033[0m Digite um valor válido!\n");
    }
  } while (qtd < 1);
  client *cl = (client *) calloc(qtd, sizeof(client));
  ler(cl, qtd);
  imprimir(cl, qtd);
  free(cl);
  return 0;
}