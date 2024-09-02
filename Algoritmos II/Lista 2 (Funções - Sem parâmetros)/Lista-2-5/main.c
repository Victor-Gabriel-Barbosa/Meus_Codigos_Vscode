/* 05 - Faça uma função que leia uma struct com as informações de nome, sexo e
 * idade de no máximo 10 pessoas. Mostre na função a quantidades de pessoas do
 * sexo masculino e retorne para a função principal a quantidade de pessoas com
 * a idade maior que 15 anos */

#include <stdio.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

int pessoas() { // Função que lê as informações de 10 pessoas
  int i, qtdMasc = 0, qtdMaior = 0;
  struct pessoa { // Cria uma struct p/ armazenar os dados
    char nome[50], sexo;
    int idade;
  } p[10];
  for (i = 0; i < 10; i++) { // Lê as informações
    printf("\nDigite o nome da pessoa %d: ", i + 1);
    fgets(p[i].nome, 50, stdin);
    limpa_buffer();
    printf("Digite o sexo da pessoa %d (M/F): ", i + 1);
    scanf("%c", &p[i].sexo);
    limpa_buffer();
    printf("Digite a idade da pessoa %d: ", i + 1);
    scanf("%d", &p[i].idade);
    limpa_buffer();
  }
  for (i = 0; i < 10; i++) { // Percorre o vetor de structs de pessoas
    if (p[i].sexo == 'M' || p[i].sexo == 'm') { // Verifica se é do sexo masculino
      qtdMasc++;
    }
    if (p[i].idade > 15) { // Verifica se é maior de 15 anos
      qtdMaior++;
    }
  }
  printf("\n[Quantidade de pessoas do sexo masculino: %d]", qtdMasc);
  return qtdMaior;
}

int main(void) {
  printf("\n[Quantidade de pessoas com mais de 15 anos é: %d]", pessoas());
  return 0;
}