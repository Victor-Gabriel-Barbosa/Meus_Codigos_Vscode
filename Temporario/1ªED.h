#ifndef FUNCOES_H
#define FUNCOES_H

/* Limpa o buffer do terminal */
void limpa_buffer();

/* Limpa a tela do terminal */
void limpa_tela();

/* Exibe uma barra de divisão com cores */
void barra_div(const char *ini, const char *fin);

/* Solicita e retorna um número inteiro do usuário */
int get_num();

/* Solicita e retorna a escolha do vetor (PAR ou IMPAR) */
int get_vet();

/* Solicita e retorna o nome do arquivo do usuário */
char *get_nome_arqv();

/* Insere um elemento no vetor PAR ou IMPAR */
int insere_elemento(int valor, int par[], int *parCont, int impar[], int *imparCont, int tam);

/* Remove um elemento do vetor */
void remove_elemento(int valor, int vetor[], int *cont);

/* Consulta e retorna o elemento na posição especificada do vetor */
int consulta_elemento(int posicao, int vetor[], int cont);

/* Exibe todos os elementos do vetor */
void exibe_elementos(int vetor[], int cont);

/* Grava os elementos do vetor em um arquivo */
void grave_elemento(const char *filename, int vetor[], int cont);

/* Exibe o menu e retorna a opção escolhida */
int escolha_menu();

#endif // FUNCOES_H
