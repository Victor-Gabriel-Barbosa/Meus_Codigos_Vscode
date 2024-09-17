/*
12 – Criar um algoritmo que receba a idade o estado civil (C – casado, S – solteiro, V – viúvo
e D – desquitado ou separado) de várias pessoas. Calcule e imprima:
 A quantidade de pessoas casadas;
 A quantidade de pessoas solteiras;
 A média das idades das pessoas viúvas;
 A porcentagem de pessoas desquitadas ou separadas dentre todas as pessoas
analisadas.
O algoritmo acaba quando se digita um número menor do que O para idade. 
  */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define TAM 100

int main(void) {
  int idade[TAM], sair = 1, cont = 0, cont_casados = 0, cont_solteiros = 0, cont_viuvas = 0, cont_separado;
  int soma_idade_viuvas = 0, soma_idade_separados = 0, total_idades = 0;
  float media_idade_viuvas = 0, porcentagem_desquitados;
  char estado[TAM];
  while (sair != 0) {
    printf("\nDigite a idade: ");
    scanf("%d", &idade[cont]);
    if (idade[cont] == 0) {
      sair = 0;
    } 
      else {
        total_idades += idade[cont];
        do {
          __fpurge(stdin);
          printf("\nDigite o estado civil: ");
          printf("\n[C – Casado(a)] \n[S – Solteiro(a)] \n[V – Viúvo(a)] \n[D – Desquitado(a) ou Separado(a)]\n:");
          fgets(estado, TAM, stdin);
          __fpurge(stdin);
          estado[strcspn(estado, "\n")] = 0;
          if (strcasecmp(estado, "C") == 0)
            cont_casados++;
          else if (strcasecmp(estado, "S") == 0) {
            cont_solteiros++;
            soma_idade_separados += idade[cont];
          }
          else if (strcasecmp(estado, "V") == 0) {
            cont_viuvas++;
            soma_idade_viuvas += idade[cont];
          }
          else if (strcasecmp(estado, "D") == 0)
            cont_separado++;
        } while (estado[0] != 'C' && estado[0] != 'S' && estado[0] != 'V' && estado[0] != 'D');
        cont++;
      }
    }
  media_idade_viuvas = soma_idade_viuvas / cont_viuvas;
  porcentagem_desquitados = soma_idade_separados / total_idades;
  printf("\nA quantidade de pessoas casadas é: %d", cont_casados);
  printf("\nA quantidade de pessoas solteiras é: %d", cont_solteiros);
  printf("\nA média das idades das pessoas viúvas é: %2.f", media_idade_viuvas);
  printf("\nA porcentagem de pessoas desquitadas ou separadas dentre todas as pessoas analisadas é: %2.f porcento", porcentagem_desquitados * 100); 
  return 0;
}