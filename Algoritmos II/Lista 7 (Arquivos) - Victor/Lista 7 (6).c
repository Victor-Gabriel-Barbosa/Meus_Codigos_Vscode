/*6 - Faça um programa que receba do usuário um arquivo texto e mostre na tela quantas vezes cada letra do alfabeto aparece dentro do arquivo.*/

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

void alfabeto(char *nome_arquivo, int contador[]) { // [FUNÇÃO DE CONTAR LETRAS DENTRO DE ARQUIVO]
  FILE *arquivo;
  char letra;
  char alfabeto[] = "abcdefghijklmnopqrstuvwxyz";
  int i;
  arquivo = fopen(nome_arquivo, "r");
  if (arquivo == NULL) {
    printf("\nErro ao abrir o arquivo\n");
    exit(1);
  }
  for (i = 0; i < 26; i++) {
    while ((letra = fgetc(arquivo)) != EOF) {
      if (tolower(letra) == alfabeto[i]) {
        contador[i]++;
      }
    }
    rewind(arquivo);
  }
  fclose(arquivo);
}

int main(void) {
  int i, alf[26] = {0};
  abrir_arquivo("alfabeto.txt");
  alfabeto("alfabeto.txt", alf);
  for (i = 0; i < 26; i++) {
    printf("\n%c: %d", 'a' + i, alf[i]);
  } 
  return 0;
}