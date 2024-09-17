#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Lista *lista_num = Cria_lista();
  int info;
  char nome_arqv[50];
  do { // Enquanto a lista não estiver cheia e o número for diferente de -1
    printf("Digite um número (Digite -1 p/ sair): ");
    scanf("%d", &info);
    limpa_buffer();
    if (info != -1) { // Se o número for diferente de -1
      lista_num = Insere_elem(lista_num, info);
    }
  } while (!E_cheia(lista_num) && info != -1);
  printf("\nLista: ");
  exibe_lista(lista_num);
  printf("\nDigite um número para remover: ");
  scanf("%d", &info);
  limpa_buffer();
  lista_num = Remove_elem(lista_num, info);
  printf("\nLista: ");
  exibe_lista(lista_num);
  printf("\nDigite o nome de arquivo para salvar a lista: ");
  scanf("%s", nome_arqv);
  limpa_buffer();
  grava_lista(lista_num, nome_arqv);
  lista_num = Libera_lista(lista_num);
  return 0;
}