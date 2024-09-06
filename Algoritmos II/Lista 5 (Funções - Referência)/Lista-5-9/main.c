/* 9 - Faça um programa que simule o sistema de um mercado. Determine um
conjunto de produtos que terá no seu mercado e estabeleça dois vetores, um de
preço e um de quantidade no estoque, que contenham as informações dos produtos.
Crie uma variável que represente o dinheiro no caixa com um valor inicial que
desejar. Leia um inteiro na função principal que corresponde à ação que se
deseja fazer (1 - adicionar ao estoque, em caso de compra de um fornecedor, e 2
- retirar do estoque, em caso de venda a um cliente). Faça uma função que
implemente cada um desses casos. Ambas as funções devem receber os vetores de
preço e quantidade, assim como o dinheiro no caixa, através de passagem por
referência. Elas também devem imprimir um menu com os produtos, cada produto
representado por um número. Depois que for lido o inteiro do produto escolhido,
será lido a quantidade comprada ou vendida. Caso seja a função da opção 1, esse
valor será adicionado à quantidade no estoque e o dinheiro em caixa será
decrementado de acordo com o preço do produto e a quantidade comprada. Caso seja
a opção 2, a quantidade no estoque será diminuída, mas o dinheiro no caixa será
incrementado. Exemplo de menu: Escolha o produto desejado: (1) - Arroz (2) -
Feijão (3) - Biscoito (4) - Molho de tomate */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void limpa_tela() { // [FUNÇÃO DE LIMPAR TELA]
  printf("\033[0m\nAperte [\033[38;5;39mENTER\033[0m] para continuar...");
  limpa_buffer();
  #ifdef _WIN32 // Verifica se o sistema é Windows
    system("cls");
  #else // Caso contrário, assume que é um sistema Unix
    system("clear");
  #endif 
}

