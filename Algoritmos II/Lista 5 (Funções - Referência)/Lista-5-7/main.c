/* 7 - Desenvolva um programa que primeiro utilize uma função para gerar um
 * vetor com tamanho definido pelo usuário e valores aleatórios dentro de um
 * intervalo [min, max] determinado pelo usuário. Em seguida, uma outra função
 * deve receber o vetor gerado, o tamanho do vetor e dois números maior e menor.
 * Retorne nas variáveis maior e menor o menor e maior elemento do vetor. Dica1:
 * menor e maior devem ser passados por referência. Dica2: use apenas uma
 * estrutura de repetição para achar o menor e maior elemento */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

int tamanho_vetor() { // [CRIA O VETOR]
  int tam;
  do { // [VALIDAÇÃO]
    printf("\033[0m\nAperte [\033[38;5;39mENTER\033[0m] para continuar...");
    getchar();
    limpa_buffer();
    system("clear");
    printf("\n=============[ GERAR VETOR ]=============\n");
    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &tam);
    limpa_buffer();
    printf("\n=========================================\n");
    if (tam <= 0) { // [VALIDAÇÃO]
      printf("\n[Tamanho inválido! Tente novamente...]\n");
    }
  } while (tam <= 0);
  return tam;
}

void maior_menor(int *vetor, int tamanho, int *maior, int *menor) { // [FUNÇÃO QUE RETORNA O MAIOR E MENOR VALOR DO VETOR]
  int i;
  *maior = vetor[0];
  *menor = vetor[0];
  for (i = 0; i < tamanho; i++) { // [LAÇO PARA ACHAR O MAIOR E MENOR VALOR DO VETOR]
    if (vetor[i] > *maior) { // [MAIOR VALOR]
      *maior = vetor[i];
    }
    if (vetor[i] < *menor) { // [MENOR VALOR]
      *menor = vetor[i];
    }
  }
}

void gerar_vetor(int tam, int *vet) { // [FUNÇÃO QUE GERA O VETOR]
  int i, j, min, max;
  do { // [VALIDAÇÃO]
    printf("\033[0m\nAperte [\033[38;5;39mENTER\033[0m] para continuar...");
    getchar();
    limpa_buffer();
    system("clear");
    printf("\n==============[ Intervalo ]==============\n");
    printf("\nDigite o valor mínimo a ser sorteado: ");
    scanf("%d", &min);
    limpa_buffer();
    printf("Digite o valor máximo a ser sorteado: ");
    scanf("%d", &max);
    limpa_buffer();
    printf("\n=========================================\n");
    if (min >= max) { // [VALIDAÇÃO]
      printf("\n[Intervalo inválido! Tente novamente...]\n");
    }
  } while (min >= max);
  for (i = 0; i < tam; i++) { // [GERA O VETOR]
    vet[i] = min + rand() % (max - min + 1); // [ALEATORIZA VALORES NO INTERVALO MIN-MAX]
  }
}

int main(void) {
  srand(time(NULL)); // [CRIA UMA SEMENTE PARA A FUNÇÃO RAND()]
  int i, tam, maior, menor;
  tam = tamanho_vetor();
  int vet[tam];
  gerar_vetor(tam, vet);
  printf("\n+Vetor gerado: ");
  for (i = 0; i < tam; i++) { // [IMPRIME O VETOR]
    printf(i == 0 ? "%d" : ", %d", vet[i]);
  }
  maior_menor(vet, tam, &maior, &menor);
  printf("\n\n[Maior elemento: %d]\n[Menor elemento: %d]\n", maior, menor);
  return 0;
}