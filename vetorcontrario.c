#include <stdio.h>

void printa_contrario(int vet[], int tam) {
  for (int i = 0; i < tam; i++) {
    printf("%d ", vet[tam - i - 1]);
  }
  printf("\n");
  for (int i = tam - 1; i >= 0; i--) {
    printf("%d ", vet[i]);
  }
}

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
  int tam = 5;
  int vet[tam];
  for (int i = 0; i < tam; i++) {
    printf("Digite o %dº nº: ", i);
    scanf("%d", &vet[i]);
    limpa_buffer();
  }
  printa_contrario(vet, tam);
  return 0;
}