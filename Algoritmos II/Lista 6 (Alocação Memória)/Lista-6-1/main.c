/* 1 -  Faça um programa em C que na função principal:
a) Aloque dinamicamente um vetor formado por 5 números inteiros;
b) Peça ao usuário para digitar os 5 números no espaço alocado;
c) Imprima na tela os 5 números digitados;
d) Libere a memória alocada */

#include <stdio.h>
#include <stdlib.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void limpa_tela() { // [FUNÇÃO DE LIMPAR TELA]
  printf("\033[0m\nAperte [\033[38;5;39mENTER\033[0m] para continuar...");
  limpa_buffer();
  #ifdef _WIN32 // Verifica se o sistema é Windows
    system("cls");
  #else // Caso contrário, assume que é um sistema Unix
    system("clear");
  #endif
}

int main() {
  int *vet, tam, i;
  do { // [VALIDAÇÃO DE ENTRADA]
    limpa_tela();
    tam = -1;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    limpa_buffer();
    if (tam < 1) {
      printf("\n\033[0;31mTamanho inválido!\033[0m\n");
    }
  } while (tam < 0);
  vet = (int *)malloc(tam * sizeof(int));
  for (i = 0; i < tam; i++) { // [PREENCHENDO O VETOR]
    printf("Digite um nº [P%d]: ", i + 1);
    scanf("%d", &vet[i]);
    limpa_buffer();
  }
  for (i = 0; i < tam; i++) { // [IMPRIMINDO O VETOR]
    printf("\nPosição %d: %d", i + 1, vet[i]);
  }
  free(vet);
  return 0;
}