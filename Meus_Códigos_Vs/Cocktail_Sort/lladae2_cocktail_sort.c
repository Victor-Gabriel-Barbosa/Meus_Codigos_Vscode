#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "lladae2_cocktail_sort.h"
#include "cores.h"

typedef struct no { // Estrutura que armazena os nós da lista
  int dado;
  struct no *prox;
  struct no *ant;
} No;

typedef struct lista { // Estrutura que armazena a lista
  No *inicio;
  No *fim;
  int tam;
} Lista;

/* Cria uma nova lista vazia */ 
Lista *listaCria() {
  Lista *Ptl = (Lista *)malloc(sizeof(Lista));
  if (Ptl != NULL) { // Inicializa a lista se a alocação for bem sucedida
    Ptl->inicio = NULL;
    Ptl->fim = NULL;
    Ptl->tam = 0;
  }
  return Ptl;
}

/* Tamanho da lista */
int listaSize(Lista *Ptl) { 
  return Ptl->tam;
}

/* Insere um novo elemento no início da lista */
Lista* listaInsereInicio(Lista *Ptl, const int dado) {
  No *novo = (No *)malloc(sizeof(No));
  if (novo == NULL) return Ptl; 
  novo->dado = dado;
  novo->prox = Ptl->inicio;
  novo->ant = NULL;
  if (Ptl->inicio != NULL) Ptl->inicio->ant = novo; 
  Ptl->inicio = novo;
  if (Ptl->fim == NULL) Ptl->fim = novo; 
  Ptl->tam++;
  return Ptl;
}

/* Insere um novo elemento no fim da lista */
Lista *listaInsereFim(Lista *Ptl, const int dado) {
  No *novo = (No *)malloc(sizeof(No));
  if (novo == NULL) return Ptl;
  novo->dado = dado;
  novo->prox = NULL;
  novo->ant = Ptl->fim;
  if (Ptl->fim != NULL) Ptl->fim->prox = novo;
  Ptl->fim = novo;
  if (Ptl->inicio == NULL) Ptl->inicio = novo;
  Ptl->tam++;
  return Ptl;
}

/* Remove um elemento da lista */
Lista *listaRemove(Lista *Ptl, const int dado) {
  if (Ptl == NULL) return Ptl;
  No *atual = Ptl->inicio;
  while (atual != NULL) { // Percorre a lista
    if (atual->dado == dado) { // Se encontrou o dado, remove e retorna a lista
      if (atual->ant != NULL) atual->ant->prox = atual->prox;
      else Ptl->inicio = atual->prox;
      if (atual->prox != NULL) atual->prox->ant = atual->ant;
      else Ptl->fim = atual->ant;
      free(atual);
      Ptl->tam--;
      return Ptl;
    }
    atual = atual->prox;
  }
  return Ptl;
}

/* Libera toda a memória alocada para a lista */
Lista *listaLibera(Lista *Ptl) {
  if (Ptl == NULL) return Ptl;
  No *atual = Ptl->inicio;
  No *prox;
  while (atual != NULL) { // Libera todos os nós da lista
    prox = atual->prox;
    free(atual); 
    atual = prox;
  }
  free(Ptl); 
  return Ptl;
}

/* Imprime a lista */
int listaImprime(Lista *Ptl) {
  if (Ptl == NULL || Ptl->inicio == NULL) return 0;
  No *atual = Ptl->inicio;
  while (atual != NULL) { // Mostra todos os elementos da lista
    printf("%d ", atual->dado);
    atual = atual->prox;
  }
  printf("\n");
  return 1;
} 

/* Ordena a lista usando o algoritmo Cocktail Sort */
Lista *listaCocktailSort(Lista *Ptl) {
  if (Ptl == NULL || Ptl->inicio == NULL) return Ptl;
  int trocou, temp;
  No *inicio = Ptl->inicio; 
  No *fim = Ptl->fim;
  No *atual;
  do { // Repete enquanto houver trocas
    trocou = 0;
    atual = inicio;
    while (atual != fim) { // Percorre da esquerda para a direita
      if (atual->dado > atual->prox->dado) { // Troca os valores dos nós se o dado atual for maior que o próximo
        temp = atual->dado;
        atual->dado = atual->prox->dado;
        atual->prox->dado = temp;
        trocou = 1;
      }
      atual = atual->prox;
    }
    if (!trocou) continue; // A lista já está ordenada se não houve trocas
    fim = fim->ant; // Atualiza o ponteiro fim para a próxima iteração
    trocou = 0;
    atual = fim;
    while (atual != inicio) {  // Percorre da direita para a esquerda
      if (atual->dado < atual->ant->dado) { // Troca os valores dos nós se o dado atual for menor que o anterior
        temp = atual->dado;
        atual->dado = atual->ant->dado;
        atual->ant->dado = temp;
        trocou = 1;
      }
      atual = atual->ant;
    }
    inicio = inicio->prox; // Atualiza o ponteiro início para a próxima iteração
  } while (trocou);
  return Ptl;
}

/* Mescla duas listas */
Lista *listaMescla(Lista *Ptl1, Lista *Ptl2) {
  No *n1 = Ptl1->inicio;
  No *n2 = Ptl2->inicio;
  Lista *novaLista = listaCria();
  while (n1 != NULL && n2 != NULL) { // Percorre as duas listas
    if (n1->dado < n2->dado) { // Insere o menor elemento da lista
      listaInsereFim(novaLista, n1->dado);
      n1 = n1->prox;
    } else {
      listaInsereFim(novaLista, n2->dado);
      n2 = n2->prox;
    }
  }
  while (n1 != NULL) { // Insere os elementos restantes da lista 1
    listaInsereFim(novaLista, n1->dado);
    n1 = n1->prox;
  }
  while (n2 != NULL) { // Insere os elementos restantes da lista 2
    listaInsereFim(novaLista, n2->dado);
    n2 = n2->prox;
  }
  return novaLista;
}

/* Limpa o buffer do teclado */
void limpaBuffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

/* Limpa a tela do terminal */
void cls() {
  #ifdef _WIN32
    system("cls");
  #else 
    system("clear");
  #endif 
} 

/* Espera uma entrado do usuário antes de limpar a tela do terminal */
void limpaTela(const char *msg) {
  printf("\n%s", msg);
  limpaBuffer();
  cls();
}

/* Escolhe um número inteiro dentro de um intervalo */
int escolheInt(const char *msg, const int min, const int max) {
  while (1) { // Verifica se o número é válido
    int num;
    printf("\n%s\n", msg);
    printf("%s[%d%s-%s%d]%s: ", C_NEGRITO C_AZUL, min, C_MAGENTA, C_VERMELHO, max, C_RESET);
    scanf("%d", &num);
    limpaBuffer();
    if (num >= min && num <= max) return num;
    printf(C_FMT_ERRO("\n[Número inválido! Tente novamente...]\n"));
  }
}

/* Confirma uma ação */
int simOuNao(const char *msg) { 
  while (1) { // Confirma uma ação
    printf("\nDeseja %s%s%s?\n", C_NEGRITO C_VERMELHO, msg, C_RESET);
    printf("%s[S%s/%sN]%s: ", C_NEGRITO C_AZUL, C_MAGENTA, C_VERMELHO, C_RESET);
    char op = tolower(getchar());
    limpaBuffer();
    if (op == 's') return 1;
    if (op == 'n') return 0;
    printf(C_FMT_ERRO("\n[Opção inválida!]\n"));
  }
}