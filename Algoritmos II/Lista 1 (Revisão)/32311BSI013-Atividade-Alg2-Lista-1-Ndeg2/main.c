// Faça um algoritmo que leia a idade de uma pessoa em dias e mostre-a expressa em anos, meses e dias (Defina que todos os meses tem 30 dias).

#include <stdio.h>

int main(void) {
  int dias = 0, dias_aux = 0, meses = 0, anos = 0;
  printf("Digite a idade da pessoa em dias: ");
  scanf("%d", &dias);  
  dias_aux = dias;
  dias = 0;
  while (dias_aux > 0) {
    if (dias_aux >= 360) {
      dias_aux = dias_aux - 360;
      anos++;
    }
      else if (dias_aux >= 30) {
        dias_aux = dias_aux - 30;
        meses++;
      }
        else if (dias < 30) {
          dias_aux--;
          dias++;
        }
  }
  printf( "A idade da pessoa é %d anos, %d meses e %d dias", anos, meses, dias);
  return 0;
}