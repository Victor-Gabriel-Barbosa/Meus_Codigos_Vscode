#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const char *rset = "\033[0m";
const char *azul = "\033[38;5;39m";
const char *verd = "\033[38;5;46m";
const char *cian = "\033[38;5;51m";
const char *verm = "\033[38;5;196m";
const char *mage = "\033[38;5;201m";
const char *amar = "\033[38;5;220m";

/* Limpa o buffer do terminal */
void limpa_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

/* Limpa a tela do terminal */
void limpa_tela() {
  printf("%s\nAperte %s[ENTER]%s p/ continuar...", rset, azul, rset);
  limpa_buffer();
  if (system("clear") && system("cls")) { // Tenta limpar a tela do terminal
    perror("\n\033[38;5;196m[Erro ao limpar a tela!]\033[0m\n");
    exit(EXIT_FAILURE);
  }
}

/* Exibe uma barra de divisão */
void barra_div(const char *ini, const char *fin) {
  printf("%s%s<>%s==============%s<>%s==============%s<>%s%s", ini, cian, rset, mage, rset, cian, rset, fin);
}

/* Solicita e retorna um número inteiro do usuário */
int get_num(const char *msg) {
  int val;
  printf("%s: ", msg);
  scanf("%d", &val);
  limpa_buffer();
  return val;
}

/* Solicita e retorna uma string do usuário */
char *get_str(const char *msg) {
  char *str = NULL;
  size_t tam, comp;
  printf("%s: ", msg);
  comp = getline(&str, &tam, stdin);
  if (comp == -1) { // Verifica se houve um erro ao ler a string
    perror("\n\033[38;5;196m[Erro ao ler a string!]\033[0m\n");
    exit(EXIT_FAILURE);
  }
  str[strcspn(str, "\n")] = '\0';
  return str;
}

/* Solicita e retorna a confirmação de uma ação do usuário */
bool sim_ou_nao(char *msg) {
  char *resp = NULL;
  bool loop = true;
  do { // Loop para garantir que a resposta seja válida
    limpa_tela();
    barra_div("", "\n");
    printf("%s\n", msg);
    barra_div("", "\n");
    resp = get_str("[S|N]");
    barra_div("", "\n");
    loop = (!strcasestr(resp, "s") && !strcasestr(resp, "n") &&
            !strcasestr(resp, "1") && !strcasestr(resp, "0"));
    if (loop) // Verifica se a resposta é válida
      printf("\n%s[Resposta inválida!]%s\n", verm, rset);
    printf("%s\n", resp);
  } while (loop);
  return (strcasestr(resp, "s") || strcasestr(resp, "1"));
}

int main() {
  barra_div("", "\n");
  int num = get_num("Digite um número inteiro");
  barra_div("", "\n");
  if (sim_ou_nao("Você gosta de programação?")) {
    printf("\n%s[Legal!]%s\n", verd, rset);
  } else {
    printf("\n%s[Que pena!]%s\n", verm, rset);
  }
  limpa_tela();
  return 0;
}