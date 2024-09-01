#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Limpa o buffer do terminal */
void limpa_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

/* Limpa a tela do terminal */
void limpa_tela() {
  printf("\033[0m\nAperte \033[38;5;39m[ENTER]\033[0m p/ continuar...");
  limpa_buffer();
  if (system("clear") && system("cls")) { // Tenta limpar a tela do terminal
    perror("\n\033[38;5;196m[Erro ao limpar a tela!]\033[0m\n");
    exit(EXIT_FAILURE);
  }
}

/* Exibe uma barra de divisão c/ cores */
void barra_div(char *ini, char *fin) {
  printf("%s\033[38;5;51m<>\033[0m==============\033[38;5;201m<>\033[0m==============\033[38;5;51m<>\033[0m%s", ini, fin);
}

/* Solicita e retorna um número inteiro do usuário */
int get_num() { 
  int val;
  printf("Digite um número inteiro: ");
  scanf("%d", &val);
  limpa_buffer();
  return val;
}

/* Solicita e retorna a escolha do vetor (PAR ou IMPAR) */
int get_vet() {
  int val;
  barra_div("", "\n");
  printf("\033[38;5;201m[Escolha o vetor]\033[0m\n");
  barra_div("", "\n");
  printf("\033[38;5;201m[1]\033[0m Par\n");
  printf("\033[38;5;201m[2]\033[0m Impar\n");
  barra_div("", "\n");
  printf("⌨ : ");
  scanf("%d", &val);
  limpa_buffer();
  limpa_tela();
  return val;
}

/* Solicita e retorna o nome do arquivo do usuário */
char *get_nome_arqv() { 
  char *str = NULL;
  size_t tam, comp;
  printf("Digite o nome p/ arquivo [S/ Extensão]:\n");
  comp = getline(&str, &tam, stdin);
  if (comp == -1) { // Verifica se houve um erro ao ler o nome do arquivo
    perror("\n\033[38;5;196m[Erro ao ler o nome do arquivo!]\033[0m\n");
    exit(EXIT_FAILURE);
  }
  if (str[comp - 1] == '\n') { // Remove o caractere de nova linha se houver
    str[comp - 1] = '\0';
  }
  return str;
}

/* Insere um elemento no vetor PAR ou IMPAR */ 
int insere_elemento(int val, int par[], int *parCont, int impar[], int *imparCont, int tam) {
  if (val % 2 == 0) { // Verifica se o valor é par
    if (*parCont < tam) { // Verifica se o vetor PAR não está cheio
      par[*parCont] = val;
      (*parCont)++; // Incrementa o contador do vetor PAR
      return 0; // Inserção bem-sucedida no vetor PAR
    } else { // ...
      printf("\n\033[38;5;196m[O vetor [PAR] está cheio!]\033[0m\n");
    }
  } else { // Se o valor é impar
    if (*imparCont < tam) { // Verifica se o vetor IMPAR não está cheio
      impar[*imparCont] = val; 
      (*imparCont)++; // Incrementa o contador do vetor IMPAR
      return 1; // Inserção bem-sucedida no vetor IMPAR
    } else { // ...
      printf("\n\033[38;5;196m[O vetor [IMPAR] está cheio!]\033[0m\n");
    }
  }
  return -1; // Inserção mal-sucedida
}

/* Remove um elemento do vetor */
void remove_elemento(int val, int vetor[], int *cont) { 
  int i, aux = -1;
  for (i = 0; i < *cont; i++) { // Percorre o vetor
    if (vetor[i] == val) { // Verifica se o valor está presente no vetor
      aux = i; // Armazena a posição do valor
      i = *cont; // Sai do loop
    }
  }
  if (aux != -1) { // Verifica se o valor foi encontrado
    for (i = aux; i < *cont - 1; i++) { // Desloca os elementos p/ preencher o espaço vazio
      vetor[i] = vetor[i + 1];
    }
    (*cont)--; // Atualiza o contador
  } else {
    printf("\n\033[38;5;196m[Elemento não encontrado!]\033[0m\n");
  }
}

/* Consulta e retorna o elemento na posição especificada do vetor */ 
int consulta_elemento(int posicao, int vetor[], int cont) {
  if (posicao < 0 || posicao >= cont) { // Verifica se a posição é válida
    printf("\n\033[38;5;196m[Posição Inválida!]\033[0m\n");
    return -1; // Código de erro
  }
  return vetor[posicao]; // Retorna o elemento na posição especificada
}

/* Exibe todos os elementos do vetor */
void exibe_elementos(int vetor[], int cont) {
  if (cont == 0) { // Verifica se o vetor está vazio
    printf("\n\033[38;5;196m[O vetor está vazio!]\033[0m\n");
    return;
  }
  barra_div("\n", "\n");
  printf("\033[38;5;51m");
  printf(vetor[0] % 2 == 0 ? "[PARES]" : "[IMPARES]");
  printf("\033[0m: ");
  for (int i = 0; i < cont; i++) { // Percorre e mostra o vetor
    printf(i == 0 ? "%d" : ", %d", vetor[i]);
  }
  barra_div("\n", "\n");
}

