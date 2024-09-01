#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

/* Estrutura p/ armazenar a lista */
struct lista { 
  int FL;
  int dados[MAX];
};

/* Cria a lista */
Lista *Cria_lista(void) {
  Lista *pt = (Lista *)malloc(sizeof(Lista));
  if (pt != NULL) // Se a lista foi criada com sucesso
    pt->FL = 0;
  return pt;
}

/* Libera a lista */
Lista *Libera_lista(Lista *Ptl) {
  free(Ptl);
  return NULL;
}

/* Insere um elemento no final da lista */
Lista *Insere_elem(Lista *Ptl, int elem) {
  if (Ptl == NULL || Ptl->FL == MAX) // Se a lista não foi criada ou está cheia
    return Ptl;
  Ptl->dados[Ptl->FL] = elem;
  Ptl->FL++;
  return Ptl;
}

/* Remove um elemento da lista */
Lista *Remove_elem_mov(Lista *Ptl, int elem) {
  int i, k;
  if (Ptl == NULL || Ptl->FL == 0) // Se a lista não foi criada ou está vazia
    return Ptl;
  i = 0;
  while (i < Ptl->FL && Ptl->dados[i] != elem) // Procura o elemento na lista
    i++;
  if (i == Ptl->FL) // Se o elemento não foi encontrado
    return Ptl;
  for (k = i; k < Ptl->FL - 1; k++) // Remove o elemento da lista
    Ptl->dados[k] = Ptl->dados[k + 1];
  Ptl->FL--; // Atualiza o tamanho da lista
  return Ptl;
}

/* Remove um elemento da lista */
Lista *Remove_elem(Lista *Ptl, int elem) {
  int i, k;
  if (Ptl != NULL) { // Se a lista foi criada
    i = 0;
    while (i < Ptl->FL && Ptl->dados[i] != elem) // Procura o elemento na lista
      i++;
    if (i == Ptl->FL) { // Se o elemento não foi encontrado
      printf("\n[Elemento nao encontrado!]\n");
      return Ptl; 
    }
    Ptl->dados[i] = Ptl->dados[Ptl->FL - 1];
    Ptl->FL--; // Atualiza o tamanho da lista
  }
  return Ptl;
}

/* Retorna o elemento da posição posição dada */
int Consulta_nodo(Lista *Ptl, int pos, int *info) {
  if (Ptl == NULL) // Se a lista não foi criada
    return 0;
  if (pos <= 0 || pos > Ptl->FL) // Se a posição é inválida
    return 0;
  *info = Ptl->dados[pos - 1];
  return 1;
}

/* Retorna o tamanho da lista */
int Tamanho_lista(Lista *Ptl) {
  if (Ptl == NULL) // Se a lista não foi criada
    return -1;//
  return Ptl->FL;
}

/* Verifica se a lista está cheia */
int E_cheia(Lista *Ptl) {
  if (Ptl == NULL) { // Se a lista não foi criada
    printf("\n[Erro: a lista não foi criada!]\n");
    return -1;
  }
  if (Ptl->FL == MAX) { // Se a lista está cheia
    printf("\n[A lista esta cheia!]\n");
    return 1;
  }
  return 0;
}

/* Verifica se a lista está vazia */
int E_vazia(Lista *Ptl) { 
  if (Ptl == NULL) // Se a lista não foi criada
    return -1;
  if (Ptl->FL == 0) // Se a lista está vazia
    return 1;
  return 0;
}

/* Limpa o buffer do terminal */
void limpa_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

/* Exibe a lista */
int exibe_lista(Lista *Ptl) { 
  if (Ptl == NULL) { // Se a lista não foi criada
    printf("\n[Lista nao existe!]\n");
    return -1;
  }
  for (int i = 0; i < Ptl->FL; i++) { // Percorre a lista
    printf(i == 0 ? "%d" : ", %d", Ptl->dados[i]);
  }
  printf("\n");
  return 1;
}

/* Grava a lista em um arquivo */
int grava_lista(Lista *Ptl, char *nome_arqv) { 
  if (Ptl == NULL) { // Se a lista não foi criada
    printf("\n[Lista nao existe!]\n");
    return -1;
  }
  FILE *fp = fopen(nome_arqv, "w"); // Abre o arquivo para escrita
  if (fp == NULL) { // Se o arquivo não foi aberto
    printf("\n[Erro ao abrir o arquivo %s]\n", nome_arqv);
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < Ptl->FL; i++) { // Percorre a lista
    fprintf(fp, "%d\n", Ptl->dados[i]);
  }
  fclose(fp); // Fecha o arquivo
  return 1;
}