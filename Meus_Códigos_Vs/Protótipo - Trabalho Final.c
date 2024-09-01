#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

typedef struct datas {
  int dia, mes, ano;
} data;

typedef struct enderecos {
  char rua[50], cidade[50], estado[50];
  int num;
} ender;

typedef struct equipamentos {
  char nome[50], tipo[50];
  int vid, def, atq, vel;
  int lvl, xp;
} equip;

typedef struct itens {
  char nome[50], tipo[50];
  int efeito, qtd, valor;
  long long int id;
} item;

typedef struct personagem {
  char nome[50], classe[50];
  int vid, def, atq, vel;
  int lvl, xp;
  long long int id;
  ender end;
  data dt_nasc;
} person;

typedef struct vendas {
  long long int id;
  person cl;
  item prodt;
  data dt_vend;
} venda;

typedef struct rpg {
  int ouro, rubi;
  char **itens, **classes;
  person *pers;
  item *itm;
  item *loja_itm;
  venda *vend;
} rpg;

void limpa_tela() { // [FUNÇÃO DE LIMPAR TELA]
  printf("\033[0m\nAperte [\033[38;5;39mENTER\033[0m] para continuar...");
  getchar();
  __fpurge(stdin);
  system("clear");
}

int sim_nao() { // [FUNÇÃO DE SIM OU NÃO]
  int opcao;
  do {
    limpa_tela();
    opcao = -1;
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("\033[38;5;201m[TEM CERTEZA?]\033[0m");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("|[\033[38;5;51m1\033[0m]> Sim\n");
    printf("|[\033[38;5;51m0\033[0m]> Não");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("Opção\033[38;5;51m: ");
    scanf("%d", &opcao);
    __fpurge(stdin);
    printf("\033[0m\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    if (opcao < 0 || opcao > 1) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (opcao < 0 || opcao > 1);
  return opcao;
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
  for (int i = 0; i < espacos; i++) {
    printf(" ");
  }
  printf("%s", str);
}

int ver_str(char *str) { // [FUNÇÃO DE VERIFICAR STRING]
  char letras_mai[] = "ABCÇDEFGHIJKLMNOPQRSTUVWXYZÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖØÙÚÛÜÝŸ";
  char letras_min[] = "abcçdefghijklmnopqrstuvwxyzàáâãäåæçèéêëìíîïðñòóôõöøùúûüýÿ";
  char temp[strlen(str)];
  sprintf(temp, "%c", str[0]);
  if (strstr(letras_mai, temp)) {
    for (int i = 0; str[i] != '\0'; i++) {
      sprintf(temp, "%c", str[i]);
      if (!strstr(letras_mai, temp) && !strstr(letras_min, temp)) {
        return 0;
      }
    }
  }
    else {
      return 0;
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

int ver_pers_vend(rpg ver, person vp, int cont_v) { //
  for (int i = 0; i < cont_v; i++) {
    if (vp.id == ver.vend[i].cl.id) {
      return 0;
    }
  }
  return 1;
} 

int ver_item_vend(rpg ver, item vi, int cont_v) {
  for (int i = 0; i < cont_v; i++) {
    if (vi.id == ver.vend[i].prodt.id) {
      return 0;
    }
  }
  return 1;
} 

int ver_id_pers(rpg ep, int cont, long long int id) { // [FUNÇÃO DE VERIFICAR ID DE PERSONAGEM]
  if (id <= 0) {
    return 0;
  }
    else {
      for (int i = 0; i < cont; i++) {
        if (ep.pers[i].id == id) {
          return 0;
        }
      }
    }
  return 1;
}

int ver_id_item(rpg ep, int cont, long long int id) { // [FUNÇÃO DE VERIFICAR ID DE ITEM]
  if (id <= 0) {
    return 0;
  }
    else {
      for (int i = 0; i < cont; i++) { 
        if (ep.itm[i].id == id) {
          return 0;
        }
      }
    }
  return 1;
}

int ver_id_vend(rpg ep, int cont, long long int id) { // [FUNÇÃO DE VERIFICAR ID DE VENDA]
  if (id <= 0) {
    return 0;
  }
    else {
      for (int i = 0; i < cont; i++) {
        if (ep.vend[i].id == id) {
          return 0;
        }
      }
    }
  return 1;
}

void list_pers(rpg rpl, int cont_p) { // [FUNÇÃO DE LISTAR PERSONAGENS]
  printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
  centralizar("\033[38;5;201m[PERSONAGENS]\033[0m");
  printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
  for (int i = 0; i < cont_p; i++) {
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("[\033[38;5;202m%d\033[0m]> \033[38;5;51m[ID: %03lld][%s][Lvl: %d] %s\033[0m", i + 1, rpl.pers[i].id, rpl.pers[i].classe, rpl.pers[i].lvl, rpl.pers[i].nome);
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    centralizar("\033[38;5;201m[DADOS DO PERSONAGEM]\033[0m");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("\033[38;5;51m[Data de nascimento: %02d/%02d/%02d]\033[0m", rpl.pers[i].dt_nasc.dia, rpl.pers[i].dt_nasc.mes, rpl.pers[i].dt_nasc.ano);
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    centralizar("\033[38;5;214m[Endereço]\033[0m"); 
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m");
    printf("\nRua: \033[38;5;51m%s\033[0m", rpl.pers[i].end.rua);
    printf("\nNº: \033[38;5;51m%d\033[0m", rpl.pers[i].end.num);
    printf("\nCidade: \033[38;5;51m%s\033[0m", rpl.pers[i].end.cidade);
    printf("\nEstado: \033[38;5;51m%s\033[0m\033[0m", rpl.pers[i].end.estado);
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    centralizar("\033[38;5;39m[STATUS]\033[0m");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("|\033[38;5;51m[Vid: %2d]\033[0m|\n", rpl.pers[i].vid);
    printf("|\033[38;5;51m[Def: %2d]\033[0m|\n", rpl.pers[i].def);
    printf("|\033[38;5;51m[Atq: %2d]\033[0m|\n", rpl.pers[i].atq);
    printf("|\033[38;5;51m[Vel: %2d]\033[0m|", rpl.pers[i].vel);
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
  }
}

void list_vend(rpg rpl, int cont_v) { // [FUNÇÃO DE LISTAR VENDAS]
  printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
  centralizar("\033[38;5;201m[VENDAS]\033[0m");
  printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m");
  for (int i = 0; i < cont_v; i++) {
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("[\033[38;5;202m%d\033[0m]> |\033[38;5;51m[ID: %03lld]\033[0m", i + 1, rpl.vend[i].id);
    printf("|\033[38;5;51m[Data: %02d/%02d/%02d]\033[0m|", rpl.vend[i].dt_vend.dia, rpl.vend[i].dt_vend.mes, rpl.vend[i].dt_vend.ano);
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    centralizar("\033[38;5;201m[DADOS DO CLIENTE]\033[0m");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("|\033[38;5;51m[ID: %03lld][Cliente: %s][Lvl: %d]\033[0m|", rpl.vend[i].cl.id, rpl.vend[i].cl.nome, rpl.vend[i].cl.lvl);
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("\033[38;5;51m[Data de nascimento: %02d/%02d/%02d]\033[0m", rpl.vend[i].cl.dt_nasc.dia, rpl.vend[i].cl.dt_nasc.mes, rpl.vend[i].cl.dt_nasc.ano);
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    centralizar("\033[38;5;214m[Endereço]\033[0m"); 
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m");
    printf("\nRua: \033[38;5;51m%s\033[0m", rpl.vend[i].cl.end.rua);
    printf("\nNº: \033[38;5;51m%d\033[0m", rpl.vend[i].cl.end.num);
    printf("\nCidade: \033[38;5;51m%s\033[0m", rpl.vend[i].cl.end.cidade);
    printf("\nEstado: \033[38;5;51m%s\033[0m\033[0m", rpl.vend[i].cl.end.estado);
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    centralizar("\033[38;5;39m[STATUS]\033[0m");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("|\033[38;5;51m[Vid: %2d]\033[0m|\n", rpl.vend[i].cl.vid);
    printf("|\033[38;5;51m[Def: %2d]\033[0m|\n", rpl.vend[i].cl.def);
    printf("|\033[38;5;51m[Atq: %2d]\033[0m|\n", rpl.vend[i].cl.atq);
    printf("|\033[38;5;51m[Vel: %2d]\033[0m|", rpl.vend[i].cl.vel);
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
  }
}

int escolh_pers(rpg ep, int cont) { // [FUNÇÃO DE ESCOLHER PERSONAGEM]
  int posi;
  do {
    limpa_tela();
    posi = -1;
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    centralizar("\033[38;5;201m[ESCOLHER PERSONAGEM]\033[0m");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m");
    list_pers(ep, cont);
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("Opção\033[38;5;202m: ");
    scanf("%d", &posi);
    __fpurge(stdin);
    printf("\033[0m\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    if (posi < 1 || posi > cont) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (posi < 1 || posi > cont);
  return --posi;
}

void ger_atb_pers(person *gap) { // [FUNÇÃO DE GERAR ATRIBUTOS DE PERSONAGEM]
  gap->lvl = 1;
  gap->xp = 0;
  gap->atq = rand() % 10 + 5;
  gap->def = rand() % 10 + 5;
  gap->vid = rand() % 10 + 5;
  gap->vel = rand() % 10 + 5;
}

void invoc_pers(rpg *iv, person *cp, int *cont_p) { // [FUNÇÃO DE INVOCAR PERSONAGEM]
  int opcao, lim;    
  do {
    limpa_tela();
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    centralizar("\033[38;5;201m[INVOCAR PERSONAGEM]\033[0m");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("ID\033[38;5;51m: ");
    scanf("%lld", &cp->id);
    __fpurge(stdin);
    printf("\033[0m\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    if (!ver_id_pers(*iv, *cont_p, cp->id)) {
      printf("\n\033[38;5;196m[ID inválido! Tente novamente...]\033[0m\n");
    }
  } while (!ver_id_pers(*iv, *cont_p, cp->id));
  
  do {
    limpa_tela();
    strcpy(cp->nome, " ");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    centralizar("\033[38;5;201m[INVOCAR PERSONAGEM]\033[0m");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("Nome\033[38;5;51m: ");
    scanf("%49[^\n]", cp->nome);
    __fpurge(stdin);
    printf("\033[0m\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    if (!ver_str(cp->nome)) {
      printf("\n\033[38;5;196m[Nome inválido! Tente novamente...]\033[0m\n");
    }
  } while (!ver_str(cp->nome));
  
  do {
    limpa_tela();
    opcao = -1, lim = 0;
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    centralizar("\033[38;5;201m[INVOCAR PERSONAGEM]\033[0m");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m");
    for (int i = 0; iv->classes[i] != NULL; i++) {
      printf("\n[\033[38;5;51m%d\033[0m]> %s", i + 1, iv->classes[i]);
      lim++;
    }
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("Classe\033[38;5;51m: ");
    scanf("%d", &opcao);
    __fpurge(stdin);
    printf("\033[0m\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    if (opcao < 1 || opcao > lim) {
      printf("\n\033[38;5;196m[Classe inválida! Tente novamente...]\033[0m\n");
    }
  } while (opcao < 1 || opcao > lim);
  strcpy(cp->classe, iv->classes[opcao - 1]);
  printf("\n\033[38;5;220m[Classe escolhida: %s]\033[0m\n", cp->classe);
  
  do {
    limpa_tela();
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    centralizar("\033[38;5;201m[INVOCAR PERSONAGEM]\033[0m");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("Data de nascimento\n\033[38;5;51m[DD/MM/AAAA]: ");
    scanf("%d/%d/%d", &cp->dt_nasc.dia, &cp->dt_nasc.mes, &cp->dt_nasc.ano);
    __fpurge(stdin);
    printf("\033[0m\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    if (!ver_data(cp->dt_nasc.dia, cp->dt_nasc.mes, cp->dt_nasc.ano)) {
      printf("\n\033[38;5;196m[Data inválida! Tente novamente...]\033[0m\n");
    }
  } while (!ver_data(cp->dt_nasc.dia, cp->dt_nasc.mes, cp->dt_nasc.ano));

  do {
    limpa_tela();
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    centralizar("\033[38;5;201m[INVOCAR PERSONAGEM]\033[0m");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("Rua\033[38;5;51m: ");
    scanf("%49[^\n]", cp->end.rua);
    __fpurge(stdin);
    printf("\033[0m\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    if (!ver_str(cp->end.rua)) {
      printf("\n\033[38;5;196m[Rua inválida! Tente novamente...]\033[0m\n");
    }
  } while (!ver_str(cp->end.rua));

  do {
    limpa_tela();
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    centralizar("\033[38;5;201m[INVOCAR PERSONAGEM]\033[0m");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("Nº da rua\033[38;5;51m: ");
    scanf("%d", &cp->end.num);
    __fpurge(stdin);
    printf("\033[0m\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    if (cp->end.num <= 0) {
      printf("\n\033[38;5;196m[Nº inválido! Tente novamente...]\033[0m\n");
    }
  } while (cp->end.num <= 0);

  do {
    limpa_tela();
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    centralizar("\033[38;5;201m[INVOCAR PERSONAGEM]\033[0m");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("Cidade\033[38;5;51m: ");
    scanf("%49[^\n]", cp->end.cidade);
    __fpurge(stdin);
    printf("\033[0m\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    if (!ver_str(cp->end.cidade)) {
      printf("\n\033[38;5;196m[Cidade inválida! Tente novamente...]\033[0m\n");
    }
  } while (!ver_str(cp->end.cidade));

  do {
    limpa_tela();
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    centralizar("\033[38;5;201m[INVOCAR PERSONAGEM]\033[0m");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("Estado\033[38;5;51m: ");
    scanf("%49[^\n]", cp->end.estado);
    __fpurge(stdin);
    printf("\033[0m\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    if (!ver_str(cp->end.estado)) {
      printf("\n\033[38;5;196m[Estado inválido! Tente novamente...]\033[0m\n");
    }
  } while (!ver_str(cp->end.estado));
  
  limpa_tela();
  printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
  centralizar("\033[38;5;220m[Aleatorizando atributos...]\033[0m");
  printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
  ger_atb_pers(cp);
  printf("\033[38;5;51m[ATQ: %d]\033[0m\n", cp->atq);
  printf("\033[38;5;51m[DEF: %d]\033[0m\n", cp->def);
  printf("\033[38;5;51m[VID: %d]\033[0m\n", cp->vid);
  printf("\033[38;5;51m[VEL: %d]\033[0m", cp->vel);
  printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
  iv->rubi -= 10;
  printf("\n[\033[38;5;196m-10◊\033[0m]\n");
  (*cont_p)++;
  printf("\n\033[38;5;220m[Personagem invocado com sucesso!]\033[0m\n");
}

void cadastr_item(rpg *ai, item *it, int *cont_i) { // [FUNÇÃO DE CADASTRAR ITEM]
  int i, lim, opcao;  
  do {
    limpa_tela();
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    centralizar("\033[38;5;201m[CADASTRAR ITEM]\033[0m");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("ID\033[38;5;51m: ");
    scanf("%lld", &it->id);
    __fpurge(stdin);
    printf("\033[0m\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    if (!ver_id_item(*ai, *cont_i, it->id)) {
      printf("\n\033[38;5;196m[ID inválido! Tente novamente...]\033[0m\n");
    }
  } while (!ver_id_item(*ai, *cont_i, it->id));
  
  do {
    limpa_tela();
    strcpy(it->nome, " ");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    centralizar("\033[38;5;201m[CADASTRAR ITEM]\033[0m");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("Nome\033[38;5;51m: ");
    scanf("%49[^\n]", it->nome);
    __fpurge(stdin);
    printf("\033[0m\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    if (!ver_str(it->nome)) {
      printf("\n\033[38;5;196m[Nome inválido! Tente novamente...]\033[0m\n");
    }
  } while (!ver_str(it->nome));
  
  do {
    limpa_tela();
    opcao = -1, lim = 0;
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    centralizar("\033[38;5;201m[CADASTRAR ITEM]\033[0m");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m");
    for (i = 0; ai->itens[i] != NULL; i++) {
      printf("\n[\033[38;5;51m%d\033[0m]> %s", i + 1, ai->itens[i]);
      lim++;
    }
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("Tipo do item\033[38;5;51m: ");
    scanf("%d", &opcao);
    __fpurge(stdin);
    printf("\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    if (opcao < 1 || opcao > lim) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (opcao < 1 || opcao > lim);
  strcpy(it->tipo, ai->itens[opcao - 1]);
  printf("\n\033[38;5;220m[Tipo escolhido: %s]\033[0m\n", it->tipo);

  do {
    limpa_tela();
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    centralizar("\033[38;5;201m[CADASTRAR ITEM]\033[0m");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("Efeito do item\033[38;5;51m: ");
    scanf("%d", &it->efeito);
    __fpurge(stdin);
    printf("\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    if (it->efeito <= 0) {
      printf("\n\033[38;5;196m[Valor inválido! Tente novamente...]\033[0m\n");
    }
  } while (it->efeito <= 0);
  
  do {
    limpa_tela();
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    centralizar("\033[38;5;201m[CADASTRAR ITEM]\033[0m");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("Valor\033[38;5;220m[¢]\033[38;5;51m: ");
    scanf("%d", &it->valor);
    __fpurge(stdin);
    printf("\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    if (it->valor <= 0) {
      printf("\n\033[38;5;196m[Valor inválido! Tente novamente...]\033[0m\n");
    }
  } while (it->valor <= 0);
  (*cont_i)++;
  printf("\n\033[38;5;220m[Item cadastrado com sucesso!]\033[0m\n");
}

void list_item(rpg li, int cont) { // [FUNÇÃO DE LISTAR ITENS]
  printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
  centralizar("\033[38;5;201m[ITENS]\033[0m");
  printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
  for (int i = 0; i < cont; i++) {
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("[\033[38;5;214m%d\033[0m]> \033[38;5;51m[ID: %03lld] %s\033[0m", i + 1, li.itm[i].id, li.itm[i].nome);
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("|\033[38;5;51m[QTD: %d]|[Efeito: +%2d]\033[0m|", li.itm[i].qtd, li.itm[i].efeito);
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
  }
}

void list_recurs(rpg lr) { // [FUNÇÃO DE LISTAR RECURSOS]
  printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
  centralizar("\033[38;5;201m[Recursos]\033[0m");
  printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
  printf("|\033[38;5;220m¢[Ouro]\033[0m: \033[38;5;51m%d\033[0m\n", lr.ouro);
  printf("|\033[38;5;196m◊[Rubi]\033[0m: \033[38;5;51m%d\033[0m", lr.rubi);
  printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
}

int escolh_item(rpg ei, int cont) { // [FUNÇÃO DE ESCOLHER ITEM]
  int posi;
  do {
    limpa_tela();
    posi = -1;
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    centralizar("\033[38;5;201m[ESCOLHER ITEM]\033[0m");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    list_item(ei, cont);
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("Opção\033[38;5;214m: ");
    scanf("%d", &posi);
    __fpurge(stdin);
    printf("\033[0m\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    if (posi < 1 || posi > cont) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (posi < 1 || posi > cont);
  return --posi;
}

int escolh_item_loja(rpg rpl, int cont_l) { // [FUNÇÃO DE ESCOLHER ITENS]
  int i, lim, opcao;
  do {
    limpa_tela();
    opcao = -1, lim = 0;
    list_recurs(rpl);
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    centralizar("\033[38;5;201m[LOJA DE ITENS]\033[0m");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m");
    for (i = 0; i < cont_l; i++) {
      printf("\n|[\033[38;5;214m%d\033[0m]> \033[38;5;51m[QTD: %d] %s\033[0m [\033[38;5;196m-%d\033[38;5;220m¢\033[0m]", i + 1, rpl.loja_itm[i].qtd, rpl.loja_itm[i].nome, rpl.loja_itm[i].valor);
      lim++;
    }
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("|[\033[38;5;214m0\033[0m]> Voltar");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("Opção\033[38;5;214m: ");
    scanf("%d", &opcao);
    __fpurge(stdin);
    printf("\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    if (opcao < 0 || opcao > lim) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novemente...]\033[0m\n");
    } 
  } while (opcao < 0 || opcao > lim);
  return --opcao;
}

void escolh_data(data *ed) {
  do {
    limpa_tela();
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    centralizar("\033[38;5;201m[ESCOLHER DATA]\033[0m");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("Opção\033[38;5;214m[DD/MM/AAAA]: ");
    scanf("%d/%d/%d", &ed->dia, &ed->mes, &ed->ano);
    __fpurge(stdin);
    printf("\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    if (!ver_data(ed->dia, ed->mes, ed->ano)) {
      printf("\n\033[38;5;196m[Data inválida! Tente novemente...]\033[0m\n");
    } 
  } while (!ver_data(ed->dia, ed->mes, ed->ano));  
}

int escolh_qtde(rpg eq, item it_loja) { // [FUNÇÃO DE ESCOLHER QUANTIDADE]
  int opcao;
  do {
    limpa_tela();
    opcao = -1;
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    centralizar("\033[38;5;201m[ESCOLHER QUANTIDADE]\033[0m");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("Opção\033[38;5;214m[QTD MAX: %d]: ", it_loja.qtd);
    scanf("%d", &opcao);
    __fpurge(stdin);
    printf("\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    if (opcao <= 0 || opcao > it_loja.qtd) {
      printf("\n\033[38;5;196m[Quantidade inválida! Tente novamente...]\033[0m\n");
    }
      else if (opcao * it_loja.valor > eq.ouro) {
        printf("\n\033[38;5;196m[Ouro insuficiente! Tente novamente...]\033[0m\n");
      }
  } while (opcao <= 0 || opcao > it_loja.qtd || opcao * it_loja.valor > eq.ouro);
  return opcao;
}

void escolh_id_vend(rpg eq, long long int *id, int cont) {
  do {
    limpa_tela();
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    centralizar("\033[38;5;201m[ESCOLHER ID]\033[0m");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("ID\033[38;5;214m: ");
    scanf("%lld", id);
    __fpurge(stdin);
    printf("\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    if (!ver_id_vend(eq, cont, *id)) {
      printf("\n\033[38;5;196m[ID inválido! Tente novamente...]\033[0m\n");
    }
  } while (!ver_id_vend(eq, cont, *id));
}

void excl_item(rpg *ei, int posi, int *cont) { // [FUNÇÃO DE EXCLUIR ITEM]
  ei->itm = (item *) realloc(ei->itm, sizeof(item) * (*cont + 1));
  for (int i = posi; i < *cont; i++) {
    ei->itm[i] = ei->itm[i + 1];
  }
  (*cont)--;
  ei->itm = (item *) realloc(ei->itm, (*cont) * sizeof(item));
}

void excl_item_loja(rpg *ei, int posi, int *cont) { // [FUNÇÃO DE EXCLUIR ITEM DA LOJA]
  ei->loja_itm = (item *) realloc(ei->loja_itm, sizeof(item) * (*cont + 1));
  for (int i = posi; i < *cont; i++) {
    ei->loja_itm[i] = ei->loja_itm[i + 1];
  }
  (*cont)--;
  ei->loja_itm = (item *) realloc(ei->loja_itm, (*cont) * sizeof(item));
}

void extr_pers(rpg *ep, int *cont_p, int cont_v) { // [FUNÇÃO DE EXTRAIR PERSONAGEM]
  int posi = escolh_pers(*ep, *cont_p), i;
  if (!ver_pers_vend(*ep, ep->pers[posi], cont_v)) {
    if (sim_nao()) {
      ep->pers = (person *) realloc(ep->pers, sizeof(person) * (*cont_p + 1));
      for (i = posi; i < *cont_p; i++) {
        ep->pers[i] = ep->pers[i + 1];
      } 
      (*cont_p)--;
      ep->rubi += 5;
      printf("\n[\033[38;5;46m+05\033[38;5;196m◊\033[0m]\n");
      printf("\n\033[38;5;220m[Personagem extraído com sucesso!]\033[0m\n");
      ep->pers = (person *) realloc(ep->pers, (*cont_p) * sizeof(person));
    }
      else {
        printf("\n\033[38;5;196m[Extração cancelada!]\033[0m\n");
      }
  }
    else {
      printf("\n\033[38;5;196m[Impossível realizar a extração!]\033[0m");
      printf("\n\033[38;5;196m[Personagem está cadastrado em uma venda!]\033[0m\n");
    }
}

void vend_item(rpg *vi, int *cont_i, int cont_v) { // [FUNÇÃO DE VENDER ITEM]
  int posi = escolh_item(*vi, *cont_i);
  if (ver_item_vend(*vi, vi->itm[posi], cont_v)) {
    if (sim_nao()) {
      vi->ouro += vi->itm[posi].valor;
      printf("\n\033[38;5;220m[\033[38;5;51m%s \033[38;5;220mvendido(a) com sucesso!]\033[0m\n", vi->itm[posi].nome);
      printf("\n[\033[38;5;46m+%d\033[38;5;220m¢\033[0m]\n", vi->itm[posi].valor);
      excl_item(vi, posi, cont_i);
    }
      else {
        printf("\n\033[38;5;196m[Venda cancelada!]\033[0m\n");
      }
  }
    else {
      printf("\n\033[38;5;196m[Impossível vender item!]\033[0m");
      printf("\n\033[38;5;196m[O item está cadastrado em uma venda!]\033[0m\n");
    }
} 

void compr_item(rpg *rpi, venda *ci, int *cont_i, int *cont_p, int *cont_v, int *cont_l) { // [FUNÇÃO DE LOJA DE ITENS]
  int aux, posi, qtde;
  aux = escolh_pers(*rpi, *cont_p);
  posi = escolh_item_loja(*rpi, *cont_l);
  if (rpi->loja_itm[posi].valor > rpi->ouro) {
    printf("\n\033[38;5;196m[Ouro insuficiente! Voltando ao menu...]\033[0m\n");
  }
    else {
      qtde = escolh_qtde(*rpi, rpi->loja_itm[posi]); 
      if (posi == -1) {
        printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
      }
        else if (rpi->loja_itm[posi].valor <= rpi->ouro) {
          if (sim_nao()) {
            escolh_data(&rpi->vend[*cont_v].dt_vend);    
            escolh_id_vend(*rpi, &ci->id, *cont_v);
            rpi->ouro -= rpi->loja_itm[posi].valor * qtde;            
            rpi->itm = (item *) realloc(rpi->itm, (*cont_i + 1) * sizeof(item));
            rpi->itm[*cont_i] = rpi->loja_itm[posi];
            rpi->itm[*cont_i].qtd = qtde;
            (*cont_i)++; 
            
            rpi->loja_itm[posi].qtd -= qtde;           
            ci->cl = rpi->pers[aux];
            ci->prodt = rpi->loja_itm[posi];
            ci->prodt.qtd = qtde;
            (*cont_v)++;
            printf("\n[\033[38;5;196m-%d\033[38;5;220m¢\033[0m]\n", rpi->loja_itm[posi].valor * qtde);
            printf("\n\033[38;5;220m[\033[38;5;208m+x%d \033[38;5;51m%s \033[38;5;220madquirido com sucesso!]\033[0m\n", qtde, rpi->loja_itm[posi].nome);
            if (rpi->loja_itm[posi].qtd == 0) {
              excl_item_loja(rpi, posi, cont_l);
            } 
          }
            else {
              printf("\n\033[38;5;196m[Compra cancelada!]\033[0m\n");
            }
        }
          else {
            printf("\n\033[38;5;196m[Você não tem ouro suficiente!]\033[0m\n");
          }
    }
}

int escolh_menu(rpg mp) { // [FUNÇÃO DE MENU PRINCIPAL]
  int opcao;
  do {
    limpa_tela();
    opcao = -1;
    list_recurs(mp);
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    centralizar("\033[38;5;201m[INICIO]\033[0m");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("|[\033[38;5;51m1\033[0m]> Invocar Personagem\n");
    printf("|[\033[38;5;51m2\033[0m]> Exibir Personagens\n");
    printf("|[\033[38;5;51m3\033[0m]> Extrair Personagem\n");
    printf("|[\033[38;5;51m4\033[0m]> Cadastrar Item\n");
    printf("|[\033[38;5;51m5\033[0m]> Mostrar Itens\n");
    printf("|[\033[38;5;51m6\033[0m]> Vender Item\n");
    printf("|[\033[38;5;51m7\033[0m]> Comprar Item\n");
    printf("|[\033[38;5;51m8\033[0m]> Histórico de Compras");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("|[\033[38;5;51m0\033[0m]> Sair");
    printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    printf("Opção\033[38;5;51m: ");
    scanf("%d", &opcao);
    __fpurge(stdin);
    printf("\033[0m\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
    if (opcao < 0 || opcao > 8) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (opcao < 0 || opcao > 8);
  return opcao;
}

void iniciar_rpg(rpg *rpg_aux, int *cont_p, int *cont_i, int *cont_v, int *cont_l) { // [FUNÇÃO DE INICIAR RPG]
  rpg_aux->classes = (char **) realloc(rpg_aux->classes, 7 * sizeof(char *));
  if (rpg_aux->classes) {
    rpg_aux->classes[0] = "Guerreiro";
    rpg_aux->classes[1] = "Cavaleiro";
    rpg_aux->classes[2] = "Arqueiro";
    rpg_aux->classes[3] = "Clérigo";
    rpg_aux->classes[4] = "Ladino";
    rpg_aux->classes[5] = "Mago";
    rpg_aux->classes[6] = NULL;
  }
    else {
      printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
    }
  rpg_aux->itens = (char **) realloc(rpg_aux->itens, 7 * sizeof(char *));
  if (rpg_aux->itens) {
    rpg_aux->itens[0] = "Equipamento";
    rpg_aux->itens[1] = "Talismã de Equipamento";
    rpg_aux->itens[2] = "Elixir da Vida";
    rpg_aux->itens[3] = "Elixir do Ataque";
    rpg_aux->itens[4] = "Elixir da Defesa";
    rpg_aux->itens[5] = "Elixir da Velocidade";
    rpg_aux->itens[6] = NULL;
  }
    else {
      printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
    }
  rpg_aux->itm = (item *) realloc(rpg_aux->itm, 6 * sizeof(item));
  if (rpg_aux->itm) {
    rpg_aux->itm[0] = (item) {"Excalibur", "Equipamento", 1000, 5, 100, 001};
    rpg_aux->itm[1] = (item) {"Rocha Antiga", "Pedra de Equipamento", 1000, 5, 100, 002};
    rpg_aux->itm[2] = (item) {"Poção Misteriosa", "Elixir do Ataque", 5, 11, 50, 003};
    rpg_aux->itm[3] = (item) {"Erva Mística", "Elixir da Vida", 5, 2, 50, 004};
    rpg_aux->itm[4] = (item) {"Remédio Potente", "Elixir da Defesa", 5, 3, 50, 005};
    rpg_aux->itm[5] = (item) {"Poção da Velocidade", "Elixir da Velocidade", 5, 2, 50, 006};
  }
    else {
      printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
    }
  rpg_aux->loja_itm = (item *) realloc(rpg_aux->loja_itm, 6 * sizeof(item));
  if (rpg_aux->loja_itm) {
    rpg_aux->loja_itm[0] = (item) {"Excalibur", "Equipamento", 1000, 5, 100, 001};
    rpg_aux->loja_itm[1] = (item) {"Lixa", "Pedra de Equipamento", 1000, 3, 100, 100};
    rpg_aux->loja_itm[2] = (item) {"Whey", "Elixir do Ataque", 5, 2, 50, 100};
    rpg_aux->loja_itm[3] = (item) {"Creatina", "Elixir da Vida", 5, 3, 50, 100};
    rpg_aux->loja_itm[4] = (item) {"Escudo", "Elixir da Defesa", 5, 7, 50, 100};
    rpg_aux->loja_itm[5] = (item) {"Magia da Velocidade", "Elixir da Velocidade", 5, 2, 50, 100};
  }
    else {
      printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
    }
  rpg_aux->pers[0] = (person) {"Ana", "Guerreiro", 10, 10, 10, 10, 5, 0, 001, "Rua Flores", "Cidade Jardim", "Montsdt", 12, 23, 04, 2001};
  *cont_p += 1;
  *cont_i += 6;
  *cont_l += 6;
  rpg_aux->ouro = 500;
  rpg_aux->rubi = 50;
}

int main() {
  srand(time(NULL));
  int ct_item = 0, ct_pers = 0, ct_vend = 0, ct_loja = 0, escolha, loop = 1;
  rpg *GwG = (rpg *) calloc(1, sizeof(rpg));
  GwG->pers = (person *) calloc(1, sizeof(person));
  GwG->itm = (item *) calloc(1, sizeof(item));
  GwG->vend = (venda *) calloc(1, sizeof(venda));
  GwG->loja_itm = (item *) calloc(1, sizeof(item));
  GwG->itens = (char **) calloc(1, sizeof(char *));
  GwG->classes = (char **) calloc(1, sizeof(char *));
  if (!GwG || !GwG->pers || !GwG->itm || !GwG->vend || !GwG->itens || !GwG->loja_itm || !GwG->classes) {
    printf("\n\033[38;5;196m[Erro ao alocar memória!]\033[0m\n");
  } 
    else {
      iniciar_rpg(GwG, &ct_pers, &ct_item, &ct_vend, &ct_loja);
      printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
      centralizar("\033[38;5;201m[*Bem-vindo ao G ⚜ G!*]\033[0m");
      printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
      while (loop) { // [LOOP PRINCIPAL]
        escolha = escolh_menu(*GwG);
        if (escolha == 0) { // [SAIR]
          if (sim_nao()) {
            limpa_tela();
            printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
            centralizar("\033[38;5;201m[*Obrigado por jogar!*]\033[0m");
            printf("\n\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m\n");
            limpa_tela();
            loop = 0;
          }
            else {
              printf("\n\033[38;5;220m[Voltando...]\033[0m\n");
            }
        }
          else if (escolha == 1) { // [INVOCAR PERSONAGEM]
            if (GwG->rubi >= 10) {
              if (sim_nao()) {
                GwG->pers = (person *) realloc(GwG->pers, sizeof(person) * (ct_pers + 1));  
                invoc_pers(GwG, &GwG->pers[ct_pers], &ct_pers);
              }
                else {
                  printf("\n\033[38;5;196m[Invocação cancelada!]\033[0m\n");
                }
            }
              else {
                printf("\n\033[38;5;196m[Você não tem rubis suficientes!]\033[0m\n");
              }
          }
            else if (escolha == 2) { // [EXIBIR PERSONAGENS]
              if (ct_pers > 0) {
                limpa_tela();
                list_pers(*GwG, ct_pers);
              }
                else {
                  printf("\n\033[38;5;196m[Não há personagens cadastrados!]\033[0m\n");
                }
            }
              else if (escolha == 3) { // [EXTRAIR PERSONAGENS]
                if (ct_pers > 0) {
                  extr_pers(GwG, &ct_pers, ct_vend);
                }
                  else {
                    printf("\n\033[38;5;196m[Não há personagens cadastrados!]\033[0m\n");
                  }
              }          
                else if (escolha == 4) { // [CADASTRAR ITEM]
                  if (GwG->ouro >= 100) {
                    if (sim_nao()) {
                      GwG->itm = (item *) realloc(GwG->itm, (ct_item + 1) * sizeof(item));
                      cadastr_item(GwG, &GwG->itm[ct_item], &ct_item);    
                    }
                      else {
                        printf("\n\033[38;5;196m[Cadastro cancelado!]\033[0m\n");
                      }
                  }
                    else {
                      printf("\n\033[38;5;196m[Você não tem ouro suficiente!]\033[0m\n");
                    }
                }
                  else if (escolha == 5) { // [MOSTRAR ITENS]
                    if (ct_item > 0) {
                      limpa_tela();
                      list_item(*GwG, ct_item);
                    }
                      else {
                        printf("\n\033[38;5;196m[Não há itens cadastrados!]\033[0m\n");
                      }
                  }
                    else if (escolha == 6) { // [VENDER ITEM]
                      if (ct_item > 0) {
                        vend_item(GwG, &ct_item, ct_vend);
                      }
                        else {
                          printf("\n\033[38;5;196m[Não há itens cadastrados!]\033[0m\n");
                        }
                    }
                      else if (escolha == 7) { // [LOJA DE ITENS]
                        if (ct_pers > 0) {
                          GwG->vend = (venda *) realloc(GwG->vend, (ct_vend + 1) * sizeof(venda));
                          compr_item(GwG, &GwG->vend[ct_vend], &ct_item, &ct_pers, &ct_vend, &ct_loja);    
                        }
                          else {
                            printf("\n\033[38;5;196m[Não há personagens cadastrados!]\033[0m\n");
                          }
                      }      
                        else if (escolha == 8) { // [HISTÓRICO DE COMPRAS]
                          if (ct_vend > 0) {
                            limpa_tela();
                            list_vend(*GwG, ct_vend);
                          }
                            else {
                              printf("\n\033[38;5;196m[Não há compras realizadas!]\033[0m\n");
                            }
                        }
      }
    }
  free(GwG->pers);
  free(GwG->itm);
  free(GwG->vend);
  free(GwG->itens);
  free(GwG->loja_itm);
  free(GwG->classes);
  free(GwG);
  return 0;
}
