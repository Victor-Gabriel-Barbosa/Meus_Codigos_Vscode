/* 20 – Faça um algoritmo que preencha um vetor com dez elementos numéricos, não
 * pode ser inserido valor repetido, o algoritmo deverá informar o usuário se
 * pode ou não inserir o novo valor */

#include <stdio.h>

int main(void) {
  int vet[10], i, j, loop;
  for (i = 0; i < 10; i++) { // Preenche o vetor
    do {
      loop = 0;
      printf("\nDigite um número [Posição: %d]: ", i);
      scanf("%d", &vet[i]);
      for (j = 0; j < i; j++) { // Verifica se o número já foi inserido
        if (vet[i] == vet[j]) { // ...
          printf("\n[Número repetido! Tente outro número...]\n");
          loop = 1;
        }
      }
    } while (loop);
  }
  printf("\nVetor: ");
  for (i = 0; i < 10; i++) { // Imprime o vetor
    printf(i == 0 ? "%d" : ", %d", vet[i]);
  }
  return 0;
}