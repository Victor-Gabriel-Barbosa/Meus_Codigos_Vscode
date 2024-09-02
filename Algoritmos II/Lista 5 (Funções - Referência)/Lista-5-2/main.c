/* 2 - Desenvolva um programa para testar as funções a seguir:
• Uma função que receba dois números a e b, em seguida, faça a troca 
destes dois números. Dica: a e b devem ser passados por referência;
• Uma função que receba dois números a e b, em seguida, decremente 
o primeiro e incremente o segundo. Dica: a e b devem ser passados 
por referência;
• Uma função que receba os valores a, b e c passados por valor, 
receba também dois valores x1 e x2 passados por referência.
Em seguida, calcule e retorne as duas raízes da
equação do segundo grau nas variáveis x1 e x2.*/

#include <math.h>
#include <stdio.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void troca(int *a, int *b) { // [TROCA OS VALORES DE A E B]
  int aux;
  aux = *a;
  *a = *b;
  *b = aux;
}

void decrmt_incrmt(int *a, int *b) { // [DECREMENTA A E INCREMENTA B]
  (*a)--;
  (*b)++;
}

void raizes(int a, int b, int c, float *x1, float *x2) { // [CALCULA AS RAÍZES DE UMA EQUAÇÃO DO 2° GRAU]
  float delta = pow(b, 2) - (4 * a * c);
  *x1 = (-b + sqrt(delta)) / (2 * a);
  *x2 = (-b - sqrt(delta)) / (2 * a);
}

int main(void) {
  int a, b, c;
  float x1, x2;
  printf("Digite dois números: ");
  scanf("%d %d", &a, &b);
  limpa_buffer();
  printf("\n[A = %d][B = %d] > (Antes da Troca)", a, b);
  troca(&a, &b);
  printf("\n[A = %d][B = %d] > (Depois da Troca)", a, b);
  printf("\n\nDigite dois números: ");
  scanf("%d %d", &a, &b);
  limpa_buffer();
  printf("\n[A = %d][B = %d] > (Antes da Alteração)", a, b);
  decrmt_incrmt(&a, &b);
  printf("\n[A = %d][B = %d] > (Depois da Alteração)", a, b);
  printf("\n\nDigite os valores de a, b e c: ");
  scanf("%d %d %d", &a, &b, &c);
  limpa_buffer();
  raizes(a, b, c, &x1, &x2);
  printf("\n[X1 = %f][X2 = %f]", x1, x2);
  return 0;
}