/* 8 - Faça uma algoritmo que receba:
- O códido do produto comprado;
- A quantidade comprada do produto, supondo que a digitação do código do produto
seja sempre válida (1 a 10);
- O peso do produto em quilos;
- O código do país de origem do produto, supondo que a digitação do código do
país sejá sempre válida (1 a 3). Calcule e mostre:
- O peso do produto convertido em gramas;
- O preço total do produto comprado;
- O valor do imposto, sabendo que o imposto é cobrado sobre o preço toal do
produto comprado e depende do país de origem;
- O valor total, preço total maior o imposto. */

#include <stdio.h>
#include <stdio_ext.h>

int main(void) {
  int cod_prod, peso_prod, cod_origem; // Declaração de variáveis
  float preco_prod, peso_g, preco_g, preco_g_aux[3] = {10, 25, 35}; // ...
  float imposto, imposto_aux[3] = {0.0, 0.15, 0.25}, preco_t, preco_t_imposto; // ...
  do { // Validação do código do produto
    printf("\nDigite o código do produto comprado[1-10]: ");
    scanf("%d", &cod_prod);
    __fpurge(stdin);
    if (cod_prod < 1 || cod_prod > 10) {
      printf("\n[Código inválido! Digite um código válido...]\n");
    }
  } while (cod_prod < 1 || cod_prod > 10);
  do { // Validação do peso do produto
    printf("\nDigite o peso do produto em quilos: ");
    scanf("%d", &peso_prod);
    __fpurge(stdin);
    if (peso_prod <= 0) {
      printf("\n[Peso inválido! Digite um peso válido...]\n");
    }
  } while (peso_prod <= 0);
  do { // Validação do código do país de origem
    printf("\nDigite o código do país de origem do produto[1-3]: ");
    scanf("%d", &cod_origem);
    __fpurge(stdin);
    if (cod_origem < 1 || cod_origem > 3) {
      printf("\n[Código inválido! Digite um código válido...]\n");
    }
  } while (cod_origem < 1 || cod_origem > 3);
  if (cod_prod >= 1 && cod_prod <= 4) { // Calcula o preço da grama de acordo com o código do produto
    preco_g = preco_g_aux[0];
  } else if (cod_prod >= 5 && cod_prod <= 7) { // ...
    preco_g = preco_g_aux[1];
  } else if (cod_prod >= 8 && cod_prod <= 10) { // ...
    preco_g = preco_g_aux[2];
  }
  peso_g = peso_prod * 1000; // Calcula o peso em gramas, o preço total do produto e o imposto
  preco_t = peso_g * preco_g; // ...
  imposto = preco_t * imposto_aux[cod_origem - 1]; // ...
  preco_t_imposto = preco_t + imposto; // ...
  printf("\n[O peso do produto convertido em gramas é: %.2f g]\n", peso_g); // Mostra os resultados 
  printf("\n[O preço total do produto comprado é: $%.2f]\n", preco_t); // ...
  printf("\n[O valor do imposto é: $%.2f]\n", imposto); // ...
  printf("\n[O valor total, preço total mais o imposto é: $%.2f]\n", preco_t_imposto); // ...
  return 0;
}