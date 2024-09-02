/* 04 – Faça uma função que verifique a validade de uma senha fornecida pelo
 * usuário. A senha é 4531. O algoritmo deve retornar se existe uma permissão de
 * acesso ou não */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

bool validaSenha(int senha) { // Função que verifica se a senha é válida
  return (senha == 4531);
}

int main(void) {
  bool acesso = false;
  int senha;
  do { // Laço de repetição para verificar se a senha é válida
    printf("\033[0m\nAperte [\033[38;5;39mENTER\033[0m] para continuar...");
    limpa_buffer();
    system("clear");
    printf("Digite a senha: ");
    scanf("%d", &senha);
    limpa_buffer();
    acesso = validaSenha(senha);
    if (!acesso) { // Se a senha não for válida, o usuário é informado
      printf("\n[Acesso negado! Senha incorreta!]\n");
    }
  } while (!acesso);
  if (acesso) { // Se a senha for válida, o usuário tem acesso ao sistema
    printf("\n[Acesso permitido!]\n");
  }
  return 0;
}