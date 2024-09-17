#include <stdio.h>

// 20 – Faça um algoritmo que preencha um vetor com dez elementos numéricos, não pode ser inserido valor repetido, o algoritmo deverá informar o usuário se pode ou não inserir o novo valor

int main(void) {
  int vet[10], i, j, loop;
  for (i = 0; i < 10; i++) {
    do {
      loop = 0;
      printf("\nDigite um número [Posição: %d]: ", i);
      scanf("%d", &vet[i]);
      for (j = 0; j < i; j++) {
        if (vet[i] == vet[j]) {
          printf("\n[Número repetido! Tente outro número...]\n");
          loop = 1;
        }
      }
    } while (loop);
  }
        
  return 0;
}