/*Nome: Victor Gabriel Barbosa;
Matr�cula: 32311BSI013;
Descri��o:
1)- Fa�a um programa que receba uma frase, calcule e mostre a quantidade de vogais da frase
digitada. (Considerar vogais mai�sculas e min�sculas)*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
void main(){
    setlocale(LC_ALL,"Portuguese_Brazil");
    char a[100];
    char c;
    int n, v = 0;
    printf("Digite uma palavra: "); //Entrada da palavra
    fgets(a, 100, stdin); //Leitor do que foi digitado
    n = strlen(a); //Quantidade de caracteres da palavra

    //La�o de repeti��o baseado na quantidade de letras da palavra digitada:
    for(int i = 0; i < n; i++) {
        c = a[i]; //Extra��o de um caracter da palavra digitada

        //Condicional que verifica quais caracteres s�o vogais e acumula na vari�vel 'v':
        if(c == 'a' | c == 'e' | c == 'i' | c == 'o' | c == 'u' | c == 'A' | c == 'E' | c == 'I' | c == 'O' | c == 'U') {
        v++;
        }
    }
    printf("A quantidade de vogais na frase �: %d", v); //Resultado da quantidade de vogais da palavra digitada
}
