#include "meu_programa.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

/* Variáveis que armazenam cores de texto */
const char *rset = "\033[0m";
const char *azul = "\033[38;5;39m";
const char *verd = "\033[38;5;46m";
const char *cian = "\033[38;5;51m";
const char *verm = "\033[38;5;196m";
const char *mage = "\033[38;5;201m";
const char *amar = "\033[38;5;220m";

/* Variáveis que armazenam formatos de bordas */
const char *brd_vaz[] = {"", "", "", "", "", "", "", ""}; 
const char *brd_dup[] = {"╔", "═", "╗", "║", "║", "╚", "═", "╝"};
const char *brd_lev[] = {"⎡", "⎺", "⎤", "⎢", "⎥", "⎣", "⎽", "⎦"};
const char *brd_dlv[] = {"╔", "─", "╗", "║", "║", "╚", "─", "╝"};
const char *brd_lin[] = {"┌", "─", "┐", "│", "│", "└", "─", "┘"};
const char *brd_neg[] = {"┏", "━", "┓", "┃", "┃", "┗", "━", "┛"};
const char *brd_crv[] = {"╭", "─", "╮", "│", "│", "╰", "─", "╯"};
const char *brd_dcr[] = {"╭", "═", "╮", "║", "║", "╰", "═", "╯"};
const char *brd_rsc[] = {"╒", "═", "╕", "│", "│", "╘", "═", "╛"};
const char *brd_nrc[] = {"┏", "╍", "┓", "╎", "╎", "┗", "╍", "┛"};
const char *brd_grd[] = {"▛", "▀", "▜", "▌", "▐", "▙", "▄", "▟"};
const char *brd_grs[] = {"▛", "▄", "▜", "▌", "▐", "▙", "▀", "▟"};
const char *brd_esp[] = {"╓", "─", "╖", "║", "║", "╙", "─", "╜"};
const char *brd_trc[] = {"⟬", "⟶", "⟭", "⟪", "⟫", "⟯", "⟵", "⟰"};
const char *brd_pnt[] = {"┌", "┈", "┐", "┆", "┆", "└", "┈", "┘"};

/* Captura exceções */
void catch_error(const char *msg) { 
  fprintf(stderr, "\n%s[Erro: %s!]%s\n", verm, msg, rset);
  exit(EXIT_FAILURE);
}

/* Cria uma String a partir de um vetor de caracteres */
String new_str(const char *txt) {
  if (txt == NULL) { // Verifica se o vetor de caracteres é válido
    catch_error("Texto de entrada é NULL");
  }
  String s;
  s.tam = strlen(txt);
  s.dados = (char*)malloc((s.tam + 1) * sizeof(char));
  if (s.dados == NULL) { // Verifica se a alocação de memória foi bem-sucedida
    catch_error("Alocação de memória para String falhou");
  }
  strcpy(s.dados, txt);
  return s;
}

/* Libera a memória alocada para a String */
void free_str(String *s) {
  free(s->dados);
  s->dados = NULL;
  s->tam = 0;
}

/* Lê uma String do teclado */
void scanf_str(String *s) {
  s->dados = NULL;
  size_t tam = 0;
  ssize_t comp = getline(&s->dados, &tam, stdin);
  if (comp == -1) { // Verifica se houve um erro ao ler a String
    catch_error("Leitura de String falhou");
  }
  s->dados[strcspn(s->dados, "\n")] = '\0'; // Remove o caractere de nova linha
  s->tam = strlen(s->dados); // Atualiza o tamanho da String
}

/* Concatena duas strings e retorna a String resultante */
String concat_str(const String s1, const String s2) {
  String result;
  result.tam = s1.tam + s2.tam;
  result.dados = (char *)malloc((result.tam + 1) * sizeof(char));
  if (result.dados == NULL) { // Verifica se a alocação de memória foi bem-sucedida
    catch_error("Alocação de memória para String falhou");
  }
  strcpy(result.dados, s1.dados);
  strcat(result.dados, s2.dados);
  return result;
}

/* Compara duas strings */
int compare_str(const String *s1, const String *s2) {
  return strcmp(s1->dados, s2->dados);
}

/* Substitui todas as ocorrências de um caractere por outro */
int subst_char(String *s, const char a, const char n) {
  int cont = 0; // Contador de substituições
  for (size_t i = 0; i < s->tam; i++) { // Percorre a String
    if (s->dados[i] == a) { // Verifica se o caractere é igual ao antigo
      s->dados[i] = n;
      cont++;
    }
  }
  return cont;
}

