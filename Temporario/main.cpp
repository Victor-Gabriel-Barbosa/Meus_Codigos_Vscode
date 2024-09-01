#include <iostream>

int main() {
    // Declaração das variáveis
    double num1, num2, soma;

    // Solicita ao usuário que insira dois números
    std::cout << "Digite o primeiro número: ";
    std::cin >> num1;

    std::cout << "Digite o segundo número: ";
    std::cin >> num2;

    // Calcula a soma dos dois números
    soma = num1 + num2;

    // Exibe o resultado
    std::cout << "A soma de " << num1 << " e " << num2 << " é " << soma << std::endl;

    return 0;
}
