/* 6 - A nota final de um estudante é calculada a partir de três notas atribuídas, respectivamente, a um trabalho de laboratório, a uma avaliação semestral e a um exame final. 

A média das três notas mencionadas obedece aos pesos a seguir: Trabaho de Laboratório: peso 2; Avaliação Semestral: peso 3; Exame Final 5. 

Faça um programa que receba as três notas, calcule e mostre a média pondera e o conceito que segue a tabela: 8.01 a 10.0 A; 7.01 a 8.0 B; 6.01 a 7.0 C, 5.01 a 6.0 D, 0.0 a 5.0 E*/

#include <stdio.h>

int main(void) {
  float nota_trabalho, nota_avaliacao, nota_exame, media;
  char conceito;
  printf("Digite a nota do trabalho de laboratório do aluno:\n");
  scanf("%f", &nota_trabalho);
  printf("Digite a nota da avaliação semestral do aluno:\n");
  scanf("%f", &nota_avaliacao);
  printf("Digite a nota do exame final do aluno:\n");
  scanf("%f", &nota_exame);
  media = (nota_trabalho*2 + nota_avaliacao*3 + nota_exame*5)/10;
  if(media >= 8.01 && media <= 10.0)
    conceito = 'A';
    else if(media >= 7.01 && media <= 8.0)
      conceito = 'B';
      else if(media >= 6.01 && media <= 7.0)
        conceito = 'C';
        else if(media >= 5.01 && media <= 6.0)
          conceito = 'D';
          else if(media >= 0.0 && media <= 5.0)
            conceito = 'E';  
  printf("A média ponderada do aluno é %.2f e seu conceito é %c", media, conceito);
  return 0;
}