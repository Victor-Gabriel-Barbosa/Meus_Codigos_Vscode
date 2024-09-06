/* 10 - Crie uma struct pessoa com nome, idade e sexo. Faça um programa que
 * preencha esta struct com até 100 pessoas. Envie para uma função a struct
 * preenchida e a quantidade de pessoas inseridas e calcule e retorne ao
 * programa principal a média da idade das mulheres inseridas. Mostre o
 * resultado no programa principal */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct pessoa { // Cria a struct pessoa
  char nome[50], sexo;
  int idade;
} p[100];

float media_idade_m(struct pessoa *p, int ct) { // Função que calcula a média da idade das mulheres
  int i, qtd = 0, soma = 0;
  for (i = 0; i < ct; i++) { // Percorre o vetor de pessoas
    if (p[i].sexo == 'F' || p[i].sexo == 'f') { // Verifica se a pessoa é mulher
      soma += p[i].idade;
      qtd++;
    }
  }
  return (float)soma / (float)qtd;
}

int main(void) {
  srand(time(NULL));
  int i, cont = 0;
  float resultado;
  char nome_aux[10][20] = {"José", "Maria", "João", "Ana", "Pedro", "Carlos", "Mariana", "Luca", "Fernanda", "Rafael"};
  char sexo_aux[2] = {'M', 'F'};
  for (i = 0; i < 100; i++) { // Preenche o vetor de pessoas
    strcpy(p[i].nome, nome_aux[rand() % 10]);
    p[i].sexo = sexo_aux[rand() % 2];
    p[i].idade = rand() % 100;
    cont++;
  }
  for (i = 0; i < cont; i++) { // Imprime o vetor de pessoas
    printf("Nome: %s\n", p[i].nome);
    printf("Sexo: %c\n", p[i].sexo);
    printf("Idade: %d\n\n", p[i].idade);
  }
  resultado = media_idade_m(p, cont);
  printf("[A média das idades das mulheres é: %.2f ano(s)]", resultado);
  return 0;
}