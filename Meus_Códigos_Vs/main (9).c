/*
10 – Foi feita uma estatística em cinco cidades brasileiras para coletar dados sobre
acidentes de trânsito. Foram obtidos os seguintes dados:
 a) código da cidade;
 b) número de veículos de passeio;
 c) número de acidentes de trânsito com vitimas.

Deseja se saber:
a) qual o maior e o menor índice de acidentes de trânsito e a qual cidade pertence;
b) qual a média de veículos nas cinco cidades juntas;
c) qual a média de acidentes de transito nas cidades com menos de 2000 veículos
de passeio. 
*/
#include <stdio.h>
#define CIDADES 5

int main(void) {
  int cod[CIDADES], veiculos[CIDADES], acidentes[CIDADES], soma_veiculos = 0, soma_acidentes = 0, soma_acidentes_cidades_menos_2000 = 0, cidades_menos_2000 = 0, i, j, cod_aux_maior, cod_aux_menor, loop;
  float media_veiculos = 0, media_acidentes = 0, menor = 0, maior = 0, media_acidentes_menos_2000 = 0, indice_acidentes[CIDADES];
  for (i = 0; i < CIDADES; i++) {
    do {
      loop = 0;
      printf("\nDigite o código da cidade: ");
      scanf("%d", &cod[i]);
      for (j = 0; j < CIDADES; j++) {
        if (i != j && cod[i] == cod[j]) {
          loop = 1;
          printf("\nCódigo já cadastrado! Digite outro código...\n");
        }
      }
    } while (loop);
    printf("\nDigite o número de veículos de passeio: ");
    scanf("%d", &veiculos[i]);
    printf("\nDigite o número de acidentes de trânsito com vitimas: ");
    scanf("%d", &acidentes[i]);
    soma_veiculos += veiculos[i];
    soma_acidentes += acidentes[i];
    indice_acidentes[i] = (float)acidentes[i] / veiculos[i];
    if (i == 0 || indice_acidentes[i] > maior) {
      maior = indice_acidentes[i];
      cod_aux_maior = cod[i];
    }
    if (i == 0 || indice_acidentes[i] < menor) {
      menor = indice_acidentes[i];
      cod_aux_menor = cod[i];
    }
    if (veiculos[i] < 2000) {
      cidades_menos_2000++;
      soma_acidentes_cidades_menos_2000 += acidentes[i];
    }
  }
  media_veiculos = (float)soma_veiculos / CIDADES;
  media_acidentes = (float)soma_acidentes / CIDADES;
  media_acidentes_menos_2000 = (float)soma_acidentes_cidades_menos_2000 / cidades_menos_2000;
  printf("\nO maior índice de acidentes de trânsito é %2.f porcento e pertence à cidade %d.", maior*100, cod_aux_maior);
  printf("\nO menor índice de acidentes de trânsito é %2.f porcento e pertence à cidade %d.", menor*100, cod_aux_menor);
  printf("\nA média de veículos nas cinco cidades juntas é %.2f", media_veiculos);
  printf("\nA média de acidentes de trânsito nas cidades com menos de 2000 veículos de passeio é %.2f", media_acidentes_menos_2000);

  return 0;
}