/* Inverte uma String */
String inverte_str(const String s) {
  if (s.tam == 0 || s.dados == NULL) {
    return s; // Retorna a String original se estiver vazia ou for nula
  }
  String result = s; // Faz uma cópia da String de entrada
  for (size_t i = 0, j = s.tam - 1; i < j; i++, j--) { // Percorre a String de trás para frente
    result.dados[i] ^= result.dados[j];
    result.dados[j] ^= result.dados[i];
    result.dados[i] ^= result.dados[j];
  }
  return result; // Retorna a String invertida
}

/* Divide uma String em tokens usando um delimitador */
String* split_str(const String *s, const char *dlm) {
  char *temp = strdup(s->dados);
  if (temp == NULL) { // Verifica se a alocação de memória foi bem-sucedida
    catch_error("Falha ao duplicar a String.");
  }
  char *token, *rest = temp; // Rest é uma cópia da String original
  size_t count = 0;
  while ((token = strtok_s(rest, dlm, &rest))) { // Descobre o número de tokens
    count++;
  }
  free(temp); // Libera a memória alocada para a String temporária
  temp = strdup(s->dados); // Duplica a String original
  rest = temp; // Restaura a String original
  String *result = (String *)malloc((count + 1) * sizeof(String));
  if (result == NULL) { // Verifica se a alocação de memória foi bem-sucedida
    catch_error("Alocação de memória para String falhou");
  }
  size_t i = 0;
  while ((token = strtok_s(rest, dlm, &rest))) { // Divide a String em tokens
    result[i] = new_str(token);
    i++;
  }
  result[i].dados = NULL; // Define o último elemento como NULL
  result[i].tam = 0; // Define o tamanho do último elemento como 0
  free(temp); // Libera a memória alocada para a String temporária
  return result; // Retorna o vetor de strings
}

/* Converte um número inteiro para uma String */
String int_to_str(int n) { 
  char buffer[100]; // Buffer temporário para armazenar a String formatada
  sprintf(buffer, "%d", n); // Formata o número inteiro em uma String
  return new_str(buffer);;
}

/* Converte um número real para uma String */
String float_to_str(double n) { 
  char buffer[100]; // Buffer temporário para armazenar a String formatada
  sprintf(buffer, "%.2f", n); // Formata o número com duas casas decimais
  return new_str(buffer);
}

/* Calcula o verdadeiro tamanho de uma String */
size_t size_str(const char *s) {
  size_t tam = 0;
  while (*s) { // Percorre a String
    if (*s == '\033') { // Verifica se o caractere é uma sequência de escape ANSI
      s = strchr(s, 'm'); // Encontra o fim da sequência
      if (s) { // Verifica se a sequência foi encontrada
        s++; // Pula a sequência
        continue;
      } else { // Se a sequência não foi encontrada
        catch_error("Sequência de escape ANSI inválida detectada!");
      }
    }
    unsigned char c = (unsigned char)*s; // Obtém o valor ASCII do caractere
    if (c < 0x80) { s++; } // Pula caracteres com menos de 8 bits
    else if (c < 0xE0) { s += 2; } // Pula caracteres com 8 a 12 bits
    else if (c < 0xF0) { s += 3; } // Pula caracteres com 13 a 16 bits
    else { s += 4; } // Pula caracteres com 17 a 21 bits
    tam++;
  }
  return tam; // Retorna o tamanho calculado da String
}

