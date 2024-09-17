#ifndef LLADAE2_COCKTAIL_SORT_H
#define LLADAE2_COCKTAIL_SORT_H

typedef struct lista Lista;

/* Cria uma nova lista vazia */ 
Lista *listaCria();

/* Tamanho da lista */
int listaSize(Lista *Ptl);

/* Insere um novo elemento no início da lista */
Lista *listaInsereInicio(Lista *list, const int dado);

/* Insere um novo elemento no fim da lista */
Lista *listaInsereFim(Lista *list, const int dado);

/* Remove um elemento da lista */
Lista *listaRemove(Lista *list, const int dado);

/* Libera toda a memória alocada para a lista */
Lista *listaLibera(Lista *list); 

/* Imprime a lista */
int listaImprime(Lista *list); 

/* Ordena a lista usando o algoritmo Cocktail Sort */
Lista *listaCocktailSort(Lista *list);

/* Mescla duas listas */
Lista *listaMescla(Lista *list1, Lista *list2);

/* Limpa o buffer do teclado */
void limpaBuffer(); 

/* Limpa a tela do terminal */
void cls();

/* Espera uma entrado do usuário antes de limpar a tela do terminal */
void limpaTela(const char *msg);

/* Escolhe um número inteiro dentro de um intervalo */
int escolheInt(const char *msg, const int min, const int max);

/* Confirma uma ação */
int simOuNao(const char *msg);

#endif 
