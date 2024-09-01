/* Faça uma algoritmo que receba:
- O códido do produto comprado;
- A quantidade comprada do produto, supondo que a digitação do código do produto seja sempre válida (1 a 10);
- O peso do produto em quilos;
- O código do país de origem do produto, supondo que a digitação do código do país sejá sempre válida (1 a 3).

Calcule e mostre:
- O peso do produto convertido em gramas;
- O preço total do produto comprado;
- O valor do imposto, sabendo que o imposto é cobrado sobre o preço toal do produto comprado e depende do país de origem;
- O valor total, preço total maior o imposto. */
#include <stdio.h>

int main(void) {
  int cod_prod, peso_prod, cod_origem;
  float preco_prod, peso_gramas, preco_gramas, preco_gramas_aux[3] = {10, 25, 35}, imposto, imposto_aux[3] = {0.0, 0.15, 0.2}, preco_total, preco_total_imposto;
  printf("Digite o código do produto comprado[1-10]: ");
  scanf("%d", &cod_prod);
  printf("Digite o peso do produto em quilos: ");
  scanf("%d", &peso_prod);
  printf("Digite o código do país de origem do produto[1-3]: ");
  scanf("%d", &cod_origem);
  if (cod_prod >= 1 && cod_prod <= 4)
    preco_gramas = preco_gramas_aux[0];
  else if (cod_prod >= 5 && cod_prod <= 7)
    preco_gramas = preco_gramas_aux[1];
  else if (cod_prod >= 8 && cod_prod <= 10)
    preco_gramas = preco_gramas_aux[2];
  peso_gramas = peso_prod * 1000;
  preco_total = peso_gramas * preco_gramas;
  imposto = preco_total * imposto_aux[cod_origem - 1];
  preco_total_imposto = preco_total + imposto;
  printf("\nO peso do produto convertido em gramas é: %.2f kg\n", peso_gramas);
  printf("\nO preço total do produto comprado é: $%.2f\n", preco_total);
  printf("\nO valor do imposto é: $%.2f\n", imposto);
  printf("\nO valor total, preço total mais o imposto é: $%.2f\n", preco_total_imposto);
  
  return 0;
}