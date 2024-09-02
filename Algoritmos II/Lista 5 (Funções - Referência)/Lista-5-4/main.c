/* 4 - Faça um programa que leia uma quantidade N de palavras, sendo que N é fornecido pelo usuário. Elas devem ser salvas em uma matriz de modo que cada linha represente uma palavra. Faça uma função que receba como parâmetro um número inteiro, a matriz lida e um vetor de inteiros, todos passados por referência. O que a função deverá fazer é salvar no vetor os números das linhas em que a primeira letra da palavra é igual à última. O número inteiro passado como referência será um contador que dirá o tamanho desse vetor, ou seja, a quantidade de palavras em que a primeira e a última letra são iguais.*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void leitura(int *tam, int vet[], char mat_pal[][30]) { // Função para ler as palavras e armazená-las na matriz
  int aux = *tam;
  *tam = 0;
  for (int i = 0; i < aux; i++) { // Laço para ler as palavras
    if (toupper(mat_pal[i][0]) == toupper(mat_pal[i][strlen(mat_pal[i]) - 1])) { // Verifica se a 1ª e a última letra são iguais
      vet[i] = i;
      (*tam)++;
    }
  }
}

int main(void) {
  int i, n;
  do { // Validação da quantidade de palavras
    printf("\nDigite a quantidade de palavras que serão lidas: ");
    scanf("%d", &n);
    limpa_buffer();
    if (n <= 0) { // Caso a quantidade de palavras seja inválida
      printf("\n[Quantidade inválida! Tente novamente...]\n");
    }
  } while (n <= 0);
  char palavras[n][30];
  int vet[n];
  for (i = 0; i < n; i++) { // Laço para inicializar o vetor auxiliar
    vet[i] = -1;
  }
  for (i = 0; i < n; i++) { // Laço para ler as palavras
    printf("\nDigite a %dª palavra: ", i + 1);
    scanf("%s", palavras[i]);
    limpa_buffer();
  }
  leitura(&n, vet, palavras);
  printf("\nPalavras em que a primeira e a última letra são iguais: ");
  for (i = 0; i < n; i++) { // Laço p/ imprimir as palavras que têm a 1ª e a última letra iguais
    if (vet[i] >= 0) { // Caso a palavra tenha a 1ª e a última letra iguais
      printf("\n=[ %s ]=", palavras[vet[i]]);
    }   
  }
  printf("\nQTD total: %d", n);
  return 0;
}