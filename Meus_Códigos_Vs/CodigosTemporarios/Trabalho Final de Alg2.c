#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

typedef struct datas { // [STRUCT DE DATA]
  int dia, mes, ano;
} data;

typedef struct localizacao { // [STRUCT DE LOCALIZAÇÃO/ENDEREÇO]
  char rua[50], cidade[50], estado[50];
  int num;
} local;

typedef struct equipamentos { // [STRUCT DE EQUIPAMENTOS]
  int ID;
  char nome[50], tipo[50];
  int vid, def, atq, vel;
  int lvl, xp;
} equip;

typedef struct habilidades { // [STRUCT DE HABILIDADES]
  int ID;
  char nome[50], tipo[50], desc[200];
  int cooldown;
  double mult;
} habil;

typedef struct aventureiro { // [STRUCT DE AVENTUREIRO]
  int ID_alma;
  char nome[50], classe[20], tel[20];
  int vid, def, atq, vel;
  int lvl, xp;
  data nasc;
  local end;
  equip eqp[6];
  habil hab[3];
} avent;

typedef struct itens { // [STRUCT DE ITENS]
  int ID;
  char nome[50], tipo[50];
  int qtd, utl, val;
} item;

typedef struct historico_vendas { // [STRUCT DE HISTÓRICO DE VENDAS]
  int ID, qtd, val;
  data dt_v;
  avent cl_v;
  item prdt_v;
} hist_vend;

typedef struct rpg { // [STRUCT DE RPG/PRINCIPAL]
  int ouro, rubi;
  char **tipos, **classes, **itens_aux, **itens_nome;
  char **habil_mods, **habil_tipos, **habil_nomes;
  item *loja_itm;
  item *itm;
  equip *eqp;
  avent *avt;
  hist_vend *vend;
  avent *inmg;
} rpg;

void limpa_tela() { // [FUNÇÃO DE LIMPAR TELA]
  printf("\033[0m\nAperte [\033[38;5;39mENTER\033[0m] para continuar...");
  getchar();
  __fpurge(stdin);
  system("clear");
}

int strlen_ext(char *str) { // [FUNÇÃO DE CONTAR CARACTERES "MELHORADA"]
  int i, tam = 0, ASCII = 0;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] == '\033') {
      ASCII = 1;
    } 
      else if (ASCII && str[i] == 'm') {
        ASCII = 0;
      } 
        else if (!ASCII) {
          tam++;
        }
  }
  return tam;
}

void centralizar(char *format, ...) { // [FUNÇÃO DE CENTRALIZAR TEXTO]
  char str[256];
  va_list args;
  va_start(args, format);
  vsprintf(str, format, args);
  va_end(args);
  int i, espacos, tam = strlen_ext(str);
  int linha = strlen_ext("\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m");
  espacos = (linha - tam) / 2;
  for (i = 0; i < espacos; i++) {
    printf(" ");
  }
  printf("%s", str);
}

void barra(char *ini, char *fin) { // [FUNÇÃO DE BARRAS DE DELIMITAÇÃO]
  printf("%s\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m%s", ini, fin);
}

int sizeof_string(char **str) { // [FUNÇÃO DE CONTAR O TAMANHO DE UMA STRING]
  int i, lim = 0;
  for (i = 0; str[i] != NULL; i++) {
    lim++;
  }
  return lim;
}

int ver_acentos(char c) { // [FUNÇÃO DE VERIFICAR CARACTERES ACCENTUADOS]
  char acentos[] = "áéíóúàèìòùâêîôûãõäëïöüçÁÉÍÓÚÀÈÌÒÙÂÊÎÔÛÃÕÄËÏÖÜÇ";
  for (int i = 0; i < strlen(acentos); i++) {
    if (c == acentos[i]) {
      return 1;
    }
  }
  return 0;
}

int ver_str(char *str) { // [FUNÇÃO DE VERIFICAR SE UM NOME É VÁLIDO]
  int i, espaco = 1;
  for (i = 0; str[i] != '\0'; i++) {
    if (!isspace(str[i])) {
      espaco = 0;
      while (str[i] != '\0') {
        i++;
      }
    }
  }
  if (espaco) {
    return 0;
  }
  for (i = 0; str[i] != '\0'; i++) {
    if (!isalpha(str[i]) && !isspace(str[i]) && !ver_acentos(str[i])) {
      return 0;
    }
  }
  return 1;
}

int ver_num(char *num) { // [FUNÇÃO DE VERIFICAR NÚMERO DE TELEFONE] 
  int i, tam = strlen(num);
  if (tam != 10) {
    return 0; 
  }
  for (i = 0; i < tam; i++) {
    if (!isdigit(num[i])) {
      return 0;
    }
  }
  return 1;
}

int bissexto(int ano) { // [FUNÇÃO DE VERIFICAR ANO BISSEXTO]
  if (ano % 400 == 0) {
    return 1;
  } 
    else if (ano % 100 == 0) {
      return 0;
    } 
      else if (ano % 4 == 0) {
        return 1;
      } 
        else {
          return 0;
        }
}

int ver_data(int dia, int mes, int ano) { // [FUNÇÃO DE VERIFICAR DATA]
  if (ano < 0 || mes < 1 || mes > 12 || dia < 1 || dia > 31) {
    return 0;
  }
  if (mes == 2) {
    if (bissexto(ano) && dia > 29) {
      return 0;
    } 
      else if (!bissexto(ano) && dia > 28) {
        return 0;
      }
  }
  if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
    if (dia > 30) {
      return 0;
    }
  }
  return 1;
}

int ver_avent_eqp(rpg FRPG, avent vep) { // [FUNÇÃO DE VERIFICAR SE O AVENTUREIRO TEM EQUIPAMENTO]
  for (int i = 0; FRPG.tipos[i]; i++) {
    if (vep.eqp[i].vid > 0) {
      return 1;
    }
  }
  return 0;
}

int ver_aleatorio(int *sav, int tam, int val) { // [FUNÇÃO DE VERIFICAR SE O VALOR JÁ FOI SORTEADO]
  for (int i = 0; i < tam; i++) {
    if (sav[i] == val) {
      return 0;
    }
  }
  return 1;
}

int ver_id_avent(rpg FRPG, int ID, int ct) { // [FUNÇÃO DE VERIFICAR SE O ID DO AVENTUREIRO JÁ EXISTE]
  if (ID <= 0) {
    return 0;
  }
    else {
      for (int i = 0; i < ct; i++) {
        if (FRPG.avt[i].ID_alma == ID) {
          return 0;
        }
      }
      return 1;
    }
}

int ver_id_eqp(rpg FRPG, int ID, int ct) { // [FUNÇÃO DE VERIFICAR SE O ID DO EQUIPAMENTO JÁ EXISTE]
  if (ID <= 0) {
    return 0;
  }
    else {
      for (int i = 0; i < ct; i++) {
        if (FRPG.eqp[i].ID == ID) {
          return 0;
        }
      }
      return 1;
    }
}

int ver_id_item(rpg FRPG, int ID, int ct) { // [FUNÇÃO DE VERIFICAR SE O ID DO ITEM JÁ EXISTE]
  if (ID <= 0) {
    return 0;
  }
    else {
      for (int i = 0; i < ct; i++) {
        if (FRPG.itm[i].ID == ID) {
          return 0;
        }
      }
      return 1;
    }
}

int ver_id_item_loja(rpg FRPG, int ID, int ct) { // [FUNÇÃO DE VERIFICAR SE O ID DO ITEM DA LOJA JÁ EXISTE]
  if (ID <= 0) {
    return 0;
  }
    else {
      for (int i = 0; i < ct; i++) {
        if (FRPG.loja_itm[i].ID == ID) {
          return 0;
        }
      }
      return 1;
    }
}

int ver_id_vend(rpg FRPG, int ID, int ct) { // [FUNÇÃO DE VERIFICAR ID DE COMPRA]
  if (ID <= 0) { 
    return 0;
  }
    else {
      for (int i = 0; i < ct; i++) { 
        if (FRPG.vend[i].ID == ID) {
          return 0;
        }
      }
    }
  return 1;
}

