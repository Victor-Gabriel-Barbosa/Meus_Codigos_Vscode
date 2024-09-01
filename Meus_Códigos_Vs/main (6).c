#include <stdio.h>

/*7 - Faça um algoritmo que receba quatro valores: I, A, B e C. Desses valores, I é inteiro e positivo, A, B e C são reais. Escreva os números A, B e C obedecendo à tabela a seguir (Suponha que o valor digitado I seja sempre um valor válido, ou seja, 1, 2 ou 3 e que os números digitados sejam sempre diferentes um do outro):
*/
int main(void) {
  int I, i, j;
  float A, B, C, ordem[3], aux;
  do {
    printf("Digite um valor inteiro para I [1-3]: ");
    scanf("%d", &I);
    if (I < 1 || I > 3)
      printf("\nValor inválido! Tente novamente...\n");
  } while (I < 1 || I > 3);
  do {
    printf("Digite um valor para A: ");
    scanf("%f", &A);
    printf("Digite um valor para B: ");
    scanf("%f", &B);
    printf("Digite um valor para C: ");
    scanf("%f", &C);
    if (A == B || A == C || B == C) 
      printf("\nOs valores devem ser diferentes um do outro! Tente novamente...\n");
  } while (A == B || A == C || B == C);
  ordem[0] = A;
  ordem[1] = B;
  ordem[2] = C;
  printf("\n[Ordem atual: %.2f, %.2f, %.2f]\n", ordem[0], ordem[1], ordem[2]);
  if(I == 1){
    for(i = 0; i < 3; i++){
      for(j = 0; j < 3; j++){
        if(ordem[i] < ordem[j]){
          aux = ordem[i];
          ordem[i] = ordem[j];
          ordem[j] = aux;
        }
      }
    }
    printf("[Ordem crescente: %.2f, %.2f, %.2f]", ordem[0], ordem[1], ordem[2]);
  }
  else if(I == 2){
    for(i = 0; i < 3; i++){
      for(j = 0; j < 3; j++){
        if(ordem[i] > ordem[j]){
          aux = ordem[i];
          ordem[i] = ordem[j];
          ordem[j] = aux;
        }
      }
    }
    printf("[Ordem decrescente: %.2f, %.2f, %.2f]", ordem[0], ordem[1], ordem[2]);
  }
  else if(I == 3){
    for(i = 0; i < 3; i++){
      for(j = 0; j < 3; j++){
        if(ordem[i] < ordem[j]){
          aux = ordem[i];
          ordem[i] = ordem[j];
          ordem[j] = aux;
        }
      }
    }
    aux = ordem[1];
    ordem[1] = ordem[2];
    ordem[2] = aux;
    printf("[Ordem com maior número no meio: %.2f, %.2f, %.2f]", ordem[0], ordem[1], ordem[2]);
  } 
  return 0;
}