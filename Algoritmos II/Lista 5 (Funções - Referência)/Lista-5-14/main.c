/* 14 – Faça uma função que receba uma string e dobre todas as palavras
existentes, mostre o resultado no programa principal. [Exemplo] Original : "O
rato roeu a roupa do rei de roma" Resultado: O O rato rato roeu roeu a a roupa
roupa do do rei rei de de roma roma */

#include <stdio.h>
#include <string.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void dobra(char *frase) { // Função que recebe a frase e dobra as palavras existentes
  char palavra[200] = "";
  char temp[100];
  int i = 0, j = 0;
  while (frase[i] != '\0') { // Loop que percorre a frase
    if (frase[i] != ' ') { // Se o caractere atual for diferente de espaço, adiciona-o à palavra
      temp[j++] = frase[i];
    } else { // Se o caractere atual for espaço, adiciona-a à palavra e dobra-a
      temp[j] = '\0';
      strcat(palavra, temp);
      strcat(palavra, " ");
      strcat(palavra, temp);
      strcat(palavra, " ");
      j = 0;
    }
    i++;
  }
  temp[j] = '\0';
  strcat(palavra, temp);
  strcat(palavra, " ");
  strcat(palavra, temp);
  strcpy(frase, palavra);
}

int main(void) {
  char frase[100] = " ";
  printf("Digite uma frase: ");
  scanf("%99[^\n]", frase);
  limpa_buffer();
  dobra(frase);
  printf("Frase dobrada: '%s'", frase);
  return 0;
}
