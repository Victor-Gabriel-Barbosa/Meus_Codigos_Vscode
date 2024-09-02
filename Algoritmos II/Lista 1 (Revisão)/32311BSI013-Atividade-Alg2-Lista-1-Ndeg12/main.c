/* 12 – Criar um algoritmo que receba a idade o estado civil (C – casado, S – solteiro, V – viúvo e D – desquitado ou separado) de várias pessoas. Calcule e imprima:
 A quantidade de pessoas casadas;
 A quantidade de pessoas solteiras;
 A média das idades das pessoas viúvas;
 A porcentagem de pessoas desquitadas ou separadas dentre todas as pessoas
analisadas.
O algoritmo acaba quando se digita um número menor do que O para idade */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int tam = 100, idade, sair = 1, cont = 0, cont_casados = 0, cont_solteiros = 0, cont_viuvas = 0, cont_separado = 0;
  int soma_idade_viuvas = 0;
  float media_idade_viuvas = 0.0, porcentagem_desquitados;
  char estado[tam];
  while (sair != 0) { // Loop para receber as idades
    printf("\nDigite a idade (ou um número menor que 0 para sair): ");
    scanf("%d", &idade);
    if (idade < 0) { // Condição para sair do loop
      sair = 0;
      continue;
    }
    do { // Loop para receber o estado civil
      printf("\nDigite o estado civil: ");
      printf("\n[C – Casado(a)] \n[S – Solteiro(a)] \n[V – Viúvo(a)] \n[D – Desquitado(a) ou Separado(a)]\n: ");
      fgets(estado, tam, stdin);
      estado[strcspn(estado, "\n")] = 0; // Remove o \n do final da string
      if (strcasecmp(estado, "C") == 0) { // Casado
        cont_casados++;
      } else if (strcasecmp(estado, "S") == 0) { // Solteiro
        cont_solteiros++;
      } else if (strcasecmp(estado, "V") == 0) { // Viúvo
        cont_viuvas++;
        soma_idade_viuvas += idade;
      } else if (strcasecmp(estado, "D") == 0) { // Desquitado ou separado
        cont_separado++;
      }
    } while (strcasecmp(estado, "C") && strcasecmp(estado, "S") && strcasecmp(estado, "V") && strcasecmp(estado, "D"));
    cont++; // Incrementa o contador de pessoas
  }
  if (cont_viuvas > 0) { // Verifica se há pessoas viúvas
    media_idade_viuvas = (float) soma_idade_viuvas / cont_viuvas; // Calcula a média das idades das pessoas viúvas
  }
  if (cont > 0) { // Verifica se há pessoas para calcular a porcentagem
    porcentagem_desquitados = ((float) cont_separado / cont) * 100; // Calcula a porcentagem de pessoas desquitadas ou separadas
  }
  printf("\nA quantidade de pessoas casadas é: %d", cont_casados);
  printf("\nA quantidade de pessoas solteiras é: %d", cont_solteiros);
  if (cont_viuvas > 0) { // Verifica se há pessoas viúvas
    printf("\nA média das idades das pessoas viúvas é: %.2f", media_idade_viuvas);
  } else { 
    printf("\nNão há pessoas viúvas cadastradas");
  }
  printf("\nA porcentagem de pessoas desquitadas ou separadas dentre todas as pessoas analisadas é: %.2f%%", porcentagem_desquitados);
  return 0;
}
