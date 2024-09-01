/*
26- Faça um algoritmo para fazer a criação dos novos tipos de dados conforme solicitado abaixo:
 Horário: composto de hora, minutos e segundos.
 Data: composto de dia, mês e ano.
 Compromisso: composto de uma data, horário e texto que descreve o compromisso. 
*/
  
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define TAM_STRING 100
#define MAX_COMPROMISSOS 10
int main(void) {
  int i, j, aux, loop;
  int diasNoMes[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  struct compromisso {
    char texto[TAM_STRING];
  
    struct data {
      int dia, mes, ano;
  
      struct horario {
        int hora, min, seg;
      } h;
  
    } d;
  
  } c[10];

  for (i = 0; i < MAX_COMPROMISSOS; i++) {
    printf("Digite o texto do compromisso %d: ", i + 1);
    fgets(c[i].texto, TAM_STRING, stdin);
    __fpurge(stdin);
    do {
      loop = 1;
      printf("Digite a data do compromisso %d [DD/MM/AAAA]: ", i + 1);
      if (scanf("%d/%d/%d", &c[i].d.dia, &c[i].d.mes, &c[i].d.ano) != 3 || c[i].d.dia < 1 || c[i].d.mes < 1 || c[i].d.mes > 12 || c[i].d.ano < 1900 || c[i].d.ano > 2023) { 
          __fpurge(stdin);
          printf("\n[Data Inválida! Tente Novamente...]\n");
        } 
          else {
            if ((c[i].d.dia % 4 == 0 && c[i].d.ano % 100 != 0) || (c[i].d.ano % 400 == 0)) 
              diasNoMes[2] = 29; 
              else
                diasNoMes[2] = 28; 
            if (c[i].d.dia > diasNoMes[c[i].d.mes])
                printf("\n[Data Inválida! Tente Novamente...]\n");
              else 
                loop = 0;
          }
    } while (loop);
        
    do {
      loop = 0;
      printf("Digite o horário do compromisso %d [HH:MM:SS]: ", i + 1);
      if (scanf("%d:%d:%d", &c[i].d.h.hora, &c[i].d.h.min, &c[i].d.h.seg) != 3 || c[i].d.h.hora < 0 || c[i].d.h.hora > 23 || c[i].d.h.min < 0 || c[i].d.h.min > 59) {
        __fpurge(stdin);
        printf("\n[Horário Inválido! Tente Novamente...]\n");
        loop = 1;
      } 
    __fpurge(stdin);
        
  } while (loop);
}
  for (i = 0; i < MAX_COMPROMISSOS; i++) {
    printf("\nCompromisso %d: %s", i + 1, c[i].texto);
    printf("Data: %d/%d/%d", c[i].d.dia, c[i].d.mes, c[i].d.ano);
    printf("\nHorário: %d:%d:%d", c[i].d.h.hora, c[i].d.h.min, c[i].d.h.seg);
  }
  return 0;
}