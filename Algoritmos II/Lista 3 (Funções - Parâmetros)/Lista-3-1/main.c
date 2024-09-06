/* 01 - A nota final de um estudante é calculada a partir de três notas
atribuídas, respectivamente, a um trabalho de laboratório, a uma avaliação
semestral e a um exame final. A média das três notas mencionadas obedece aos
pesos a seguir:
- Nota Peso;
- Trabalho de laboratório 2;
- Avaliação semestral 3;
- Exame final 5.
Faça uma função que receba três notas, calcule e retorne ao programa principal a
média ponderada e imprima a partir da média o conceito que segue a tabela:
- 8.01 a 10: A
- 7.01 a 8: B
- 6.01 a 7: C
- 5.01 a 6: D
- 0 a 5: E */

#include <stdio.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

float mediaPond(float n1, float n2, float n3) { // Função que calcula a média ponderada
  return (n1 * 2 + n2 * 3 + n3 * 5) / (float) 10;
}

int main(void) {
  float trabLab, avalSem, examFin;
  printf("😀😀Digite a nota do trabalho de laboratório \n[0-10]: ");
  scanf("%f", &trabLab);
  limpa_buffer();
  printf("Digite a nota da avaliação semestral \n[0-10]: ");
  scanf("%f", &avalSem);
  limpa_buffer();
  printf("Digite a nota do exame final \n[0-10]: ");
  scanf("%f", &examFin);
  limpa_buffer();
  float media = mediaPond(trabLab, avalSem, examFin);
  printf("\n[A média ponderada é %.2f]\n", media);
  if (media > 8 && media <= 10) { // Conceito A
    printf("[Conceito A]");
  } else if (media > 7 && media <= 8) { // Conceito B
    printf("[Conceito B]");
  } else if (media > 6 && media <= 7) { // Conceito C
    printf("[Conceito C]");
  } else if (media > 5 && media <= 6) { // Conceito D
    printf("[Conceito D]");
  } else if (media >= 0 && media <= 5) { // Conceito E
    printf("[Conceito E]");
  }
  return 0;
}