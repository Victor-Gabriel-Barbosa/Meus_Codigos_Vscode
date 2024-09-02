/* 4 - Escreva uma função que determine a média e a situação de um aluno em uma
disciplina. A função recebe como parâmetros as três notas de um aluno (p1, p2, e
p3), seu número de faltas (faltas), o número total de aulas da disciplina
(aulas) e o ponteiro para uma variável (media), conforme o seguinte protótipo:
char situacao(float p1, float p2, float p3, int faltas, int aulas, float
*media); Na variável indicada pelo ponteiro media, a função deve armazenar a
média do aluno, calculada como a média aritmética das três provas. Além disso, a
função deve retornar um caractere indicando a situação do aluno no curso,
definido de acordo com o seguinte critério:
- Se a média for maior ou igual a 6 e o número de faltas menor ou igual a 25% do
total de aulas da disciplina, a função deve retornar 'A';
- Se a média for maior ou igual a 6 e o número de faltas maior que 25% do total
de aulas da disciplina, a função deve retornar 'R';
- Se o número de faltas for maior que 25% do total de aulas da disciplina, a
função deve retornar 'F' */

#include <stdio.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

char situacao(float p1, float p2, float p3, int faltas, int aulas, float *media) { // Função que calcula a média e a situação do aluno
  *media = (p1 + p2 + p3) / (float)3;
  if (faltas <= aulas * 0.25) { // Verifica se a qtde de faltas está dentro do limite
    if (*media < 6) { // Verifica se a média é menor que 6
      return 'R';
    }
    return 'A';
  }
  return 'F';
}

int main(void) {
  float p1, p2, p3, media;
  int faltas, aulas;
  char result;
  printf("Digite a nota da [1ª] prova [0-10]: ");
  scanf("%f", &p1);
  limpa_buffer();
  printf("Digite a nota da [2ª] prova [0-10]: ");
  scanf("%f", &p2);
  limpa_buffer();
  printf("Digite a nota da [3ª] prova [0-10]: ");
  scanf("%f", &p3);
  limpa_buffer();
  printf("Digite o nº total de aulas: ");
  scanf("%d", &aulas);
  limpa_buffer();
  printf("Digite o nº de faltas: ");
  scanf("%d", &faltas);
  limpa_buffer();
  result = situacao(p1, p2, p3, faltas, aulas, &media);
  printf("\n[A média do aluno é %.2f]", media);
  printf("\n[A situação do aluno é '%c']: ", result);
  if (result == 'A') { // Se o aluno foi aprovado
    printf("[APROVADO]");
  } else if (result == 'R') { // Se o aluno foi reprovado
    printf("[REPROVADO]");
  } else { // Se o aluno foi reprovado por falta
    printf("[REPROVADO POR FALTA]");
  }
  return 0;
}