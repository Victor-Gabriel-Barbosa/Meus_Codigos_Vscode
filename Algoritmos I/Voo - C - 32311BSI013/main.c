#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shell_sort(int vet[], int tam) { // [FUNÇÃO DE ORDENAÇÃO SHELL SORT]
  int i, j, interv, temp;
  for (interv = tam / 2; interv > 0; interv /= 2) {
    for (i = interv; i < tam; i++) {
      temp = vet[i];
      for (j = i; j >= interv && vet[j - interv] > temp; j -= interv) {
        vet[j] = vet[j - interv];
      }
      vet[j] = temp;
    }
  }
}

void mostrar_vetor(int vet[], int tam) { // [FUNÇÃO DE MOSTRAR O VETOR]
  for (int i = 0; i < tam; i++) {
    printf("%d ", vet[i]);
  }
}

int main() {
  srand(time(NULL));
  int i, tam = 1000000;
  int vetor[tam];
  for (i = 0; i < tam; i++) {
    vetor[i] = tam - i;
  }
  shell_sort(vetor, tam);
  printf("\n\nVetor ordenado: ");
  mostrar_vetor(vetor, tam);
  return 0;
}
