/* 9 – Faça um algoritmo que leia um número N e que indique quantos valores inteiros e positivos devem ser lidos a seguir. Para cada valor lido, mostre uma tabela contendo o valor lido e o fatorial desse valor */
#include <stdio.h>

int main(void) {
  int N, fator, i, j, num;
  printf("Digite a quantidade de números que serão lidos: ");
  scanf("%d", &N);
  while (N > 0) { // 
    fator = 1;
    do {
      printf("\nDigite um número positivo: ");
      scanf("%d", &num);
      if (num < 0) {
        printf("\n[Número inválido! Digite novamente...]\n");
      }
    } while (num < 0);
    for (i = 1; i <= num; i++) {
      fator = fator * i;
    }
    printf("O fatorial de %d é %d\n", num, fator);
    N--;
  }
  return 0;
}