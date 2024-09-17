/*
9. Faca um programa que faça operações simples de números complexos:
• Crie e leia dois números complexos z e w, compostos por parte real e parte imaginaria.
• Apresente a soma, subtração e produto entre z e w, nessa ordem, bem como o modulo de ambos. 
*/


/*
> Fórmulas dos números complexos <

• Soma: z=a+bi; 
• Subtração: z=a-bi;
• Multiplicação: z=(ac-bd)+(ad+bc)i;
• Divisão: z=(ac+bd)/(c²+d²)+(ad-bc)/(c²+d²)i;
• Conjugado: z*=a-bi;
• Módulo/Magnitude: |z| = sqrt(a² + b²);
                     ↑      ↑
                   Módulo  Raiz

Notas:
- z: resultado de uma operação entre números complexos;
- a: parte real do primeiro número complexo;
- b: parte imaginária do primeiro número complexo;	
- c: parte real do segundo número complexo;
- d: parte imaginária do segundo número complexo;
- i: número imaginário (unidade de medida);
*/


#include <stdio.h>
#include <math.h>

typedef struct { 
    float real, imag;
} complexo; // Define uma estrutura para representar números complexos

void exibe_complexo(complexo c) { // Exibe um número complexo no formato "a + bi" ou "a - bi"
    if (c.imag >= 0) {
        printf("%.2f + %.2fi\n", c.real, c.imag);
    } else {
        printf("%.2f - %.2fi\n", c.real, -c.imag);
    }
}

complexo soma_complexos(complexo a, complexo b) { // Soma de dois números complexos
    complexo resultado;
    resultado.real = a.real + b.real;
    resultado.imag = a.imag + b.imag;
    return resultado;
}

complexo subtracao_complexos(complexo a, complexo b) { // Subtração de dois números complexos
    complexo resultado;
    resultado.real = a.real - b.real;
    resultado.imag = a.imag - b.imag;
    return resultado;
}

complexo multiplicacao_complexos(complexo a, complexo b) { // Multiplicação de dois números complexos
    complexo resultado;
    resultado.real = a.real * b.real - a.imag * b.imag;
    resultado.imag = a.real * b.imag + a.imag * b.real;
    return resultado;
}

complexo divisao_complexos(complexo a, complexo b) { // Divisão de dois números complexos
    double divisor = pow(b.real, 2) + pow(b.imag, 2);
    complexo resultado;
    resultado.real = (a.real * b.real + a.imag * b.imag) / divisor;
    resultado.imag = (a.imag * b.real - a.real * b.imag) / divisor;
    return resultado;
}

double modulo_complexo(complexo c) { // Calcula o módulo (magnitude) de um número complexo
    return sqrt(pow(c.real, 2) + pow(c.imag, 2));
}

complexo conjugado_complexo(complexo c) { // Calcula o conjugado de um número complexo
    complexo resultado;
    resultado.real = c.real;
    resultado.imag = -c.imag;
    return resultado;
}

void limpa_buffer() { // Limpa o buffer de entrada
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    complexo z, w; // Declara as variáveis z e w com o tipo complexo

    printf("Digite o primeiro número complexo (real e imaginário): ");
    scanf("%f %f", &z.real, &z.imag);
    limpa_buffer();
    printf("Digite o segundo número complexo (real e imaginário): ");
    scanf("%f %f", &w.real, &w.imag);
    limpa_buffer();
    
    printf("\nNúmeros complexos digitados:\n");
    exibe_complexo(z);
    exibe_complexo(w);
    
    printf("\nSoma dos números complexos:\n");
    exibe_complexo(soma_complexos(z, w)); // Faz a soma e exibe o resultado
    
    printf("\nSubtração dos números complexos:\n");
    exibe_complexo(subtracao_complexos(z, w)); // Faz a subtração e exibe o resultado
    
    printf("\nMultiplicação dos números complexos:\n");
    exibe_complexo(multiplicacao_complexos(z, w)); // Faz a multiplicação e exibe o resultado
    
    printf("\nDivisão dos números complexos:\n");
    exibe_complexo(divisao_complexos(z, w)); // Faz a divisão e exibe o resultado
    
    printf("\nModulo do primeiro número complexo: %f\n", modulo_complexo(z)); // Calcula o módulo e exibe o resultado
    
    printf("\nConjugado do primeiro número complexo:\n");
    exibe_complexo(conjugado_complexo(z)); // Faz o conjugado e exibe o resultado
    
    return 0;
}