void ver_venda(rpg FRPG, int ct_v) { // [FUNÇÃO DE VERIFICAR VENDAS]
  int i, valor, qtd = 0;
  do {
    limpa_tela();
    valor = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[ESCOLHER VALOR]\033[0m");
    barra("\n", "\n");
    printf("Valor a ser verificado\033[38;5;220m[¢]\033[38;5;214m: ");
    scanf("%d", &valor);
    __fpurge(stdin);
    barra("", "\n");
    if (valor < 0) {
      printf("\n\033[38;5;196m[Valor inválido! Tente novamente...]\033[0m\n");
    }
  } while (valor < 0);
  for (i = 0; i < ct_v; i++) {
    if (FRPG.vend[i].val > valor) {
      qtd++;
    }
  }
  if (qtd == 0) {
    printf("\n\033[38;5;196m[Não há vendas acima desse valor!]\033[0m\n");
  }
    else {
      barra("\n", "\n");
      printf("\033[38;5;208m[QTDE de vendas com valor \nacima de \033[38;5;220m[¢]\033[38;5;208m%d: %d]\033[0m", valor, qtd);
      barra("\n", "\n");
    }
}

void ver_estoq(rpg FRPG, int ct_l) { // [FUNÇÃO DE VERIFICAR ESTOQUE]
  int i, estoq, aux = 0;
  do {
    limpa_tela();
    estoq = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[ESCOLHER ESTOQUE]\033[0m");
    barra("\n", "\n");
    printf("Estoque a ser verificado\033[38;5;214m: ");
    scanf("%d", &estoq);
    __fpurge(stdin);
    barra("", "\n");
    if (estoq < 0) {
      printf("\n\033[38;5;196m[Quantidade inválida! Tente novamente...]\033[0m\n");
    }
  } while (estoq < 0);
  limpa_tela();
  barra("\n", "\n");
  centralizar("\033[38;5;201m[ITENS COM ESTOQUE ABAIXO DE %d]\033[0m", estoq);
  barra("\n", "\n");
  for (i = 0; i < ct_l; i++) {
    if (FRPG.loja_itm[i].qtd < estoq) {
      barra("\n", "\n");
      printf("[\033[38;5;214m%d\033[0m]> \033[38;5;51m[ID.: %02d] %s\033[0m\n", i + 1, FRPG.itm[i].ID, FRPG.itm[i].nome);
      printf("[\033[38;5;214mValor Unitário\033[38;5;220m[¢]: %d\033[0m]", FRPG.itm[i].val);
      barra("\n", "\n");
      printf("|\033[38;5;51m[QTDE.: %d][Efeito: +%2d]\033[0m|", FRPG.itm[i].qtd, FRPG.itm[i].utl);
      barra("\n", "\n");
      aux = 1;
    }
  }
  if (!aux) {
    printf("\n\033[38;5;196m[Não há itens com estoque abaixo de %d!]\033[0m\n", estoq);
  }
}

int ver_item_vend(rpg FRPG, int ID, int ct_v) { // [FUNÇÃO DE VERIFICAR ITEM NA COMPRA]
  for (int i = 0; i < ct_v; i++) { 
    if (ID == FRPG.vend[i].prdt_v.ID) {
      return 0;
    }
  }
  return 1;
} 

int ver_avent_vend(rpg FRPG, int ID, int ct_v) { // [FUNÇÃO DE VERIFICAR AVENTUREIRO NA VENDA]
  for (int i = 0; i < ct_v; i++) {
    if (ID == FRPG.vend[i].cl_v.ID_alma) {
      return 1;
    }
  }
  return 0;
} 

int sim_nao() { // [FUNÇÃO DE SIM OU NÃO]
  int opcao;
  do {
    limpa_tela();
    opcao = -1;
    barra("\n", "\n");
    printf("\033[38;5;201m[TEM CERTEZA?]\033[0m");
    barra("\n", "\n");
    printf("|[\033[38;5;51m1\033[0m]> Sim\n");
    printf("|[\033[38;5;51m0\033[0m]> Não");
    barra("\n", "\n");
    printf("Opção\033[38;5;51m: ");
    scanf("%d", &opcao);
    __fpurge(stdin);
    barra("", "\n");
    if (opcao < 0 || opcao > 1) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (opcao < 0 || opcao > 1);
  return opcao;
}

void calc_atb(rpg FRPG, avent *ca) { // [FUNÇÃO DE CALCULAR ATRIBUTOS]
  for (int i = 0; FRPG.tipos[i] != NULL; i++) {
    ca->def += ca->eqp[i].def;
    ca->vid += ca->eqp[i].vid;
    ca->vel += ca->eqp[i].vel;
    ca->atq += ca->eqp[i].atq;
  }
}

void list_eqp_avent(rpg FRPG, avent lea) { // [FUNÇÃO DE LISTAR EQUIPAMENTOS DE AVENTUREIRO]
  barra("\n", "\n");
  centralizar("\033[38;5;201m[EQUIPAMENTOS]\033[0m");
  barra("\n", "\n");
  for (int i = 0; FRPG.tipos[i] != NULL; i++) {
    if (lea.eqp[i].vid > 0) {
      barra("", "\n");
      printf("[\033[38;5;205m%d\033[0m]> \033[38;5;51m[ID.: %02d] %s\033[0m", i + 1, lea.eqp[i].ID, lea.eqp[i].nome);
      barra("\n", "\n");
      printf("\033[38;5;51m[Tip.: %s][Lvl.: %d] %s\033[0m", lea.eqp[i].tipo, lea.eqp[i].lvl, lea.eqp[i].nome);
      barra("\n", "\n");
      printf("|\033[38;5;51m[Atq: %2d]\033[0m|\n", lea.eqp[i].atq);
      printf("|\033[38;5;51m[Vid: %2d]\033[0m|\n", lea.eqp[i].vid);
      printf("|\033[38;5;51m[Def: %2d]\033[0m|\n", lea.eqp[i].def);
      printf("|\033[38;5;51m[Vel: %2d]\033[0m|", lea.eqp[i].vel);
      barra("\n", "\n");
    }
      else {
        barra("", "\n");
        printf("[\033[38;5;205m%d\033[0m]> \033[38;5;51m[%s] Vazio\033[0m", i + 1, FRPG.tipos[i]);
        barra("\n", "\n");
      }
  }
}

void list_hab_avent(rpg FRPG, avent lha) { // [FUNÇÃO DE LISTAR HABILIDADES DE AVENTUREIRO]
  barra("\n", "\n");
  centralizar("\033[38;5;201m[HABILIDADES]\033[0m");
  barra("\n", "");
  for (int i = 0; FRPG.habil_tipos[i] != NULL; i++) {
    barra("\n", "\n");
    printf("[\033[38;5;202m%d\033[0m]> \033[38;5;51m[ID.: %02d][Tip.: %s] %s\033[0m", i + 1, lha.hab[i].ID, lha.hab[i].tipo, lha.hab[i].nome);
    barra("\n", "\n");
    printf("Descrição: \033[38;5;51m%s\033[0m", lha.hab[i].desc);
    printf("\nCooldown: \033[38;5;51m%d\033[0m | ", lha.hab[i].cooldown);
    printf("Multiplicador: \033[38;5;51m%.2f\033[0m", lha.hab[i].mult);
    barra("\n", "");
  }
}

void list_avent(rpg *FRPG, int ct) { // [FUNÇÃO DE LISTAR AVENTUREIROS]
  barra("\n", "\n");
  centralizar("\033[38;5;201m[AVENTUREIROS]\033[0m");
  barra("\n", "");
  for (int i = 0; i < ct; i++) {
    avent lp_a = FRPG->avt[i];
    calc_atb(*FRPG, &lp_a);
    barra("\n", "\n");
    printf("[\033[38;5;202m%d\033[0m]> \033[38;5;51m[ID.: %02d] %s\033[0m", i + 1, lp_a.ID_alma, lp_a.nome);
    barra("\n", "\n");
    printf("\033[38;5;51m[Cls.: %s][Lvl.: %d]\033[0m", lp_a.classe, lp_a.lvl);
    barra("\n", "\n");
    centralizar("\033[38;5;208m[DADOS PESSOAIS]\033[0m");
    barra("\n", "\n");
    centralizar("\033[38;5;214m[Endereco]\033[0m"); 
    barra("\n", "");
    printf("\nRua: \033[38;5;51m%s\033[0m", lp_a.end.rua);
    printf("\nNº: \033[38;5;51m%d\033[0m", lp_a.end.num);
    printf("\nCidade: \033[38;5;51m%s\033[0m", lp_a.end.cidade);
    printf("\nEstado: \033[38;5;51m%s\033[0m\033[0m", lp_a.end.estado);
    barra("\n", "\n"); 
    printf("\033[38;5;51m[Data de nascimento: %02d/%02d/%04d]\033[0m\n", lp_a.nasc.dia, lp_a.nasc.mes, lp_a.nasc.ano);
    printf("\033[38;5;51m[Nº de Comunicação: %s]\033[0m", lp_a.tel);
    barra("\n", "\n");
    centralizar("\033[38;5;39m[STATUS]\033[0m");
    barra("\n", "\n");
    printf("|\033[38;5;51m[Vid: %2d]\033[0m|\n", lp_a.vid);
    printf("|\033[38;5;51m[Def: %2d]\033[0m|\n", lp_a.def);
    printf("|\033[38;5;51m[Atq: %2d]\033[0m|\n", lp_a.atq);
    printf("|\033[38;5;51m[Vel: %2d]\033[0m|", lp_a.vel);
    barra("\n", "");
    list_hab_avent(*FRPG, lp_a);
    list_eqp_avent(*FRPG, lp_a);
  }
}

void list_eqp(rpg FRPG, int ct) { // [FUNÇÃO DE LISTAR EQUIPAMENTOS]
  barra("\n", "\n");
  centralizar("\033[38;5;201m[EQUIPAMENTOS]\033[0m");
  barra("\n", "");
  for (int i = 0; i < ct; i++) {
    barra("\n", "\n");
    printf("[\033[38;5;205m%d\033[0m]> \033[38;5;51m[ID.: %02d] %s\033[0m", i + 1, FRPG.eqp[i].ID, FRPG.eqp[i].nome);
    barra("\n", "\n");
    printf("\033[38;5;51m[Tip.: %s][Lvl.: %d]\033[0m", FRPG.eqp[i].tipo, FRPG.eqp[i].lvl);
    barra("\n", "\n");
    printf("|\033[38;5;51m[Def: %2d]\033[0m|\n", FRPG.eqp[i].def);
    printf("|\033[38;5;51m[Vid: %2d]\033[0m|\n", FRPG.eqp[i].vid);
    printf("|\033[38;5;51m[Atq: %2d]\033[0m|\n", FRPG.eqp[i].atq);
    printf("|\033[38;5;51m[Vel: %2d]\033[0m|", FRPG.eqp[i].vel);
    barra("\n", "\n");
  }
}

void list_item(rpg FRPG, int ct) { // [FUNÇÃO DE LISTAR ITENS]
  barra("\n", "\n");
  centralizar("\033[38;5;201m[ITENS]\033[0m");
  barra("\n", "\n");
  for (int i = 0; i < ct; i++) {
    barra("\n", "\n");
    printf("[\033[38;5;214m%d\033[0m]> \033[38;5;51m[ID.: %02d] %s\033[0m\n", i + 1, FRPG.itm[i].ID, FRPG.itm[i].nome);
    printf("[\033[38;5;214mValor Unitário\033[38;5;220m[¢]: %d\033[0m]", FRPG.itm[i].val);
    barra("\n", "\n");
    printf("|\033[38;5;51m[QTDE.: %d][Efeito: +%2d]\033[0m|", FRPG.itm[i].qtd, FRPG.itm[i].utl);
    barra("\n", "\n");
  }
}

void list_item_loja(rpg FRPG, int ct) { // [FUNÇÃO DE LISTAR ITENS DA LOJA]
  barra("\n", "\n");
  centralizar("\033[38;5;201m[ITENS DA LOJA]\033[0m");
  barra("\n", "\n");
  for (int i = 0; i < ct; i++) {
    barra("\n", "\n");
    printf("[\033[38;5;214m%d\033[0m]> \033[38;5;51m[ID: %03d] %s\n", i + 1, FRPG.loja_itm[i].ID, FRPG.loja_itm[i].nome);
    printf("[\033[38;5;214mValor Unitário\033[38;5;220m[¢]: %d\033[0m]", FRPG.loja_itm[i].val);
    barra("\n", "\n");
    printf("|\033[38;5;51m[QTDE.: %d][Efeito: +%2d]\033[0m|", FRPG.loja_itm[i].qtd, FRPG.loja_itm[i].utl);
    barra("\n", "\n");    
  } 
}

void list_recurs(rpg FRPG) { // [FUNÇÃO DE LISTAR RECURSOS]
  barra("\n", "\n");
  centralizar("\033[38;5;201m[Recursos]\033[0m");
  barra("\n", "\n");
  printf("|\033[38;5;220m[¢][Ouro]\033[0m: \033[38;5;51m%d\033[0m\n", FRPG.ouro);
  printf("|\033[38;5;196m[◊][Rubi]\033[0m: \033[38;5;51m%d\033[0m", FRPG.rubi);
  barra("\n", "\n");
}

void list_vend(rpg FRPG, int ct_v) { // [FUNÇÃO DE LISTAR VENDAS]
  barra("\n", "\n");
  centralizar("\033[38;5;201m[VENDAS]\033[0m");
  barra("\n", "");
  for (int i = 0; i < ct_v; i++) {
    barra("\n", "\n");
    printf("[\033[38;5;202m%d\033[0m]> \033[38;5;51m[ID: %02d]\033[0m", i + 1, FRPG.vend[i].ID);
    printf("\033[38;5;51m[Data: %02d/%02d/%04d]\033[0m", FRPG.vend[i].dt_v.dia, FRPG.vend[i].dt_v.mes, FRPG.vend[i].dt_v.ano);
    barra("\n", "\n");
    printf("\033[38;5;51m[Valor da venda: \033[38;5;220m[¢]%d\033[38;5;51m]\033[0m", FRPG.vend[i].val);
    barra("\n", "\n");
    centralizar("\033[38;5;201m[DADOS DO CLIENTE]\033[0m");
    barra("\n", "\n");
    printf("|\033[38;5;51m[ID: %02d][Cliente: %s][Lvl: %d]\033[0m|", FRPG.vend[i].cl_v.ID_alma, FRPG.vend[i].cl_v.nome, FRPG.vend[i].cl_v.lvl);
    barra("\n", "\n");
    printf("\033[38;5;51m[Data de nascimento: %02d/%02d/%04d]\033[0m\n", FRPG.vend[i].cl_v.nasc.dia, FRPG.vend[i].cl_v.nasc.mes, FRPG.vend[i].cl_v.nasc.ano);
    printf("\033[38;5;51m[Nº de Comunicação: %s]\033[0m", FRPG.vend[i].cl_v.tel);
    barra("\n", "\n");
    centralizar("\033[38;5;214m[Endereco]\033[0m"); 
    barra("\n", "");
    printf("\nRua: \033[38;5;51m%s\033[0m", FRPG.vend[i].cl_v.end.rua);
    printf("\nNº: \033[38;5;51m%d\033[0m", FRPG.vend[i].cl_v.end.num);
    printf("\nCidade: \033[38;5;51m%s\033[0m", FRPG.vend[i].cl_v.end.cidade);
    printf("\nEstado: \033[38;5;51m%s\033[0m\033[0m", FRPG.vend[i].cl_v.end.estado);
    barra("\n", "\n");
    centralizar("\033[38;5;39m[STATUS]\033[0m");
    barra("\n", "\n");
    printf("|\033[38;5;51m[Vid: %2d]\033[0m|\n", FRPG.vend[i].cl_v.vid);
    printf("|\033[38;5;51m[Def: %2d]\033[0m|\n", FRPG.vend[i].cl_v.def);
    printf("|\033[38;5;51m[Atq: %2d]\033[0m|\n", FRPG.vend[i].cl_v.atq);
    printf("|\033[38;5;51m[Vel: %2d]\033[0m|", FRPG.vend[i].cl_v.vel);
    barra("\n", "\n");
    centralizar("\033[38;5;93m[ITEM COMPRADO]\033[0m");
    barra("\n", "\n");
    printf("\033[38;5;51m[ID.: %02d][Nome: %s]\033[0m\n", FRPG.vend[i].prdt_v.ID, FRPG.vend[i].prdt_v.nome);
    printf("\033[38;5;51m[QTDE.: %d][Valor Unitário: \033[38;5;220m[¢]%d\033[38;5;51m]\033[0m", FRPG.vend[i].qtd, FRPG.vend[i].prdt_v.val);
    barra("\n", "\n");
  } 
}

void ger_atb_avent(avent *gav) { // [FUNÇÃO DE GERAR ATRIBUTOS DE AVENTUREIRO]
  gav->lvl = 1;
  gav->xp = 0;
  gav->atq = rand() % 10 + 5;
  gav->def = rand() % 10 + 5;
  gav->vid = rand() % 10 + 5;
  gav->vel = rand() % 10 + 5;
}

void ger_atb_eqp(equip *gae) { // [FUNÇÃO DE GERAR ATRIBUTOS DE EQUIPAMENTO]
  gae->lvl = 1;
  gae->xp = 0;
  gae->atq = rand() % 5 + 5;
  gae->def = rand() % 5 + 5;
  gae->vid = rand() % 5 + 5;
  gae->vel = rand() % 5 + 5;
}

void ger_habil(rpg FRPG, habil *gha, int posi, int ct) { // [FUNÇÃO DE GERAR HABILIDADES]
  int i, j, mod, *aux, temp, lim1 = 0, lim2 = 0;
  gha->ID = posi + ct + 1;
  gha->mult = (double) rand() / RAND_MAX * 2 + 1;
  for (i = 0; FRPG.habil_nomes[i] != NULL; i++) {
    lim1++;
  }
  strcpy(gha->nome, FRPG.habil_nomes[rand() % lim1]);
  for (i = 0; FRPG.habil_mods[i] != NULL; i++) {
    lim2++;
  }
  if (posi == 0) {
    strcat(gha->desc, "[");
    strcat(gha->desc, FRPG.habil_mods[rand() % lim2]);
    strcat(gha->desc, "]");
    strcpy(gha->tipo, FRPG.habil_tipos[0]);
    gha->cooldown = 0;
  }
    else {
      aux = (int *) calloc(lim2, sizeof(int));
      mod = rand() % lim2 + 1;
      for (i = 0; i < mod; i++) {
        do {
          temp = rand() % lim2;
        } while (!ver_aleatorio(aux, i, temp));
        strcat(gha->desc, "[");
        strcat(gha->desc, FRPG.habil_mods[temp]);
        strcat(gha->desc, "]");
        if (i + 1 < mod) {
          strcat(gha->desc, "\n");
        }
        aux[i] = temp;
      }
      gha->cooldown = mod;
      strcpy(gha->tipo, FRPG.habil_tipos[rand() % 3]);
      free(aux);
    }
}

void regist_avent(rpg *FRPG, avent *avt, int *ct_a) { // [FUNÇÃO DE REGISTRAR AVENTUREIRO]
  int i, opcao, temp, aux;    
  do {
    limpa_tela();
    temp = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[REGISTRAR AVENTUREIRO]\033[0m");
    barra("\n", "\n");
    printf("ID\033[38;5;51m: ");
    scanf("%d", &temp);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_id_avent(*FRPG, temp, *ct_a)) {
      printf("\n\033[38;5;196m[ID inválido! Tente novamente...]\033[0m\n");
    }
  } while (!ver_id_avent(*FRPG, temp, *ct_a));
  avt->ID_alma = temp;
  do {
    limpa_tela();
    strcpy(avt->nome, " ");
    barra("\n", "\n");
    centralizar("\033[38;5;201m[REGISTRAR AVENTUREIRO]\033[0m");
    barra("\n", "\n");
    printf("Nome\033[38;5;51m: ");
    scanf("%49[^\n]", avt->nome);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_str(avt->nome)) {
      printf("\n\033[38;5;196m[Nome inválido! Tente novamente...]\033[0m\n");
    }
  } while (!ver_str(avt->nome));
  do {
    limpa_tela();
    opcao = -1;
    aux = sizeof_string(FRPG->classes);
    barra("\n", "\n");
    centralizar("\033[38;5;201m[REGISTRAR AVENTUREIRO]\033[0m");
    barra("\n", "");
    for (i = 0; i < aux; i++) {
      printf("\n[\033[38;5;51m%d\033[0m]> %s", i + 1, FRPG->classes[i]);
    }
    barra("\n", "\n");
    printf("Classe\033[38;5;51m: ");
    scanf("%d", &opcao);
    __fpurge(stdin);
    barra("", "\n");
    if (opcao < 1 || opcao > aux) {
      printf("\n\033[38;5;196m[Classe inválida! Tente novamente...]\033[0m\n");
    }
  } while (opcao < 1 || opcao > aux);
  strcpy(avt->classe, FRPG->classes[opcao - 1]);
  printf("\n\033[38;5;220m[Classe escolhida: %s]\033[0m\n", avt->classe);
  do {
    limpa_tela();
    strcpy(avt->tel, " ");
    barra("\n", "\n");
    centralizar("\033[38;5;201m[REGISTRAR AVENTUREIRO]\033[0m");
    barra("\n", "\n");
    printf("Nº de comunicação\n\033[38;5;51m[10 Nºˢ]: ");
    scanf("%49[^\n]", avt->tel);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_num(avt->tel)) {
      printf("\n\033[38;5;196m[Nº inválido! Tente novamente...]\033[0m\n");
    }
  } while (!ver_num(avt->tel));
  do {
    limpa_tela();
    avt->nasc.dia = -1, avt->nasc.mes = -1, avt->nasc.ano = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[REGISTRAR AVENTUREIRO]\033[0m");
    barra("\n", "\n");
    printf("Data de nascimento\n\033[38;5;51m[DD/MM/AAAA]: ");
    scanf("%d/%d/%d", &avt->nasc.dia, &avt->nasc.mes, &avt->nasc.ano);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_data(avt->nasc.dia, avt->nasc.mes, avt->nasc.ano)) {
      printf("\n\033[38;5;196m[Data inválida! Tente novamente...]\033[0m\n");
    }
  } while (!ver_data(avt->nasc.dia, avt->nasc.mes, avt->nasc.ano));
  do {
    limpa_tela();
    strcpy(avt->end.rua, " ");
    barra("\n", "\n");
    centralizar("\033[38;5;201m[REGISTRAR AVENTUREIRO]\033[0m");
    barra("\n", "\n");
    printf("Rua\033[38;5;51m: ");
    scanf("%49[^\n]", avt->end.rua);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_str(avt->end.rua)) {
      printf("\n\033[38;5;196m[Rua inválida! Tente novamente...]\033[0m\n");
    }
  } while (!ver_str(avt->end.rua));
  do {
    limpa_tela();
    avt->end.num = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[REGISTRAR AVENTUREIRO]\033[0m");
    barra("\n", "\n");
    printf("Nº da casa\033[38;5;51m: ");
    scanf("%d", &avt->end.num);
    __fpurge(stdin);
    barra("", "\n");
    if (avt->end.num <= 0) {
      printf("\n\033[38;5;196m[Número inválido! Tente novamente...]\033[0m\n");
    }
  } while (avt->end.num <= 0);
  do {
    limpa_tela();
    strcpy(avt->end.cidade, " ");
    barra("\n", "\n");
    centralizar("\033[38;5;201m[REGISTRAR AVENTUREIRO]\033[0m");
    barra("\n", "\n");
    printf("Cidade\033[38;5;51m: ");
    scanf("%49[^\n]", avt->end.cidade);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_str(avt->end.cidade)) {
      printf("\n\033[38;5;196m[Cidade inválida! Tente novamente...]\033[0m\n");
    }
  } while (!ver_str(avt->end.cidade));
  do {
    limpa_tela();
    strcpy(avt->end.estado, " ");
    barra("\n", "\n");
    centralizar("\033[38;5;201m[REGISTRAR AVENTUREIRO]\033[0m");
    barra("\n", "\n");
    printf("Estado\033[38;5;51m: ");
    scanf("%49[^\n]", avt->end.estado);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_str(avt->end.estado)) {
      printf("\n\033[38;5;196m[Estado inválido! Tente novamente...]\033[0m\n");
    }
  } while (!ver_str(avt->end.estado));
  limpa_tela();
  barra("\n", "\n");
  centralizar("\033[38;5;220m[Aleatorizando atributos...]\033[0m");
  barra("\n", "\n");
  ger_atb_avent(avt);
  printf("\033[38;5;51m[ATQ: %d]\033[0m\n", avt->atq);
  printf("\033[38;5;51m[DEF: %d]\033[0m\n", avt->def);
  printf("\033[38;5;51m[VID: %d]\033[0m\n", avt->vid);
  printf("\033[38;5;51m[VEL: %d]\033[0m", avt->vel);
  barra("\n", "\n");
  limpa_tela();
  barra("\n", "\n");
  centralizar("\033[38;5;220m[Aleatorizando habilidades...]\033[0m");
  for (i = 0; FRPG->habil_tipos[i] != NULL; i++) {
    ger_habil(*FRPG, &avt->hab[i], i, *ct_a);
  }
  list_hab_avent(*FRPG, *avt);
  (*ct_a)++;
  FRPG->rubi -= 10;
  printf("\n\n[\033[38;5;196m-10[◊]\033[0m]\n");
  printf("\n\033[38;5;220m[Aventureiro invocado com sucesso!]\033[0m\n");
}

void alter_avent(rpg *FRPG, avent *avt, int ct_a) {
  int i, opcao, temp, aux;    
  do {
    limpa_tela();
    temp = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[ALTERAR AVENTUREIRO]\033[0m");
    barra("\n", "\n");
    printf("Novo ID\033[38;5;51m: ");
    scanf("%d", &temp);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_id_avent(*FRPG, temp, ct_a)) {
      printf("\n\033[38;5;196m[ID inválido! Tente novamente...]\033[0m\n");
    }
  } while (!ver_id_avent(*FRPG, temp, ct_a));
  avt->ID_alma = temp;
  do {
    limpa_tela();
    strcpy(avt->nome, " ");
    barra("\n", "\n");
    centralizar("\033[38;5;201m[REGISTRAR AVENTUREIRO]\033[0m");
    barra("\n", "\n");
    printf("Novo nome\033[38;5;51m: ");
    scanf("%49[^\n]", avt->nome);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_str(avt->nome)) {
      printf("\n\033[38;5;196m[Nome inválido! Tente novamente...]\033[0m\n");
    }
  } while (!ver_str(avt->nome));
  do {
    limpa_tela();
    opcao = -1;
    aux = sizeof_string(FRPG->classes);
    barra("\n", "\n");
    centralizar("\033[38;5;201m[REGISTRAR AVENTUREIRO]\033[0m");
    barra("\n", "");
    for (i = 0; i < aux; i++) {
      printf("\n[\033[38;5;51m%d\033[0m]> %s", i + 1, FRPG->classes[i]);
    }
    barra("\n", "\n");
    printf("Nova classe\033[38;5;51m: ");
    scanf("%d", &opcao);
    __fpurge(stdin);
    barra("", "\n");
    if (opcao < 1 || opcao > aux) {
      printf("\n\033[38;5;196m[Classe inválida! Tente novamente...]\033[0m\n");
    }
  } while (opcao < 1 || opcao > aux);
  strcpy(avt->classe, FRPG->classes[opcao - 1]);
  printf("\n\033[38;5;220m[Classe escolhida: %s]\033[0m\n", avt->classe);
  do {
    limpa_tela();
    strcpy(avt->tel, " ");
    barra("\n", "\n");
    centralizar("\033[38;5;201m[REGISTRAR AVENTUREIRO]\033[0m");
    barra("\n", "\n");
    printf("Novo nº de comunicação\n\033[38;5;51m[10 Nºˢ]: ");
    scanf("%49[^\n]", avt->tel);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_num(avt->tel)) {
      printf("\n\033[38;5;196m[Nº inválido! Tente novamente...]\033[0m\n");
    }
  } while (!ver_num(avt->tel));
  do {
    limpa_tela();
    barra("\n", "\n");
    avt->nasc.dia = -1, avt->nasc.mes = -1, avt->nasc.ano = -1;
    centralizar("\033[38;5;201m[REGISTRAR AVENTUREIRO]\033[0m");
    barra("\n", "\n");
    printf("Nova data de nascimento\n\033[38;5;51m[DD/MM/AAAA]: ");
    scanf("%d/%d/%d", &avt->nasc.dia, &avt->nasc.mes, &avt->nasc.ano);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_data(avt->nasc.dia, avt->nasc.mes, avt->nasc.ano)) {
      printf("\n\033[38;5;196m[Data inválida! Tente novamente...]\033[0m\n");
    }
  } while (!ver_data(avt->nasc.dia, avt->nasc.mes, avt->nasc.ano));
  do {
    limpa_tela();
    strcpy(avt->end.rua, " ");
    barra("\n", "\n");
    centralizar("\033[38;5;201m[REGISTRAR AVENTUREIRO]\033[0m");
    barra("\n", "\n");
    printf("Nova rua\033[38;5;51m: ");
    scanf("%49[^\n]", avt->end.rua);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_str(avt->end.rua)) {
      printf("\n\033[38;5;196m[Rua inválida! Tente novamente...]\033[0m\n");
    }
  } while (!ver_str(avt->end.rua));
  do {
    limpa_tela();
    avt->end.num = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[REGISTRAR AVENTUREIRO]\033[0m");
    barra("\n", "\n");
    printf("Novo nº da casa\033[38;5;51m: ");
    scanf("%d", &avt->end.num);
    __fpurge(stdin);
    barra("", "\n");
    if (avt->end.num <= 0) {
      printf("\n\033[38;5;196m[Número inválido! Tente novamente...]\033[0m\n");
    }
  } while (avt->end.num <= 0);
  do {
    limpa_tela();
    strcpy(avt->end.cidade, " ");
    barra("\n", "\n");
    centralizar("\033[38;5;201m[REGISTRAR AVENTUREIRO]\033[0m");
    barra("\n", "\n");
    printf("Nova cidade\033[38;5;51m: ");
    scanf("%49[^\n]", avt->end.cidade);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_str(avt->end.cidade)) {
      printf("\n\033[38;5;196m[Cidade inválida! Tente novamente...]\033[0m\n");
    }
  } while (!ver_str(avt->end.cidade));
  do {
    limpa_tela();
    strcpy(avt->end.estado, " ");
    barra("\n", "\n");
    centralizar("\033[38;5;201m[REGISTRAR AVENTUREIRO]\033[0m");
    barra("\n", "\n");
    printf("Novo estado\033[38;5;51m: ");
    scanf("%49[^\n]", avt->end.estado);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_str(avt->end.estado)) {
      printf("\n\033[38;5;196m[Estado inválido! Tente novamente...]\033[0m\n");
    }
  } while (!ver_str(avt->end.estado));
  limpa_tela();
  barra("\n", "\n");
  centralizar("\033[38;5;220m[Aleatorizando novos atributos...]\033[0m");
  barra("\n", "\n");
  ger_atb_avent(avt);
  printf("\033[38;5;51m[ATQ: %d]\033[0m\n", avt->atq);
  printf("\033[38;5;51m[DEF: %d]\033[0m\n", avt->def);
  printf("\033[38;5;51m[VID: %d]\033[0m\n", avt->vid);
  printf("\033[38;5;51m[VEL: %d]\033[0m", avt->vel);
  barra("\n", "\n");
  limpa_tela();
  barra("\n", "\n");
  centralizar("\033[38;5;220m[Aleatorizando novas habilidades...]\033[0m");
  for (i = 0; FRPG->habil_tipos[i] != NULL; i++) {
    ger_habil(*FRPG, &avt->hab[i], i, ct_a);
  }
  list_hab_avent(*FRPG, *avt);
  FRPG->rubi -= 5;
  printf("\n\n[\033[38;5;196m-5[◊]\033[0m]\n");
  printf("\n\033[38;5;220m[Aventureiro alterado com sucesso!]\033[0m\n");
}

