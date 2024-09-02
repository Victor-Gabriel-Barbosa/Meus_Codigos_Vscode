/* 1 – Faça uma função que receba 3 números e retorne para o programa principal
 * os 3 números em ordem crescente. Mostre o resultado no programa principal */

#include <stdio.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void reordena(int vet[]) { // Função que recebe um vetor de inteiros e ordena os valores em ordem crescente
  int temp, i, j;
  for (j = 0; j < 2; j++) {   // Loop de reordenação 'Buble Sort'
    for (i = 0; i < 3; i++) { // Percorre o vetor
      if (i + 1 < 3 && vet[i] > vet[i + 1]) { // Se o próximo valor for menor que o atual, troca os valores
        temp = vet[i];
        vet[i] = vet[i + 1];
        vet[i + 1] = temp;
      }
    }
  }
}

int main(void) {
  int vet[3], i;
  for (i = 0; i < 3; i++) { // Preenche o vetor
    printf("Digite o %d° Nº: ", i + 1);
    scanf("%d", &vet[i]);
    limpa_buffer();
  }
  printf("\n}>Nºs ANTES- DA ORDENAÇÃO: ");
  for (i = 0; i < 3; i++) { // Imprime o vetor
    printf(i == 0 ? "%d" : ", %d", vet[i]);
  }
  reordena(vet);
  printf("\n}>Nºs DEPOIS DA ORDENAÇÃO: ");
  for (i = 0; i < 3; i++) { // Imprime o vetor ordenado
    printf(i == 0 ? "%d" : ", %d", vet[i]);
  }
  return 0;
}