/* Grava os elementos do vetor em um arquivo */
void grave_elemento(char *nome_arqv, int vetor[], int cont) {
  FILE *file = fopen(nome_arqv, "w"); // Abre o arquivo p/ escrita
  if (file == NULL) { // Verifica se o arquivo foi aberto c/ sucesso
    printf("\n\033[38;5;196m[Erro ao abrir arquivo!]\033[0m\n");
    return;
  }
  for (int i = 0; i < cont; i++) { // Percorre o vetor e grava os elementos no arquivo
    fprintf(file, "%d ", vetor[i]);
  }
  fclose(file); // Fecha o arquivo
  printf("\n\033[38;5;39m[Elementos gravados em [%s] c/ sucesso!]\033[0m\n", nome_arqv);
}

/* Exibe o menu e retorna a opção escolhida */
int escolha_menu() {
  int opcao;
  limpa_tela();
  barra_div("", "\n");
  printf("\033[38;5;51m[Menu]\033[0m\n");
  barra_div("", "\n");
  printf("\033[38;5;51m[1]\033[0m Inserir Elemento\n");
  printf("\033[38;5;51m[2]\033[0m Remover Elemento\n");
  printf("\033[38;5;51m[3]\033[0m Consultar Posição\n");
  printf("\033[38;5;51m[4]\033[0m Exibir Elementos\n");
  printf("\033[38;5;51m[5]\033[0m Gravar Elementos\n");
  barra_div("", "\n");
  printf("\033[38;5;51m[0]\033[0m Sair\n");
  barra_div("", "\n");
  printf("⌨ : ");
  scanf("%d", &opcao);
  limpa_buffer();
  limpa_tela();
  return opcao;
}

int main() {
  int tam = 100, par[tam], impar[tam], parCont = 0, imparCont = 0, opcao, posi, temp;
  bool loop = true;
  while (loop) { // Loop principal
    if ((opcao = escolha_menu()) == 0) { // Sair
      printf("\n\033[38;5;220m[Saindo do programa...]\033[0m\n");
      loop = false;
      continue;
    } else if (opcao == 1) { // Inserir Elemento
      /* Verifica se o elemento foi inserido no vetor 0 [PAR] ou 1 [IMPAR] */
      if (insere_elemento(get_num(), par, &parCont, impar, &imparCont, tam) == 0) { // Exibe o vetor PAR
        exibe_elementos(par, parCont);
      } else { // Exibe o vetor IMPAR
        exibe_elementos(impar, imparCont);
      }
    } else if (opcao == 2) { // Remover Elemento
      if ((opcao = get_vet()) == 1) { // Verifica se é o vetor PAR
        remove_elemento(get_num(), par, &parCont);
      } else if (opcao == 2) { // Verifica se é o vetor IMPAR
        remove_elemento(get_num(), impar, &imparCont);
      } else { // Opção inválida
        printf("\n\033[38;5;196m[Opção Inválida!]\033[0m\n");
      }
    } else if (opcao == 3) { // Consultar Posição
      if ((opcao = get_vet()) == 1) { // Verifica se é o vetor PAR
        if (parCont > 0) { // Verifica se o vetor PAR não está vazio
          if ((temp = consulta_elemento((posi = get_num()), par, parCont)) != -1) // Consulta e retorna o elemento
            printf("\n\033[38;5;39m[Elemento na posição[%d]: %d]\033[0m\n", posi, temp);
        } else { // ...
          printf("\n\033[38;5;196m[O vetor [PAR] está vazio!]\033[0m\n");
        }
      } else if (opcao == 2) { // Verifica se é o vetor IMPAR
        if (imparCont > 0) { // Verifica se o vetor IMPAR não está vazio
          if ((temp = consulta_elemento((posi = get_num()), impar, imparCont)) != -1) // Consulta e retorna o elemento
            printf("\n\033[38;5;39m[Elemento na posição[%d]: %d]\033[0m\n", posi, temp);
        } else { // ...
          printf("\n\033[38;5;196m[O vetor [IMPAR] está vazio!]\033[0m\n");
        }
      } else { // Opção inválida
        printf("\n\033[38;5;196m[Opção Inválida!]\033[0m\n");
      }
    } else if (opcao == 4) { // Exibir Elementos
      if ((opcao = get_vet()) == 1) { // Verifica se é o vetor PAR
        exibe_elementos(par, parCont);
      } else if (opcao == 2) { // Verifica se é o vetor IMPAR
        exibe_elementos(impar, imparCont);
      } else { // Opção inválida
        printf("\n\033[38;5;196m[Opção Inválida!]\033[0m\n");
      }
    } else if (opcao == 5) { // Gravar Elementos
      if ((opcao = get_vet()) == 1) { // Verifica se é o vetor PAR
        grave_elemento(strcat(get_nome_arqv(), ".txt"), par, parCont);
      } else if (opcao == 2) { // Verifica se é o vetor IMPAR
        grave_elemento(strcat(get_nome_arqv(), ".txt"), impar, imparCont);
      } else { // Opção inválida
        printf("\n\033[38;5;196m[Opção Inválida!]\033[0m\n");
      }
    } else { // Opção Inválida
      printf("\n\033[38;5;196m[Opção Inválida!]\033[0m\n");
    }
  } 
  printf("\n\033[38;5;39m[Obrigado por usar o programa!]\033[0m\n");
  return 0;
}