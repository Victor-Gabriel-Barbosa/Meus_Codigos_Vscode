// 25 - Utilizando uma estrutura, faça um programa que permita a entrada de nome, endereço e telefone de 5 pessoas e os imprima em ordem alfabética.

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define MAX_PESSOAS 2
#define TAM_STRING 100

int main(void) {
  int i, j;
  struct pessoa {
    char nome[TAM_STRING], endereco[TAM_STRING];
    int telefone;
  } p[MAX_PESSOAS], aux;

  for (i = 0; i < MAX_PESSOAS; i++) {
    printf("Digite o nome da pessoa %d: ", i + 1);
    fgets(p[i].nome, TAM_STRING, stdin);
    __fpurge(stdin);
    printf("Digite o endereço da pessoa %d: ", i + 1);
    fgets(p[i].endereco, TAM_STRING, stdin);
    __fpurge(stdin);
    printf("Digite o telefone da pessoa %d: ", i + 1);
    scanf("%d", &p[i].telefone);
    __fpurge(stdin);
  }

  for (i = 0; i < MAX_PESSOAS-1; i++) {
    for (j = i+1; j < MAX_PESSOAS; j++) {
      if (strcmp(p[i].nome, p[j].nome) > 0) {
        aux = p[i];
        p[i] = p[j];
        p[j] = aux;
      }
    }
  }

  printf("\nPessoas em ordem alfabética:\n");
  for (i = 0; i < MAX_PESSOAS; i++) {
    printf("%s", p[i].nome);
    printf("%s", p[i].endereco);
    printf("%d\n\n", p[i].telefone);
  }

  return 0;
}