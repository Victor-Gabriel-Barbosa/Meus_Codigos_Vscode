/* 5 - Desenvolva um programa principal (main) que deverá ler o dia, mês e ano.
 * Faça uma função receba esses valores e retorne se os valores fornecidos
 * formam uma data válida. Se for válida, faça uma outra função que recebe esta
 * data também e imprime a data como ilustrado a seguir: Entrada: 27/08/2023
 * Saída: 27 de agosto de 2023*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void limpa_buffer() { // Função para limpar o buffer do teclado
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

bool data(int d, int m, int a) { // Função que verifica se a data é válida
  return (d > 0 && d <= 31 && m > 0 && m <= 12 && a > 0);
}

void mostra_data(int d, int m, int a) { // Função que mostra a data
  char meses[12][10] = {"janeiro",  "fevereiro", "março",    "abril",
                        "maio",     "junho",     "julho",    "agosto",
                        "setembro", "outubro",   "novembro", "dezembro"};
  printf("+Entrada: %02d/%02d/%04d", d, m, a);
  printf("\n-Saída: %02d de %s de %02d", d, meses[m - 1], a);
}

int main(void) {
  int dia, mes, ano;
  bool loop = false;
  do { // Loop para ler a data
    printf("\033[0m\nAperte [\033[38;5;39mENTER\033[0m] para continuar...");
    limpa_buffer();
    system("clear");
    printf("\nDigite a data no formato dd/mm/aaaa: ");
    scanf("%d/%d/%d", &dia, &mes, &ano);
    limpa_buffer();
    loop = !data(dia, mes, ano);
    if (loop) { // Verifica se a data é válida
      printf("\n[Data inválida! Tente novamente...]\n");
    }
  } while (loop);
  mostra_data(dia, mes, ano);
  return 0;
}