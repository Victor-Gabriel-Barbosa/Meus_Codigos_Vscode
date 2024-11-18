#include <stdio.h>
#include <math.h>

double soma(double a, double b){
  double c = 0;
  c = a + b;
  return c;
}

double subtracao(double a, double b){
  double c = 0;
  c = a - b;
  return c;
}


double divisao(double a, double b){
  double c;
  if (b == 0){
      printf("\nNão é possível dividir por 0\n");
      return 0;
  } else{
      c = a/b;
      return c;
  }
}

double mult(double a, double b) {
  return a * b;
}

double raiz(double x){
  if (x <= 0) {
    printf("\nO número é negativo!\n");
    return 0;
  }
  return sqrt(x);
}

double potencia(double base, double expoente){
   return pow(base, expoente) ;
}

double media(double a, double b, double c){
    return (a+b+c)/ 3.0;
}

double porcentagem(double percent, double total){
    return(percent / 100) * total; 
}

double fatorial(double a) {
  if (a == 1) return 1;
  return fatorial(a - 1) * a;
}

int main() {
  char op;
  double temp, a, b, c;
  do {
    printf("\nCalculadora");
    printf("\n+ -> Soma");
    printf("\n- -> Subtração");
    printf("\n/ -> Divisão");
    printf("\n* -> Multiplicação");
    printf("\n^ -> Potenciação");
    printf("\nr -> Radiciação");
    printf("\nm -> Média");
    printf("\n%% -> Porcentagem");
    printf("\n! -> Fatorial");
    printf("\n0 -> Sair");
    printf("\nDigite a operação desejada: ");
    scanf("%c", &op);
    getchar();
    if (op == '0') continue;


    printf("Digite o primeiro nº: ");
    scanf("%lf", &a);
    getchar();

    printf("Digite o segundo nº: ");
    scanf("%lf", &b);
    getchar();

    switch (op) {
      case '+':
        temp = soma(a, b);
        printf("\nO resultado é %.4lf", temp);

      break;

      case '-':
        temp = subtracao(a, b);
        printf("\nO resultado é %.4lf", temp);

      break;

      case '/':
        temp = divisao(a, b);
        printf("\nO resultado é %.4lf", temp);

      break;

      case '*':
        temp = mult(a, b);
        printf("\nO resultado é %.4lf", temp);

      break;

      case '^':
        temp = potencia(a, b);
        printf("\nO resultado é %.4lf", temp);
      break;

      case 'r':
        temp = raiz(a);
        printf("\nA raiz do primeiro número é %.4lf", temp);

        temp = raiz(b);
        printf("\nA raiz do segundo número é %.4lf", temp);
      break;

      case 'm':
        printf("\nDigite mais um número: ");
        scanf("%lf", &c);
        getchar();

        temp = media(a, b, c);
        printf("\nO resultado é %.4lf", temp);
      break;

      case '%':
        temp = porcentagem(a, b);
        printf("\nO resultado é %.4lf", temp);
      break;

      case '!':
        temp = fatorial(a);
        printf("\nO fatorial do primeiro nº é %.4lf", temp);

        temp = fatorial(b);
        printf("\nO fatorial do segundo n é %.4lf", temp);
      break;

      default:
        printf("\nOperação inválida!\n");
    }

  } while (op != '0');
}