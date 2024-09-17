#include "meu_programa.h"
#include <stdio.h>

int main() {
  String cx_conf = cnt_cx(" TEM CERTEZA? ", brd_crv, amar, cian, 10);
  String cx_s = cnt_cx(" SIM ", brd_crv, amar, cian, 0);
  String cx_n = cnt_cx(" NÃO \n 1 \n o \n p", brd_crv, amar, cian, 0);
  String cx_s_n = align_cx(align_cx(cx_s, cx_n, 2), cx_conf, 2);
  String cx_perg = cnt_cx(concat_str(cx_conf, cx_s_n).dados, brd_crv, amar, cian, 0);
  printf("%s\n", cx_conf.dados);
  printf("%s\n", cx_s.dados);
  printf("%s\n", cx_n.dados);
  printf("%s\n", cx_s_n.dados);
  printf("%s\n", cx_perg.dados); 
  printf("%s\n", cnt_cx(inverte_str(get_str("Digite uma palavra")).dados, brd_crv, amar, cian, 0).dados);
  limpa_tela();
  double tempo = barra_carreg(10);
  printf("%s\n", cnt_cx("Carregamento concluído!" , brd_crv, amar, cian, 0).dados);
  printf("\nTempo decorrido: %.2f segundos\n", tempo);
  return 0;
} 