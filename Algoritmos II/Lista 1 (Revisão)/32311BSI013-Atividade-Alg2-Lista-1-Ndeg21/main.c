/* 21 - Faça um algoritmo para apagar valores de um vetor de no máximo cem
 * valores numéricos. O usuário digita um valor e o algoritmo deve apagar e
 * reorganizar o vetor */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
  srand(time(0)); //
  int vet[10], i, j, n, loop, tam_vet = 10;
  for (i = 0; i < tam_vet; i++) { // Preenche o vetor com valores aleatórios
    vet[i] = (rand() % 201) - 100; // Gera valores entre -100 e 100
  }
  printf("Vetor original: ");
  for (i = 0; i < tam_vet; i++) { // Imprime o vetor original
    printf(i == 0 ? "%d" : ", %d", vet[i]);
  }
  do { // Loop para apagar valores
    loop = 1;
    printf("\nDigite um número para excluir: ");
    scanf("%d", &n);
    limpa_buffer();
    for (i = 0; i < tam_vet; i++) {
      if (vet[i] == n) {
        loop = 0;
      }
    }
    if (loop)
      printf("\n[Número não encontrado no vetor! Digite um número que esteja no vetor...]\n");
  } while (loop);
  for (i = 0; i < tam_vet; i++) { // Loop para apagar o valor
    if (vet[i] == n) { // Verifica se o valor é igual ao número digitado
      tam_vet--;
      for (j = i; j < tam_vet; j++) { // Loop para apagar o valor
        vet[j] = vet[j + 1];
      }
    }
  }
  printf("\nVetor após apagar o valor: ");
  for (i = 0; i < tam_vet; i++) { // Imprime o vetor após apagar o valor
    printf(i == 0 ? "%d" : ", %d", vet[i]);
  }
  return 0;
}