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
} String;

/* Captura exceções */
void catch_error(const char *msg);

/* Cria uma String a partir de um vetor de caracteres */
String new_str(const char *txt);

/* Libera a memória alocada para a String */
void free_str(String *s);

/* Lê uma String do teclado */
void scanf_str(String *s);

/* Concatena duas strings e retorna a String resultante */
String concat_str(const String s1, const String s2);

/* Compara duas strings */
int compare_str(const String *s1, const String *s2);

/* Substitui todas as ocorrências de um caractere por outro */
int subst_char(String *s, const char a, const char n);

/* Inverte uma String */
String inverte_str(const String s);

/* Divide uma String em tokens usando um delimitador */
String* split_str(const String *s, const char *dlm);

/* Converte um número inteiro para uma String */
String int_to_str(int n);

/* Converte um número real para uma String */
String float_to_str(double n);

/* Calcula o verdadeiro tamanho de uma String */
size_t size_str(const char *s);

/* Centraliza uma String dentro de uma caixa */
String cnt_cx(const char *txt, const char **brd, const char *c_txt, const char *c_brd, int tam_cx);

/* Centraliza uma String à esquerda dentro de uma caixa */
String esq_cx(const char *txt, const char **brd, const char *c_txt, const char *c_brd, int tam_cx);

/* Centraliza uma String à direita dentro de uma caixa */
String dir_cx(const char *txt, const char **brd, const char *c_txt, const char *c_brd, int tam_cx);

/* Alinha duas caixas de texto lado a lado */
String align_cx(const String cx_txt1, const String cx_txt2, const int spcs);

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
String get_str(const char *msg);

/* Solicita e retorna uma String do usuário */
int sim_ou_nao(const char *msg);

/* Exibe uma barra de carregamento */
double barra_carreg(const int tam);

#endif /* MEU_PROGRAMA_H */