/* Centraliza uma String dentro de uma caixa */
String cnt_cx(const char *txt, const char **brd, const char *c_txt, const char *c_brd, int tam_cx) {
  if (brd == NULL || brd[0] == NULL || brd[7] == NULL) { // Verifica se as bordas são válidas
    catch_error("Bordas inválidas");
  }
  String txt_temp = new_str(txt), cx_txt = new_str(""); // strings auxiliares
  ssize_t max_tam_txt = 0, tam_txt = 0, spcs = 0, i, j; // Variáveis auxiliares
  String *linhas = split_str(&txt_temp, "\n"); // Divide a String em linhas

  /* Descobre o tamanho máximo de linha */
  for (i = 0; linhas[i].dados != NULL; i++) { // Percorre as linhas
    tam_txt = size_str(linhas[i].dados); // Obtém o tamanho da linha
    if (tam_txt > max_tam_txt) { // Atualiza o tamanho máximo de linha
      max_tam_txt = tam_txt;
    }
  }

  /* Atualiza o tamanho da caixa se necessário */
  tam_cx = (tam_cx < max_tam_txt + 2) ? max_tam_txt + 2 : tam_cx; 
  /* Concatena a borda superior */
  cx_txt = concat_str(cx_txt, new_str(c_brd)); // Cor da borda superior
  cx_txt = concat_str(cx_txt, new_str(brd[0])); // Borda superior esquerda
  for (i = 0; i < tam_cx - 2; ++i) { 
    cx_txt = concat_str(cx_txt, new_str(brd[1])); // Borda superior central
  }
  cx_txt = concat_str(cx_txt, new_str(brd[2])); // Borda superior direita
  cx_txt = concat_str(cx_txt, new_str(rset)); // Reseta a cor
  cx_txt = concat_str(cx_txt, new_str("\n")); // Quebra de linha

  /* Concatena as linhas de texto */
  for (i = 0; linhas[i].dados != NULL; i++) { // Percorre as linhas de texto
    tam_txt = size_str(linhas[i].dados); // Obtém o tamanho da linha
    spcs = (tam_cx - tam_txt - 2) / 2; // Calcula o número de espaços em branco
    cx_txt = concat_str(cx_txt, new_str(c_brd)); // Cor da borda esquerda
    cx_txt = concat_str(cx_txt, new_str(brd[3])); // Borda esquerda
    for (j = 0; j < spcs; j++) { // Alinha as linhas de texto ao centro
      cx_txt = concat_str(cx_txt, new_str(" ")); 
    }
    cx_txt = concat_str(cx_txt, new_str(c_txt)); // Cor do texto
    cx_txt = concat_str(cx_txt, linhas[i]); // Conteúdo da linha
    cx_txt = concat_str(cx_txt, new_str(rset)); // Reseta a cor do texto
    for (j = 0; j < tam_cx - tam_txt - spcs - 2; j++) { // Alinha as linhas de texto ao centro
      cx_txt = concat_str(cx_txt, new_str(" "));
    }
    cx_txt = concat_str(cx_txt, new_str(c_brd)); // Cor da borda direita
    cx_txt = concat_str(cx_txt, new_str(brd[4])); // Borda direita
    cx_txt = concat_str(cx_txt, new_str(rset)); // Reseta a cor da borda
    cx_txt = concat_str(cx_txt, new_str("\n")); // Quebra de linha
  }

  /* Concatena a borda inferior */
  cx_txt = concat_str(cx_txt, new_str(c_brd)); // Cor da borda inferior
  cx_txt = concat_str(cx_txt, new_str(brd[5])); // Borda inferior esquerda
  for (i = 0; i < tam_cx - 2; ++i) { 
    cx_txt = concat_str(cx_txt, new_str(brd[6])); // Borda inferior central
  }
  cx_txt = concat_str(cx_txt, new_str(brd[7])); // Borda inferior direita
  cx_txt = concat_str(cx_txt, new_str(rset)); // Reseta a cor
  cx_txt = concat_str(cx_txt, new_str("\n")); // Quebra de linha

  /* Libera a memória das strings temporárias */
  free_str(&txt_temp);
  for (i = 0; linhas[i].dados != NULL; i++) { 
    free_str(&linhas[i]);
  }
  free(linhas);
  
  return cx_txt; // Retorna a caixa de texto formatada
}