void forj_epq(rpg *FRPG, equip *eqt, int *ct_e) { // [FUNÇÃO DE FORJAR EQUIPAMENTO]
  int i, opcao, temp, aux;
  do {
    limpa_tela();
    temp = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[FORJAR EQUIPAMENTO]\033[0m");
    barra("\n", "\n");
    printf("ID\033[38;5;51m: ");
    scanf("%d", &temp);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_id_eqp(*FRPG, temp, *ct_e)) {
      printf("\n\033[38;5;196m[ID inválido! Tente novamente...]\033[0m\n");
    }
  } while (!ver_id_eqp(*FRPG, temp, *ct_e));
  eqt->ID = temp;
  do {
    limpa_tela();
    strcpy(eqt->nome, " ");
    barra("\n", "\n");
    centralizar("\033[38;5;201m[FORJAR EQUIPAMENTO]\033[0m");
    barra("\n", "\n");
    printf("Nome\033[38;5;51m: ");
    scanf("%49[^\n]", eqt->nome);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_str(eqt->nome)) {
      printf("\n\033[38;5;196m[Nome inválido! Tente novamente...]\033[0m\n");
    }
  } while (!ver_str(eqt->nome));
  do {
    limpa_tela();
    opcao = -1;
    aux = sizeof_string(FRPG->tipos);
    barra("\n", "\n");
    centralizar("\033[38;5;201m[FORJAR EQUIPAMENTO]\033[0m");
    barra("\n", "");
    for (i = 0; i < aux; i++) {
      printf("\n[\033[38;5;51m%d\033[0m]> %s", i + 1, FRPG->tipos[i]);
    }
    barra("\n", "\n");
    printf("Tipo\033[38;5;51m: ");
    scanf("%d", &opcao);
    __fpurge(stdin);
    barra("", "\n");
    if (opcao < 1 || opcao > aux) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (opcao < 1 || opcao > aux);
  strcpy(eqt->tipo, FRPG->tipos[opcao - 1]);
  printf("\n\033[38;5;220m[Tipo escolhido: %s]\033[0m\n", eqt->tipo);
  limpa_tela();
  barra("\n", "\n");
  centralizar("\033[38;5;220m[Aleatorizando atributos...]\033[0m");
  barra("\n", "\n");
  ger_atb_eqp(eqt);
  printf("\033[38;5;51m[ATQ: %d]\033[0m\n", eqt->atq);
  printf("\033[38;5;51m[DEF: %d]\033[0m\n", eqt->def);
  printf("\033[38;5;51m[VID: %d]\033[0m\n", eqt->vid);
  printf("\033[38;5;51m[VEL: %d]\033[0m", eqt->vel);
  barra("\n", "\n");
  (*ct_e)++;
  FRPG->ouro -= 100;
  printf("\n[\033[38;5;196m-100\033[38;5;220m[¢]\033[0m]\n");
  printf("\n\033[38;5;220m[Equipamento forjado com sucesso!]\033[0m\n");
}

void alter_eqp(rpg *FRPG, equip *eqt, int ct_e) { // [FUNÇÃO DE ALTERAR EQUIPAMENTO]
  int i, opcao, temp, aux;
  do {
    limpa_tela();
    temp = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[ALTERAR EQUIPAMENTO]\033[0m");
    barra("\n", "\n");
    printf("Novo ID\033[38;5;51m: ");
    scanf("%d", &temp);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_id_eqp(*FRPG, temp, ct_e)) {
      printf("\n\033[38;5;196m[ID inválido! Tente novamente...]\033[0m\n");
    }
  } while (!ver_id_eqp(*FRPG, temp, ct_e));
  eqt->ID = temp;
  do {
    limpa_tela();
    strcpy(eqt->nome, " ");
    barra("\n", "\n");
    centralizar("\033[38;5;201m[ALTERAR EQUIPAMENTO]\033[0m");
    barra("\n", "\n");
    printf("Novo nome\033[38;5;51m: ");
    scanf("%49[^\n]", eqt->nome);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_str(eqt->nome)) {
      printf("\n\033[38;5;196m[Nome inválido! Tente novamente...]\033[0m\n");
    }
  } while (!ver_str(eqt->nome));
  do {
    limpa_tela();
    opcao = -1;
    aux = sizeof_string(FRPG->tipos);
    barra("\n", "\n");
    centralizar("\033[38;5;201m[ALTERAR EQUIPAMENTO]\033[0m");
    barra("\n", "");
    for (i = 0; i < aux; i++) {
      printf("\n[\033[38;5;51m%d\033[0m]> %s", i + 1, FRPG->tipos[i]);
    }
    barra("\n", "\n");
    printf("Novo tipo\033[38;5;51m: ");
    scanf("%d", &opcao);
    __fpurge(stdin);
    barra("", "\n");
    if (opcao < 1 || opcao > aux) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (opcao < 1 || opcao > aux);
  strcpy(eqt->tipo, FRPG->tipos[opcao - 1]);
  printf("\n\033[38;5;220m[Tipo escolhido: %s]\033[0m\n", eqt->tipo);
  limpa_tela();
  barra("\n", "\n");
  centralizar("\033[38;5;220m[Aleatorizando novos atributos...]\033[0m");
  barra("\n", "\n");
  ger_atb_eqp(eqt);
  printf("\033[38;5;51m[ATQ: %d]\033[0m\n", eqt->atq);
  printf("\033[38;5;51m[DEF: %d]\033[0m\n", eqt->def);
  printf("\033[38;5;51m[VID: %d]\033[0m\n", eqt->vid);
  printf("\033[38;5;51m[VEL: %d]\033[0m", eqt->vel);
  barra("\n", "\n");
  FRPG->ouro -= 50;
  printf("\n[\033[38;5;196m-50\033[38;5;220m[¢]\033[0m]\n");
  printf("\n\033[38;5;220m[Equipamento alterado com sucesso!]\033[0m\n");
}

