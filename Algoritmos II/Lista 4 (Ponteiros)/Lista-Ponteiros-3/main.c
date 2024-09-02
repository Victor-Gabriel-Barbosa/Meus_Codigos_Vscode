/* 3 - a) qual o resultado da execução do programa?
a: 25; pa: 1955208060; &a: 1955208060; *pa: 25; b: 50; &b: 1955208056
b) Qual o signiﬁcado de cada um dos valores impressos?
(a) 25 - Valor de a; (pa) 1955208060 - Endereço de a; (*pa) 25 - Valor de apontamento de a; 
(b) 50 - Valor de b; (&b) 1955208056 - Endereço de b */

#include <stdio.h>

int main(void) {
  int a = 25;
  int *pa = &a; // pa recebe o endereço de a
  int b = *pa + a; // b recebe o valor de a mais o valor de apontamento de pa
  printf("%d %p %p %d %d %p\n", a, pa, &a, *pa, b, &b);
  return 0;
}