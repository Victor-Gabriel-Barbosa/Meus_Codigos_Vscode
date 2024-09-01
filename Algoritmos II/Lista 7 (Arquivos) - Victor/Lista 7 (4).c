/*4 - Faça um programa que receba do usuário um arquivo texto e mostre na tela quantas letras são vogais e quantas são consoantes.*/

#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>

void abrir_arquivo(char *nome_arquivo) { // [FUNÇÃO DE ABRIR ARQUIVO]
  FILE *arquivo = fopen(nome_arquivo, "a");
  if (!arquivo) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  fclose(arquivo);
}

void ver_vogais_consoantes(char *nome_arq, int *cont_v, int *cont_c) { // [FUNÇÃO DE VERIFICAÇÃO DE VOGAL E CONSOANTE EM ARQUIVO]
  FILE *arquivo;
  char c;
  *cont_v = 0, *cont_c = 0;
  char vogais_aux[] = "aeiouAEIOU";
  char consoantes_aux[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
  arquivo = fopen(nome_arq, "r");
  if (!arquivo) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  while (fscanf(arquivo, "%c", &c) != EOF) {
    if (strchr(vogais_aux, c) != NULL) {
      (*cont_v)++;
    } 
      else if (strchr(consoantes_aux, c) != NULL) {
        (*cont_c)++;
      }
  }
  fclose(arquivo);
}

int main(void) {
  int ct_v, ct_c;
  abrir_arquivo("Letras.txt");
  ver_vogais_consoantes("Letras.txt", &ct_v, &ct_c);
  printf("Quantidade de vogais: %d\n", ct_v);
  printf("Quantidade de consoantes: %d", ct_c);
  return 0;
}