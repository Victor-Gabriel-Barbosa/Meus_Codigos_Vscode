#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include "lladae2_cocktail_sort.h"
#include "cores.h"

int main() {  
  do {
    limpaTela("Aperte " C_FMT(C_NEGRITO C_AZUL, "[ENTER]") " p/ iniciar...");
    printf(C_FMT(C_NEGRITO C_SUBLINHADO C_AZUL, "\n[INÍCIO]\n"));
    srand(time(NULL));
    clock_t inicio, fim;
    int i, j, temp;
    int qtd_l = escolheInt("Digite a " C_FMT(C_NEGRITO C_LARANJA, "quantidade de listas") " p/ testar", 1, 9);
    int qtd_n = escolheInt("Digite a " C_FMT(C_NEGRITO C_LARANJA, "quantidade de números") " p/ testar", 1, 999999);
    int min = escolheInt("Digite o " C_FMT(C_NEGRITO C_LARANJA, "valor mínimo") " a ser aleatorizado", 0, 999);
    int max = escolheInt("Digite o " C_FMT(C_NEGRITO C_LARANJA, "valor máximo") " a ser aleatorizado", min, 999999);
    Lista *listas[qtd_l], *mesclada; 

    for (i = 0; i < qtd_l; i++) { // Cria cada uma das listas
      listas[i] = listaCria();
    }
    mesclada = listaCria();

    for (i = 0; i < qtd_l; i++) { // Percorre o vetor de listas
      for (j = 0; j < qtd_n; j++) { // Insere todos os números
        temp = (rand() % (max - min + 1) + min); 
        listas[i] = (rand() % 2 == 1) ? listaInsereInicio(listas[i], temp) : listaInsereFim(listas[i], temp);
      }
    }

    limpaTela("Aperte " C_FMT(C_NEGRITO C_AZUL, "[ENTER]") " p/ continuar...");
    printf(C_FMT(C_NEGRITO C_SUBLINHADO C_AZUL, "\n[LISTA(S) ANTES DA ORDENAÇÃO]\n")); 
    for (i = 0; i < qtd_l; i++) { // Mostra os elementos de cada lista
      printf("\nLista %soriginal%s(%d)%s[%d]%s:\n", C_NEGRITO C_VERDE, C_MAGENTA, i + 1, C_AMARELO, listaSize(listas[i]), C_RESET);
      if (simOuNao("imprimir essa lista")) listaImprime(listas[i]);
    } 

    limpaTela("Aperte " C_FMT(C_NEGRITO C_AZUL, "[ENTER]") " p/ continuar...");
    printf(C_FMT(C_NEGRITO C_SUBLINHADO C_AZUL, "\n[TEMPO DE ORDENAÇÃO]\n")); 
    for (i = 0; i < qtd_l; i++) { // Ordena cada uma das listas usando o Cocktail Sort
      printf("\n%sOrdenando%s a lista%s(%d)%s[%d]%s...\n", C_NEGRITO C_AZUL, C_RESET, C_NEGRITO C_MAGENTA, i + 1, C_AMARELO, listaSize(listas[i]), C_RESET);
      inicio = clock();
      listas[i] = listaCocktailSort(listas[i]);
      fim = clock();
      printf("Tempo de " C_FMT(C_NEGRITO C_AZUL, "execução: %.4fs\n"), ((double)(fim - inicio)) / CLOCKS_PER_SEC);
    }

    limpaTela("Aperte " C_FMT(C_NEGRITO C_AZUL, "[ENTER]") " p/ continuar...");
    printf(C_FMT(C_NEGRITO C_SUBLINHADO C_AZUL, "\n[LISTA(S) ORDENADA(S)]\n")); 
    for (i = 0; i < qtd_l; i++) { // Mostra os elementos de cada lista depois de ordenar
      printf("\nLista %sordenada%s(%d)%s[%d]%s:\n", C_NEGRITO C_AZUL, C_MAGENTA, i + 1, C_AMARELO, listaSize(listas[i]), C_RESET);
      if (simOuNao("imprimir essa lista")) listaImprime(listas[i]);
    }

    limpaTela("Aperte " C_FMT(C_NEGRITO C_AZUL, "[ENTER]") " p/ continuar...");
    printf(C_FMT(C_NEGRITO C_SUBLINHADO C_AZUL, "\n[MESCLAGEM]\n")); 
    printf("\n%sMesclando%s listas...\n", C_NEGRITO C_AZUL, C_RESET);
    for (i = 0; i < qtd_l; i++) { // Mescla todas as listas
      mesclada = listaMescla(mesclada, listas[i]);
    } 
    printf("\nLista %sresultante%s[%d]%s:\n", C_NEGRITO C_AZUL, C_AMARELO, listaSize(mesclada), C_RESET);
    if (simOuNao("imprimir essa lista")) listaImprime(mesclada);

    for (i = 0; i < qtd_l; i++) { // Libera a memória de todas as listas
      listas[i] = listaLibera(listas[i]);
    }
    mesclada = listaLibera(mesclada);
  } while (simOuNao("testar novamente"));
  limpaTela("Aperte " C_FMT(C_NEGRITO C_VERMELHO, "[ENTER]") " p/ terminar...");
  return 0;
}