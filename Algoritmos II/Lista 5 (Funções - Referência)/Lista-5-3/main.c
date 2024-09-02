/* 3 - Faça um programa que calcule a pontuação de dois times após uma partida
 * de futebol. Na função principal leia dois números inteiros que correspondem
 * ao número de pontos dos dois times antes do jogo. Depois leia dois inteiros
 * que representam o número de gols que cada time fez na partida. Você deverá
 * fazer uma função separada que receba os pontos dos dois times por referência
 * e os atualize de acordo com o resultado. Em caso de vitória são somados 3
 * pontos, em caso de empate é somado um ponto, e em caso de derrota, nenhum
 * ponto é somado.*/

#include <stdio.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void pontuacao(int *time1, int *time2, int gol1, int gol2) { // Função p/ calcular a pontuação dos times
  if (gol1 > gol2) { // Se o time 1 fez mais gols que o time 2 o time 1 ganha 3 pontos
    *time1 += 3;
  } else if (gol1 == gol2) { // Se o time 1 fez o mesmo número de gols que o time 2 ambos recebem 1 ponto
    *time1 += 1;
    *time2 += 1;
  } else if (gol2 > gol1) { // Se o time 2 fez mais gols que o time 1 o time 2 ganha 3 pontos
    *time2 += 3;
  }
}

int main(void) {
  int pts_time1, pts_time2, gols_time1, gols_time2;
  printf("Digite o número de pts do time 1 (antes do jogo): ");
  scanf("%d", &pts_time1);
  limpa_buffer();
  printf("Digite o número de pts do time 2 (antes do jogo): ");
  scanf("%d", &pts_time2);
  limpa_buffer();
  printf("\nDigite o número de gols do time 1: ");
  scanf("%d", &gols_time1);
  limpa_buffer();
  printf("Digite o número de gols do time 2: ");
  scanf("%d", &gols_time2);
  limpa_buffer();
  pontuacao(&pts_time1, &pts_time2, gols_time1, gols_time2);
  printf("\n[Pontuação do time 1 (depois do jogo): %d]", pts_time1);
  printf("\n[Pontuação do time 2 (depois do jogo): %d]", pts_time2);
  return 0;
}