int escolhe_prdt(float cx, char pdt_aux[][20]) { // [FUNÇÃO DE ESCOLHA DE PRODUTO]
  int i, op, produto, qtd_ad;
  do { // [LAÇO DE REPETIÇÃO P/ ESCOLHA DE PRODUTO]
    limpa_tela();
    op = -1;
    printf("\n===========[ \033[38;5;46mMERCADO SUPER SEU\033[0m ]===========\n");
    printf("Caixa: \033[38;5;46mR$%.2f\033[0m", cx);
    printf("\n-------------------------------------------\n");
    printf("Escolha o produto desejado:");
    for (i = 0; i < 5; i++) { // [LAÇO DE REPETIÇÃO P/ IMPRESSÃO DOS PRODUTOS]
      printf("\n[\033[38;5;51m%d\033[0m]> %s", i + 1, pdt_aux[i]);
    }
    printf("\n===========================================\n");
    printf("[\033[38;5;51m0\033[0m]> Voltar");
    printf("\n===========================================\n");
    printf("Opção:\033[38;5;51m ");
    scanf("%d", &op);
    limpa_buffer();
    printf("\033[0m===========================================\n");
    if (op < 0 || op > 5) { // [VALIDAÇÃO DA ESCOLHA]
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (op < 0 || op > 5);
  return op;
}

void adiciona_estoque(float *dinheiro, float prc_prdt, int estq, char prdt_esc[]) { // [FUNÇÃO DE ADICIONAR ESTOQUE]
  int qtd_adc;
  char s_n;
  do { // [LAÇO DE REPETIÇÃO PARA VALIDAÇÃO DA QUANTIDADE A SER ADCIONADA]
    limpa_tela();
    qtd_adc = -1;
    printf("\n==============[ \033[38;5;201m%s\033[0m ]==============", prdt_esc);
    printf("\nCaixa: \033[38;5;46mR$%.2f\033[0m", *dinheiro);
    printf("\n--------------------------------------");
    printf("\nQtd-estq: %d", estq);
    printf("\nPreço-prodt: R$%.2f", prc_prdt);
    printf("\n--------------------------------------\n");
    printf("Escolha a qtd p/ adcionar [\033[38;5;196mCOMPRA\033[0m]:\n\033[38;5;39m");
    scanf("%d", &qtd_adc);
    limpa_buffer();
    printf("\033[0m======================================\n");
    if (qtd_adc < 0) { // [VALIDAÇÃO DA QUANTIDADE]
      printf("\n\033[38;5;196m[Quantidade inválida! Tente novamente...]\033[0m\n");
    } else if (prc_prdt * qtd_adc > *dinheiro) { // [VALIDAÇÃO DO DINHEIRO]
      printf("\n\033[38;5;196m[Dinheiro insuficiente! Tente novamente...]\033[0m\n");
    }
  } while (qtd_adc < 0 || prc_prdt * qtd_adc > *dinheiro);
  do { // [LAÇO DE REPETIÇÃO PARA CONFIRMAÇÃO]
    limpa_tela();
    printf("\n==============[ \033[38;5;201m%s\033[0m ]==============", prdt_esc);
    printf("\nCaixa: \033[38;5;46mR$%.2f\033[0m", *dinheiro);
    printf("\n--------------------------------------");
    printf("\n[Estoque pre-compra: \033[38;5;39m%d\033[0m]", estq);
    printf("\n[Estoque pós-compra: \033[38;5;46m+%d\033[0m]", qtd_adc);
    printf("\n[Custo da compra: \033[38;5;196m-R$%.2f\033[0m]", prc_prdt * qtd_adc);
    printf("\n======================================\n");
    printf("Deseja continuar? [\033[38;5;39mS\033[0m/\033[38;5;39mN\033[0m]:\033[38;5;39m ");
    scanf("%c", &s_n);
    limpa_buffer();
    printf("\033[0m======================================\n");
    if (s_n == 'S' || s_n == 's') { // [VALIDAÇÃO DA CONFIRMAÇÃO]
      estq += qtd_adc;
      *dinheiro -= (prc_prdt * qtd_adc);
      printf("\n\033[38;5;39m[Compra realizada com sucesso!]\033[0m\n");
    } else if (s_n == 'N' || s_n == 'n') { // [...]
      printf("\n\033[38;5;196m[Compra cancelada!]\033[0m\n");
    } else { // [...]
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (s_n != 'S' && s_n != 's' && s_n != 'N' && s_n != 'n');
}

void retira_estoque(float *dinheiro, float prc_prdt, int estq, char prdt_esc[]) { // [FUNÇÃO DE RETIRAR ESTOQUE]
  int qtd_ret;
  char s_n;
  do { // [LAÇO DE REPETIÇÃO PARA VALIDAÇÃO DA QUANTIDADE A SER RETIRADA]
    limpa_tela();
    qtd_ret = -1;
    printf("\n==============[ \033[38;5;201m%s\033[0m ]==============", prdt_esc);
    printf("\nCaixa: \033[38;5;46mR$%.2f\033[0m", *dinheiro);
    printf("\n-------------------------------------");
    printf("\nQtd-estq: %d", estq);
    printf("\nPreço-prodt: R$%.2f", prc_prdt);
    printf("\n-------------------------------------\n");
    printf("Escolha a qtd p/ retirar [\033[38;5;220mVENDER\033[0m]:\n\033[38;5;39m");
    scanf("%d", &qtd_ret);
    limpa_buffer();
    printf("\033[0m======================================\n");
    if (qtd_ret < 0) { // [VALIDAÇÃO DA QUANTIDADE]
      printf("\n\033[38;5;196m[Quantidade inválida! Tente novamente...]\033[0m\n");
    } else if (estq < qtd_ret) { // [VALIDAÇÃO DO ESTOQUE]
      printf("\n\033[38;5;196m[Estoque insuficiente! Tente novamente...]\033[0m\n");
    }
  } while (qtd_ret < 0 || estq < qtd_ret);
  do { // [LAÇO DE REPETIÇÃO PARA CONFIRMAÇÃO]
    limpa_tela();
    printf("\n==============[ \033[38;5;201m%s\033[0m ]==============", prdt_esc);
    printf("\nCaixa: \033[38;5;46mR$%.2f\033[0m", *dinheiro);
    printf("\n--------------------------------------");
    printf("\n[Estoque pre-venda: \033[38;5;39m%d\033[0m]", estq);
    printf("\n[Estoque pós-venda: \033[38;5;196m-%d\033[0m]", qtd_ret);
    printf("\n[Valor da venda: \033[38;5;46m+R$%.2f\033[0m]", prc_prdt * qtd_ret);
    printf("\n======================================\n");
    printf("Deseja continuar? [\033[38;5;39mS\033[0m/\033[38;5;39mN\033[0m]:\033[38;5;39m ");
    scanf("%c", &s_n);
    limpa_buffer();
    printf("\033[0m======================================\n");
    if (s_n == 'S' || s_n == 's') { // [VALIDAÇÃO DA CONFIRMAÇÃO]
      estq -= qtd_ret;
      *dinheiro += (prc_prdt * qtd_ret);
      printf("\n\033[38;5;39m[Venda realizada com sucesso!]\033[0m\n");
    } else if (s_n == 'N' || s_n == 'n') { // [...]
      printf("\n\033[38;5;196m[Venda cancelada!]\033[0m\n");
    } else { // [...]
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (s_n != 'S' && s_n != 's' && s_n != 'N' && s_n != 'n');
}

int main(void) {
  srand(time(NULL));
  int loop_m = 1, i, opcao, aux, quantidade, prodt, estoque[5];
  char s_n, prod_aux[10][20] = {"Arroz", "Feijão", "Biscoito", "Molho de tomate", "Maçã"};
  float preco_prod[5], caixa = rand() % 1000 + 500;
  for (i = 0; i < 5; i++) { // [LAÇO DE REPETIÇÃO PARA GERAR PREÇOS ALEATÓRIOS]
    preco_prod[i] = rand() % 5 + 3;
    estoque[i] = rand() % 10 + 10;
  }
  printf("<{BEM-VINDO(A) AO GERENCIADOR\n DE [\033[38;5;196mCOMPRAR\033[0m] E [\033[38;5;220mVENDA\033[0m]\n DO [\033[38;5;46mMERCADO SUPER SEU\033[0m]!}>\n");
  do { // [LOOP DE MENU]
    do { // [LOOP DE ESCOLHA DE OPÇÃO]
      limpa_tela();
      opcao = -1;
      printf("\n===========[ \033[38;5;46mMERCADO SUPER SEU\033[0m ]===========\n");
      printf("Caixa: \033[38;5;46mR$%.2f\033[0m", caixa);
      printf("\n-------------------------------------------\n");
      printf("Escolha a operação desejada:");
      printf("\n[\033[38;5;51m1\033[0m]> Adcionar ao estoque [\033[38;5;196mCOMPRAR\033[0m]");
      printf("\n[\033[38;5;51m2\033[0m]> Retirar do estoque [\033[38;5;220mVENDER\033[0m]");
      printf("\n===========================================\n");
      printf("[\033[38;5;51m0\033[0m]> Sair");
      printf("\n===========================================\n");
      printf("Opção:\033[38;5;51m ");
      scanf("%d", &opcao);
      limpa_buffer();
      printf("\033[0===========================================\n");
      if (opcao < 0 || opcao > 2) { // [VALIDAÇÃO DA ESCOLHA]
        printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
      }
    } while (opcao < 0 || opcao > 2);
    if (opcao == 0) { // [OPÇÃO DE SAIR]
      do { // [LOOP DE SAÍDA]
        limpa_tela();
        aux = -1;
        printf("\n================[ \033[38;5;196mSAIR\033[0m ]================\n");
        printf("Você deseja sair do programa?");
        printf("\n========================================");
        printf("\n[\033[38;5;51m1\033[0m]> Sim");
        printf("\n[\033[38;5;51m2\033[0m]> Não");
        printf("\n========================================\n");
        printf("Opção:\033[38;5;51m ");
        scanf("%d", &aux);
        limpa_buffer();
        printf("\033[0m========================================\n");
        if (aux == 1) { // [OPÇÃO DE SAÍDA]
          printf("\n\033[38;5;196m[Programa encerrado!]\033[0m\n");
          loop_m = 0;
          continue;
        } else if (aux == 2) { // [OPÇÃO DE RETORNO]
          printf("\n\033[38;5;196m[Retornando ao menu...]\033[0m\n");
        } else { // [OPÇÃO INVÁLIDA]
          printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
        }
      } while (aux != 1 && aux != 2);
    } else { // [OPÇÃO DE ADICIONAR ESTOQUE OU RETIRAR ESTOQUE]
      aux = escolhe_prdt(caixa, prod_aux);
      if (aux == 0) { // [OPÇÃO DE VOLTAR]
        printf("\n\033[38;5;220m[Voltando ao menu...]\033[0m\n");
      } else if (opcao == 1) { // [OPÇÃO DE ADICIONAR ESTOQUE]
        adiciona_estoque(&caixa, preco_prod[aux - 1], estoque[aux - 1], prod_aux[aux - 1]);
      } else if (opcao == 2) { // [OPÇÃO DE RETIRAR ESTOQUE]
        retira_estoque(&caixa, preco_prod[aux - 1], estoque[aux - 1], prod_aux[aux - 1]);
      }
    }
  } while (loop_m);
  return 0;
}