/* Centraliza uma String à esquerda dentro de uma caixa */
String esq_cx(const char *txt, const char **brd, const char *c_txt, const char *c_brd, int tam_cx) {
  if (!brd || brd[0] == NULL || brd[7] == NULL) { // Verifica se as bordas são válidas
    catch_error("Bordas inválidas");
  }
  String txt_temp = new_str(txt), cx_txt = new_str(""); // strings auxiliares
  size_t max_tam_txt = 0, tam_txt = 0, spcs = 0, i, j; // Variáveis auxiliares
  String *linhas = split_str(&txt_temp, "\n"); // Divide a String em linhas

  /* Descobre o tamanho máximo de linha */
  for (i = 0; linhas[i].dados != NULL; i++) { 
    tam_txt = size_str(linhas[i].dados); // Obtém o tamanho da linha
    if (tam_txt > max_tam_txt) { // Atualiza o tamanho máximo de linha
      max_tam_txt = tam_txt;
    }
  }

  /* Atualiza o tamanho da caixa se necessário */
  tam_cx = (tam_cx < max_tam_txt + 2) ? max_tam_txt + 2 : tam_cx; 

  /* Concatena a borda superior */
  cx_txt = concat_str(cx_txt, new_str(c_brd)); // Cor da borda superior
  cx_txt = concat_str(cx_txt, new_str(brd[0])); // Borda superior esquerda
  for (i = 0; i < tam_cx - 2; ++i) { 
    cx_txt = concat_str(cx_txt, new_str(brd[1])); // Borda superior central
  }
  cx_txt = concat_str(cx_txt, new_str(brd[2])); // Borda superior direita
  cx_txt = concat_str(cx_txt, new_str(rset)); // Reseta a cor da borda
  cx_txt = concat_str(cx_txt, new_str("\n")); // Quebra de linha

  /* Concatena as linhas de texto */
  for (i = 0; linhas[i].dados != NULL; i++) { // Percorre as linhas de texto
    tam_txt = size_str(linhas[i].dados); // Obtém o tamanho da linha
    cx_txt = concat_str(cx_txt, new_str(c_brd)); // Cor da borda esquerda
    cx_txt = concat_str(cx_txt, new_str(brd[3])); // Borda esquerda
    cx_txt = concat_str(cx_txt, new_str(c_txt)); // Cor do texto
    cx_txt = concat_str(cx_txt, linhas[i]); // Conteúdo da linha
    for (j = 0; j < tam_cx - tam_txt - 2; j++) { // Alinha as linhas de texto à esquerda
      cx_txt = concat_str(cx_txt, new_str(" "));
    }
    cx_txt = concat_str(cx_txt, new_str(rset)); // Reseta a cor do texto
    cx_txt = concat_str(cx_txt, new_str(c_brd)); // Cor da borda direita
    cx_txt = concat_str(cx_txt, new_str(brd[4])); // Borda direita
    cx_txt = concat_str(cx_txt, new_str(rset)); // Reseta a cor da borda
    cx_txt = concat_str(cx_txt, new_str("\n")); // Quebra de linha
  }

  /* Concatena a borda inferior */
  cx_txt = concat_str(cx_txt, new_str(c_brd)); // Cor da borda inferior
  cx_txt = concat_str(cx_txt, new_str(brd[5])); // Borda inferior esquerda
  for (i = 0; i < tam_cx - 2; ++i) { 
    cx_txt = concat_str(cx_txt, new_str(brd[6])); // Borda inferior central
  }
  cx_txt = concat_str(cx_txt, new_str(brd[7])); // Borda inferior direita
  cx_txt = concat_str(cx_txt, new_str(rset)); // Reseta a cor da borda
  cx_txt = concat_str(cx_txt, new_str("\n")); // Quebra de linha

  /* Libera a memória das strings temporárias */
  free_str(&txt_temp);
  for (i = 0; linhas[i].dados != NULL; i++) {
    free_str(&linhas[i]);
  }
  free(linhas);

  return cx_txt; // Retorna a caixa de texto formatada
}

