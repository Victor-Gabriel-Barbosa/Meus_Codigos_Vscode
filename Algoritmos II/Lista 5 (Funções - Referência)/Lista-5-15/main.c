/* 15 - Faça uma função que receba uma string e duas palavras, a primeira
palavra será a palavra a ser buscada na string e a segunda palavra a ser
inserida no lugar da primeira, mostre o resultado no programa principal.
[Exemplo] Original : O rato tem medo do gato. O gato tem medo do cachorro!
Primeira palavra (a ser substituida): gato
Segunda palavra (a substituir): sapo
Resultado: O rato tem medo do sapo. O sapo tem medo do cachorro! */

#include <stdio.h>
#include <string.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void substituir(char *fras, char *fras_f, char *pal1, char *pal2) { // Função que substitui a palavra 1 pela palavra 2
  char temp[strlen(fras)];
  char *f = fras;
  char *t = temp;
  while (*f != '\0') { // Percorre a frase
    if (strstr(f, pal1) == f) { // Verifica se a palavra a ser substituída está presente na posição atual
      strcpy(t, pal2);
      t += strlen(pal2);
      f += strlen(pal1);
    } else { // Se a palavra não estiver presente, copia o caractere atual para temp
      *t++ = *f++;
    }
  }
  *t = '\0';
  strcpy(fras_f, temp);
}

int main(void) {
  char palavra1[30], palavra2[30], frase[100], frase_f[100];
  printf("Digite uma frase: ");
  scanf("%99[^\n]", frase);
  limpa_buffer();
  printf("Digite a palavra ser substituída: ");
  scanf("%29[^\n]", palavra1);
  limpa_buffer();
  printf("Digite palavra a substituir: ");
  scanf("%29[^\n]", palavra2);
  limpa_buffer();
  substituir(frase, frase_f, palavra1, palavra2);
  printf("\nFrase inicial: %s\n", frase);
  printf("Frase final: %s", frase_f);
  return 0;
}