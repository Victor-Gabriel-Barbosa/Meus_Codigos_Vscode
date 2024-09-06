// Bibliotecas +úteis:
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main () {
    setlocale(ALL_LC, "Portuguese");
    int i, j;
    char validacao[100];
    printf("Digite uma palavra: ");
    fgets(validacao, 100, stdin);
    fflush(stdin);
    if (isalpha(validacao) != 0) {
        printf("É uma palavra mesmo");
    }
        else {
            printf("Não é uma palavra não");
        }
    return 0;
}