/* Centraliza uma String à direita dentro de uma caixa */
String dir_cx(const char *txt, const char **brd, const char *c_txt, const char *c_brd, int tam_cx) {
  if (!brd || brd[0] == NULL || brd[7] == NULL) { // Verifica se as bordas são válidas
    catch_error("Bordas inválidas");
  }
  String txt_temp = new_str(txt), cx_txt = new_str(""); // strings auxiliares
  size_t max_tam_txt = 0, tam_txt = 0, spcs = 0, i, j; // Variáveis auxiliares
  String *linhas = split_str(&txt_temp, "\n"); // Divide a String em linhas

  /* Descobre o tamanho máximo de linha */
  for (i = 0; linhas[i].dados != NULL; i++) { // Percorre as linhas
    tam_txt = size_str(linhas[i].dados); // Obtém o tamanho da linha
    if (tam_txt > max_tam_txt) { // Atualiza o tamanho máximo de linha
      max_tam_txt = tam_txt;
    }
  }

  /* Atualiza o tamanho da caixa se necessário */
  tam_cx = (tam_cx < max_tam_txt + 2) ? max_tam_txt + 2 : tam_cx; 

  /* Concatena a borda superior */
  cx_txt = concat_str(cx_txt, new_str(c_brd)); // Cor da borda superior
  cx_txt = concat_str(cx_txt, new_str(brd[0])); // Borda superior esquerda
  for (i = 0; i < tam_cx - 2; ++i) { 
    cx_txt = concat_str(cx_txt, new_str(brd[1])); // Borda superior central
  }
  cx_txt = concat_str(cx_txt, new_str(brd[2])); // Borda superior direita
  cx_txt = concat_str(cx_txt, new_str(rset)); // Reseta a cor da borda
  cx_txt = concat_str(cx_txt, new_str("\n")); // Quebra de linha

  /* Concatena as linhas de texto */
  for (i = 0; linhas[i].dados != NULL; i++) { // Percorre as linhas de texto
    tam_txt = size_str(linhas[i].dados); // Obtém o tamanho da linha
    cx_txt = concat_str(cx_txt, new_str(c_brd)); // Cor da borda esquerda
    cx_txt = concat_str(cx_txt, new_str(brd[3])); // Borda esquerda
    for (j = 0; j < tam_cx - tam_txt - 2; j++) { // Alinha as linhas de texto à direita
      cx_txt = concat_str(cx_txt, new_str(" "));
    }
    cx_txt = concat_str(cx_txt, new_str(c_txt)); // Cor do texto
    cx_txt = concat_str(cx_txt, linhas[i]); // Conteúdo da linha
    cx_txt = concat_str(cx_txt, new_str(rset)); // Reseta a cor do texto
    cx_txt = concat_str(cx_txt, new_str(c_brd)); // Cor da borda direita
    cx_txt = concat_str(cx_txt, new_str(brd[4])); // Borda direita
    cx_txt = concat_str(cx_txt, new_str(rset)); // Reseta a cor da borda
    cx_txt = concat_str(cx_txt, new_str("\n")); // Quebra de linha
  }

  /* Concatena a borda inferior */
  cx_txt = concat_str(cx_txt, new_str(c_brd)); // Cor da borda inferior
  cx_txt = concat_str(cx_txt, new_str(brd[5])); // Borda inferior esquerda
  for (i = 0; i < tam_cx - 2; ++i) { 
    cx_txt = concat_str(cx_txt, new_str(brd[6])); // Borda inferior central
  }
  cx_txt = concat_str(cx_txt, new_str(brd[7])); // Borda inferior direita
  cx_txt = concat_str(cx_txt, new_str(rset)); // Reseta a cor da borda
  cx_txt = concat_str(cx_txt, new_str("\n")); // Quebra de linha

  /* Libera a memória das strings temporárias */
  free_str(&txt_temp);
  for (i = 0; linhas[i].dados != NULL; i++) {
    free_str(&linhas[i]);
  }
  free(linhas);

  return cx_txt; // Retorna a caixa de texto formatada
}

/* Alinha duas caixas de texto lado a lado */
String align_cx(const String cx_txt1, const String cx_txt2, const int spcs) { 
  size_t i = 0, j = 0, k = 0;
  String cx_fin = new_str("");

  /* Divide as caixas de texto em linhas */
  String *lin1 = split_str(&cx_txt1, "\n");
  String *lin2 = split_str(&cx_txt2, "\n");

  /* Concatena linhas das duas caixas */
  while (lin1[i].dados != NULL || lin2[j].dados != NULL) { // Percorre as linhas
    if (lin1[i].dados != NULL) { // Concatena a primeira caixa
      cx_fin = concat_str(cx_fin, lin1[i]);
      i++;
    } else { // Adiciona espaços se lin1 terminou
      for (k = 0; k < size_str(lin1[i - 1].dados); k++) { // Percorre a linha anterior
        cx_fin = concat_str(cx_fin, new_str(" ")); 
      }
    }
    for (k = 0; k < spcs; k++) { // Separa as caixas com espaços em branco
      cx_fin = concat_str(cx_fin, new_str(" "));
    }
    if (lin2[j].dados != NULL) { // Concatena a segunda caixa
      cx_fin = concat_str(cx_fin, lin2[j]);
      j++;
    } else { // Adiciona espaços se lin2 terminou
      for (k = 0; k < size_str(lin2[j - 1].dados); k++) { // Percorre a linha anterior
        cx_fin = concat_str(cx_fin, new_str(" "));
      }
    }
    cx_fin = concat_str(cx_fin, new_str("\n")); // Quebra de linha
  }

  /* Libera a memória das strings temporárias */
  for (i = 0; lin1[i].dados != NULL; i++) {
    free_str(&lin1[i]);
  }
  free(lin1);
  for (j = 0; lin2[j].dados != NULL; j++) {
    free_str(&lin2[j]);
  }
  free(lin2);

  return cx_fin; // Retorna a caixa alinhada
}

