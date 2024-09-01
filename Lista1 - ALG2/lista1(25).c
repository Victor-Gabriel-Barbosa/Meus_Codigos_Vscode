/* 25 - Utilizando uma estrutura, faça um programa que permita a entrada de
 * nome, endereço e telefone de 5 pessoas e os imprima em ordem alfabética */

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

int main(void) {
  int qtde_p = 2, i, j;
  struct pessoa { // Cria uma estrutura p/ armazenar os dados de uma pessoa
    char nome[100], endereco[100];
    int telefone;
  } p[qtde_p], aux;
  for (i = 0; i < qtde_p; i++) { // Loop p/ entrada de dados
    printf("Digite o nome da pessoa %d: ", i + 1);
    fgets(p[i].nome, 100, stdin);
    __fpurge(stdin);
    printf("Digite o endereço da pessoa %d: ", i + 1);
    fgets(p[i].endereco, 100, stdin);
    __fpurge(stdin);
    printf("Digite o telefone da pessoa %d: ", i + 1);
    scanf("%d", &p[i].telefone);
    __fpurge(stdin);
  }
  for (i = 0; i < qtde_p - 1; i++) {          // Loop p/ ordenação
    for (j = i + 1; j < qtde_p; j++) {        // ...
      if (strcmp(p[i].nome, p[j].nome) > 0) { // Compara os nomes
        aux = p[i];
        p[i] = p[j];
        p[j] = aux;
      }
    }
  }
  printf("\nPessoas em ordem alfabética:\n");
  for (i = 0; i < qtde_p; i++) { // Loop p/ impressão
    printf("%s", p[i].nome);
    printf("%s", p[i].endereco);
    printf("%d\n\n", p[i].telefone);
  }
  return 0;
}