#include <stdio.h>
#include <string.h>

void main() {
    char fr1[100], fr2[10][10], pl[10]; // Declaração de variáveis
    int i, j, c = 0, count[10] = {0}, k = 0; // Inicialização de contadores

    printf("Digite uma frase: "); // Solicita ao usuário que insira uma frase
    fgets(fr1, 100, stdin); // Lê a entrada do usuário

    // Remove o caractere de nova linha da string de entrada
    fr1[strcspn(fr1, "\n")] = 0;

    for(i = 0; i <= strlen(fr1); i++) {
        if(fr1[i] == ' ' || fr1[i] == '\0') {
            pl[k] = '\0';
            strcpy(fr2[c], pl);
            c++;
            k = 0;
        } else {
            pl[k++] = fr1[i];
        }
    }

    for (i = 0; i < c; i++) { // Loop através de cada palavra
        for (j = 0; j < c; j++) { // Compara cada palavra com todas as outras palavras
            if (strcmp(fr2[i], fr2[j]) == 0) { // Se as palavras são iguais...
                count[i]++; // Incrementa o contador para essa palavra
            }
        }
    }

    for (i = 0; i < c; i++) { // Loop que imprime a quantidade de palavras repetidas
        printf("A quantidade de vezes que a %dª palavra: (%s) aparece na frase é: %d\n", i+1, fr2[i], count[i]); // E imprime a frequência de cada palavra
    }
}
