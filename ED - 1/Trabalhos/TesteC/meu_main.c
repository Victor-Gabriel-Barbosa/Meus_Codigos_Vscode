// main.c
#include <stdio.h>
#include "documentacao.h"

int main() {
    int num1, num2, resultado;

    // Solicita os números ao usuário
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);

    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    // Chama a função de soma
    resultado = soma(num1, num2);

    // Exibe o resultado
    printf("A soma de %d e %d é: %d\n", num1, num2, resultado);

    return 0;
}
