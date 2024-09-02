/*06 - Faça um programa que leia a quantidade total de segundos e envia para uma
 * função, nesta função converta para Horas, Minutos e Segundos e retorne para o
 * programa principal imprimir o resultado da conversão no formato HH:MM:SS */

#include <stdio.h>
#include <stdlib.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void convertHora(int *segundos, int *minutos, int *horas) { // Função que converte os segundos p/ horas, minutos e segundos
  *horas = *segundos / 3600;
  *minutos = (*segundos % 3600) / 60;
  *segundos = *segundos % 60;
}

int main(void) {
  int seg, min, hor;
  printf("Digite a quantidade de segundos: ");
  scanf("%d", &seg);
  limpa_buffer();
  convertHora(&seg, &min, &hor);
  printf("[HH:MM:SS][%02d:%02d:%02d]", hor, min, seg);
  return 0;
}