/*12 - Abra um arquivo texto, calcule e escreva o número de caracteres, o número de linhas e o número de palavras neste arquivo. Escreva também quantas vezes cada letra ocorre no arquivo (ignorando letras com acento). Obs.: palavras são separadas por um ou mais caracteres espaço, tabulação ou nova linha.*/

#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>

void abrir_arquivo(char *nome_arquivo) { // [FUNÇÃO DE ABRIR ARQUIVO]
  FILE *arquivo = fopen(nome_arquivo, "a");
  if (!arquivo) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  fclose(arquivo);
}

void ler_arquivo(char *nome_arquivo, int *ct_car, int *ct_lin, int *ct_pal, int *ct_let) { // [FUNÇÃO DE LER ARQUIVO]
  FILE *arqv;
  char c;
  char palavra[100];
  char letras[] = "abcdefghijklmnopqrstuvwxyz";
  arqv = fopen(nome_arquivo, "r");
  if (arqv == NULL) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  for (int i = 0; i < 26; i++) {
    while ((c = fgetc(arqv)) != EOF) {
      if (tolower(c) == letras[i]) {
        ct_let[i]++;
      }
    }
    rewind(arqv);
  }
  rewind(arqv);
  while ((c = fgetc(arqv)) != EOF) {
    if (c != ' ' && c != '\t' && c != '\n') {
      (*ct_car)++;
    }  
    if (c == '\n') {
      (*ct_lin)++;
    }
    if (c == ' ' || c == '\t' || c == '\n' || c == '\0') {
      (*ct_pal)++;
      while ((c = fgetc(arqv)) != EOF && (c == ' ' || c == '\t' || c == '\n')) {
        if (c == '\n') {
          (*ct_lin)++;
        }
      }
      if (c != EOF) {
        ungetc(c, arqv);
      }
    }
  }
  if (c != ' ' && c != '\t' && c != '\n') { 
    (*ct_pal)++;
  }
  fclose(arqv);
} 

int main(void) {
  int cont_caracters = 0, cont_linhas = 1;
  int cont_palavras = 0, cont_letras[26] = {0};
  abrir_arquivo("texto.txt");
  ler_arquivo("texto.txt", &cont_caracters, &cont_linhas, &cont_palavras, cont_letras);
  printf("Caracteres: %d\n", cont_caracters);
  printf("Linhas: %d\n", cont_linhas);
  printf("Palavras: %d\n", cont_palavras);
  printf("Letras:\n");
  for (int i = 0; i < 26; i++) {
    printf("%c: %d\n", 'a' + i, cont_letras[i]);
  }
  return 0;
}