void cadast_item(rpg *FRPG, item *ite, int *ct_l) { // [FUNÇÃO DE CADASTRAR ITEM NA LOJA]
  int i, aux, temp, opcao;
  do {
    limpa_tela();
    temp = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[CADASTRAR ITEM]\033[0m");
    barra("\n", "\n");
    printf("ID\033[38;5;51m: ");
    scanf("%d", &temp);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_id_item_loja(*FRPG, temp, *ct_l)) {
      printf("\n\033[38;5;196m[ID inválido! Tente novamente...]\033[0m\n");
    }
  } while (!ver_id_item_loja(*FRPG, temp, *ct_l));
  ite->ID = temp;
  do {
    limpa_tela();
    ite->val = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[CADASTRAR ITEM]\033[0m");
    barra("\n", "\n");
    printf("Valor\033[38;5;220m[¢]\033[38;5;51m: ");
    scanf("%d", &ite->val);
    __fpurge(stdin);
    barra("", "\n");
    if (ite->val <= 0) {
      printf("\n\033[38;5;196m[Valor inválido! Tente novamente...]\033[0m\n");
    }
  } while (ite->val <= 0);
  do {
    limpa_tela();
    strcpy(ite->nome, " ");
    barra("\n", "\n");
    centralizar("\033[38;5;201m[CADASTRAR ITEM]\033[0m");
    barra("\n", "\n");
    printf("Nome\033[38;5;51m: ");
    scanf("%49[^\n]", ite->nome);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_str(ite->nome)) {
      printf("\n\033[38;5;196m[Nome inválido! Tente novamente...]\033[0m\n");
    }
  } while (!ver_str(ite->nome));
  do {
    limpa_tela();
    opcao = -1, aux = 0;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[CADASTRAR ITEM]\033[0m");
    barra("\n", "");
    for (i = 0; FRPG->itens_aux[i] != NULL; i++) {
      printf("\n[\033[38;5;51m%d\033[0m]> %s", i + 1, FRPG->itens_aux[i]);
      aux++;
    }
    barra("\n", "\n");
    printf("Tipo\033[38;5;51m: ");
    scanf("%d", &opcao);
    __fpurge(stdin);
    barra("", "\n");
    if (opcao < 1 || opcao > aux) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (opcao < 1 || opcao > aux);
  strcpy(ite->tipo, FRPG->itens_aux[opcao - 1]);
  printf("\n\033[38;5;220m[Tipo escolhido: %s]\033[0m\n", ite->tipo);
  do {
    limpa_tela();
    ite->utl = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[CADASTRAR ITEM]\033[0m");
    barra("\n", "\n");
    printf("Efeito\033[38;5;51m[0-1000]: ");
    scanf("%d", &ite->utl);
    __fpurge(stdin);
    barra("", "\n");
    if (ite->utl <= 0 || ite->utl > 1000) {
      printf("\n\033[38;5;196m[Efeito inválido! Tente novamente...]\033[0m\n");
    }
  } while (ite->utl <= 0 || ite->utl > 1000);
  do {
    limpa_tela();
    ite->qtd = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[CADASTRAR ITEM]\033[0m");
    barra("\n", "\n");
    printf("Quantidade\033[38;5;51m[1-5]: ");
    scanf("%d", &ite->qtd);
    __fpurge(stdin);
    barra("", "\n");
    if (ite->qtd <= 0 || ite->qtd > 5) {
      printf("\n\033[38;5;196m[Quantidade inválida! Tente novamente...]\033[0m\n");
    }
  } while (ite->qtd <= 0 || ite->qtd > 5);
  (*ct_l)++;
  printf("\n\033[38;5;220m[Item cadastrado com sucesso!]\033[0m\n");
}

void alter_item_loja(rpg *FRPG, item *ite, int ct_i) { // [FUNÇÃO DE ALTERAR ITEM DA LOJA]
  int i, aux, temp, opcao;
  do {
    limpa_tela();
    temp = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[ALTERAR ITEM]\033[0m");
    barra("\n", "\n");
    printf("Novo ID\033[38;5;51m: ");
    scanf("%d", &temp);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_id_item_loja(*FRPG, temp, ct_i)) {
      printf("\n\033[38;5;196m[ID inválido! Tente novamente...]\033[0m\n");
    }
  } while (!ver_id_item_loja(*FRPG, temp, ct_i));
  ite->ID = temp;
  do {
    limpa_tela();
    strcpy(ite->nome, " ");
    barra("\n", "\n");
    centralizar("\033[38;5;201m[ALTERAR ITEM]\033[0m");
    barra("\n", "\n");
    printf("Novo nome\033[38;5;51m: ");
    scanf("%49[^\n]", ite->nome);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_str(ite->nome)) {
      printf("\n\033[38;5;196m[Nome inválido! Tente novamente...]\033[0m\n");
    }
  } while (!ver_str(ite->nome));
  do {
    limpa_tela();
    opcao = -1, aux = 0;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[ALTERAR ITEM]\033[0m");
    barra("\n", "");
    for (i = 0; FRPG->itens_aux[i] != NULL; i++) {
      printf("\n[\033[38;5;51m%d\033[0m]> %s", i + 1, FRPG->itens_aux[i]);
      aux++;
    }
    barra("\n", "\n");
    printf("Novo tipo\033[38;5;51m: ");
    scanf("%d", &opcao);
    __fpurge(stdin);
    barra("", "\n");
    if (opcao < 1 || opcao > aux) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (opcao < 1 || opcao > aux);
  strcpy(ite->tipo, FRPG->itens_aux[opcao - 1]);
  printf("\n\033[38;5;220m[Tipo escolhido: %s]\033[0m\n", ite->tipo);
  do {
    limpa_tela();
    ite->utl = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[ALTERAR ITEM]\033[0m");
    barra("\n", "\n");
    printf("Novo efeito\033[38;5;51m[0-1000]: ");
    scanf("%d", &ite->utl);
    __fpurge(stdin);
    barra("", "\n");
    if (ite->utl <= 0 || ite->utl > 1000) {
      printf("\n\033[38;5;196m[Efeito inválido! Tente novamente...]\033[0m\n");
    }
  } while (ite->utl <= 0 || ite->utl > 1000);
  do {
    limpa_tela();
    ite->qtd = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[ALTERAR ITEM]\033[0m");
    barra("\n", "\n");
    printf("Nova quantidade\033[38;5;51m[1-5]: ");
    scanf("%d", &ite->qtd);
    __fpurge(stdin);
    barra("", "\n");
    if (ite->qtd <= 0 || ite->qtd > 5) {
      printf("\n\033[38;5;196m[Quantidade inválida! Tente novamente...]\033[0m\n");
    }
  } while (ite->qtd <= 0 || ite->qtd > 5);
  printf("\n\033[38;5;220m[Item alterado com sucesso!]\033[0m\n");
}

void alter_venda(rpg *FRPG, hist_vend *vnd, int ct_v) { // [FUNÇÃO DE ALTERAR VENDA]
  int temp;
  do {
    limpa_tela();
    temp = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[ALTERAR VENDA]\033[0m");
    barra("\n", "\n");
    printf("Novo ID\033[38;5;51m: ");
    scanf("%d", &temp);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_id_vend(*FRPG, temp, ct_v)) {
      printf("\n\033[38;5;196m[ID inválido! Tente novamente...]\033[0m\n");
    }    
  } while (!ver_id_vend(*FRPG, temp, ct_v));
  vnd->ID = temp;
  do {
    limpa_tela();
    vnd->dt_v.dia = -1, vnd->dt_v.mes = -1, vnd->dt_v.ano = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[ALTERAR VENDA]\033[0m");
    barra("\n", "\n");
    printf("Nova data\033[38;5;51m[DD/MM/AAAA]: ");
    scanf("%d/%d/%d", &vnd->dt_v.dia, &vnd->dt_v.mes, &vnd->dt_v.ano);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_data(vnd->dt_v.dia, vnd->dt_v.mes, vnd->dt_v.ano)) {
      printf("\n\033[38;5;196m[Data inválida! Tente novamente...]\033[0m\n");
    }
  } while (!ver_data(vnd->dt_v.dia, vnd->dt_v.mes, vnd->dt_v.ano));
  do {
    limpa_tela();
    vnd->val = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[ALTERAR VENDA]\033[0m");
    barra("\n", "\n");
    printf("Novo valor\033[38;5;51m[0-1000]\033[38;5;220m[¢]\033[38;5;51m: ");
    scanf("%d", &vnd->val);
    __fpurge(stdin);
    barra("", "\n");
    if (vnd->val <= 0 || vnd->val > 1000) {
      printf("\n\033[38;5;196m[Valor inválido! Tente novamente...]\033[0m\n");
    }
  } while (vnd->val <= 0 || vnd->val > 1000);
  printf("\n\033[38;5;220m[Venda alterada com sucesso!]\033[0m\n");
}

int escolh_avent(rpg FRPG, int ct) { // [FUNÇÃO DE ESCOLHER AVENTUREIRO]
  int posi;
  do {
    limpa_tela();
    posi = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[ESCOLHER AVENTUREIRO]\033[0m");
    barra("\n", "");
    list_avent(&FRPG, ct);
    barra("", "\n");
    printf("|[\033[38;5;220m0\033[0m]> Voltar");
    barra("\n", "\n");
    printf("Opção\033[38;5;202m: ");
    scanf("%d", &posi);
    __fpurge(stdin);
    barra("", "\n");
    if (posi < 0 || posi > ct) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (posi < 0 || posi > ct);
  return --posi;
}

int escolh_eqp(rpg FRPG, int ct) { // [FUNÇÃO DE ESCOLHER EQUIPAMENTO]
  int posi;
  do {
    limpa_tela();
    posi = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[ESCOLHER EQUIPAMENTO]\033[0m");
    barra("\n", "\n");
    list_eqp(FRPG, ct);
    barra("\n", "\n");
    printf("|[\033[38;5;220m0\033[0m]> Voltar");
    barra("\n", "\n");
    printf("Opção\033[38;5;205m: ");
    scanf("%d", &posi);
    __fpurge(stdin);
    barra("", "\n");
    if (posi < 0 || posi > ct) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (posi < 0 || posi > ct);
  return --posi;
}

int escolh_item(rpg FRPG, int ct) { // [FUNÇÃO DE ESCOLHER ITEM]
  int posi;
  do {
    limpa_tela();
    posi = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[ESCOLHER ITEM]\033[0m");
    barra("\n", "\n");
    list_item(FRPG, ct);
    barra("\n", "\n");
    printf("|[\033[38;5;220m0\033[0m]> Voltar");
    barra("\n", "\n");
    printf("Opção\033[38;5;214m: ");
    scanf("%d", &posi);
    __fpurge(stdin);
    barra("", "\n");
    if (posi < 0 || posi > ct) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (posi < 0 || posi > ct);
  return --posi;
}

int escolh_item_loja(rpg FRPG, int ct_l) { // [FUNÇÃO DE ESCOLHER ITENS]
  int i, opcao;
  do {
    limpa_tela();
    opcao = -1;
    list_recurs(FRPG);
    barra("\n", "\n");
    centralizar("\033[38;5;201m[LOJA DE ITENS]\033[0m");
    barra("\n", "");
    list_item_loja(FRPG, ct_l);
    barra("\n", "\n");
    printf("|[\033[38;5;220m0\033[0m]> Voltar");
    barra("\n", "\n");
    printf("Opção\033[38;5;214m: ");
    scanf("%d", &opcao);
    __fpurge(stdin);
    barra("", "\n");
    if (opcao < 0 || opcao > ct_l) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novemente...]\033[0m\n");
    } 
  } while (opcao < 0 || opcao > ct_l);
  return --opcao;
}

int escolh_venda(rpg FRPG, int ct_v) { // [FUNÇÃO DE ESCOLHER VENDA]
  int posi;
  do {
    limpa_tela();
    posi = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[ESCOLHER VENDA]\033[0m");
    barra("\n", "\n");
    list_vend(FRPG, ct_v);
    barra("\n", "\n");
    printf("|[\033[38;5;220m0\033[0m]> Voltar");
    barra("\n", "\n");
    printf("Opção\033[38;5;202m: ");
    scanf("%d", &posi);
    __fpurge(stdin);
    barra("", "\n");
    if (posi < 0 || posi > ct_v) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    } 
  } while (posi < 0 || posi > ct_v);
  return --posi;
}

int escolh_id_vend(rpg FRPG, int ct) { // [FUNÇÃO DE ESCOLHER ID DA COMPRA]
  int temp;
  do {
    limpa_tela();
    barra("\n", "\n");
    centralizar("\033[38;5;201m[ESCOLHER ID DA VENDA]\033[0m");
    barra("\n", "\n");
    printf("ID\033[38;5;214m: ");
    scanf("%d", &temp);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_id_vend(FRPG, temp, ct)) {
      printf("\n\033[38;5;196m[ID inválido! Tente novamente...]\033[0m\n");
    }
  } while (!ver_id_vend(FRPG, temp, ct));
  return temp;
}

void escolh_data_vend(data *dta) { // [FUNÇÃO DE ESCOLHER DATA DA VENDA]
  do { 
    limpa_tela();
    dta->dia = -1, dta->mes = -1, dta->ano = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[ESCOLHER DATA DA VENDA]\033[0m");
    barra("\n", "\n");
    printf("Opção\033[38;5;214m[DD/MM/AAAA]: ");
    scanf("%d/%d/%d", &dta->dia, &dta->mes, &dta->ano);
    __fpurge(stdin);
    barra("", "\n");
    if (!ver_data(dta->dia, dta->mes, dta->ano)) {
      printf("\n\033[38;5;196m[Data inválida! Tente novemente...]\033[0m\n");
    } 
  } while (!ver_data(dta->dia, dta->mes, dta->ano));  
}

int escolh_qtde(rpg FRPG, item ite) { // [FUNÇÃO DE ESCOLHER QUANTIDADE]
  int opcao;
  do { 
    limpa_tela();
    opcao = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[ESCOLHER QUANTIDADE]\033[0m");
    barra("\n", "\n");
    printf("|[\033[38;5;220m0\033[0m]> Voltar");
    barra("\n", "\n");
    printf("Opção\033[38;5;214m[QTDE MAX: %d]: ", ite.qtd);
    scanf("%d", &opcao);
    __fpurge(stdin);
    barra("", "\n");
    if (opcao < 0 || opcao > ite.qtd) {
      printf("\n\033[38;5;196m[Quantidade inválida! Tente novamente...]\033[0m\n");
    }
  } while (opcao < 0 || opcao > ite.qtd);
  return opcao;
}

void excl_avent(rpg *FRPG, int *ct_a, int ct_v) { // [FUNÇÃO DE EXCLUIR AVENTUREIRO]
  int posi = escolh_avent(*FRPG, *ct_a), i;
  if (posi + 1 == 0) {
    printf("\n\033[38;5;220m[Voltando...]\033[0m\n");    
    return;
  }
  if (!ver_avent_vend(*FRPG, FRPG->avt[posi].ID_alma, ct_v)) {
    if (!ver_avent_eqp(*FRPG, FRPG->avt[posi])) {
      if (sim_nao()) { 
        FRPG->avt = (avent *) realloc(FRPG->avt, sizeof(avent) * (*ct_a + 1));
        if (!FRPG->avt) {
          printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
          exit(1);
        }
        for (i = posi; i < *ct_a; i++) {
          FRPG->avt[i] = FRPG->avt[i + 1];
        } 
        FRPG->avt = (avent *) realloc(FRPG->avt, (*ct_a) * sizeof(avent));
        if (!FRPG->avt) {
          printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
          exit(1);
        }
        (*ct_a)--;
        if (*ct_a > 0) {
          FRPG->avt = (avent *) realloc(FRPG->avt, (*ct_a) * sizeof(avent));
          if (!FRPG->avt) {
            printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
            exit(1);
          }
        }
        FRPG->rubi += 5;
        printf("\n[\033[38;5;46m+05\033[38;5;196m[◊]\033[0m]\n");
        printf("\n\033[38;5;220m[Aventureiro excluído com sucesso!]\033[0m\n");
      }
        else {
          printf("\n\033[38;5;196m[Exclusão cancelada!]\033[0m\n");
        }
    }
      else {
        printf("\n\033[38;5;196m[Impossível realizar a exclusão!]\033[0m");
        printf("\n\033[38;5;196m[Aventureiro está equipado!]\033[0m\n");
      }
  }
    else {
      printf("\n\033[38;5;196m[Impossível realizar a exclusão!]\033[0m");
      printf("\n\033[38;5;196m[Aventureiro está cadastrado em uma venda!]\033[0m\n");
    }
}

void vend_eqp(rpg *FRPG, int *ct) { // [FUNÇÃO DE VENDER EQUIPAMENTO]
  int temp = escolh_eqp(*FRPG, *ct);
  if (temp + 1 == 0) {
    printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
    return;
  }
  if (sim_nao()) {
    FRPG->eqp = (equip *) realloc(FRPG->eqp, sizeof(equip) * (*ct + 1));
    if (!FRPG->eqp) {
      printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
      exit(1);
    }
    for (int i = temp; i < *ct; i++) {
      FRPG->eqp[i] = FRPG->eqp[i + 1];
    }
    (*ct)--;
    FRPG->eqp = (equip *) realloc(FRPG->eqp, (*ct) * sizeof(equip));
    if (!FRPG->eqp && *ct != 0) {
      printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
      exit(1);
    }
    FRPG->ouro += 50;
    printf("\n[\033[38;5;46m+50\033[38;5;220m[¢]\033[0m]\n");
    printf("\n\033[38;5;220m[Equipamento vendido com sucesso!]\033[0m\n");
  }
    else {
      printf("\n\033[38;5;196m[Venda cancelada!]\033[0m\n");
    }
}

void excl_item(rpg *FRPG, int posi, int *ct) { // [FUNÇÃO DE EXCLUIR ITEM]
  FRPG->itm = (item *) realloc(FRPG->itm, sizeof(item) * (*ct + 1));
  if (!FRPG->itm) {
    printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
    exit(1);
  }
  for (int i = posi; i < *ct; i++) {
    FRPG->itm[i] = FRPG->itm[i + 1];
  }
  FRPG->itm = (item *) realloc(FRPG->itm, (*ct) * sizeof(item));
  if (!FRPG->itm) {
    printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
    exit(1);
  }
  (*ct)--;
  if (*ct > 0) {
    FRPG->itm = (item *) realloc(FRPG->itm, (*ct) * sizeof(item));
    if (!FRPG->itm) {
      printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
      exit(1);
    }
  }
}

void excl_item_loja(rpg *FRPG, int posi, int *ct) { // [FUNÇÃO DE EXCLUIR ITEM DA LOJA]
  FRPG->loja_itm = (item *) realloc(FRPG->loja_itm, sizeof(item) * (*ct + 1));
  if (!FRPG->loja_itm) {
    printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
    exit(1);
  }
  for (int i = posi; i < *ct; i++) { 
    FRPG->loja_itm[i] = FRPG->loja_itm[i + 1];
  }
  FRPG->loja_itm = (item *) realloc(FRPG->loja_itm, (*ct) * sizeof(item));
  if (!FRPG->loja_itm) {
    printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
    exit(1);
  }
  (*ct)--;
  if (*ct > 0) {
    FRPG->loja_itm = (item *) realloc(FRPG->loja_itm, (*ct) * sizeof(item));
    if (!FRPG->loja_itm) {
      printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
      exit(1);
    }
  }
}

void excl_venda(rpg *FRPG, int posi, int *ct) { // [FUNÇÃO DE EXCLUIR VENDA]
  FRPG->vend = (hist_vend *) realloc(FRPG->vend, sizeof(hist_vend) * (*ct + 1));
  if (!FRPG->vend) {
    printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
    exit(1);
  }
  for (int i = posi; i < *ct; i++) {
    FRPG->vend[i] = FRPG->vend[i + 1]; 
  }
  FRPG->vend = (hist_vend *) realloc(FRPG->vend, (*ct) * sizeof(hist_vend));
  if (!FRPG->vend) {
    printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
    exit(1);
  }
  (*ct)--; 
  if (*ct > 0) {
    FRPG->vend = (hist_vend *) realloc(FRPG->vend, (*ct) * sizeof(hist_vend));
    if (!FRPG->vend) {
      printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
      exit(1);
    }
  }
}

void loja_item(rpg *FRPG, hist_vend *vnd, int *ct_i, int *ct_a, int *ct_v, int *ct_l) { // [FUNÇÃO DE LOJA DE ITENS]
  int aux = escolh_avent(*FRPG, *ct_a);
  if (aux + 1 == 0) {
    printf("\n\033[38;5;220m[Voltando...]\033[0m\n");    
    return;
  }
  int posi = escolh_item_loja(*FRPG, *ct_l);
  if (posi + 1 == 0) {
    printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
    return;
  }
  if (FRPG->loja_itm[posi].val > FRPG->ouro) { // [VERIFICA SE O VALOR DO ITEM É MAIOR QUE O OURO]
    printf("\n\033[38;5;196m[Ouro insuficiente! Voltando ao menu...]\033[0m\n");
    return;
  }
  int qtde = escolh_qtde(*FRPG, FRPG->loja_itm[posi]); 
  if (qtde == 0) {
    printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
    return;
  }
  if (FRPG->loja_itm[posi].val * qtde <= FRPG->ouro) {
    if (sim_nao()) {
      escolh_data_vend(&FRPG->vend[*ct_v].dt_v);    
      vnd->ID = escolh_id_vend(*FRPG, *ct_v);          
      FRPG->itm = (item *) realloc(FRPG->itm, (*ct_i + 1) * sizeof(item));
      if (!FRPG->itm) {
        printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
        exit(1);
      }
      FRPG->itm[*ct_i] = FRPG->loja_itm[posi];
      FRPG->itm[*ct_i].qtd = qtde;
      FRPG->loja_itm[posi].qtd -= qtde;           
      vnd->cl_v = FRPG->avt[aux];
      vnd->prdt_v = FRPG->loja_itm[posi];
      vnd->qtd = qtde;
      vnd->val = FRPG->loja_itm[posi].val * qtde;
      FRPG->ouro -= FRPG->loja_itm[posi].val * qtde;
      (*ct_v)++;
      (*ct_i)++; 
      printf("\n[\033[38;5;196m-%d\033[38;5;220m[¢]\033[0m]\n", FRPG->loja_itm[posi].val * qtde);
      printf("\n\033[38;5;220m[\033[38;5;208m+x%d \033[38;5;51m%s \033[38;5;220madquirido com sucesso!]\033[0m\n", qtde, FRPG->loja_itm[posi].nome);
    }
      else {
        printf("\n\033[38;5;196m[Venda cancelada!]\033[0m\n");
      }
  }
    else {
      printf("\n\033[38;5;196m[Você não tem ouro suficiente!]\033[0m\n");
    }
}

void revend_item(rpg *FRPG, int *ct_i, int ct_v) { // [FUNÇÃO DE VENDER ITEM]
  int posi = escolh_item(*FRPG, *ct_i);
  if (posi + 1 == 0) {
    printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
    return;
  }
  if (ver_item_vend(*FRPG, FRPG->itm[posi].ID, ct_v)) { // [VERIFICAÇÃO SE O ITEM ESTÁ CADASTRADO EM ALGUMA VENDA]
    int qtd = escolh_qtde(*FRPG, FRPG->itm[posi]);
    if (qtd == 0) {
      printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
      return;
    }
    if (sim_nao()) {
      FRPG->ouro += FRPG->itm[posi].val * qtd;
      printf("\n\033[38;5;220m[\033[38;5;51m%s \033[38;5;220mvendido(a) com sucesso!]\033[0m\n", FRPG->itm[posi].nome);
      printf("\n[\033[38;5;46m+%d\033[38;5;220m[¢]\033[0m]\n", FRPG->itm[posi].val * qtd);
      excl_item(FRPG, posi, ct_i);
    }
      else {
        printf("\n\033[38;5;196m[Venda cancelada!]\033[0m\n");
      }
  }
    else {
      printf("\n\033[38;5;196m[Impossível revender item!]\033[0m");
      printf("\n\033[38;5;196m[O item está cadastrado em uma venda!]\033[0m\n");
    }
} 

int escolh_deseqp(rpg *FRPG, avent avt) { // [FUNÇÃO DE ESCOLHER EQUIPAMENTO PARA DESEQUIPAR]
  int posi, aux;
  aux = sizeof_string(FRPG->tipos);
  do {
    do {
      limpa_tela();
      posi = -1;
      barra("\n", "\n");
      centralizar("\033[38;5;201m[DESEQUIPAR EQUIPAMENTO]\033[0m");
      barra("\n", "");
      list_eqp_avent(*FRPG, avt);
      barra("", "\n");
      printf("|[\033[38;5;220m0\033[0m]> Voltar");
      barra("\n", "\n");
      printf("Opção\033[38;5;205m: ");
      scanf("%d", &posi);
      __fpurge(stdin);
      barra("", "\n");
      if (posi < 0 || posi > aux) {
        printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
      }
    } while (posi < 0 || posi > aux);
    if (avt.eqp[posi - 1].vid == 0) {
      printf("\n\033[38;5;196m[Equipamento inexistente!]\033[0m\n");
    }
  } while (avt.eqp[posi - 1].vid == 0);
  return --posi;
}

void equip_avent(rpg *FRPG, int ct_a, int *ct_e) { // [FUNÇÃO DE EQUIPAR AVENTUREIRO]
  int loc = escolh_avent(*FRPG, ct_a);
  if (loc + 1 == 0) {
    printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
    return;
  }
  int aux = escolh_eqp(*FRPG, *ct_e);
  if (aux + 1 == 0) {
    printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
    return;
  }
  int posi, i;
  for (i = 0; FRPG->tipos[i] != NULL; i++) {
    if (!strcmp(FRPG->eqp[aux].tipo, FRPG->tipos[i])) {
      posi = i;
    }
  }
  if (sim_nao()) {
    equip temp = FRPG->avt[loc].eqp[posi];
    FRPG->avt[loc].eqp[posi] = FRPG->eqp[aux];
    FRPG->eqp[aux] = temp;
    if (temp.vid == 0) {
      FRPG->eqp = (equip *) realloc(FRPG->eqp, (*ct_e + 1) * sizeof(equip));
      if (!FRPG->eqp) {
        printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
        exit(1);
      }
      for (i = aux; i < *ct_e; i++) {
        FRPG->eqp[i] = FRPG->eqp[i + 1];
      }
      (*ct_e)--;
      FRPG->eqp = (equip *) realloc(FRPG->eqp, (*ct_e) * sizeof(equip));
      if (!FRPG->eqp && *ct_e != 0) {
        printf("\n\033[38;5;196m[Erro ao alocar memória!12]\033[0m\n");
        exit(1);
      }
    }
    printf("\n\033[38;5;220m[Equipamento equipado com sucesso!]\033[0m\n");
  }
    else {
      printf("\n\033[38;5;196m[Equipamento não equipado!]\033[0m\n");
    }
}

void desequip_avent(rpg *FRPG, int ct_a, int *ct_e) { // [FUNÇÃO DE DESEQUIPAR AVENTUREIRO]
  int loc = escolh_avent(*FRPG, ct_a);
  if (loc + 1 == 0) {
    printf("\n\033[38;5;220m[Voltando...]\033[0m\n");    
    return;
  }
  if (ver_avent_eqp(*FRPG, FRPG->avt[loc])) {
    int posi = escolh_deseqp(FRPG, FRPG->avt[loc]);
    if (posi + 1 == 0) {
      printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
      return;
    }
    if (sim_nao()) {
      FRPG->eqp = (equip *) realloc(FRPG->eqp, (*ct_e + 1) * sizeof(equip));
      if (!FRPG->eqp) {
        printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
        exit(1);
      }
      equip temp = FRPG->avt[loc].eqp[posi];
      FRPG->avt[loc].eqp[posi] = FRPG->eqp[*ct_e];
      FRPG->eqp[*ct_e] = temp;
      (*ct_e)++;
      printf("\n\033[38;5;220m[Equipamento desequipado com sucesso!]\033[0m\n");
    }
      else {
        printf("\n\033[38;5;196m[Equipamento não desequipado!]\033[0m\n");
      }
  }
    else {
      printf("\n\033[38;5;196m[Aventureiro não possui equipamento!]\033[0m\n");
    }
}

void lvl_up_avent(avent *avt, int lvl_dif) { // [FUNÇÃO DE LVL UP]
  int xp = (lvl_dif + 1) * 1000;
  int xp_lvl = avt->lvl * 100;
  avt->xp += xp;
  while (avt->xp >= xp_lvl) {
    barra("\n", "\n");
    centralizar("\033[38;5;220m[\033[38;5;51m[%s]\033[38;5;220m subiu de level!]\033[0m", avt->nome);
    printf("\n<>--------------<>--------------<>\n");
    printf("|\033[38;5;51m[Lvl: %2d [\033[38;5;46m+1\033[38;5;51m]]\033[0m|", avt->lvl);
    printf("\n<>--------------<>--------------<>\n");
    printf("|\033[38;5;51m[ATQ: %2d [\033[38;5;46m+1\033[38;5;51m]]\033[0m\n", avt->atq);
    printf("|\033[38;5;51m[VID: %2d [\033[38;5;46m+1\033[38;5;51m]]\033[0m\n", avt->vid);
    printf("|\033[38;5;51m[DEF: %2d [\033[38;5;46m+1\033[38;5;51m]]\033[0m\n", avt->def);
    printf("|\033[38;5;51m[VEL: %2d [\033[38;5;46m+1\033[38;5;51m]]\033[0m", avt->vel);
    barra("\n", "\n");
    avt->lvl++;
    avt->atq++;
    avt->vid++;
    avt->def++;
    avt->vel++;
    avt->xp -= xp_lvl;
    xp_lvl = avt->lvl * 100;
    limpa_tela();
  }    
}

void lvl_up_epq(equip *eqt) { // [FUNÇÃO DE UPAR EQUIPAMENTO]
  int xp_lvl = eqt->lvl * 100;
  while (eqt->xp >= xp_lvl) {
    limpa_tela();
    barra("\n", "\n");
    centralizar("\033[38;5;220m[O equipamento subiu de level!]\033[0m");
    printf("\n<>--------------<>--------------<>\n");
    printf("|\033[38;5;51m[Lvl: %2d [\033[38;5;46m+1\033[38;5;51m]]\033[0m|", eqt->lvl);
    printf("\n<>--------------<>--------------<>\n");
    printf("|\033[38;5;51m[ATQ: %2d [\033[38;5;46m+1\033[38;5;51m]]\033[0m\n", eqt->atq);
    printf("|\033[38;5;51m[DEF: %2d [\033[38;5;46m+1\033[38;5;51m]]\033[0m\n", eqt->def);
    printf("|\033[38;5;51m[VID: %2d [\033[38;5;46m+1\033[38;5;51m]]\033[0m\n", eqt->vid);
    printf("|\033[38;5;51m[VEL: %2d [\033[38;5;46m+1\033[38;5;51m]]\033[0m", eqt->vel);
    barra("\n", "\n");
    eqt->lvl++;
    eqt->atq++;
    eqt->vid++;
    eqt->def++;
    eqt->vel++;
    eqt->xp -= xp_lvl;
    xp_lvl = eqt->lvl * 100;
  }
}

void use_item(rpg *FRPG, int ct_a, int ct_e, int *ct_i) { // [FUNÇÃO DE USAR ITEM]
  int posi = escolh_item(*FRPG, *ct_i);
  if (posi + 1 == 0) {
    printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
    return;
  }
  int i, loc, aux, qtd;
  for (i = 0; FRPG->itens_aux[i] != NULL; i++) {
    if (!strcmp(FRPG->itm[posi].tipo, FRPG->itens_aux[i])) {
      loc = i;
    }
  }
  if (loc == 0) {
    aux = escolh_eqp(*FRPG, ct_e);
    if (aux + 1 == 0) {
      printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
      return;
    }
    if (sim_nao()) {
      qtd = escolh_qtde(*FRPG, FRPG->itm[posi]);
      FRPG->eqp[aux].xp += qtd * FRPG->itm[posi].utl;
      FRPG->itm[posi].qtd -= qtd;
      printf("\n\033[38;5;51m[\033[38;5;46m+%d XP\033[38;5;51m]\033[0m\n", qtd * FRPG->itm[posi].utl);
      lvl_up_epq(&FRPG->eqp[aux]);
      printf("\n\033[38;5;220m[Item usado com sucesso!]\033[0m\n");
    }
      else {
        printf("\n\033[38;5;196m[Item não usado!]\033[0m\n");
      }
  }
    else if (loc == 1) {
      aux = escolh_avent(*FRPG, ct_a);
      if (aux + 1 == 0) {
        printf("\n\033[38;5;220m[Voltando...]\033[0m\n");    
        return;
      }
      if (sim_nao()) {
        qtd = escolh_qtde(*FRPG, FRPG->itm[posi]);
        FRPG->avt[aux].vid += qtd * FRPG->itm[posi].utl;
        FRPG->itm[posi].qtd -= qtd;
        printf("\n\033[38;5;51m[\033[38;5;46m+%d VID\033[38;5;51m]\033[0m\n", qtd * FRPG->itm[posi].utl);
        printf("\n\033[38;5;220m[Item usado com sucesso!]\033[0m\n");
      }
        else {
          printf("\n\033[38;5;196m[Item não usado!]\033[0m\n");
        }
    }
      else if (loc == 2) {
        aux = escolh_avent(*FRPG, ct_a);
        if (aux + 1 == 0) {
          printf("\n\033[38;5;220m[Voltando...]\033[0m\n");    
          return;
        }
        if (sim_nao()) {
          qtd = escolh_qtde(*FRPG, FRPG->itm[posi]);
          FRPG->avt[aux].atq += qtd * FRPG->itm[posi].utl;
          FRPG->itm[posi].qtd -= qtd;
          printf("\n\033[38;5;51m[\033[38;5;46m+%d ATQ\033[38;5;51m]\033[0m\n", qtd * FRPG->itm[posi].utl);
          printf("\n\033[38;5;220m[Item usado com sucesso!]\033[0m\n");
        }
          else {
            printf("\n\033[38;5;196m[Item não usado!]\033[0m\n");
          }
      }
        else if (loc == 3) {
          aux = escolh_avent(*FRPG, ct_a);
          if (aux + 1 == 0) {
            printf("\n\033[38;5;220m[Voltando...]\033[0m\n");    
            return;
          }
          if (sim_nao()) {
            qtd = escolh_qtde(*FRPG, FRPG->itm[posi]);
            FRPG->avt[aux].def += qtd * FRPG->itm[posi].utl;
            FRPG->itm[posi].qtd -= qtd;      
            printf("\n\033[38;5;51m[\033[38;5;46m+%d DEF\033[38;5;51m]\033[0m\n", qtd * FRPG->itm[posi].utl);
          }
            else {
              printf("\n\033[38;5;196m[Item não usado!]\033[0m\n");
            }
          printf("\n\033[38;5;220m[Item usado com sucesso!]\033[0m\n");
        }
          else if (loc == 4) {
            aux = escolh_avent(*FRPG, ct_a);
            if (aux + 1 == 0) {
              printf("\n\033[38;5;220m[Voltando...]\033[0m\n");    
              return;
            }
            if (sim_nao()) {
              qtd = escolh_qtde(*FRPG, FRPG->itm[posi]);
              FRPG->avt[aux].vel += qtd * FRPG->itm[posi].utl;
              FRPG->itm[posi].qtd -= qtd;
              printf("\n\033[38;5;51m[\033[38;5;46m+%d VEL\033[38;5;51m]\033[0m\n", qtd * FRPG->itm[posi].utl);
              printf("\n\033[38;5;220m[Item usado com sucesso!]\033[0m\n");
            }
              else {
                printf("\n\033[38;5;196m[Item não usado!]\033[0m\n");
              }
          }
            else {
              printf("\n\033[38;5;196m[Nenhum aventureiro ou equipamento encontrados!]\033[0m\n");
            }
}

int escolh_lvl_dif() { // [FUNÇÃO DE ESCOLHER NÍVEL DE DIFICULDADE]
  int opcao;
  do {
    limpa_tela();
    opcao = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[NIVEL DE DIFICULDADE]\033[0m");
    barra("\n", "\n");
    printf("|[\033[38;5;51m1\033[0m]> \033[38;5;46mFácil\033[0m\n");
    printf("|[\033[38;5;51m2\033[0m]> \033[38;5;39mMédio\033[0m\n");
    printf("|[\033[38;5;51m3\033[0m]> \033[38;5;220mDifícil\033[0m\n");
    printf("|[\033[38;5;51m4\033[0m]> \033[38;5;196mMuito Difícil\033[0m\n");
    printf("|[\033[38;5;51m5\033[0m]> \033[38;5;201mImpossível\033[0m");
    barra("\n", "\n");
    printf("|[\033[38;5;220m0\033[0m]> Voltar");
    barra("\n", "\n");
    printf("Opção\033[38;5;51m: ");
    scanf("%d", &opcao);
    __fpurge(stdin);
    barra("", "\n");
    if (opcao < 0 || opcao > 5) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (opcao < 0 || opcao > 5);
  return --opcao;
}

void exib_vid(int hp_atual, int hp_maximo) { // [FUNÇÃO DE EXIBIR BARRA DE VIDA]
  int i, tam_barra = 20; 
  int qtd_simb = (hp_atual * tam_barra) / hp_maximo; 
  printf("HP: ");
  for (i = 0; i < qtd_simb; i++) {
    printf("\033[38;5;46m=\033[0m"); 
  }
  for (i = qtd_simb; i < tam_barra; i++) {
    printf(" ");
  }
  printf(" %d/%d\n", hp_atual, hp_maximo);
}

void exib_energia(float en_p) { // [FUNÇÃO DE EXIBIR ENERGIA]
  en_p *= 100;
  if (en_p > 100) {
    en_p = 100;
  }
  printf("⚡ \033[38;5;208m%.0f%%\033[0m\n", en_p);
}

void calc_energ(avent avt, avent inmg, float *en_a, float *en_m) { // [FUNÇÃO DE BARRA DE COMBATE]
  do {
    *en_a += (avt.vel + rand() % 5) / 100.0;
    *en_m += (inmg.vel + rand() % 5) / 100.0;
  } while ((*en_a < 1 && *en_m < 1) || *en_a == *en_m);
}

int calc_dano(int atq, int def, double dano_base) { // [FUNÇÃO DE CÁLCULO DE DANO]
  int dano = 0;
  if (def > 0) {
    dano = (1 + (atq / def)) * dano_base;
  }
    else {
      dano = atq * dano_base;
    }
  return dano;
}

int turn_avent(rpg FRPG, avent avt, avent inmg, int vid_a, int vid_m, int turn, float en_a, float en_m) { // [FUNÇÃO DE TURNO DO ALIADO]
  int i, opcao, aux;
  aux = sizeof_string(FRPG.habil_tipos);
  do {
    do {
      limpa_tela();
      opcao = -1;
      barra("\n", "\n");
      centralizar("\033[38;5;46m[Turno: %d]\033[0m", turn);
      barra("\n", "\n");
      barra("\n", "\n");
      printf("\033[38;5;39m[%s][Lvl: %d]\033[0m\n", avt.nome, avt.lvl);
      exib_energia(en_a);
      exib_vid(vid_a, avt.vid);
      barra("", "\n");
      barra("\n", "\n");
      printf("\033[38;5;196m[%s][Lvl: %d]\033[0m\n", inmg.nome, inmg.lvl);
      exib_energia(en_m);
      exib_vid(vid_m, inmg.vid);
      barra("", "\n");
      barra("\n", "\n");
      centralizar("\033[38;5;39m[TURNO DO ALIADO]\033[0m");
      barra("\n", "");
      list_hab_avent(FRPG, avt);
      barra("\n", "\n");
      printf("[\033[38;5;202m0\033[0m]> Desistir");
      barra("\n", "");
      barra("\n", "\n");
      printf("Opção\033[38;5;202m: ");
      scanf("%d", &opcao);
      __fpurge(stdin);
      barra("", "\n");
      if (opcao < 0 || opcao > aux) {
        printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
      }
    } while (opcao < 0 || opcao > aux);
    opcao--;
    if (!strcmp(avt.hab[opcao].tipo, FRPG.habil_tipos[1])) {
      printf("\n\033[38;5;196m[Não é possível atacar com essa habilidade!]\033[0m\n"); 
    }      
      else if (avt.hab[opcao].cooldown > 0) {
        printf("\n\033[38;5;196m[Habilidade em cooldown!]\033[0m\n");
      }
  } while (!strcmp(avt.hab[opcao].tipo, FRPG.habil_tipos[1]) || avt.hab[opcao].cooldown > 0);
  return opcao;
}

int turn_inmg(rpg FRPG, avent inmg, avent avt, int vid_m, int vid_a, int turn, float en_a, float en_m) { // [FUNÇÃO DE TURNO DO INIMIGO]
  limpa_tela();
  barra("\n", "\n");
  centralizar("\033[38;5;46m[Turno: %d]\033[0m", turn);
  barra("\n", "\n");
  barra("\n", "\n");
  printf("\033[38;5;39m[%s][Lvl: %d]\033[0m\n", avt.nome, avt.lvl);
  exib_energia(en_a);
  exib_vid(vid_a, avt.vid);
  barra("", "\n");
  barra("\n", "\n");
  printf("\033[38;5;196m[%s][Lvl: %d]\033[0m\n", inmg.nome, inmg.lvl);
  exib_energia(en_m);
  exib_vid(vid_m, inmg.vid);
  barra("", "\n");
  barra("\n", "\n");
  centralizar("\033[38;5;196m[TURNO DO INIMIGO]\033[0m");
  barra("\n", "");
  list_hab_avent(FRPG, inmg);
  barra("\n", "\n");
  if (inmg.hab[2].cooldown == 0 && strcmp(inmg.hab[2].tipo, FRPG.habil_tipos[1])) {
    return 2;
  }
    else if (inmg.hab[1].cooldown == 0 && strcmp(inmg.hab[1].tipo, FRPG.habil_tipos[1])) {
      return 1;
    }
  return 0;
}

void efeit_habil(rpg FRPG, avent *avt, avent *inmg, habil hbl, int *vid_a, int *vid_m, float *en_a, float *en_m) { // [FUNÇÃO DE EFEITOS DA HABILIDADE]
  for (int i = 0; FRPG.habil_mods[i] != NULL; i++) {
    if (strstr(hbl.desc, FRPG.habil_mods[i]) != NULL) {
      if (i == 0) {
        avt->atq += avt->atq * (atoi(FRPG.habil_mods[i]) / 100.0);
        printf("\n\033[38;5;51m[\033[38;5;46m%s\033[38;5;51m]\033[0m\n", FRPG.habil_mods[i]);
      }
        else if (i == 1) {
          inmg->atq += inmg->atq * (atoi(FRPG.habil_mods[i]) / 100.0);
          printf("\n\033[38;5;51m[\033[38;5;46m%s\033[38;5;51m]\033[0m\n", FRPG.habil_mods[i]);
        }
          else if (i == 2) {
            avt->def += avt->def * (atoi(FRPG.habil_mods[i]) / 100.0);
            printf("\n\033[38;5;51m[\033[38;5;46m%s\033[38;5;51m]\033[0m\n", FRPG.habil_mods[i]);
          }
            else if (i == 3) {
              inmg->def += inmg->def * (atoi(FRPG.habil_mods[i]) / 100.0);
              printf("\n\033[38;5;51m[\033[38;5;46m%s\033[38;5;51m]\033[0m\n", FRPG.habil_mods[i]);
            }
              else if (i == 4) {
                avt->vel += avt->vel * (atoi(FRPG.habil_mods[i]) / 100.0);
                printf("\n\033[38;5;51m[\033[38;5;46m%s\033[38;5;51m]\033[0m\n", FRPG.habil_mods[i]);
              }
                else if (i == 5) {
                  inmg->vel += inmg->vel * (atoi(FRPG.habil_mods[i]) / 100.0);
                  printf("\n\033[38;5;51m[\033[38;5;46m%s\033[38;5;51m]\033[0m\n", FRPG.habil_mods[i]);
                }
                  else if (i == 6) {
                    *vid_a += *vid_a * (atoi(FRPG.habil_mods[i]) / 100.0);
                    if (*vid_a > avt->vid) {
                      *vid_a = avt->vid;
                    }
                    printf("\n\033[38;5;51m[\033[38;5;46m%s\033[38;5;51m]\033[0m\n", FRPG.habil_mods[i]);
                  }
                    else if (i == 7) {
                      *vid_m += *vid_m * (atoi(FRPG.habil_mods[i]) / 100.0);
                      printf("\n\033[38;5;51m[\033[38;5;46m%s\033[38;5;51m]\033[0m\n", FRPG.habil_mods[i]);
                    }
                      else if (i == 8) {
                        for (int j = 1; FRPG.habil_tipos[j] != NULL; j++) {
                          if (avt->hab[j].cooldown > 0) {
                            avt->hab[j].cooldown += atoi(FRPG.habil_mods[i]);  
                          }
                        }
                        printf("\n\033[38;5;51m[\033[38;5;46m%s\033[38;5;51m]\033[0m\n", FRPG.habil_mods[i]);
                      }
                        else if (i == 9) {
                          for (int j = 1; FRPG.habil_tipos[j] != NULL; j++) {
                            inmg->hab[j].cooldown += atoi(FRPG.habil_mods[i]);
                          }
                          printf("\n\033[38;5;51m[\033[38;5;46m%s\033[38;5;51m]\033[0m\n", FRPG.habil_mods[i]);
                        }
                          else if (i == 10) {
                            *en_a += atoi(FRPG.habil_mods[i]) / 100.0;
                            printf("\n\033[38;5;51m[\033[38;5;46m%s\033[38;5;51m]\033[0m\n", FRPG.habil_mods[i]);
                          }
                            else if (i == 11) {
                              *en_m += atoi(FRPG.habil_mods[i]) / 100.0;
                              if (*en_m < 0) {
                                *en_m = 0;
                              }
                              printf("\n\033[38;5;51m[\033[38;5;46m%s\033[38;5;51m]\033[0m\n", FRPG.habil_mods[i]);
                            }
    }
  }
}

void use_habil(rpg *FRPG, avent *avt, avent *inmg, habil *hbl, int *vid_a, int *vid_m, int esc, int *esc_h, int turn, float *en_a, float *en_m) { // [FUNÇÃO DE USAR HABILIDADE]
  int i, dano;
  limpa_tela();
  if (!strcmp(avt->classe, "Monstro")) {
    barra("\n", "\n");
    centralizar("\033[38;5;46m[Turno: %d]\033[0m", turn);
    barra("\n", "\n");  
    barra("\n", "\n");
    printf("\033[38;5;39m[%s][Lvl: %d]\033[0m\n", inmg->nome, inmg->lvl);
    exib_energia(*en_m);
    exib_vid(*vid_m, inmg->vid);
    barra("", "\n");
    barra("\n", "\n");
    printf("\033[38;5;196m[%s][Lvl: %d]\033[0m\n", avt->nome, avt->lvl);
    exib_energia(*en_a);
    exib_vid(*vid_a, avt->vid);
    barra("", "\n");
    barra("\n", "\n");
    printf("\033[38;5;220m[%s usou [\033[38;5;51m%s\033[38;5;220m]!]\033[0m", avt->nome, hbl->nome);
    barra("\n", "\n");
  }
    else {
      barra("\n", "\n");
      centralizar("\033[38;5;46m[Turno: %d]\033[0m", turn);
      barra("\n", "\n");   
      barra("\n", "\n");
      printf("\033[38;5;39m[%s][Lvl: %d]\033[0m\n", avt->nome, avt->lvl);
      exib_energia(*en_a);
      exib_vid(*vid_a, avt->vid);
      barra("", "\n");
      barra("\n", "\n");
      printf("\033[38;5;196m[%s][Lvl: %d]\033[0m\n", inmg->nome, inmg->lvl);
      exib_energia(*en_m);
      exib_vid(*vid_m, inmg->vid);
      barra("", "\n");
      barra("\n", "\n");
      printf("\033[38;5;220m[%s usou [\033[38;5;51m%s\033[38;5;220m]!]\033[0m", avt->nome, hbl->nome);
      barra("\n", "\n");
    }
  *en_a = 0;
  efeit_habil(*FRPG, avt, inmg, *hbl, vid_a, vid_m, en_a, en_m);
  if (!strcmp(hbl->tipo, FRPG->habil_tipos[0])) {
    dano = calc_dano(avt->atq, inmg->def, hbl->mult);
    barra("\n", "\n");
    printf("\033[38;5;220m[%s causou [\033[38;5;196m%d\033[38;5;220m] de dano!]\033[0m", avt->nome, dano);
    barra("\n", "\n");
    *vid_m -= dano;
  }
  for (i = 0; FRPG->habil_tipos[i] != NULL; i++) {
    if (avt->hab[i].cooldown > 0) {
      avt->hab[i].cooldown--;
      if (!strcmp(avt->hab[i].tipo, FRPG->habil_tipos[1]) && avt->hab[i].cooldown == 0) {
        barra("\n", "\n");
        printf("\033[38;5;220m[%s ativou a passiva \n[\033[38;5;51m%s\033[38;5;220m]!]\033[0m", avt->nome, avt->hab[i].nome);
        barra("\n", "\n");
        if (!strcmp(avt->classe, "Monstro")) {
          efeit_habil(*FRPG, avt, inmg, FRPG->inmg[esc].hab[1], vid_a, vid_m, en_a, en_m);
        }
          else {
            efeit_habil(*FRPG, avt, inmg, FRPG->avt[esc].hab[1], vid_a, vid_m, en_a, en_m);
          }
        dano = calc_dano(avt->atq, inmg->def, hbl->mult);
        barra("\n", "\n");
        printf("\033[38;5;220m[%s causou [\033[38;5;196m%d\033[38;5;220m] de dano!]\033[0m", avt->nome, dano);
        barra("\n", "\n");
        *vid_m -= dano;
        if (!strcmp(avt->classe, "Monstro")) {
          avt->hab[i].cooldown = FRPG->inmg[esc].hab[i].cooldown;
        }
          else {
            avt->hab[i].cooldown = FRPG->avt[esc].hab[i].cooldown;
          }
      }
    }
  }
  if (!strcmp(avt->classe, "Monstro")) {
    hbl->cooldown = FRPG->inmg[esc].hab[*esc_h].cooldown;
  }
    else {
      hbl->cooldown = FRPG->avt[esc].hab[*esc_h].cooldown;
    }
  if (!strcmp(hbl->tipo, FRPG->habil_tipos[2])) {
    barra("\n", "\n");
    printf("\033[38;5;220m[%s ganhou [\033[38;5;51mTURNO EXTRA\033[38;5;220m]!]\033[0m", avt->nome);
    barra("\n", "\n");
    *esc_h = -2;
  }
}

void drop_item(rpg *FRPG, item *ite, int lvl_dif, int *ct) { // [FUNÇÃO DE ITEM DROP]
  int i, aux;
  aux = sizeof_string(FRPG->itens_nome);
  strcpy(ite->nome, FRPG->itens_nome[rand() % aux]);
  strcpy(ite->tipo, FRPG->itens_aux[rand() % 5]);
  if (strstr(ite->tipo, "Equipamento") != NULL) {
    ite->utl = 1000 * (lvl_dif + 1);
  }
    else {
      ite->utl = (lvl_dif + 1);
    }
  ite->ID = *ct + 1;
  barra("\n", "\n");
  centralizar("\033[38;5;220m[Você obteve um item!]\033[0m");
  printf("\n<>--------------<>--------------<>\n");
  printf("|\033[38;5;51m[Nome: %s]\033[0m\n", ite->nome);
  printf("|\033[38;5;51m[Tipo: %s]\033[0m\n", ite->tipo);
  printf("|\033[38;5;51m[Efeito: +%d]\033[0m", ite->utl);
  barra("\n", "\n");
  printf("[\033[38;5;46m+%d\033[38;5;220m[¢]\033[0m]\n", (lvl_dif + 1) * 100);
  printf("[\033[38;5;46m+%d\033[38;5;196m[◊]\033[0m]", (lvl_dif + 1) * 10);
  barra("\n", "\n");
  FRPG->ouro += (lvl_dif + 1) * 100;
  FRPG->rubi += (lvl_dif + 1) * 10; 
  (*ct)++;
}

void aventura(rpg *FRPG, int ct_a, int *ct_e, int *ct_i) { // [FUNÇÃO DE AVENTURA]
  int lvl_dif = escolh_lvl_dif();
  if (lvl_dif + 1 == 0) {
    printf("\n\033[38;5;220m[Voltando...]\033[0m\n"); 
    return;
  }
  int esc = escolh_avent(*FRPG, ct_a);
  if (esc + 1 == 0) {
    printf("\n\033[38;5;220m[Voltando...]\033[0m\n");    
    return;
  }
  int aux, vida_a, vida_m, turno = 1;
  float energ_p = 0, energ_m = 0;  
  avent btl_a = FRPG->avt[esc];
  avent btl_m = FRPG->inmg[lvl_dif];  
  calc_atb(*FRPG, &btl_a);
  vida_a = btl_a.vid, vida_m = btl_m.vid;
  while (vida_a > 0 && vida_m > 0) {
    calc_energ(btl_a, btl_m, &energ_p, &energ_m);
    if (energ_p > energ_m) { // [TURNO DO AVENTUREIRO]
      do {
        aux = turn_avent(*FRPG, btl_a, btl_m, vida_a, vida_m, turno, energ_p, energ_m);
        if (aux + 1 == 0) {
          if (sim_nao()) {
            barra("\n", "\n");
            centralizar("\033[38;5;196m[Você desistiu!]\033[0m");
            barra("\n", "\n");
            vida_a = 0;
          }
            else {
              printf("\n\033[38;5;196m[Você não desistiu!]\033[0m\n");
              aux = -2;
            }
        }
          else {
            use_habil(FRPG, &btl_a, &btl_m, &btl_a.hab[aux], &vida_a, &vida_m, esc, &aux, turno, &energ_p, &energ_m);   
          }       
      } while (aux == -2);
    }
      else if (energ_p < energ_m) { // [TURNO DO MONSTRO]
        do {
          aux = turn_inmg(*FRPG, btl_m, btl_a, vida_m, vida_a, turno, energ_p, energ_m);
          use_habil(FRPG, &btl_m, &btl_a, &btl_m.hab[aux], &vida_m, &vida_a, lvl_dif, &aux, turno, &energ_m, &energ_p);
        } while (aux == -2);
      }
    turno++;
  }

  limpa_tela();
  if (vida_a <= 0 && vida_m <= 0) {
    barra("\n", "\n");
    centralizar("\033[38;5;201m[EMPATE!]\033[0m");
    barra("\n", "\n");
  }
    else if (vida_a <= 0) {
      barra("\n", "\n");
      centralizar("\033[38;5;196m[DERROTA!]\033[0m");
      barra("\n", "\n");
    }
      else if (vida_m <= 0) {
        barra("\n", "\n");
        centralizar("\033[38;5;201m[VITORIA!]\033[0m");
        barra("\n", "\n");       
        lvl_up_avent(&FRPG->avt[esc], lvl_dif);
        FRPG->itm = (item *) realloc(FRPG->itm, (*ct_i + 1) * sizeof(item));
        if (FRPG->itm != NULL) {
          drop_item(FRPG, &FRPG->itm[*ct_i], lvl_dif, ct_i); 
        }
          else {
            printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
            exit(1);
          }
      }
}

int escolh_salvar() { // [FUNÇÃO DE ESCOLHA DO ARQUIVO P/ SALVAR]
  int opcao;
  do {
    limpa_tela();
    opcao = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[ESCOLHER O QUE SALVAR]\033[0m");
    barra("\n", "\n");
    printf("|[\033[38;5;51m1\033[0m]> Salvar Aventureiros\n");
    printf("|[\033[38;5;51m2\033[0m]> Salvar Equipamentos\n");
    printf("|[\033[38;5;51m3\033[0m]> Salvar Itens\n");
    printf("|[\033[38;5;51m4\033[0m]> Salvar Vendas");
    barra("\n", "\n");
    printf("|[\033[38;5;220m0\033[0m]> Voltar");
    barra("\n", "\n");
    printf("Opção\033[38;5;51m: ");
    scanf("%d", &opcao);
    __fpurge(stdin);
    barra("", "\n");
    if (opcao < 0 || opcao > 4) {
      printf("\n\033[38;5;196m[Opção inválida!]\033[0m\n");
    }
  } while (opcao < 0 || opcao > 4);
  return opcao;
}

int escolh_carregar() { // [FUNÇÃO DE ESCOLHA DO ARQUIVO P/ CARREGAR]
  int opcao;
  do {
    limpa_tela();
    opcao = -1;
    barra("\n", "\n");
    centralizar("\033[38;5;201m[ESCOLHER O QUE CARREGAR]\033[0m");
    barra("\n", "\n");
    printf("|[\033[38;5;51m1\033[0m]> Carregar Aventureiros\n");
    printf("|[\033[38;5;51m2\033[0m]> Carregar Equipamentos\n");
    printf("|[\033[38;5;51m3\033[0m]> Carregar Itens\n");
    printf("|[\033[38;5;51m4\033[0m]> Carregar Vendas");
    barra("\n", "\n");
    printf("|[\033[38;5;220m0\033[0m]> Voltar");
    barra("\n", "\n");
    printf("Opção\033[38;5;51m: ");
    scanf("%d", &opcao);
    __fpurge(stdin);
    barra("", "\n");
    if (opcao < 0 || opcao > 4) {
      printf("\n\033[38;5;196m[Opção inválida!]\033[0m\n");
    }
  } while (opcao < 0 || opcao > 4);
  return opcao;
}

void salvar_avent(char *arquivo, avent *avt, int ct) { // [FUNÇÃO P/ SALVAR OS AVENTUREIROS EXISTENTES]
  FILE *file = fopen(arquivo, "wb");
  if (file) {
    fwrite(&ct, sizeof(int), 1, file);
    for (int i = 0; i < ct; i++) {
      fwrite(avt, sizeof(avent), 1, file);
      avt++;
    }
    printf("\n\033[38;5;201m[Aventureiros salvos com sucesso!]\033[0m\n");
    fclose(file);  
  }
    else {
      printf("\n\033[38;5;196m[Erro ao abrir arquivo de aventureiros!]\033[0m\n");
      exit(1);
    }
}

void salvar_equip(char *arquivo, equip *eqt, int ct) { // [FUNÇÃO P/ SALVAR OS EQUIPAMENTOS EXISTENTES]
  FILE *file = fopen(arquivo, "wb");
  if (file) {
    fwrite(&ct, sizeof(int), 1, file);
    for (int i = 0; i < ct; i++) {
      fwrite(eqt, sizeof(equip), 1, file);
      eqt++;
    }
    printf("\n\033[38;5;201m[Equipamentos salvos com sucesso!]\033[0m\n");
    fclose(file);
  }
    else {
      printf("\n\033[38;5;196m[Erro ao abrir arquivo de equipamentos!]\033[0m\n");
      exit(1);
    }
}

void salvar_itens(char *arquivo, item *ite, int ct) { // [FUNÇÃO P/ SALVAR OS ITENS EXISTENTES]
  FILE *file = fopen(arquivo, "wb");
  if (file) {
    fwrite(&ct, sizeof(int), 1, file);
    for (int i = 0; i < ct; i++) {
      fwrite(ite, sizeof(item), 1, file);
      ite++;
    }  
    printf("\n\033[38;5;201m[Itens salvos com sucesso!]\033[0m\n");
    fclose(file);    
  } 
    else {
      printf("\n\033[38;5;196m[Erro ao abrir arquivo de itens!]\033[0m\n");
      exit(1);
    }
}

void salvar_vendas(char *arquivo, hist_vend *vnd, int ct) { // [FUNÇÃO P/ SALVAR AS VENDAS EXISTENTES]
  FILE *file = fopen(arquivo, "wb");
  if (file) {
    fwrite(&ct, sizeof(int), 1, file);
    for (int i = 0; i < ct; i++) {
      fwrite(vnd, sizeof(hist_vend), 1, file);    
      vnd++;
    }
    printf("\n\033[38;5;201m[Vendas salvas com sucesso!]\033[0m\n");
    fclose(file);  
  }
    else {
      printf("\n\033[38;5;196m[Erro ao abrir arquivo de vendas!]\033[0m\n");
      exit(1);
    }
}

void carregar_avent(char *arquivo, rpg *FRPG, int *ct) { // [FUNÇÃO P/ CARREGAR OS AVENTUREIROS EXISTENTES]
  FILE *file = fopen(arquivo, "rb");
  if (file) {
    int aux, i;
    fread(&aux, sizeof(int), 1, file);
    if (aux > 0) {
      *ct = aux;
      FRPG->avt = (avent *) realloc(FRPG->avt, *ct * sizeof(avent));
      if (!FRPG->avt) {
        printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
        exit(1);
      }
      for (i = 0; i < *ct; i++) {
        fread(&(FRPG->avt[i]), sizeof(avent), 1, file);
      }
      printf("\n\033[38;5;201m[Aventureiros carregados com sucesso!]\033[0m\n"); 
    }
      else {
        printf("\n\033[38;5;196m[Não há aventureiros salvos!]\033[0m\n");
      }
    rewind(file);
    fclose(file);
  } 
    else {
      printf("\n\033[38;5;196m[Erro ao abrir arquivo de aventureiros!]\033[0m\n");
      exit(1);
    }
}

void carregar_equip(char *arquivo, rpg *FRPG, int *ct) { // [FUNÇÃO P/ CARREGAR OS EQUIPAMENTOS EXISTENTES]
  FILE *file = fopen(arquivo, "rb");
  if (file) {
    int aux, i;
    fread(&aux, sizeof(int), 1, file);
    if (aux > 0) {
      *ct = aux;
      FRPG->eqp = (equip *) realloc(FRPG->eqp, *ct * sizeof(equip));
      if (!FRPG->eqp) {
        printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
        exit(1);
      }
      for (i = 0; i < *ct; i++) {
        fread(&(FRPG->eqp[i]), sizeof(equip), 1, file);
      }
      printf("\n\033[38;5;201m[Equipamentos carregados com sucesso!]\033[0m\n");
    }
      else {
        printf("\n\033[38;5;196m[Não há equipamentos salvos!]\033[0m\n");
      }
    rewind(file);
    fclose(file);
  } 
    else {
      printf("\n\033[38;5;196m[Erro ao abrir arquivo de equipamentos!]\033[0m\n");
      exit(1);
    }
}

void carregar_itens(char *arquivo, rpg *FRPG, int *ct) { // [FUNÇÃO P/ CARREGAR OS ITENS EXISTENTES]
  FILE *file = fopen(arquivo, "rb");
  if (file) {
    int aux, i;
    fread(&aux, sizeof(int), 1, file);
    if (aux > 0) {
      *ct = aux;
      FRPG->loja_itm = (item *) realloc(FRPG->loja_itm, *ct * sizeof(item));
      if (!FRPG->loja_itm) {
        printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
        exit(1);        
      }
      for (i = 0; i < *ct; i++) {
        fread(&(FRPG->loja_itm[i]), sizeof(item), 1, file);
      }
      printf("\n\033[38;5;201m[Itens carregados com sucesso!]\033[0m\n");
    }
      else {
        printf("\n\033[38;5;196m[Não há itens salvos!]\033[0m\n");
      }
    rewind(file);
    fclose(file);
  } 
    else {
      printf("\n\033[38;5;196m[Erro ao abrir arquivo de itens!]\033[0m\n");
      exit(1);
    }
}

void carregar_vendas(char *arquivo, rpg *FRPG, int *ct) { // [FUNÇÃO P/ CARREGAR AS VENDAS EXISTENTES]
  FILE *file = fopen(arquivo, "rb");
  if (file) {
    int aux, i;
    fread(&aux, sizeof(int), 1, file);
    if (aux > 0) {
      *ct = aux;
      FRPG->vend = (hist_vend *) realloc(FRPG->vend, *ct * sizeof(hist_vend));
      if (!FRPG->vend) {
        printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
        exit(1);                  
      }
      for (i = 0; i < *ct; i++) {
        fread(&(FRPG->vend[i]), sizeof(hist_vend), 1, file);
      }
      printf("\n\033[38;5;201m[Vendas carregadas com sucesso!]\033[0m\n");
    }
      else {
        printf("\n\033[38;5;196m[Não há vendas salvas!]\033[0m\n");
      }
    rewind(file);
    fclose(file);
  } 
    else {
      printf("\n\033[38;5;196m[Erro ao abrir arquivo de vendas!]\033[0m\n");
      exit(1);
    }
}

void iniciar_rpg(rpg *FRPG, int *ct_a, int *ct_e, int *ct_i, int *ct_l) { // [FUNÇÃO DE INICIAR RPG]
  FRPG->tipos = (char **) realloc(FRPG->tipos, 7 * sizeof(char *));
  if (!FRPG->tipos) {
    printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
    exit(1);
  }
  FRPG->tipos[0] = "Arma";
  FRPG->tipos[1] = "Elmo";
  FRPG->tipos[2] = "Armadura";
  FRPG->tipos[3] = "Colar";
  FRPG->tipos[4] = "Anel";
  FRPG->tipos[5] = "Bota";
  FRPG->tipos[6] = NULL;

  FRPG->classes = (char **) realloc(FRPG->classes, 7 * sizeof(char *));
  if (!FRPG->classes) {
    printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
    exit(1);
  }
  FRPG->classes[0] = "Guerreiro";
  FRPG->classes[1] = "Cavaleiro";
  FRPG->classes[2] = "Arqueiro";
  FRPG->classes[3] = "Clérigo";
  FRPG->classes[4] = "Ladino";
  FRPG->classes[5] = "Mago";
  FRPG->classes[6] = NULL;

  FRPG->itens_aux = (char **) realloc(FRPG->itens_aux, 6 * sizeof(char *));
  if (!FRPG->itens_aux) {
    printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
    exit(1);
  }
  FRPG->itens_aux[0] = "Pedra de Equipamento";
  FRPG->itens_aux[1] = "Elixir da Vida";
  FRPG->itens_aux[2] = "Elixir do Ataque";
  FRPG->itens_aux[3] = "Elixir da Defesa";
  FRPG->itens_aux[4] = "Elixir da Velocidade";
  FRPG->itens_aux[5] = NULL;

  FRPG->itens_nome = (char **) realloc(FRPG->itens_nome, 10 * sizeof(char *));
  if (!FRPG->itens_nome) {
    printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
    exit(1);
  }
  FRPG->itens_nome[0] = "Elixir da Cura Profunda";
  FRPG->itens_nome[1] = "Poção da Velocidade Felina";
  FRPG->itens_nome[2] = "Elixir da Força Titânica";
  FRPG->itens_nome[3] = "Poção da Invisibilidade Efêmera";
  FRPG->itens_nome[4] = "Elixir da Sabedoria Ancestral";
  FRPG->itens_nome[5] = "Poção do Fogo Interno";
  FRPG->itens_nome[6] = "Elixir da Resistência Elemental";
  FRPG->itens_nome[7] = "Poção da Clareza Mental";
  FRPG->itens_nome[8] = "Elixir da Agilidade Graciosa";
  FRPG->itens_nome[9] = NULL;    

  FRPG->habil_nomes = (char **) realloc(FRPG->habil_nomes, 16 * sizeof(char *));
  if (!FRPG->habil_nomes) {
    printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
    exit(1);
  }
  FRPG->habil_nomes[0] = "Flecha Sombria";
  FRPG->habil_nomes[1] = "Escudo da Aurora";
  FRPG->habil_nomes[2] = "Lâmina Ardente";
  FRPG->habil_nomes[3] = "Vórtice Arcano";
  FRPG->habil_nomes[4] = "Mão da Cura";
  FRPG->habil_nomes[5] = "Rugido Selvagem";
  FRPG->habil_nomes[6] = "Lâmina Fantasma";
  FRPG->habil_nomes[7] = "Tempestade Elemental";
  FRPG->habil_nomes[8] = "Sussurros da Mente";
  FRPG->habil_nomes[9] = "Fúria Celestial";
  FRPG->habil_nomes[10] = "Toque da Morte";
  FRPG->habil_nomes[11] = "Redemoinho Venenoso";
  FRPG->habil_nomes[12] = "Dança das Sombras";
  FRPG->habil_nomes[13] = "Luz Purificadora";
  FRPG->habil_nomes[14] = "Estilhaço Estelar";
  FRPG->habil_nomes[15] = NULL;

  FRPG->habil_tipos = (char **) realloc(FRPG->habil_tipos, 4 * sizeof(char *));
  if (!FRPG->habil_tipos) {
    printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
    exit(1);
  }
  FRPG->habil_tipos[0] = "Ativa";
  FRPG->habil_tipos[1] = "Passiva";
  FRPG->habil_tipos[2] = "Especial";
  FRPG->habil_tipos[3] = NULL;

  FRPG->habil_mods = (char **) realloc(FRPG->habil_mods, 13 * sizeof(char *));
  if (!FRPG->habil_mods) {
    printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
    exit(1);
  }
  FRPG->habil_mods[0] = "+35% ATK"; 
  FRPG->habil_mods[1] = "-35% ATK";
  FRPG->habil_mods[2] = "+25% DEF";
  FRPG->habil_mods[3] = "-25% DEF";
  FRPG->habil_mods[4] = "+15% VEL";
  FRPG->habil_mods[5] = "-15% VEL";
  FRPG->habil_mods[6] = "+10% VID";  
  FRPG->habil_mods[7] = "-10% VID";
  FRPG->habil_mods[8] = "-1 CDWN";
  FRPG->habil_mods[9] = "+1 CDWN";
  FRPG->habil_mods[10] = "+20% ENERG";
  FRPG->habil_mods[11] = "-20% ENERG";
  FRPG->habil_mods[12] = NULL;

  FRPG->inmg = (avent *) realloc(FRPG->inmg, 5 * sizeof(avent));
  if (!FRPG->inmg) {
    printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
    exit(1);
  }
  FRPG->inmg[0] = (avent) {1, "Goblin", "Monstro", "666", 10, 10, 10, 10, 5, 0};
  FRPG->inmg[0].hab[0] = (habil) {1, "Ataque Rápido", "Ativa", "[+35% ATK]", 0, 1.15};
  FRPG->inmg[0].hab[1] = (habil) {2, "Investida Brutal", "Passiva", "[-1 CDWN]\n[+20% ENERG]", 2, 1.21};
  FRPG->inmg[0].hab[2] = (habil) {3, "Flecha Envenenada", "Especial", "[-10% VID]\n[-20% ENERG]\n[-25% DEF]", 3, 1.23};

  FRPG->inmg[1] = (avent) {2, "Orc", "Monstro", "666", 20, 20, 20, 20, 15, 0};
  FRPG->inmg[1].hab[0] = (habil) {4, "Ataque Poderoso", "Ativa", "[-1 CDWN]", 0, 1.31};
  FRPG->inmg[1].hab[1] = (habil) {5, "Intuição", "Passiva", "[+35% ATK]\n[+20% ENERG]\n[-25% DEF]", 3, 1.42};
  FRPG->inmg[1].hab[2] = (habil) {6, "Punição", "Ativa", "[-10% VID]\n[-20% ENERG]\n[-35% ATK]", 3, 1.45};

  FRPG->inmg[2] = (avent) {3, "Golen", "Monstro", "666", 30, 30, 30, 30, 25, 0};
  FRPG->inmg[2].hab[0] = (habil) {7, "Golpe Pesado", "Ativa", "[-25% DEF]", 0, 1.51};
  FRPG->inmg[2].hab[1] = (habil) {8, "Ataque Esmagador", "Ativa", "[-10% VID]\n[-20% ENERG]\n[-25% DEF]", 3, 1.61};
  FRPG->inmg[2].hab[2] = (habil) {9, "Núcleo de Mana", "Especial", "[+20% ENERG]\n[-10% VID]\n[-25% DEF]", 3, 1.62};

  FRPG->inmg[3] = (avent) {4, "Lich", "Monstro", "666", 40, 40, 40, 40, 35, 0};
  FRPG->inmg[3].hab[0] = (habil) {10, "Ataque Relâmpago", "Ativa", "[-20% ENERG]", 0, 1.71};
  FRPG->inmg[3].hab[1] = (habil) {11, "Poder das Almas", "Passiva", "[+35% ATK]\n[+20% ENERG]\n[-25% DEF]", 3, 1.81};
  FRPG->inmg[3].hab[2] = (habil) {12, "Poder da Morte", "Especial", "[-10% VID]\n[-20% ENERG]\n[-35% ATK]", 3, 1.82};

  FRPG->inmg[4] = (avent) {5, "Dragão", "Monstro","666", 50, 50, 50, 50, 45, 0};
  FRPG->inmg[4].hab[0] = (habil) {13, "Garras de Diamante", "Ativa", "[-25% DEF]", 0, 1.91};
  FRPG->inmg[4].hab[1] = (habil) {14, "Poder Ancestral", "Passiva", "[+35% ATK]\n[+20% ENERG]\n[+15% VEL]", 3, 2.01};
  FRPG->inmg[4].hab[2] = (habil) {15, "Sopro Divino", "Ativa", "[-10% VID]\n[-20% ENERG]\n[-35% ATK]", 3, 2.11};

  FRPG->itm = (item *) realloc(FRPG->itm, 5 * sizeof(item));
  if (!FRPG->itm) {
    printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
    exit(1);
  }
  FRPG->itm[0] = (item) {1, "Pedra de Amolar", "Pedra de Equipamento", 3, 1000, 100};
  FRPG->itm[1] = (item) {2, "Tônico Poderoso", "Elixir do Ataque", 6, 5, 100};
  FRPG->itm[2] = (item) {3, "Pena de Fênix", "Elixir da Vida", 4, 5, 100};
  FRPG->itm[3] = (item) {4, "Estatua da Deusa", "Elixir da Defesa", 1, 5, 100};
  FRPG->itm[4] = (item) {5, "Mercurio", "Elixir da Velocidade", 2, 5, 100};

  FRPG->loja_itm = (item *) realloc(FRPG->loja_itm, 5 * sizeof(item));
  if (!FRPG->loja_itm) {
    printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
    exit(1);
  }
  FRPG->loja_itm[0] = (item) {11, "Amolador", "Pedra de Equipamento", 2, 1000, 100};
  FRPG->loja_itm[1] = (item) {22, "Poção de Força", "Elixir do Ataque", 1, 5, 100};
  FRPG->loja_itm[2] = (item) {33, "Poção de Vida", "Elixir da Vida", 4, 5, 100};
  FRPG->loja_itm[3] = (item) {44, "Poção de Defesa", "Elixir da Defesa", 11, 5, 100};
  FRPG->loja_itm[4] = (item) {55, "Poção de Velocidade", "Elixir da Velocidade", 3, 5, 100};
  *ct_l += 5;

  FRPG->ouro = 50000;
  FRPG->rubi = 5000;
  FRPG->avt[0] = (avent) {1, "Alen", "Guerreiro", "031666", 50, 50, 50, 50, 25, 0, 23, 04, 1084, "Angélicas", "Montsdt", "Fitoa", 41};
  FRPG->avt[0].hab[0] = (habil) {1, "Golpe X", "Ativa", "[-1 CDWN]", 0, 1.34};
  FRPG->avt[0].hab[1] = (habil) {2, "Morte Certa", "Especial", "[+25% DEF]\n[-20% ENERG]", 2, 1.15};
  FRPG->avt[0].hab[2] = (habil) {3, "Ataque Rápido", "Ativa", "[+35% ATK]\n[-10% VID]\n[+20% ENERG]", 3, 1.65};
  FRPG->eqp[0] = (equip) {1, "Elysion", "Arma", 7, 7, 7, 7, 1, 0};
  *ct_a += 1;
  *ct_e += 1;
  *ct_i += 5;
}

int escolh_menu(rpg FRPG) { // [FUNÇÃO DE MENU PRINCIPAL]
  int op;
  do {
    limpa_tela();
    op = -1;
    list_recurs(FRPG);
    barra("\n", "\n");
    centralizar("\033[38;5;201m[INICIO]\033[0m");
    barra("\n", "\n");
    printf("|[\033[38;5;51m1\033[0m]> Aventureiros\n");
    printf("|[\033[38;5;51m2\033[0m]> Equipamentos\n");
    printf("|[\033[38;5;51m3\033[0m]> Loja de Itens\n");
    printf("|[\033[38;5;51m4\033[0m]> Inventário de Itens\n");
    printf("|[\033[38;5;51m5\033[0m]> Aventura\n");
    printf("|[\033[38;5;51m6\033[0m]> Arquivos");
    barra("\n", "\n");
    printf("|[\033[38;5;196m0\033[0m]> Sair");
    barra("\n", "\n");
    printf("Opção\033[38;5;51m: ");
    scanf("%d", &op);
    __fpurge(stdin);
    barra("", "\n");
    if (op < 0 || op > 6) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (op < 0 || op > 6);
  return op;
}

int escolh_menu_avent(rpg FRPG) { // [FUNÇÃO DE ESCOLHA DO MENU AVENTUREIRO]
  int op;
  do {
    limpa_tela();
    op = -1;
    list_recurs(FRPG);
    barra("\n", "\n");
    centralizar("\033[38;5;201m[AVENTUREIROS]\033[0m");
    barra("\n", "\n");
    printf("|[\033[38;5;51m1\033[0m]> Registrar Aventureiro \033[38;5;196m-10[◊]\033[0m\n");
    printf("|[\033[38;5;51m2\033[0m]> Alterar Aventureiro \033[38;5;196m-5[◊]\033[0m\n");
    printf("|[\033[38;5;51m3\033[0m]> Mostrar Aventureiros\n");
    printf("|[\033[38;5;51m4\033[0m]> Excluir Aventureiro \033[38;5;46m+05\033[38;5;196m[◊]\033[0m\n");
    printf("|[\033[38;5;51m5\033[0m]> Equipar Aventureiro\n");
    printf("|[\033[38;5;51m6\033[0m]> Desequipar Aventureiro");
    barra("\n", "\n");
    printf("|[\033[38;5;220m0\033[0m]> Voltar");
    barra("\n", "\n");
    printf("Opção\033[38;5;51m: ");
    scanf("%d", &op);
    __fpurge(stdin);
    barra("", "\n");
    if (op < 0 || op > 6) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (op < 0 || op > 6);
  return op;
}

int escolh_menu_eqp(rpg FRPG) { // [FUNÇÃO DE ESCOLHA DO MENU EQUIPAMENTO]
  int op;
  do {
    limpa_tela();
    op = -1;
    list_recurs(FRPG);
    barra("\n", "\n");
    centralizar("\033[38;5;201m[EQUIPAMENTOS]\033[0m");
    barra("\n", "\n");
    printf("|[\033[38;5;51m1\033[0m]> Forjar Equipamento \033[38;5;196m-100\033[38;5;220m[¢]\033[0m\n");
    printf("|[\033[38;5;51m2\033[0m]> Alterar Equipamento \033[38;5;196m-50\033[38;5;220m[¢]\033[0m\n");
    printf("|[\033[38;5;51m3\033[0m]> Exibir Equipamentos\n");
    printf("|[\033[38;5;51m4\033[0m]> Vender Equipamento \033[38;5;46m+50\033[38;5;220m[¢]\033[0m");
    barra("\n", "\n");
    printf("|[\033[38;5;220m0\033[0m]> Voltar");
    barra("\n", "\n");
    printf("Opção\033[38;5;51m: ");
    scanf("%d", &op);
    __fpurge(stdin);
    barra("", "\n");
    if (op < 0 || op > 4) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (op < 0 || op > 4);
  return op;
}

int escolh_menu_loja(rpg FRPG) { // [FUNÇÃO DE ESCOLHA DO MENU LOJA]
  int op;
  do {
    limpa_tela();
    op = -1;
    list_recurs(FRPG);
    barra("\n", "\n");
    centralizar("\033[38;5;201m[LOJA DE ITENS]\033[0m");
    barra("\n", "\n");
    printf("|[\033[38;5;51m01\033[0m]> Cadastrar Item\n");
    printf("|[\033[38;5;51m02\033[0m]> Alterar Item\n");
    printf("|[\033[38;5;51m03\033[0m]> Acessar Itens\n");
    printf("|[\033[38;5;51m04\033[0m]> Excluir Item\n");
    printf("|[\033[38;5;51m05\033[0m]> Vender Item\n");
    printf("|[\033[38;5;51m06\033[0m]> Alterar Venda\n");
    printf("|[\033[38;5;51m07\033[0m]> Histórico de Vendas\n");
    printf("|[\033[38;5;51m08\033[0m]> Excluir Venda\n");
    printf("|[\033[38;5;51m09\033[0m]> Verificar Vendas\n");
    printf("|[\033[38;5;51m10\033[0m]> Verificar Estoque");
    barra("\n", "\n");
    printf("|[\033[38;5;220m0\033[0m]> Voltar");
    barra("\n", "\n");
    printf("Opção\033[38;5;51m: ");
    scanf("%d", &op);
    __fpurge(stdin);
    barra("", "\n");
    if (op < 0 || op > 10) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (op < 0 || op > 10);
  return op;
}

int escolh_menu_itens(rpg FRPG) { // [FUNÇÃO DE ESCOLHA DO MENU INVENTÁRIO]
  int op;
  do {
    limpa_tela();
    op = -1;
    list_recurs(FRPG);
    barra("\n", "\n");
    centralizar("\033[38;5;201m[INVENTÁRIO DE ITENS]\033[0m");
    barra("\n", "\n");
    printf("|[\033[38;5;51m1\033[0m]> Acessar Itens\n");
    printf("|[\033[38;5;51m2\033[0m]> Utilizar Itens\n");
    printf("|[\033[38;5;51m3\033[0m]> Revender Item");
    barra("\n", "\n");
    printf("|[\033[38;5;220m0\033[0m]> Voltar");
    barra("\n", "\n");
    printf("Opção\033[38;5;51m: ");
    scanf("%d", &op);
    __fpurge(stdin);
    barra("", "\n");
    if (op < 0 || op > 3) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (op < 0 || op > 3);
  return op;
}

void menu_avent(rpg *FRPG, int *ct_a, int *ct_e, int *ct_i, int *ct_v, int *ct_l) { // [FUNÇÃO DE MENU DE AVENTUREIROS]
  int opcao, aux, loop_ext = 1;
  while (loop_ext) {
    opcao = escolh_menu_avent(*FRPG);
    if (opcao == 0) { // [VOLTAR]
      if (sim_nao()) {
        loop_ext = 0;
        printf("\n\033[38;5;220m[Voltando...]\033[0m\n"); 
      }
        else {
          printf("\n\033[38;5;196m[Cancelado!]\033[0m\n");
        }
    }
      else if (opcao == 1) { // [REGISTRAR AVENTUREIRO]
        if (*ct_a < 100) {
          if (FRPG->rubi >= 10) {
            if (sim_nao()) {
              FRPG->avt = (avent *) realloc(FRPG->avt, (*ct_a + 1) * sizeof(avent));
              if (FRPG->avt) {
                regist_avent(FRPG, &FRPG->avt[*ct_a], ct_a);
              } 
                else {
                  printf("\n\033[38;5;196m[Erro ao realocar memória!]\033[0m\n");
                  exit(1);
                }
            }
              else {
                printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
              }
          }
            else {
              printf("\n\033[38;5;196m[Rubis insuficientes!]\033[0m\n");
            }
        }
          else {
            printf("\n\033[38;5;196m[Limite de aventureiros atingido!]\033[0m\n");
          }
      }
        else if (opcao == 2) { // [ALTERAR AVENTUREIRO]
          if (FRPG->rubi >= 5) {
            if (*ct_a > 0) {
              aux = escolh_avent(*FRPG, *ct_a);
              if (aux + 1 == 0) {
                printf("\n\033[38;5;220m[Voltando...]\033[0m\n");    
              }
                else if (sim_nao()) {
                  alter_avent(FRPG, &FRPG->avt[aux], *ct_a);
                }
                  else {
                    printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
                  }
            }
              else {
                printf("\n\033[38;5;196m[Não há aventureiros registrados!]\033[0m\n");
              }
          }
            else {
              printf("\n\033[38;5;196m[Rubis insuficientes!]\033[0m\n");
            }
        }
          else if (opcao == 3) { // [MOSTRAR AVENTUREIROS]
            if (*ct_a > 0) {
              limpa_tela();
              list_avent(FRPG, *ct_a);
            }
              else {
                printf("\n\033[38;5;196m[Nenhum aventureiro encontrado!]\033[0m\n");
              }
          }
            else if (opcao == 4) { // [EXCLUIR AVENTUREIRO]
              if (*ct_a > 0) {
                excl_avent(FRPG, ct_a, *ct_v);
              }
                else {
                  printf("\n\033[38;5;196m[Nenhum aventureiro encontrado!]\033[0m\n");
                }
            }
              else if (opcao == 5) { // [EQUIPAR AVENTUREIRO]
                if (*ct_a > 0) {
                  if (*ct_e > 0) {
                    equip_avent(FRPG, *ct_a, ct_e);
                  }
                    else {
                      printf("\n\033[38;5;196m[Nenhum equipamento encontrado!]\033[0m\n");
                    }
                }
                  else {
                    printf("\n\033[38;5;196m[Nenhum aventureiro encontrado!]\033[0m\n");
                  }
              }
                else if (opcao == 6) { // [DESEQUIPAR AVENTUREIRO]
                  if (*ct_a > 0) {
                    desequip_avent(FRPG, *ct_a, ct_e);
                  }
                    else {
                      printf("\n\033[38;5;196m[Nenhum equipamento encontrado!]\033[0m\n");
                    }
                }
  }
}

void menu_eqp(rpg *FRPG, int *ct_a, int *ct_e, int *ct_i, int *ct_v, int *ct_l) { // [FUNÇÃO DE MENU DE EQUIPAMENTOS]
  int opcao, aux, loop_ext = 1;
  while (loop_ext) {
    opcao = escolh_menu_eqp(*FRPG);
    if (opcao == 0) { // [VOLTAR]
      if (sim_nao()) {
        loop_ext = 0;
        printf("\n\033[38;5;220m[Voltando...]\033[0m\n"); 
      }
        else {
          printf("\n\033[38;5;196m[Cancelado!]\033[0m\n");
        }
    }
      else if (opcao == 1) { // [FORJAR EQUIPAMENTO]
        if (*ct_e < 100) {
          if (FRPG->ouro >= 100) {
            if (sim_nao()) {
              FRPG->eqp = (equip *) realloc(FRPG->eqp, (*ct_e + 1) * sizeof(equip));
              if (FRPG->eqp) {
                forj_epq(FRPG, &FRPG->eqp[*ct_e], ct_e);
              }
                else {
                  printf("\n\033[38;5;196m[Erro ao realocar memória!]\033[0m\n");
                  exit(1);
                }  
            }
              else {
                printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
              }
          }
            else {
              printf("\n\033[38;5;196m[Ouro insuficiente!]\033[0m\n");
            }
        }
          else {
            printf("\n\033[38;5;196m[Limite de equipamentos atingido!]\033[0m\n");
          }
      }
        else if (opcao == 2) { // [ALTERAR EQUIPAMENTO]
          if (FRPG->ouro >= 50) {
            if (*ct_e > 0) {
              aux = escolh_eqp(*FRPG, *ct_e);
              if (aux + 1 == 0) {
                printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
              }
                else if (sim_nao()) {
                  alter_eqp(FRPG, &FRPG->eqp[aux], *ct_e);
                }
                  else {
                    printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
                  }
            }
              else {
                printf("\n\033[38;5;196m[Não há equipamentos registrados!]\033[0m\n");
              }
          }
            else {
              printf("\n\033[38;5;196m[Ouro insuficiente!]\033[0m\n");
            }
        }
          else if (opcao == 3) { // [EXIBIR EQUIPAMENTOS]
            if (*ct_e > 0) {
              limpa_tela();
              list_eqp(*FRPG, *ct_e);
            }
              else {
                printf("\n\033[38;5;196m[Nenhum equipamento encontrado!]\033[0m\n");
              }
          }
            else if (opcao == 4) { // [VENDER EQUIPAMENTO]
              if (*ct_e > 0) {
                vend_eqp(FRPG, ct_e);
              }
                else {
                  printf("\n\033[38;5;196m[Nenhum equipamento encontrado!]\033[0m\n");
                }
            } 
  }
}

void menu_loja(rpg *FRPG, int *ct_a, int *ct_e, int *ct_i, int *ct_v, int *ct_l) { // [FUNÇÃO DE MENU DE ITENS DA LOJA]
  int opcao, aux, loop_ext = 1;
  while (loop_ext) {
    opcao = escolh_menu_loja(*FRPG);
    if (opcao == 0) { // [VOLTAR]
      if (sim_nao()) {
        loop_ext = 0;
        printf("\n\033[38;5;220m[Voltando...]\033[0m\n"); 
      }
        else {
          printf("\n\033[38;5;196m[Cancelado!]\033[0m\n");
        }
    }
      else if (opcao == 1) { // [CADASTRAR ITEM NA LOJA]
        if (*ct_l < 100) {
          if (sim_nao()) {
            FRPG->loja_itm = (item *) realloc(FRPG->loja_itm, (*ct_l + 1) * sizeof(item));
            if (FRPG->loja_itm) {
              cadast_item(FRPG, &FRPG->loja_itm[*ct_l], ct_l);
            }
              else {
                printf("\n\033[38;5;196m[Erro ao realocar memória!]\033[0m\n");
                exit(1);
              }
          }
            else {
              printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
            }
        }
          else {
            printf("\n\033[38;5;196m[Limite de vendas atingido!]\033[0m\n");
          }
      }
        else if (opcao == 2) { // [ALTERAR ITEM DA LOJA]
          if (*ct_l > 0) {
            aux = escolh_item_loja(*FRPG, *ct_l);
            if (aux + 1 == 0) {
              printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
            }
              else if (sim_nao()) {
                alter_item_loja(FRPG, &FRPG->loja_itm[aux], *ct_l);     
              }
                else {
                  printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
                }
          }
            else {
              printf("\n\033[38;5;196m[Não há itens registrados!]\033[0m\n");
            }
        }
          else if (opcao == 3) { // [ACESSAR ITENS DA LOJA]
            if (*ct_l > 0) {
              limpa_tela();
              list_item_loja(*FRPG, *ct_l);
            }
              else {
                printf("\n\033[38;5;196m[Nenhum item encontrado!]\033[0m\n");
              }
          }
            else if (opcao == 4) { // [EXCLUIR ITEM DA LOJA]
              if (*ct_l > 0) {
                aux = escolh_item_loja(*FRPG, *ct_l);
                if (aux + 1 == 0) {
                  printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
                }
                  else if (ver_item_vend(*FRPG, FRPG->loja_itm[aux].ID, *ct_v)) {
                    if (sim_nao()) {
                      excl_item_loja(FRPG, aux, ct_l);
                      printf("\n\033[38;5;220m[Item excluído com sucesso!]\033[0m\n");
                    }
                      else {
                        printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
                      }
                }
                  else {
                    printf("\n\033[38;5;196m[Impossível excluir item!]\033[0m");
                    printf("\n\033[38;5;196m[O item está cadastrado em uma venda!]\033[0m\n");
                  }     
              }
                else {
                  printf("\n\033[38;5;196m[Nenhum item encontrado!]\033[0m\n");
                }
            }
              else if (opcao == 5) { // [VENDER ITEM]
                if (*ct_v < 100) {
                  FRPG->vend = (hist_vend *) realloc(FRPG->vend, (*ct_v + 1) * sizeof(hist_vend));
                  loja_item(FRPG, &FRPG->vend[*ct_v], ct_i, ct_a, ct_v, ct_l);   
                }
                  else {
                    printf("\n\033[38;5;196m[Limite de vendas atingido!]\033[0m\n");
                  }
              }
                else if (opcao == 6) { // [ALTERAR VENDA]
                  if (*ct_v > 0) {
                    aux = escolh_venda(*FRPG, *ct_v);
                    if (aux + 1 == 0) {
                      printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
                    }
                      else if (sim_nao()) {
                        alter_venda(FRPG, &FRPG->vend[aux], *ct_v);
                      }
                        else {
                          printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
                        }
                  }
                    else {
                      printf("\n\033[38;5;196m[Nenhuma venda encontrada!]\033[0m\n");
                    }
                }
                  else if (opcao == 7) { // [VER HISTÓRICO DE VENDAS DE ITENS]
                    if (*ct_v > 0) {
                      limpa_tela();
                      list_vend(*FRPG, *ct_v);
                    }
                      else {
                        printf("\n\033[38;5;196m[Nenhuma venda encontrada!]\033[0m\n");
                      }
                  }
                    else if (opcao == 8) { // [EXCUIR VENDA]
                      if (*ct_v > 0) {
                        aux = escolh_venda(*FRPG, *ct_v);
                        if (aux + 1 == 0) {
                          printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
                        }
                          else if (sim_nao()) {
                            excl_venda(FRPG, aux, ct_v);
                            printf("\n\033[38;5;220m[Venda excluída com sucesso!]\033[0m\n");
                          }
                            else {
                              printf("\n\033[38;5;220m[Exclusão cancelada!]\033[0m\n");
                            }             
                      }
                        else {
                          printf("\n\033[38;5;196m[Nenhuma venda encontrada!]\033[0m\n");
                        }
                    }
                      else if (opcao == 9) { // [VERIFICAR VENDAS DE ITENS ACIMA DE UM VALOR]
                        if (*ct_v > 0) {
                          ver_venda(*FRPG, *ct_v);
                        }
                          else {
                            printf("\n\033[38;5;196m[Nenhuma venda encontrada!]\033[0m\n");
                          }  
                      }
                        else if (opcao == 10) { // [VERIFICAR ESTOQUE DE ITENS]
                          if (*ct_l > 0) {
                            ver_estoq(*FRPG, *ct_l);
                          }
                            else {
                              printf("\n\033[38;5;196m[Nenhum aventureiro encontrado!]\033[0m\n");
                            }
                        }
  }
}

void menu_itens(rpg *FRPG, int *ct_a, int *ct_e, int *ct_i, int *ct_v, int *ct_l) { // [FUNÇÃO DE MENU DE ITENS DO INVENTÁRIO]
  int opcao, aux, loop_ext = 1;
  while (loop_ext) {
    opcao = escolh_menu_itens(*FRPG);
    if (opcao == 0) { // [VOLTAR]
      if (sim_nao()) {
        loop_ext = 0;
        printf("\n\033[38;5;220m[Voltando...]\033[0m\n"); 
      }
        else {
          printf("\n\033[38;5;196m[Cancelado!]\033[0m\n");
        }
    }
      else if (opcao == 1) { // [VER ITENS]
        if (*ct_i > 0) {
          limpa_tela();
          list_item(*FRPG, *ct_i);
        }
          else {
            printf("\n\033[38;5;196m[Nenhum item encontrado!]\033[0m\n");
          }
      }
        else if (opcao == 2) { // [USAR ITEM]
          if ((*ct_a > 0 || *ct_e > 0) && *ct_i > 0) {
            use_item(FRPG, *ct_a, *ct_e, ct_i);
          }
            else {
              printf("\n\033[38;5;196m[Nenhum avent. e equip. ou item encontrados!]\033[0m\n");
            }       
        }
            else if (opcao == 3) { // [REVENDER ITENS]
              if (*ct_i > 0) {
                if (sim_nao()) {
                  revend_item(FRPG, ct_i, *ct_v);
                }
                  else {
                    printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
                  }
              }
                else {
                  printf("\n\033[38;5;196m[Nenhum item encontrado!]\033[0m\n");                  
                }
            }
  }
}

void menu_arquivo(rpg *FRPG, int *ct_a, int *ct_e, int *ct_i, int *ct_v, int *ct_l) { // [FUNÇÃO DE MENU DE ARQUIVOS]
  int opcao, esc, aux, loop_ext = 1;
  while (loop_ext) {
    aux = 0;
    do {
      limpa_tela();
      opcao = -1;
      list_recurs(*FRPG);
      barra("\n", "\n");
      centralizar("\033[38;5;201m[ARQUIVOS]\033[0m");
      barra("\n", "\n");
      printf("|[\033[38;5;51m1\033[0m]> Salvar Jogo\n");
      printf("|[\033[38;5;51m2\033[0m]> Carregar Jogo");
      barra("\n", "\n");
      printf("|[\033[38;5;220m0\033[0m]> Voltar");
      barra("\n", "\n");
      printf("Opção\033[38;5;51m: ");
      scanf("%d", &opcao);
      __fpurge(stdin);
      barra("", "\n");
      if (opcao < 0 || opcao > 2) {
        printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
      }
    } while (opcao < 0 || opcao > 2);

    if (opcao == 0) { // [VOLTAR]
      if (sim_nao()) {
        loop_ext = 0;
        printf("\n\033[38;5;220m[Voltando...]\033[0m\n"); 
      }
        else {
          printf("\n\033[38;5;196m[Cancelado!]\033[0m\n");
        }
    }
      else if (opcao == 1) { // [SALVAR JOGO]
        esc = escolh_salvar();
        if (esc == 0) {
          printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
        }
          else if (esc == 1) { // [SALVAR AVENTUREIROS]
            if (*ct_a > 0) {
              if (sim_nao()) {
                salvar_avent("Aventureiros.bin", FRPG->avt, *ct_a);
              }
                else {
                  printf("\n\033[38;5;196m[Salvamento cancelado!]\033[0m\n");
                }
            }
              else {
                printf("\n\033[38;5;196m[Não há aventureiros para salvar!]\033[0m\n");
              }
          }
            else if (esc == 2) { // [SALVAR EQUIPAMENTOS]
              if (*ct_e > 0) {
                if (sim_nao()) {
                  salvar_equip("Equipamentos.bin", FRPG->eqp, *ct_e);
                }
                  else {
                    printf("\n\033[38;5;196m[Salvamento cancelado!]\033[0m\n");
                  }
              }
                else {
                  printf("\n\033[38;5;196m[Não há equipamentos para salvar!]\033[0m\n");
                }               
            }
              else if (esc == 3) { // [SALVAR ITENS]
                if (*ct_i > 0) {
                  if (sim_nao()) {
                    salvar_itens("Itens.bin", FRPG->loja_itm, *ct_l);
                  }
                    else {
                      printf("\n\033[38;5;196m[Salvamento cancelado!]\033[0m\n");
                    }
              }
                else {
                  printf("\n\033[38;5;196m[Não há itens para salvar!]\033[0m\n");
                }
              }
                else if (esc == 4) { // [SALVAR VENDAS]
                  if (*ct_v > 0) {
                    if (sim_nao()) {
                      salvar_vendas("Vendas.bin", FRPG->vend, *ct_v);
                    }
                      else {
                        printf("\n\033[38;5;196m[Salvamento cancelado!]\033[0m\n");
                      }
                  }
                    else {
                      printf("\n\033[38;5;196m[Não há vendas para salvar!]\033[0m\n");   
                    }
                }
      }
        else if (opcao == 2) { // [CARREGAR JOGO]
          esc = escolh_carregar();
          if (esc == 0) { // [VOLTAR]
            printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
          }
            else if (esc == 1) { // [CARREGAR AVENTUREIROS]
              if (sim_nao()) {
                carregar_avent("Aventureiros.bin", FRPG, ct_a);
              }
                else {
                  printf("\n\033[38;5;196m[Carregamento cancelado!]\033[0m\n");
                }
            }
              else if (esc == 2) { // [CARREGAR EQUIPAMENTOS]
                if (sim_nao()) {
                  carregar_equip("Equipamentos.bin", FRPG, ct_e);
                }
                  else {
                    printf("\n\033[38;5;196m[Salvamento cancelado!]\033[0m\n");
                  }
              }
                else if (esc == 3) {  // [CARREGAR ITENS]
                  if (sim_nao()) {
                    carregar_itens("Itens.bin", FRPG, ct_l);    
                  }
                    else {
                      printf("\n\033[38;5;196m[Carregamento cancelado!]\033[0m\n");
                    }
                }
                  else if (esc == 4) { // [CARREGAR VENDAS]
                    if (sim_nao()) {
                      carregar_vendas("Vendas.bin", FRPG, ct_v);             
                    }
                      else {
                        printf("\n\033[38;5;196m[Carregamento cancelado!]\033[0m\n");
                      }
                  }
        }
  }
}

int main(void) { // [FUNÇÃO PRINCIPAL]
  srand(time(NULL));
  int ct_avent = 0, ct_eqp = 0, ct_vend = 0, ct_item = 0, ct_loja = 0, esc, loop = 1;
  rpg *GwG = (rpg *) calloc(1, sizeof(rpg));
  GwG->avt = (avent *) calloc(1, sizeof(avent));
  GwG->inmg = (avent *) calloc(1, sizeof(avent));
  GwG->eqp = (equip *) calloc(1, sizeof(equip));
  GwG->itm = (item *) calloc(1, sizeof(item));
  GwG->loja_itm = (item *) calloc(1, sizeof(item));
  GwG->vend = (hist_vend *) calloc(1, sizeof(hist_vend));
  GwG->tipos = (char **) calloc(1, sizeof(char *));
  GwG->classes = (char **) calloc(1, sizeof(char *));
  GwG->itens_aux = (char **) calloc(1, sizeof(char *));
  GwG->itens_nome = (char **) calloc(1, sizeof(char *));
  GwG->habil_mods = (char **) calloc(1, sizeof(char *));
  GwG->habil_tipos = (char **) calloc(1, sizeof(char *));
  GwG->habil_nomes = (char **) calloc(1, sizeof(char *));
  if (!GwG || !GwG->avt || !GwG->inmg || !GwG->eqp || !GwG->itm 
   || !GwG->vend || !GwG->tipos || !GwG->classes || !GwG->itens_aux 
   || !GwG->habil_mods || !GwG->itens_nome || !GwG->habil_tipos 
   || !GwG->habil_nomes || !GwG->loja_itm) {
    printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
    exit(1);
  } 
  iniciar_rpg(GwG, &ct_avent, &ct_eqp, &ct_item, &ct_loja);
  barra("\n", "\n");
  centralizar("\033[38;5;201m[*Bem-vindo ao G ⚜ G!*]\033[0m");
  barra("\n", "\n");
  while (loop) { // [LOOP PRINCIPAL]
    esc = escolh_menu(*GwG);
    if (esc == 0) { // [SAIR]
      if (sim_nao()) {
        limpa_tela();
        barra("\n", "\n");
        centralizar("\033[38;5;201m[*Obrigado por jogar!*]\033[0m");
        barra("\n", "\n");
        limpa_tela();
        loop = 0;
      }
        else {
          printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
        }
    }
      else if (esc == 1) { // [MENU AVENTUREIROS]
        menu_avent(GwG, &ct_avent, &ct_eqp, &ct_item, &ct_vend, &ct_loja);
      }
        else if (esc == 2) { // [MENU EQUIPAMENTOS]
          menu_eqp(GwG, &ct_avent, &ct_eqp, &ct_item, &ct_vend, &ct_loja);
        }
          else if (esc == 3) { // [MENU LOJA ITENS]
            menu_loja(GwG, &ct_avent, &ct_eqp, &ct_item, &ct_vend, &ct_loja);
          }     
            else if (esc == 4) { // [MENU INVENTÁRIO ITENS]
              menu_itens(GwG, &ct_avent, &ct_eqp, &ct_item, &ct_vend, &ct_loja);
            }
              else if (esc == 5) { // [MODO AVENTURA]
                if (ct_avent > 0) {
                  aventura(GwG, ct_avent, &ct_eqp, &ct_item);
                }
                  else {
                    printf("\n\033[38;5;196m[Nenhum aventureiro encontrado!]\033[0m\n");
                  }
              }
                else if (esc == 6) { // [MENU ARQUIVOS]
                  menu_arquivo(GwG, &ct_avent, &ct_eqp, &ct_item, &ct_vend, &ct_loja);            
                }
  }
  free(GwG->avt);
  free(GwG->inmg);
  free(GwG->eqp);
  free(GwG->itm);
  free(GwG->vend);
  free(GwG->loja_itm);
  free(GwG->tipos);
  free(GwG->classes);
  free(GwG->itens_aux);
  free(GwG->itens_nome);
  free(GwG->habil_mods);
  free(GwG->habil_tipos);
  free(GwG->habil_nomes);
  free(GwG);
  return 0;
}