/* Limpa o buffer do terminal */
void limpa_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF); 
}

/* Obtém o tamanho da tela */
void get_tam_tela(int *tam_l, int *tam_c) {
  FILE *fp;
  char temp[16];
  fp = popen("stty size", "r"); // Obtém o tamanho da tela
  if (fp == NULL) { // Verifica se a abertura do pipe foi bem-sucedida
    catch_error("Execução de comando 'stty size' falhou");
  }
  if (fgets(temp, sizeof(temp), fp) != NULL) { // Lê a saída do pipe
    sscanf(temp, "%d %d", tam_l, tam_c); // Extrai o tamanho da tela
  }
  pclose(fp); // Fecha o pipe
}

/* Limpa a tela do terminal */
void cls_screen() { 
  #ifdef _WIN32 // Verifica se o sistema é Windows
    system("cls");
  #else // Caso contrário, assume que é um sistema Unix
    system("clear");
  #endif 
}

/* Aguarda uma entrada do usuário p/ limpar a tela do terminal */
void limpa_tela() {
  printf("%s\nAperte %s[ENTER]%s p/ continuar...", rset, azul, rset);
  limpa_buffer();
  cls_screen();
}

/* Exibe uma barra de divisão */
void barra_div(const char *i, const char *f) {
  printf("%s%s<>%s==============%s<>%s==============%s<>%s%s", i, cian, rset, mage, rset, cian, rset, f);
}

/* Solicita e retorna um número inteiro do usuário */
int get_num(const char *msg) {
  int val;
  printf("%s: ", msg);
  scanf("%d", &val);
  limpa_buffer();
  return val;
}

/* Solicita e retorna uma String do usuário */
String get_str(const char *msg) {
  String str;
  printf("%s: ", msg);
  scanf_str(&str);
  return str;
}

/* Solicita e retorna a confirmação de uma ação do usuário */
int sim_ou_nao(const char *msg) {
  do { 
    limpa_tela();
    barra_div("", "\n");
    printf("%s\n", cnt_cx(msg, brd_crv, amar, cian, 34).dados);
    String resp = get_str("[S|N]");
    barra_div("", "\n");
    if (strstr(resp.dados, "s") || strstr(resp.dados, "1")) { // Verifica se a resposta é "s" ou "1"
      free_str(&resp);
      return 1;
    } else if (strstr(resp.dados, "n") || strstr(resp.dados, "0")) { // Verifica se a resposta é "n" ou "0"
      free_str(&resp);
      return 0;
    } else {
      printf("\n%s[Resposta inválida!]%s\n", verm, rset);
    }
  } while (1); // Repete até que a resposta seja válida
}

/* Exibe uma barra de carregamento */
double barra_carreg(const int tam) { 
  clock_t inicio, fim;
  String barra_carreg = new_str(""); // Inicializa a barra de carregamento como uma String vazia
  char *msg_carreg; // Mensagem de carregamento

  inicio = clock();
  for (int i = 0; i <= tam; i++) { // Loop para exibir a barra de carregamento 
    cls_screen(); // Limpa a tela

    /* Atualiza a barra de carregamento e imprime-a */
    switch (i % 3) { // Mensagem de carregamento alternada
      case 0: msg_carreg = "Carregando."; break;
      case 1: msg_carreg = "Carregando.."; break;
      case 2: msg_carreg = "Carregando..."; break;
      default: msg_carreg = "Carregando..."; break;
    }
    printf("%s\n", msg_carreg);  
    if (i != 0) { // Se não for a primeira iteração adiciona um bloco à barra de carregamento
      barra_carreg = concat_str(barra_carreg, new_str("▇"));
    }
    printf("%s", align_cx(esq_cx(barra_carreg.dados, brd_crv, cian, amar, tam + 2), concat_str(new_str("\n \n"), float_to_str(i / (float) tam * 100)), 1).dados);

    sleep(1); // Aguarda 1 segundo para simular o carregamento
  }
  free_str(&barra_carreg); // Libera a memória da String da barra de carregamento
  fim = clock();
  return (double) (fim - inicio) / CLOCKS_PER_SEC;
}