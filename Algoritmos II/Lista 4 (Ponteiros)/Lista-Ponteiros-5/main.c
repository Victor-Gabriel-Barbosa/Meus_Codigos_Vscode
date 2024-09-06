/* 04 - Escreva uma função que determine a média e a situação de um aluno em uma
disciplina. A função recebe como parâmetros as três notas de um aluno (p1, p2, e
p3), seu número de faltas (faltas), o número total de aulas da disciplina
(aulas) e o ponteiro para uma variável (media), conforme o seguinte protótipo:
char situacao(float p1, float p2, float p3, int faltas, int aulas, float
*media); Na variável indicada pelo ponteiro media, a função deve armazenar a
média do aluno, calculada como a média aritmética das três provas. Além disso, a
função deve retornar um caractere indicando a situação do aluno no curso,
definido de acordo com o seguinte critério Ler do teclado três números reais e
dois números inteiros, representando as notas da p1, p2 e p3, o número de faltas
e o número de aulas, respectivamente; • Chamar a função desenvolvida na primeira
questão para determinar a média e a situação do aluno na disciplina; • Exibir a
média (com apenas uma casa decimal) e a situação do aluno, isto é, “APROVADO”,
“REPROVADO” ou “REPROVADO POR FALTAS”, dependendo do caractere retornado pela
função, conforme a tabela acima */

#include <stdio.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

char situacao(float p1, float p2, float p3, int faltas, int aulas, float *media) { // Verifica a situação do aluno
  *media = (p1 + p2 + p3) / 3;
  if (faltas <= aulas * 0.25) { // Verifica se o aluno tem mais de 25% de faltas
    if (*media < 6) { // Verifica se a média do aluno é menor que 6
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
  printf("Digite a nota da primeira prova: ");
  scanf("%f", &p1);
  limpa_buffer();
  printf("Digite a nota da segunda prova: ");
  scanf("%f", &p2);
  limpa_buffer();
  printf("Digite a nota da terceira prova: ");
  scanf("%f", &p3);
  limpa_buffer();
  printf("Digite o número de faltas: ");
  scanf("%d", &faltas);
  limpa_buffer();
  printf("Digite o número total de aulas: ");
  scanf("%d", &aulas);
  limpa_buffer();
  result = situacao(p1, p2, p3, faltas, aulas, &media);
  if (result == 'A') { // Verifica a situação do aluno
    printf("[APROVADO] com média: %.2f", media);
  } else if (result == 'R') { // ...
    printf("[REPROVADO] com média: %.2f", media);
  } else {
    printf("[REPROVADO POR FALTAS] com média: %.2f", media);
  }
  return 0;
}