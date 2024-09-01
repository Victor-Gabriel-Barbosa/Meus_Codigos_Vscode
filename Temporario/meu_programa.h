#ifndef MEU_PROGRAMA_H
#define MEU_PROGRAMA_H

#include <stddef.h>

/* Variáveis que armazenam cores de texto */
extern const char *rset;
extern const char *azul;
extern const char *verd;
extern const char *cian;
extern const char *verm;
extern const char *mage;
extern const char *amar;

/* Variáveis que armazenam formatos de bordas */
extern const char *brd_vaz[];
extern const char *brd_dup[];
extern const char *brd_lev[];
extern const char *brd_dlv[];
extern const char *brd_lin[];
extern const char *brd_neg[];
extern const char *brd_crv[];
extern const char *brd_dcr[];
extern const char *brd_rsc[];
extern const char *brd_nrc[];
extern const char *brd_grd[];
extern const char *brd_grs[];
extern const char *brd_esp[];
extern const char *brd_trc[];
extern const char *brd_pnt[];

/* Struct para lidar com strings */
typedef struct {
  char *dados;
  size_t tam;
} string;

/* Captura exceções */
void catch_error(const char *msg);

/* Cria uma string a partir de um vetor de caracteres */
string new_str(const char *txt);

/* Libera a memória alocada para a string */
void free_str(string *s);

/* Lê uma string do teclado */
void scanf_str(string *s);

/* Concatena duas strings e retorna a string resultante */
string concat_str(const string s1, const string s2);

/* Compara duas strings */
int compare_str(const string *s1, const string *s2);

/* Substitui todas as ocorrências de um caractere por outro */
int subst_char(string *s, const char a, const char n);

/* Inverte uma string */
string inverte_str(const string s);

/* Divide uma string em tokens usando um delimitador */
string* split_str(const string *s, const char *dlm);

/* Calcula o verdadeiro tamanho de uma string */
size_t size_str(const char *s);

/* Centraliza uma string dentro de uma caixa */
string cnt_cx(const char *txt, const char **brd, const char *c_txt, const char *c_brd, int tam_cx);

/* Centraliza uma string à esquerda dentro de uma caixa */
string esq_cx(const char *txt, const char **brd, const char *c_txt, const char *c_brd, int tam_cx);

/* Centraliza uma string à direita dentro de uma caixa */
string dir_cx(const char *txt, const char **brd, const char *c_txt, const char *c_brd, int tam_cx);

/* Alinha duas caixas de texto lado a lado */
string align_cx(const string cx_txt1, const string cx_txt2, const int spcs);

/* Limpa o buffer do terminal */
void limpa_buffer(void);

/* Obtém o tamanho da tela */
void get_tam_tela(int *tam_l, int *tam_c);

/* Limpa a tela do terminal */
void cls_screen();

/* Aguarda uma entrada do usuário p/ limpar a tela do terminal */
void limpa_tela(void);

/* Limpa a tela do terminal */
void barra_div(const char *i, const char *f);

/* Exibe uma barra de divisão */
int get_num(const char *msg);

/* Solicita e retorna um número inteiro do usuário */
string get_str(const char *msg);

/* Solicita e retorna uma string do usuário */
int sim_ou_nao(const char *msg);

/* Exibe uma barra de carregamento */
double barra_carreg(const int tam);

#endif /* MEU_PROGRAMA_H */