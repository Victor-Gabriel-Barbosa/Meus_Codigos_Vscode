/* 26- Faça um algoritmo para fazer a criação dos novos tipos de dados conforme solicitado abaixo:
 Horário: composto de hora, minutos e segundos.
 Data: composto de dia, mês e ano.
 Compromisso: composto de uma data, horário e texto que descreve o compromisso */

#include <stdio.h>
#include <stdio_ext.h>

int main(void) {
  int qtde_c = 10, i, j, aux, loop;
  int diasNoMes[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  struct compromisso { // Cria uma struct p/ armazenar compromissos (vetor)
    char texto[100];
    struct data { // Cria uma struct p/ armazenar datas
      int dia, mes, ano;
      struct horario { // Cria uma struct p/ armazenar horários
        int hora, min, seg;
      } h;
    } d;
  } c[10];
  for (i = 0; i < qtde_c; i++) { // Preenche o vetor de compromissos
    printf("\nDigite o texto do compromisso [%d]:\n", i + 1);
    fgets(c[i].texto, 100, stdin);
    __fpurge(stdin);
    do { // Verifica se o dia é válido
      loop = 1;
      printf("\nDigite a data do compromisso [%d] \n[DD/MM/AAAA]: ", i + 1);
      if (scanf("%d/%d/%d", &c[i].d.dia, &c[i].d.mes, &c[i].d.ano) != 3 ||
          c[i].d.dia < 1 || c[i].d.mes < 1 || c[i].d.mes > 12 ||
          c[i].d.ano < 1900 || c[i].d.ano > 2023) {
        __fpurge(stdin);
        printf("\n[Data Inválida! Tente Novamente...]\n");
      } else {
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
    do { // Verifica se o horário é válido
      loop = 0;
      printf("\nDigite o horário do compromisso %d [HH:MM:SS]: ", i + 1);
      if (scanf("%d:%d:%d", &c[i].d.h.hora, &c[i].d.h.min, &c[i].d.h.seg) != 3 ||
          c[i].d.h.hora < 0 || c[i].d.h.hora > 23 || c[i].d.h.min < 0 ||
          c[i].d.h.min > 59) {
        __fpurge(stdin);
        printf("\n[Horário Inválido! Tente Novamente...]\n");
        loop = 1;
      }
      __fpurge(stdin);
    } while (loop);
  }
  for (i = 0; i < qtde_c; i++) { // Imprime os compromissos
    printf("\nCompromisso %d: %s", i + 1, c[i].texto);
    printf("Data: %d/%d/%d", c[i].d.dia, c[i].d.mes, c[i].d.ano);
    printf("\nHorário: %d:%d:%d", c[i].d.h.hora, c[i].d.h.min, c[i].d.h.seg);
  }
  return 0;
}