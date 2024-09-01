/*O trabalho consiste na elaboração de um programa para manipulação de matrizes que deverá conter: 
 A declaração de duas matrizes de 9 posições de inteiros; 

Um menu com as seguintes opções: 
 Inserir dados nas matrizes, escolher qual matriz será inserido; 
 Remover dados de uma matriz em determinada posição escolhida pelo usuário; 
 Alterar um dado de uma posição determinada pelo usuário; 
 Mostrar todas as posições preenchidas nas matrizes; 
 Soma das duas matrizes;
 Calcular o determinante de cada uma; 
 Mostrar os valores diferentes das duas matrizes; 
 Mostrar os valores iguais das duas matrizes;
 Sair do programa. 

Informações: 
 As matrizes deverão ser preenchidas sequencialmente, para isso use um contador para saber quantas posições foram utilizadas para cada uma; 
 Quando o usuário escolher a opção remover determinado valor, este valor deverá ser apagado fisicamente, fazendo os dados que estão nas posições posteriores voltarem uma posição; 
 Enquanto o usuário não escolher sair do programa, este deverá estar em funcionamento com o menu com as opções sempre pronto para a escolha do usuário;
 Se o dado, a ser removido ou alterado não existir na matriz escolhida, o programa deverá enviar uma mensagem de dado não existente para o usuário; 
 Se toda a matriz escolhida for preenchida, o programa deverá enviar uma mensagem para o usuário informando que não poderá inserir mais, por estar com todas as posições ocupadas.*/

// Bibliotecas:
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>

int main(void) { // Função principal
  srand(time(NULL)); // Função de gerar números aleatórios
  // Declaração de variáveis:
  int l = 3, c = 3, x, y, i, j, k, op, aux, loop_m = 1, ct_m1 = 0, ct_m2 = 0, comp, ord;
  int mat_1[l][c], mat_2[l][c], mat_aux[l][c*2], mat_soma[l][c], temp, soma;
  int diag_p, diag_s, diag_p_aux, diag_s_aux, dtmn;
  char sim_nao;

  for (i = 0; i < l; i++) { // Inicialização das matrizes 1 e 2
    for (j = 0; j < c; j++) {
      mat_1[i][j] = 0;
      mat_2[i][j] = 0;
    }
  }
  for (i = 0; i < l; i++) { // Inicialização da matriz auxiliar
    for (j = 0; j < c*2; j++) {
      mat_aux[i][j] = 0;
    }
  }

  printf("\n[\033[0;31m*\033[0;34mBEM-VINDO AO PROGRAMA DE \033[0;31m[MANIPULAÇÃO] \033[0;34mDE \033[0;31m[MATRIZES]\033[0;34m!\033[0;31m*\033[0m]\n");
  do { // |LOOP PRINCIPAL|
    do { // |MENU DE OPÇÕES|
      printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
      getchar();
      __fpurge(stdin);
      system("clear");
      op = -1;
      printf("=========================================\n");
      printf("\033[0;32m[MENU DE MANIPULAÇÃO DE MATRIZES]\033[0m");
      printf("\n=========================================");
      printf("\n[\033[0;36m1\033[0m]> Preencher matriz");
      printf("\n[\033[0;36m2\033[0m]> Mostrar matriz");
      printf("\n[\033[0;36m3\033[0m]> Remover dados de matriz");
      printf("\n[\033[0;36m4\033[0m]> Alterar dados de matriz");
      printf("\n[\033[0;36m5\033[0m]> Reordenar matriz");
      printf("\n[\033[0;36m6\033[0m]> Intercalar matrizes");
      printf("\n[\033[0;36m7\033[0m]> Somar matrizes");
      printf("\n[\033[0;36m8\033[0m]> Determinante de matriz");
      printf("\n[\033[0;36m9\033[0m]> Diferenças entre matrizes");
      printf("\n[\033[0;36m10\033[0m]> Igualdades entre matrizes");
      printf("\n=========================================\n");
      printf("[\033[0;31m0\033[0m]> Sair");
      printf("\n=========================================\n");
      printf("Digite a opção desejada: ");
      scanf("%d", &op);
      __fpurge(stdin);
      if (op < 0 || op > 10)
        printf("\n\033[0;31m[Opção inválida! Tente novamente...]\033[0m\n");
    } while (op < 0 || op > 10);

    if (op == 0) { // |SAIR|
      do { // Loop de confirmação de saída
        printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
        getchar();
        __fpurge(stdin);
        system("clear");
        printf("=========================================\n");
        printf("Tem certeza que deseja \033[0;31m[sair]\033[0m? ");
        printf("\n=========================================\n");
        printf("[\033[0;34mS\033[0m/\033[0;31mN\033[0m]: ");
        scanf("%c", &sim_nao);
        __fpurge(stdin);
        if (sim_nao == 'S' || sim_nao == 's') { // Confirma a saída
          printf("\n[\033[0;31m*\033[0;34mObrigado por usar o programa!\033[0;31m*\033[0m]\n");
          printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
          getchar();
          __fpurge(stdin);
          system("clear");
          loop_m = 0;
        }
          else if (sim_nao == 'N' || sim_nao == 'n') { // Volta ao menu
            printf("\n\033[0;33m[Retornando ao menu...]\033[0m\n");
          }
            else // Opção inválida
              printf("\n\033[0;31m[Opção inválida! Tente novamente...]\033[0m\n"); 
      } while (sim_nao != 'S' && sim_nao != 's' && sim_nao != 'N' && sim_nao != 'n');
    }

      else if (op == 1) { // |PREENCHER MATRIZ|
        do { // Loop para escolher a matriz
          printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
          getchar();
          __fpurge(stdin);
          system("clear");
          aux = -1;
          printf("\n=========================================\n");
          printf("\033[0;34m[PREENCHER MATRIZ]\033[0m");
          printf("\n=========================================");
          printf("\n[\033[0;35m1\033[0m]> Matriz 1");
          printf("\n[\033[0;35m2\033[0m]> Matriz 2");
          printf("\n=========================================\n");
          printf("[\033[0;32m0\033[0m]> Voltar");
          printf("\n=========================================\n");
          printf("Digite a opção desejada: ");
          scanf("%d", &aux);
          __fpurge(stdin);
          if (aux < 0 || aux > 2)
            printf("\n\033[0;31m[Opção inválida! Tente novamente...]\033[0m\n");
        } while (aux < 0 || aux > 2);
        if (aux == 0) { // Voltar
          printf("\n\033[0;33m[Voltando ao menu...]\033[0m\n");
        }
          else if (aux == 1 && ct_m1 < l*c) { // Preencher matriz 1
            do { // Loop de escolha do modo de preenchimento: aleatório ou manual
              printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
              getchar();
              __fpurge(stdin);
              system("clear");
              printf("\n=========================================\n");
              printf("\033[0;35m[Matriz 1]\033[0m");
              printf("\n=========================================\n");
              printf("Deseja aleatorizar os valores? \n[\033[0;34mS\033[0m/\033[0;31mN\033[0m]: ");
              scanf("%c", &sim_nao);
              __fpurge(stdin);
              printf("=========================================");
              if (sim_nao != 'S' && sim_nao != 's' && sim_nao != 'N' && sim_nao != 'n')
                printf("\n\033[0;31m[Opção inválida! Tente novamente...]\033[0m\n");
            } while (sim_nao != 'S' && sim_nao != 's' && sim_nao != 'N' && sim_nao != 'n');
            for (i = 0; i < l; i++) { // Preenche matriz 1
              for (j = 0; j < c; j++) {
                if (mat_1[i][j] == 0) { // Verifica se a posição está vazia
                  if (sim_nao == 'S' || sim_nao == 's') { // Aleatório
                    do { // Sorteia números entre -10 e 10, exceto 0 
                      mat_1[i][j] = rand() % 21 - 10;
                    } while (mat_1[i][j] == 0);
                    printf("\nPosição [\033[0;34m%d\033[0m][\033[0;31m%d\033[0m]: %d", i, j, mat_1[i][j]);
                  }
                    else { // Manual
                      printf("\n\033[0;33m[*0 = POSIÇÃO VAZIA]\033[0m");
                      printf("\nDigite o valor da posição [\033[0;34m%d\033[0m][\033[0;31m%d\033[0m]: ", i, j);
                      scanf("%d", &mat_1[i][j]);
                      __fpurge(stdin);
                    }
                  if (mat_1[i][j] != 0) { // Verifica se a posição foi preenchida
                    ct_m1++; // Incrementa o contador de posições da matriz 1
                  }
                }
              }
            }
            printf("\n=========================================\n");
            printf("\033[0;33m[Matriz[1] preenchida com sucesso!]\033[0m");
            printf("\n=========================================\n");
          }
            else if (aux == 2 && ct_m2 < l*c) { // Preencher matriz 2
              do { // Loop de escolha do modo de preenchimento: aleatório ou manual
                printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
                getchar();
                __fpurge(stdin);
                system("clear");
                printf("\n=========================================\n");
                printf("\033[0;35m[Matriz 2]\033[0m");
                printf("\n=========================================\n");
                printf("Deseja aleatorizar os valores? \n[\033[0;34mS\033[0m/\033[0;31mN\033[0m]: ");
                scanf("%c", &sim_nao);
                __fpurge(stdin);
                printf("=========================================");
                if (sim_nao != 'S' && sim_nao != 's' && sim_nao != 'N' && sim_nao != 'n')
                  printf("\n\033[0;31m[Opção inválida! Tente novamente...]\033[0m\n");
              } while (sim_nao != 'S' && sim_nao != 's' && sim_nao != 'N' && sim_nao != 'n');
              for (i = 0; i < l; i++) { // Preenche matriz 2
                for (j = 0; j < c; j++) {
                  if (mat_2[i][j] == 0) { // Verifica se a posição está vazia
                    if (sim_nao == 'S' || sim_nao == 's') { // Aleatório
                      do { // Sorteia números entre -10 e 10, exceto 0
                        mat_2[i][j] = rand() % 21 - 10; 
                      } while (mat_2[i][j] == 0);
                      printf("\nPosição [\033[0;34m%d\033[0m][\033[0;31m%d\033[0m]: %d", i, j, mat_2[i][j]);
                    }
                      else { // Manual
                        printf("\n\033[0;33m[*0 = POSIÇÃO VAZIA]\033[0m");
                        printf("\nDigite o valor da posição [\033[0;34m%d\033[0m][\033[0;31m%d\033[0m]: ", i, j);
                        scanf("%d", &mat_2[i][j]);
                        __fpurge(stdin);
                      }
                    if (mat_2[i][j] != 0) { // Verifica se a posição foi preenchida
                      ct_m2++; // Incrementa o contador de posições da matriz 2
                    }
                  }
                }
              }
              printf("\n=========================================\n");
              printf("\033[0;33m[Matriz[2] preenchida com sucesso!]\033[0m");
              printf("\n=========================================\n");
            }
              else
                printf("\n\033[0;33m[Matriz[%d] cheia! Voltando ao menu...]\033[0m\n", aux);
      }

        else if (op == 2) { // |MOSTRAR MATRIZ|
          do { // Loop para escolher a matriz
            printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
            getchar();
            __fpurge(stdin);
            system("clear");
            aux = -1;
            printf("\n=========================================\n");
            printf("\033[0;34m[MOSTRAR MATRIZ]\033[0m");
            printf("\n=========================================");
            printf("\n[\033[0;35m1\033[0m]> Matriz 1");
            printf("\n[\033[0;35m2\033[0m]> Matriz 2");
            printf("\n=========================================\n");
            printf("[\033[0;32m0\033[0m]> Voltar");
            printf("\n=========================================\n");
            printf("Digite a opção desejada: ");
            scanf("%d", &aux);
            __fpurge(stdin);
            if (aux < 0 || aux > 2)
              printf("\n\033[0;31m[Opção inválida! Tente novamente...]\033[0m\n");
          } while (aux < 0 || aux > 2);
          if (aux == 0) { // Voltar
            printf("\n\033[0;33m[Voltando ao menu...]\033[0m\n");
          }
            else if (aux == 1) { // Mostra matriz 1
              printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
              getchar();
              __fpurge(stdin);
              system("clear");
              printf("\n=========================================\n");
              printf("\033[0;35m[Matriz 1]\033[0m");
              printf("\n-----------------------------------------\n");
              printf("   |");
              for (j = 0; j < c; j++) {
                printf("\033[0;31m%3d ", j);
              }
              printf("  ⬅ |y| (COLUNAS) \033[0m\n---+--");
              for (i = 0; i < c; i++) { 
                printf("----");
              }
              printf("\n");
              for (i = 0; i < l; i++) { 
                printf("\033[0;34m%2d\033[0m |", i); 
                for (j = 0; j < c; j++) {
                  if (mat_1[i][j] != 0) {
                    printf("%3d ", mat_1[i][j]); 
                  }
                    else
                      printf("    ");
                }
                printf("\n");
              }
              printf(" \033[0;34m⬆ \n|x| (LINHAS)\033[0m");
              printf("\n=========================================\n");
            }
              else if (aux == 2) { // Mostra matriz 2
                printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
                getchar();
                __fpurge(stdin);
                system("clear");
                printf("\n=========================================\n");
                printf("\033[0;35m[Matriz 2]\033[0m");
                printf("\n-----------------------------------------\n");
                printf("   |");
                for (j = 0; j < c; j++) {
                  printf("\033[0;31m%3d ", j);
                }
                printf("  ⬅ |y| (COLUNAS) \033[0m\n---+--");
                for (i = 0; i < c; i++) { 
                  printf("----");
                }
                printf("\n");
                for (i = 0; i < l; i++) { 
                  printf("\033[0;34m%2d\033[0m |", i); 
                  for (j = 0; j < c; j++) {
                    if (mat_2[i][j] != 0) {
                      printf("%3d ", mat_2[i][j]); 
                    }
                      else
                        printf("    ");
                  }
                  printf("\n");
                }
                printf(" \033[0;34m⬆ \n|x| (LINHAS)\033[0m");
                printf("\n=========================================\n");
              }
        }

          else if (op == 3) { // |REMOVER DADOS DE MATRIZ|
            if (ct_m1 > 0 || ct_m2 > 0) { // Verifica se a matriz possui dados
              do { // Loop para escolher a matriz
                printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
                getchar();
                __fpurge(stdin);
                system("clear");
                aux = -1;
                printf("\n=========================================\n");
                printf("\033[0;34m[REMOVER DADOS DE MATRIZ]\033[0m");
                printf("\n=========================================");
                printf("\n[\033[0;35m1\033[0m]> Matriz 1");
                printf("\n[\033[0;35m2\033[0m]> Matriz 2");
                printf("\n=========================================\n");
                printf("[\033[0;32m0\033[0m]> Voltar");
                printf("\n=========================================\n");
                printf("Digite a opção desejada: ");
                scanf("%d", &aux);
                __fpurge(stdin);
                if (aux < 0 || aux > 2)
                  printf("\n\033[0;31m[Opção inválida! Tente novamente...]\033[0m\n");
              } while (aux < 0 || aux > 2);
              if (aux == 0) { // Voltar
                printf("\n\033[0;33m[Voltando ao menu...]\033[0m\n");
              }
                else if (aux == 1 && ct_m1 > 0) { // Remover dados da matriz 1
                  do { // Loop para escolher a posição para remover
                    printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
                    getchar();
                    __fpurge(stdin);
                    system("clear");
                    x = -1, y = -1; 
                    printf("\n=========================================\n");
                    printf("\033[0;35m[Matriz 1]\033[0m");
                    printf("\n-----------------------------------------\n");
                    printf("   |");
                    for (j = 0; j < c; j++) {
                      printf("\033[0;31m%3d ", j);
                    }
                    printf("  ⬅ |y| (COLUNAS) \033[0m\n---+--");
                    for (i = 0; i < c; i++) { 
                      printf("----");
                    }
                    printf("\n");
                    for (i = 0; i < l; i++) { 
                      printf("\033[0;34m%2d\033[0m |", i); 
                      for (j = 0; j < c; j++) {
                        if (mat_1[i][j] != 0) {
                          printf("%3d ", mat_1[i][j]); 
                        }
                          else
                            printf("    ");
                      }
                      printf("\n");
                    }
                    printf(" \033[0;34m⬆ \n|x| (LINHAS)\033[0m");
                    printf("\n=========================================\n");
                    printf("Escolha a posição que deseja remover:\n");
                    printf("\033[0;34m[Linha][0-%d]: ", l-1);
                    scanf("%d", &x);
                    __fpurge(stdin);
                    printf("\033[0;31m[Coluna][0-%d]: ", c-1);
                    scanf("%d", &y);
                    __fpurge(stdin);
                    printf("\033[0m=========================================\n");
                    if (x < 0 || x > l-1 || y < 0 || y > c-1)
                      printf("\n\033[0;31m[Posição inválida! Tente novamente...]\033[0m\n");
                  } while (x < 0 || x > l-1 || y < 0 || y > c-1);
                  if (mat_1[x][y] != 0) { // Verifica se a posição escolhida não está vazia
                    do { // Verifica se o usuário deseja excluir o valor
                      printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
                      getchar();
                      __fpurge(stdin);
                      system("clear");
                      printf("\n=========================================\n");
                      printf("Tem certeza que deseja remover a \nposição [\033[0;34m%d\033[0m][\033[0;31m%d\033[0m]: {%d}?", x, y, mat_1[x][y]);
                      printf("\n=========================================\n");
                      printf("[\033[0;34mS\033[0m/\033[0;31mN\033[0m]: ");
                      scanf("%c", &sim_nao);
                      __fpurge(stdin);
                      printf("=========================================\n");
                      if (sim_nao != 'S' && sim_nao != 's' && sim_nao != 'N' && sim_nao != 'n')
                        printf("\n\033[0;31m[Opção inválida! Tente novamente...]\033[0m\n");
                    } while (sim_nao != 'S' && sim_nao != 's' && sim_nao != 'N' && sim_nao != 'n');     
                    if (sim_nao == 'S' || sim_nao == 's') { // Se o usuário deseja excluir o valor
                      for (i = x; i < l; i++) { // Loop para remover a posição escolhida e reordenar a matriz
                        for (j = y; j < c; j++) {
                          if (j + 1 < c) { // Se a próxima posição não é a última da linha
                            mat_1[i][j] = mat_1[i][j+1];
                          }
                            else if (i + 1 < l) { // Se a próxima posição não é a última da coluna
                              mat_1[i][j] = mat_1[i+1][0];
                              y = 0;
                            }
                              else { // Se a posição é a última da matriz
                                mat_1[i][j] = 0;
                                ct_m1--; // Decrementa o contador de posições preenchidas
                              }
                        }
                      } 
                      printf("\033[0;33m[Posição [%d][%d] removida com sucesso!]\033[0m", x, y);
                      printf("\n=========================================\n");
                    }
                      else
                        printf("\n\033[0;33m[Remoção cancelada! Voltando ao menu...]\033[0m\n");
                  }
                    else
                      printf("\n\033[0;33m[Posição vazia! Voltando ao menu...]\033[0m\n");
                }
                  else if (aux == 2 && ct_m2 > 0) { // Remover dados da matriz 2
                    do { // Loop para escolher a posição para remover
                      printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
                      getchar();
                      __fpurge(stdin);
                      system("clear");
                      x = -1, y = -1; 
                      printf("\n=========================================\n");
                      printf("\033[0;35m[Matriz 2]\033[0m");
                      printf("\n-----------------------------------------\n");
                      printf("   |");
                      for (j = 0; j < c; j++) {
                        printf("\033[0;31m%3d ", j);
                      }
                      printf("  ⬅ |y| (COLUNAS) \033[0m\n---+--");
                      for (i = 0; i < c; i++) { 
                        printf("----");
                      }
                      printf("\n");
                      for (i = 0; i < l; i++) { 
                        printf("\033[0;34m%2d\033[0m |", i); 
                        for (j = 0; j < c; j++) {
                          if (mat_2[i][j] != 0) {
                            printf("%3d ", mat_2[i][j]); 
                          }
                            else
                              printf("    ");
                        }
                        printf("\n");
                      }
                      printf(" \033[0;34m⬆ \n|x| (LINHAS)\033[0m");
                      printf("\n=========================================\n");
                      printf("Escolha a posição que deseja remover:\n");
                      printf("\033[0;34m[Linha][0-%d]: ", l-1);
                      scanf("%d", &x);
                      __fpurge(stdin);
                      printf("\033[0;31m[Coluna][0-%d]: ", c-1);
                      scanf("%d", &y);
                      __fpurge(stdin);
                      printf("\033[0m=========================================\n");
                      if (x < 0 || x > l-1 || y < 0 || y > c-1)
                        printf("\n\033[0;31m[Posição inválida! Tente novamente...]\033[0m\n");
                    } while (x < 0 || x > l-1 || y < 0 || y > c-1);
                    if (mat_2[x][y] != 0) { // Verifica se a posição escolhida não está vazia
                      do { // Verifica se o usuário deseja excluir o valor
                        printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
                        getchar();
                        __fpurge(stdin);
                        system("clear");
                        printf("\n=========================================\n");
                        printf("Tem certeza que deseja remover a \nposição [\033[0;34m%d\033[0m][\033[0;31m%d\033[0m]: {%d}?", x, y, mat_2[x][y]);
                        printf("\n=========================================\n");
                        printf("[\033[0;34mS\033[0m/\033[0;31mN\033[0m]: ");
                        scanf("%c", &sim_nao);
                        __fpurge(stdin);
                        printf("=========================================\n");
                        if (sim_nao != 'S' && sim_nao != 's' && sim_nao != 'N' && sim_nao != 'n')
                          printf("\n\033[0;31m[Opção inválida! Tente novamente...]\033[0m\n");
                      } while (sim_nao != 'S' && sim_nao != 's' && sim_nao != 'N' && sim_nao != 'n');   
                      if (sim_nao == 'S' || sim_nao == 's') { // Se o usuário deseja excluir o valor
                        for (i = x; i < l; i++) { // Loop para remover a posição escolhida e reordenar a matriz
                          for (j = y; j < c; j++) {
                            if (j + 1 < c) { // Se a próxima posição não é a última da linha
                              mat_2[i][j] = mat_2[i][j+1];
                            }
                              else if (i + 1 < l) { // Se a próxima posição não é a última da coluna
                                mat_2[i][j] = mat_2[i+1][0];
                                y = 0;
                              }
                                else { // Se a posição é a última da matriz
                                  mat_2[i][j] = 0;
                                  ct_m2--; // Decrementa o contador de posições preenchidas
                                }
                          }
                        } 
                        printf("\033[0;33m[Posição [%d][%d] removida com sucesso!]\033[0m", x, y);
                        printf("\n=========================================\n");
                      }
                        else 
                          printf("\n\033[0;33m[Remoção cancelada! Voltando ao menu...]\033[0m\n");
                    }
                      else
                        printf("\n\033[0;33m[Posição vazia! Voltando ao menu...]\033[0m\n");
                  }  
                    else
                      printf("\n\033[0;33m[Não há dados para remover! Voltando ao menu...]\033[0m\n");
            }
              else
                printf("\n\033[0;33m[Não há dados para remover! Voltando ao menu...]\033[0m\n");
          }

            else if (op == 4) { // |ALTERAR DADOS DE MATRIZ|
              if (ct_m1 > 0 || ct_m2 > 0) { // Verifica se a matriz possui dados
                do { // Loop para escolher a matriz
                  printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
                  getchar();
                  __fpurge(stdin);
                  system("clear");
                  aux = -1;
                  printf("\n=========================================\n");
                  printf("\033[0;34m[ALTERAR DADOS DE MATRIZ]\033[0m");
                  printf("\n=========================================");
                  printf("\n[\033[0;35m1\033[0m]> Matriz 1");
                  printf("\n[\033[0;35m2\033[0m]> Matriz 2");
                  printf("\n=========================================\n");
                  printf("[\033[0;32m0\033[0m]> Voltar");
                  printf("\n=========================================\n");
                  printf("Digite a opção desejada: ");
                  scanf("%d", &aux);
                  __fpurge(stdin);
                  if (aux < 0 || aux > 2)
                    printf("\n\033[0;31m[Opção inválida! Tente novamente...]\033[0m\n");
                } while (aux < 0 || aux > 2);
                if (aux == 0) { // Voltar
                  printf("\n\033[0;33m[Voltando ao menu...]\033[0m\n");
                }
                  else if (aux == 1 && ct_m1 > 0) { // Alterar dados da matriz 1
                    do { // Loop para escolher a posição para alterar
                      printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
                      getchar();
                      __fpurge(stdin);
                      system("clear");
                      x = -1, y = -1; 
                      printf("\n=========================================\n");
                      printf("\033[0;35m[Matriz 1]\033[0m");
                      printf("\n-----------------------------------------\n");
                      printf("   |");
                      for (j = 0; j < c; j++) {
                        printf("\033[0;31m%3d ", j);
                      }
                      printf("  ⬅ |y| (COLUNAS) \033[0m\n---+--");
                      for (i = 0; i < c; i++) { 
                        printf("----");
                      }
                      printf("\n");
                      for (i = 0; i < l; i++) { 
                        printf("\033[0;34m%2d\033[0m |", i); 
                        for (j = 0; j < c; j++) {
                          if (mat_1[i][j] != 0) {
                            printf("%3d ", mat_1[i][j]); 
                          }
                            else
                              printf("    ");
                        }
                        printf("\n");
                      }
                      printf(" \033[0;34m⬆ \n|x| (LINHAS)\033[0m");
                      printf("\n=========================================\n");
                      printf("Escolha a posição que deseja remover:\n");
                      printf("\033[0;34m[Linha][0-%d]: ", l-1);
                      scanf("%d", &x);
                      __fpurge(stdin);
                      printf("\033[0;31m[Coluna][0-%d]: ", c-1);
                      scanf("%d", &y);
                      __fpurge(stdin);
                      printf("\033[0m=========================================\n");
                      if (x < 0 || x > l-1 || y < 0 || y > c-1)
                        printf("\n\033[0;31m[Posição inválida! Tente novamente...]\033[0m\n");
                    } while (x < 0 || x > l-1 || y < 0 || y > c-1);
                    if (mat_1[x][y] != 0) { // Verifica se a posição escolhida não está vazia
                      do { // Loop de confirmação de alteração
                        printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
                        getchar();
                        __fpurge(stdin);
                        system("clear");
                        printf("\n=========================================\n");
                        printf("Tem certeza que deseja alterar a \nposição [\033[0;34m%d\033[0m][\033[0;31m%d\033[0m]: {%d}?", x, y, mat_1[x][y]);
                        printf("\n=========================================\n");
                        printf("[\033[0;34mS\033[0m/\033[0;31mN\033[0m]: ");
                        scanf("%c", &sim_nao);
                        __fpurge(stdin);
                        printf("=========================================\n");
                        if (sim_nao != 'S' && sim_nao != 's' && sim_nao != 'N' && sim_nao != 'n')
                          printf("\n\033[0;31m[Opção inválida! Tente novamente...]\033[0m\n");
                      } while (sim_nao != 'S' && sim_nao != 's' && sim_nao != 'N' && sim_nao != 'n');
                      if (sim_nao == 'S' || sim_nao == 's') { // Se o usuário deseja alterar o valor
                        printf("\033[0;33m[*0 = POSIÇÃO VAZIA]\033[0m\n");
                        printf("Digite o novo valor para \na posição [\033[0;31m%d\033[0m][\033[0;34m%d\033[0m]: ", x, y);
                        scanf("%d", &mat_1[x][y]);
                        __fpurge(stdin);
                        if (mat_1[x][y] == 0) { // Verifica se o valor digitado é 0
                          ct_m1--; // Decrementa o contador de posições da matriz 1
                        }
                        printf("-----------------------------------------\n");
                        printf("\033[0;33m[Posição [%d][%d] alterada com sucesso!]\033[0m", x, y);
                        printf("\n=========================================\n");
                      }
                        else 
                          printf("\n\033[0;33m[Alteração cancelada! Voltando ao menu...]\033[0m\n");
                    }
                      else
                        printf("\n\033[0;33m[Posição vazia! Voltando ao menu...]\033[0m\n");
                  }
                    else if (aux == 2 && ct_m2 > 0) { // Alterar dados da matriz 2
                      do { // Loop para escolher a posição para alterar
                        printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
                        getchar();
                        __fpurge(stdin);
                        system("clear");
                        x = -1, y = -1; 
                        printf("\n=========================================\n");
                        printf("\033[0;35m[Matriz 2]\033[0m");
                        printf("\n-----------------------------------------\n");
                        printf("   |");
                        for (j = 0; j < c; j++) {
                          printf("\033[0;31m%3d ", j);
                        }
                        printf("  ⬅ |y| (COLUNAS) \033[0m\n---+--");
                        for (i = 0; i < c; i++) { 
                          printf("----");
                        }
                        printf("\n");
                        for (i = 0; i < l; i++) { 
                          printf("\033[0;34m%2d\033[0m |", i); 
                          for (j = 0; j < c; j++) {
                            if (mat_2[i][j] != 0) {
                              printf("%3d ", mat_2[i][j]); 
                            }
                              else
                                printf("    ");
                          }
                          printf("\n");
                        }
                        printf(" \033[0;34m⬆ \n|x| (LINHAS)\033[0m");
                        printf("\n=========================================\n");
                        printf("Escolha a posição que deseja remover:\n");
                        printf("\033[0;34m[Linha][0-%d]: ", l-1);
                        scanf("%d", &x);
                        __fpurge(stdin);
                        printf("\033[0;31m[Coluna][0-%d]: ", c-1);
                        scanf("%d", &y);
                        __fpurge(stdin);
                        printf("\033[0m=========================================\n");
                        if (x < 0 || x > l-1 || y < 0 || y > c-1)
                          printf("\n\033[0;31m[Posição inválida! Tente novamente...]\033[0m\n");
                      } while (x < 0 || x > l-1 || y < 0 || y > c-1);
                      if (mat_2[x][y] != 0) { // Verifica se a posição escolhida não está vazia
                        do { // Loop de confirmação de alteração
                          printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
                          getchar();
                          __fpurge(stdin);
                          system("clear");
                          printf("\n=========================================\n");
                          printf("Tem certeza que deseja alterar a \nposição [\033[0;34m%d\033[0m][\033[0;31m%d\033[0m]: {%d}?", x, y, mat_2[x][y]);
                          printf("\n=========================================\n");
                          printf("[\033[0;34mS\033[0m/\033[0;31mN\033[0m]: ");
                          scanf("%c", &sim_nao);
                          __fpurge(stdin);
                          printf("=========================================\n");
                          if (sim_nao != 'S' && sim_nao != 's' && sim_nao != 'N' && sim_nao != 'n')
                            printf("\n\033[0;31m[Opção inválida! Tente novamente...]\033[0m\n");
                        } while (sim_nao != 'S' && sim_nao != 's' && sim_nao != 'N' && sim_nao != 'n');
                        if (sim_nao == 'S' || sim_nao == 's') {
                          printf("\033[0;33m[0 = POSIÇÃO VAZIA]\033[0m\n");
                          printf("Digite o novo valor para \na posição [\033[0;31m%d\033[0m][\033[0;34m%d\033[0m]: ", x, y);
                          scanf("%d", &mat_2[x][y]);
                          __fpurge(stdin);
                          if (mat_2[x][y] == 0) { // Verifica se o valor digitado é 0
                            ct_m2--; // Decrementa o contador de posições da matriz 2
                          }
                          printf("-----------------------------------------\n");
                          printf("\033[0;33m[Posição [%d][%d] alterada com sucesso!]\033[0m", x, y);
                          printf("\n=========================================\n");
                        }
                          else 
                            printf("\n\033[0;33m[Alteração cancelada! Voltando ao menu...]\033[0m\n");
                      }
                        else
                          printf("\n\033[0;33m[Posição vazia! Voltando ao menu...]\033[0m\n");
                    }  
                      else
                        printf("\n\033[0;33m[Não há dados para alterar! Voltando ao menu...]\033[0m\n");
              }
                else
                  printf("\n\033[0;33m[Não há dados para alterar! Voltando ao menu...]\033[0m\n");
            }

              else if (op == 5) { // |REORDENAR MATRIZ|
                if (ct_m1 > 0 || ct_m2 > 0) { // Verifica se há dados nas matrizes
                  do { // Loop para escolher a matriz
                    printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
                    getchar();
                    __fpurge(stdin);
                    system("clear");
                    aux = -1;
                    printf("\n=========================================\n");
                    printf("\033[0;34m[REORDENAR MATRIZ]\033[0m");
                    printf("\n=========================================");
                    printf("\n[\033[0;35m1\033[0m]> Matriz 1");
                    printf("\n[\033[0;35m2\033[0m]> Matriz 2");
                    printf("\n=========================================\n");
                    printf("[\033[0;32m0\033[0m]> Voltar");
                    printf("\n=========================================\n");
                    printf("Digite a opção desejada: ");
                    scanf("%d", &aux);
                    __fpurge(stdin);
                    if (aux < 0 || aux > 2)
                      printf("\n\033[0;31m[Opção inválida! Tente novamente...]\033[0m\n");
                  } while (aux < 0 || aux > 2);
                  if (aux == 0) { // Voltar
                    printf("\n\033[0;33m[Voltando ao menu...]\033[0m\n");
                  }
                    else if (aux == 1 && ct_m1 > 0 || aux == 2 && ct_m2 > 0) {
                      do { // Loop de escolha da forma de reordenação
                        printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
                        getchar();
                        __fpurge(stdin);
                        system("clear");
                        ord = -1;
                        printf("\n=========================================\n");
                        printf("\033[0;34mREORDENAR MATRIZ\033[0m");
                        printf("\n=========================================");
                        printf("\n[\033[0;35m1\033[0m]> Reordenar em ordem crescente");
                        printf("\n[\033[0;35m2\033[0m]> Reordenar em ordem decrescente");
                        printf("\n=========================================\n");
                        printf("[\033[0;32m0\033[0m]> Voltar");
                        printf("\n=========================================\n");
                        printf("Digite a opção desejada: ");
                        scanf("%d", &ord);
                        __fpurge(stdin);
                        if (ord < 0 || ord > 2)
                          printf("\n\033[0;31m[Opção inválida! Tente novamente...]\033[0m\n");
                      } while (ord < 0 || ord > 2);
                      if (ord == 0) { // Voltar
                        printf("\n\033[0;33m[Voltando ao menu...]\033[0m\n");
                      }
                        else if (aux == 1) { // Reordena a matriz 1
                          printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
                          getchar();
                          __fpurge(stdin);
                          system("clear");
                          if (ord == 1) { // Reordena a matriz em ordem crescente
                            printf("\n=========================================\n");
                            printf("\033[0;34m[ORDEM CRESCENTE]\033[0m");
                            printf("\n=========================================\n");
                            for (k = 0; k < c*l-1; k++) { // "Bubble Sort"
                              for (i = 0; i < l; i++) {
                                for (j = 0; j < c; j++) {
                                  if (j + 1 < c && mat_1[i][j] > mat_1[i][j+1]) { // Ordem crescente
                                    temp = mat_1[i][j];
                                    mat_1[i][j] = mat_1[i][j+1];
                                    mat_1[i][j+1] = temp;
                                  }
                                    else if (i + 1 < l && mat_1[i][j] > mat_1[i+1][0]) {
                                      temp = mat_1[i][j];
                                      mat_1[i][j] = mat_1[i+1][0];
                                      mat_1[i+1][0] = temp;
                                    }
                                }
                              }
                            }
                          }
                            else if (ord == 2) { // Reordena a matriz em ordem decrescente
                              printf("\n=========================================\n");
                              printf("\033[0;34m[ORDEM DECRESCENTE]\033[0m");
                              printf("\n=========================================\n");
                              for (k = 0; k < c*l-1; k++) { // "Bubble Sort"
                                for (i = 0; i < l; i++) {
                                  for (j = 0; j < c; j++) {
                                    if (j + 1 < c && mat_1[i][j] < mat_1[i][j+1]) { // Ordem decrescente
                                      temp = mat_1[i][j];
                                      mat_1[i][j] = mat_1[i][j+1];
                                      mat_1[i][j+1] = temp;
                                    }
                                      else if (i + 1 < l && mat_1[i][j] < mat_1[i+1][0]) {
                                        temp = mat_1[i][j];
                                        mat_1[i][j] = mat_1[i+1][0];
                                        mat_1[i+1][0] = temp;
                                      }
                                  }
                                }
                              }
                            }
                          printf("\033[0;33m[Matriz 1 reordenada com sucesso!]\033[0m");
                          printf("\n-----------------------------------------\n");
                          printf("   |");
                          for (j = 0; j < c; j++) {
                            printf("\033[0;31m%3d ", j);
                          }
                          printf("  ⬅ |y| (COLUNAS) \033[0m\n---+--");
                          for (i = 0; i < c; i++) { 
                            printf("----");
                          }
                          printf("\n");
                          for (i = 0; i < l; i++) { 
                            printf("\033[0;34m%2d\033[0m |", i); 
                            for (j = 0; j < c; j++) {
                              if (mat_1[i][j] != 0) {
                                printf("%3d ", mat_1[i][j]); 
                              }
                                else
                                  printf("    ");
                            }
                            printf("\n");
                          }
                          printf(" \033[0;34m⬆ \n|x| (LINHAS)\033[0m");
                          printf("\n=========================================\n");
                        }
                          else if (aux == 2) { // Reordena a matriz 2 
                            printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
                            getchar();
                            __fpurge(stdin);
                            system("clear");
                            if (ord == 1) { // Reordena a matriz em ordem crescente
                              printf("\n=========================================\n");
                              printf("\033[0;34m[ORDEM CRESCENTE]\033[0m");
                              printf("\n=========================================\n");
                              for (k = 0; k < c*l-1; k++) { // "Bubble Sort"
                                for (i = 0; i < l; i++) {
                                  for (j = 0; j < c; j++) {
                                    if (j + 1 < c && mat_2[i][j] > mat_2[i][j+1]) { // Ordem crescente
                                      temp = mat_2[i][j];
                                      mat_2[i][j] = mat_2[i][j+1];
                                      mat_2[i][j+1] = temp;
                                    }
                                      else if (i + 1 < l && mat_2[i][j] > mat_2[i+1][0]) {
                                        temp = mat_2[i][j];
                                        mat_2[i][j] = mat_2[i+1][0];
                                        mat_2[i+1][0] = temp;
                                      }
                                  }
                                }
                              }
                            }
                              else if (ord == 2) { // Reordena a matriz em ordem decrescente
                                printf("\n=========================================\n");
                                printf("\033[0;34m[ORDEM DECRESCENTE]\033[0m");
                                printf("\n=========================================\n");
                                for (k = 0; k < c*l-1; k++) { // "Bubble Sort"
                                  for (i = 0; i < l; i++) {
                                    for (j = 0; j < c; j++) {
                                      if (j + 1 < c && mat_2[i][j] < mat_2[i][j+1]) { // Ordem decrescente
                                        temp = mat_2[i][j];
                                        mat_2[i][j] = mat_2[i][j+1];
                                        mat_2[i][j+1] = temp;
                                      }
                                        else if (i + 1 < l && mat_2[i][j] < mat_2[i+1][0]) {
                                          temp = mat_2[i][j];
                                          mat_2[i][j] = mat_2[i+1][0];
                                          mat_2[i+1][0] = temp;
                                        }
                                    }
                                  }
                                }
                              }
                            printf("\033[0;33m[Matriz 2 reordenada com sucesso!]\033[0m");
                            printf("\n-----------------------------------------\n");
                            printf("   |");
                            for (j = 0; j < c; j++) {
                              printf("\033[0;31m%3d ", j);
                            }
                            printf("  ⬅ |y| (COLUNAS) \033[0m\n---+--");
                            for (i = 0; i < c; i++) { 
                              printf("----");
                            }
                            printf("\n");
                            for (i = 0; i < l; i++) { 
                              printf("\033[0;34m%2d\033[0m |", i); 
                              for (j = 0; j < c; j++) {
                                if (mat_2[i][j] != 0) {
                                  printf("%3d ", mat_2[i][j]); 
                                }
                                  else
                                    printf("    ");
                              }
                              printf("\n");
                            }
                            printf(" \033[0;34m⬆ \n|x| (LINHAS)\033[0m");
                            printf("\n=========================================\n");
                          }
                            else // Se acontecer algum erro anormal
                              printf("\n\033[0;31m[FATAL ERROR!]\033[0m\n");
                    }
                      else {
                        printf("\n\033[0;31m[Não há dados na matriz[%d]!]\033[0m", aux);
                        printf("\n-----------------------------------------\n");
                        printf("\033[0;33m[Voltando ao menu...]\033[0m\n");
                      }
                }
                  else
                    printf("\n\033[0;33m[Não há dados para reordenar! Voltando ao menu...]\033[0m\n");
              }

                else if (op == 6) { // |INTERCALAR MATRIZES|  
                  if (ct_m1 > 0 || ct_m2 > 0) { // Verifica se há dados nas matrizes
                    printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
                    getchar();
                    __fpurge(stdin);
                    system("clear");
                    aux = -1;
                    printf("\n=========================================\n");
                    printf("\033[0;34m[INTERCALAR MATRIZES]\033[0m");
                    printf("\n=========================================\n");
                    printf("\033[0;35m[Matriz 1]\033[0m");
                    printf("\n-----------------------------------------\n");
                    printf("   |");
                    for (j = 0; j < c; j++) {
                      printf("\033[0;31m%3d ", j);
                    }
                    printf("  ⬅ |y| (COLUNAS) \033[0m\n---+--");
                    for (i = 0; i < c; i++) { 
                      printf("----");
                    }
                    printf("\n");
                    for (i = 0; i < l; i++) { 
                      printf("\033[0;34m%2d\033[0m |", i); 
                      for (j = 0; j < c; j++) {
                        if (mat_1[i][j] != 0) {
                          printf("%3d ", mat_1[i][j]); 
                        }
                          else
                            printf("    ");
                      }
                      printf("\n");
                    }
                    printf(" \033[0;34m⬆ \n|x| (LINHAS)\033[0m");
                    printf("\n=========================================\n");
                    printf("\033[0;35m[Matriz 2]\033[0m");
                    printf("\n-----------------------------------------\n");
                    printf("   |");
                    for (j = 0; j < c; j++) {
                      printf("\033[0;31m%3d ", j);
                    }
                    printf("  ⬅ |y| (COLUNAS) \033[0m\n---+--");
                    for (i = 0; i < c; i++) { 
                      printf("----");
                    }
                    printf("\n");
                    for (i = 0; i < l; i++) { 
                      printf("\033[0;34m%2d\033[0m |", i); 
                      for (j = 0; j < c; j++) {
                        if (mat_2[i][j] != 0) {
                          printf("%3d ", mat_2[i][j]); 
                        }
                          else
                            printf("    ");
                      }
                      printf("\n");
                    }
                    printf(" \033[0;34m⬆ \n|x| (LINHAS)\033[0m");
                    printf("\n=========================================\n");
                    for (i = 0; i < l; i++) { // Loop para intercalar as matrizes
                      for (j = 0; j < c; j++) {
                        if (j * 2 < c*2) // Verifica se a coluna é par
                          mat_aux[i][j*2] = mat_1[i][j];
                        if (j * 2 + 1 < c*2) // Verifica se a coluna é ímpar
                          mat_aux[i][j*2+1] = mat_2[i][j];
                      }
                    }
                    printf("\033[0;35m[Matriz Intercalada]\033[0m");
                    printf("\n-----------------------------------------\n");
                    printf("   |");
                    for (j = 0; j < c*2; j++) {
                      printf("\033[0;31m%3d ", j);
                    }
                    printf("  ⬅ |y| (COLUNAS) \033[0m\n---+--");
                    for (i = 0; i < c*2; i++) { 
                      printf("----");
                    }
                    printf("\n");
                    for (i = 0; i < l; i++) { 
                      printf("\033[0;34m%2d\033[0m |", i); 
                      for (j = 0; j < c*2; j++) {
                        if (mat_aux[i][j] != 0) {
                          printf("%3d ", mat_aux[i][j]); 
                        }
                          else
                            printf("    ");
                      }
                      printf("\n");
                    }
                    printf(" \033[0;34m⬆ \n|x| (LINHAS)\033[0m");
                    printf("\n=========================================\n");
                  }
                    else
                      printf("\n\033[0;33m[Não há dados para intercalar! Voltando ao menu...]\033[0m\n");
                }

                  else if (op == 7) { // |SOMAR MATRIZES|
                    printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
                    getchar();
                    __fpurge(stdin);
                    system("clear");
                    printf("\n======================================\n");
                    printf("\033[0;34m[SOMAR MATRIZES]\033[0m");
                    printf("\n======================================\n");
                    printf("\033[0;35m[Matriz 1]\033[0m");
                    printf("\n--------------------------------------\n");
                    printf("   |");
                    for (j = 0; j < c; j++) {
                      printf("\033[0;31m%3d ", j);
                    }
                    printf("  ⬅ |y| (COLUNAS) \033[0m\n---+--");
                    for (i = 0; i < c; i++) { 
                      printf("----");
                    }
                    printf("\n");
                    for (i = 0; i < l; i++) { 
                      printf("\033[0;34m%2d\033[0m |", i); 
                      for (j = 0; j < c; j++) {
                        if (mat_1[i][j] != 0) {
                          printf("%3d ", mat_1[i][j]); 
                        }
                          else
                            printf("    ");
                      }
                      printf("\n");
                    }
                    printf(" \033[0;34m⬆ \n|x| (LINHAS)\033[0m");
                    printf("\n======================================\n");
                    printf("\033[0;35m[Matriz 2]\033[0m");
                    printf("\n--------------------------------------\n");
                    printf("   |");
                    for (j = 0; j < c; j++) {
                      printf("\033[0;31m%3d ", j);
                    }
                    printf("  ⬅ |y| (COLUNAS) \033[0m\n---+--");
                    for (i = 0; i < c; i++) { 
                      printf("----");
                    }
                    printf("\n");
                    for (i = 0; i < l; i++) { 
                      printf("\033[0;34m%2d\033[0m |", i); 
                      for (j = 0; j < c; j++) {
                        if (mat_2[i][j] != 0) {
                          printf("%3d ", mat_2[i][j]); 
                        }
                          else
                            printf("    ");
                      }
                      printf("\n");
                    }
                    printf(" \033[0;34m⬆ \n|x| (LINHAS)\033[0m");
                    printf("\n======================================\n");
                    soma = 0; // Inicializa a variável soma
                    for (i = 0; i < l; i++) { // Loop para somar as matrizes
                      for (j = 0; j < c; j++) {
                        mat_soma[i][j] = mat_1[i][j] + mat_2[i][j];
                        soma += mat_1[i][j] + mat_2[i][j];
                      }
                    }
                    printf("[A soma total das matrizes é: %d]", soma);
                    printf("\n======================================\n");
                    printf("\033[0;35m[Matriz Soma]\033[0m");
                    printf("\n--------------------------------------\n");
                    printf("   |");
                    for (j = 0; j < c; j++) {
                      printf("\033[0;31m%3d ", j);
                    }
                    printf("  ⬅ |y| (COLUNAS) \033[0m\n---+--");
                    for (i = 0; i < c; i++) { 
                      printf("----");
                    }
                    printf("\n");
                    for (i = 0; i < l; i++) { 
                      printf("\033[0;34m%2d\033[0m |", i); 
                      for (j = 0; j < c; j++) {
                        if (mat_soma[i][j] != 0) {
                          printf("%3d ", mat_soma[i][j]); 
                        }
                          else
                            printf("    ");
                      }
                      printf("\n");
                    }
                    printf(" \033[0;34m⬆ \n|x| (LINHAS)\033[0m");
                    printf("\n======================================\n");
                  }

                    else if (op == 8) { // |DETERMINANTE DE MATRIZ|
                      do { // Loop para escolher a matriz
                        printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
                        getchar();
                        __fpurge(stdin);
                        system("clear");
                        aux = -1;
                        printf("\n=========================================\n");
                        printf("\033[0;34m[DETERMINANTE DE MATRIZ]\033[0m");
                        printf("\n=========================================");
                        printf("\n[\033[0;35m1\033[0m]> Matriz 1");
                        printf("\n[\033[0;35m2\033[0m]> Matriz 2");
                        printf("\n=========================================\n");
                        printf("[\033[0;32m0\033[0m]> Voltar");
                        printf("\n=========================================\n");
                        printf("Digite a opção desejada: ");
                        scanf("%d", &aux);
                        __fpurge(stdin);
                        if (aux < 0 || aux > 2)
                          printf("\n\033[0;31m[Opção inválida! Tente novamente...]\033[0m\n");
                      } while (aux < 0 || aux > 2);
                      if (aux == 0) {
                        printf("\n\033[0;33m[Voltando ao menu...]\033[0m\n");
                      }
                        else if (aux == 1) { // Determinante da matriz 1
                          if (l == c) { // Verifica se a matriz 1 é quadrada
                            printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
                            getchar();
                            __fpurge(stdin);
                            system("clear");
                            if (ct_m1 > 0) { // Verifica se há dados na matriz 1
                              diag_p = 0, diag_s = 0; 
                              for (i = 0; i < 2*l-3; i++) { // Loop para calcular as diagonais
                                diag_p_aux = 1, diag_s_aux = 1; // Reseta as variáveis auxiliares
                                for (j = 0; j < l; j++) { 
                                  if (j + i < l) { // Verifica se a posição da diagonal é válida
                                    diag_p_aux *= mat_1[j][j+i];
                                    diag_s_aux *= mat_1[j][l-1-j-i];
                                  }
                                    else {
                                      diag_p_aux *= mat_1[j][(j+i)%l]; // Calcula a diagonal principal
                                      diag_s_aux *= mat_1[j][l-1-(j+i)%l]; // Calcula a diagonal secundária
                                    }
                                }
                                diag_p += diag_p_aux; // Somatório das diagonais principais
                                diag_s += diag_s_aux; // Somatório das diagonais secundárias
                              }
                              dtmn = diag_p - diag_s; // Determinante 
                            }
                              else { // Se não houver dados na matriz
                                dtmn = 1; // Determinante é igual a 1
                              }
                            printf("\n======================================\n");
                            printf("\033[0;35m[Matriz 1]\033[0m");
                            printf("\n--------------------------------------\n");
                            printf("   |");
                            for (j = 0; j < c; j++) {
                              printf("\033[0;31m%3d ", j);
                            }
                            printf("  ⬅ |y| (COLUNAS) \033[0m\n---+--");
                            for (i = 0; i < c; i++) { 
                              printf("----");
                            }
                            printf("\n");
                            for (i = 0; i < l; i++) { 
                              printf("\033[0;34m%2d\033[0m |", i); 
                              for (j = 0; j < c; j++) {
                                if (mat_1[i][j] != 0) {
                                  printf("%3d ", mat_1[i][j]); 
                                }
                                  else
                                    printf("    ");
                              }
                              printf("\n");
                            }
                            printf(" \033[0;34m⬆ \n|x| (LINHAS)\033[0m");
                            printf("\n======================================\n");
                            printf("[Determinante da matriz[\033[0;35m1\033[0m]: %d]", dtmn);
                            printf("\n======================================\n");
                          }
                            else {
                              printf("\n======================================\n");
                              printf("\033[0;31m[Erro! A matriz[1] não é quadrada!]\033[0m");
                              printf("\n======================================\n");
                            }
                        }
                          else if (aux == 2) { // Determinante da matriz 2
                            if (l == c) { // Verifica se a matriz 2 é quadrada
                              printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
                              getchar();
                              __fpurge(stdin);
                              system("clear");
                              if (ct_m2 > 0) { // Verifica se há dados na matriz 2
                                diag_p = 0, diag_s = 0; 
                                for (i = 0; i < 2*l-3; i++) { // Loop para calcular as diagonais
                                  diag_p_aux = 1, diag_s_aux = 1; // Reseta as variáveis auxiliares
                                  for (j = 0; j < l; j++) { 
                                    if (j + i < l) { // Verifica se a posição da diagonal é válida
                                      diag_p_aux *= mat_2[j][j+i];
                                      diag_s_aux *= mat_2[j][l-1-j-i];
                                    }
                                      else {
                                        diag_p_aux *= mat_2[j][(j+i)%l]; // Calcula a diagonal principal
                                        diag_s_aux *= mat_2[j][l-1-(j+i)%l]; // Calcula a diagonal secundária
                                      }
                                  }
                                  diag_p += diag_p_aux; // Somatório das diagonais principais
                                  diag_s += diag_s_aux; // Somatório das diagonais secundárias
                                }
                                dtmn = diag_p - diag_s; // Determinante 
                              }
                                else { // Se não houver dados na matriz
                                  dtmn = 1; // Determinante é igual a 1
                                }
                              printf("\n======================================\n");
                              printf("\033[0;35m[Matriz 2]\033[0m");
                              printf("\n--------------------------------------\n");
                              printf("   |");
                              for (j = 0; j < c; j++) {
                                printf("\033[0;31m%3d ", j);
                              }
                              printf("  ⬅ |y| (COLUNAS) \033[0m\n---+--");
                              for (i = 0; i < c; i++) { 
                                printf("----");
                              }
                              printf("\n");
                              for (i = 0; i < l; i++) { 
                                printf("\033[0;34m%2d\033[0m |", i); 
                                for (j = 0; j < c; j++) {
                                  if (mat_2[i][j] != 0) {
                                    printf("%3d ", mat_2[i][j]); 
                                  }
                                    else
                                      printf("    ");
                                }
                                printf("\n");
                              }
                              printf(" \033[0;34m⬆ \n|x| (LINHAS)\033[0m");
                              printf("\n======================================\n");
                              printf("[Determinante da matriz[\033[0;35m2\033[0m]: %d]", dtmn);
                              printf("\n======================================\n");
                            }
                              else {
                                printf("\n======================================\n");
                                printf("\033[[Erro! A matriz[2] não é quadrada!]\033[0m");
                                printf("\n======================================\n");
                              }
                          }
                    }

                      else if (op == 9) { // |DIFERENÇAS ENTRE MATRIZES|
                        printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
                        getchar();
                        __fpurge(stdin);
                        system("clear");
                        printf("\n======================================\n");
                        printf("\033[0;34m[DIFERENÇAS ENTRE MATRIZES]\033[0m");
                        printf("\n======================================\n");
                        if (ct_m1 > 0 || ct_m2 > 0) { // Verifica se há dados nas matrizes
                          printf("\033[0;35m[Matriz 1]\033[0m");
                          printf("\n--------------------------------------\n");
                          printf("   |");
                          for (j = 0; j < c; j++) {
                            printf("\033[0;31m%3d ", j);
                          }
                          printf("  ⬅ |y| (COLUNAS) \033[0m\n---+--");
                          for (i = 0; i < c; i++) { 
                            printf("----");
                          }
                          printf("\n");
                          for (i = 0; i < l; i++) { 
                            printf("\033[0;34m%2d\033[0m |", i); 
                            for (j = 0; j < c; j++) {
                              if (mat_1[i][j] != 0) {
                                printf("%3d ", mat_1[i][j]); 
                              }
                                else
                                  printf("    ");
                            }
                            printf("\n");
                          }
                          printf(" \033[0;34m⬆ \n|x| (LINHAS)\033[0m");
                          printf("\n======================================\n");
                          printf("\033[0;35m[Matriz 2]\033[0m");
                          printf("\n--------------------------------------\n");
                          printf("   |");
                          for (j = 0; j < c; j++) {
                            printf("\033[0;31m%3d ", j);
                          }
                          printf("  ⬅ |y| (COLUNAS) \033[0m\n---+--");
                          for (i = 0; i < c; i++) { 
                            printf("----");
                          }
                          printf("\n");
                          for (i = 0; i < l; i++) { 
                            printf("\033[0;34m%2d\033[0m |", i); 
                            for (j = 0; j < c; j++) {
                              if (mat_2[i][j] != 0) {
                                printf("%3d ", mat_2[i][j]); 
                              }
                                else
                                  printf("    ");
                            }
                            printf("\n");
                          }
                          printf(" \033[0;34m⬆ \n|x| (LINHAS)\033[0m");
                          printf("\n======================================");
                          comp = 0; // Variável para verificar se há diferenças
                          for (i = 0; i < l; i++) { // Loop para verificar as diferenças entre as matrizes
                            for (j = 0; j < c; j++) {
                              if (mat_1[i][j] != mat_2[i][j]) { // Verifica se os valores das matrizes são diferentes
                                printf("\nPosição [\033[0;34m%d\033[0m][\033[0;31m%d\033[0m]: ", i, j);
                                comp = 1; // Se houver diferença, comp recebe 1
                                if (mat_1[i][j] != 0 && mat_2[i][j] != 0) { // Verifica se os valores são diferentes de 0
                                  printf("%d ≠ %d", mat_1[i][j], mat_2[i][j]);
                                }  
                                  else if (mat_1[i][j] != 0 && mat_2[i][j] == 0) { // Verifica se o 1º valor é diferente de 0 e o 2º é 0
                                    printf("%d ≠ ∅", mat_1[i][j]);
                                  }
                                    else if (mat_1[i][j] == 0 && mat_2[i][j] != 0) // Verifica se o 1º valor é 0 e o 2º é diferente de 0
                                      printf("∅ ≠ %d", mat_2[i][j]);
                              }
                            }
                          }
                          if (comp == 1) { // Verifica se há valores diferentes
                            printf("\n======================================\n");
                            printf("\033[0;33m[*∅ = Vazio]\033[0m");
                          }
                            else { // Se não houver valores diferentes
                              printf("\n\033[0;33m[matriz[1] = matriz[2]!]\033[0m");
                            }
                          printf("\n======================================\n");
                        }
                          else {
                            printf("\033[0;33m[As matrizes não possuem dados!]\033[0m");
                            printf("\n--------------------------------------\n");
                            printf("[Portanto, matriz[1] = matriz[2],");
                            printf("\npois não há dados diferentes!]");
                            printf("\n======================================\n");
                          }
                      }

                        else if (op == 10) { // |IGUALDADES ENTRE MATRIZES|
                          printf("\033[0m\nAperte [\033[0;34mENTER\033[0m] para continuar...");
                          getchar();
                          __fpurge(stdin);
                          system("clear");
                          printf("\n======================================\n");
                          printf("\033[0;34m[IGUALDADES ENTRE MATRIZES]\033[0m");
                          printf("\n======================================\n");
                          if (ct_m1 > 0 || ct_m2 > 0) { // Verifica se há dados nas matrizes
                            printf("\033[0;35m[Matriz 1]\033[0m");
                            printf("\n--------------------------------------\n");
                            printf("   |");
                            for (j = 0; j < c; j++) {
                              printf("\033[0;31m%3d ", j);
                            }
                            printf("  ⬅ |y| (COLUNAS) \033[0m\n---+--");
                            for (i = 0; i < c; i++) { 
                              printf("----");
                            }
                            printf("\n");
                            for (i = 0; i < l; i++) { 
                              printf("\033[0;34m%2d\033[0m |", i); 
                              for (j = 0; j < c; j++) {
                                if (mat_1[i][j] != 0) {
                                  printf("%3d ", mat_1[i][j]); 
                                }
                                  else
                                    printf("    ");
                              }
                              printf("\n");
                            }
                            printf(" \033[0;34m⬆ \n|x| (LINHAS)\033[0m");
                            printf("\n======================================\n");
                            printf("\033[0;35m[Matriz 2]\033[0m");
                            printf("\n--------------------------------------\n");
                            printf("   |");
                            for (j = 0; j < c; j++) {
                              printf("\033[0;31m%3d ", j);
                            }
                            printf("  ⬅ |y| (COLUNAS) \033[0m\n---+--");
                            for (i = 0; i < c; i++) { 
                              printf("----");
                            }
                            printf("\n");
                            for (i = 0; i < l; i++) { 
                              printf("\033[0;34m%2d\033[0m |", i); 
                              for (j = 0; j < c; j++) {
                                if (mat_2[i][j] != 0) {
                                  printf("%3d ", mat_2[i][j]); 
                                }
                                  else
                                    printf("    ");
                              }
                              printf("\n");
                            }
                            printf(" \033[0;34m⬆ \n|x| (LINHAS)\033[0m");
                            printf("\n======================================");
                            comp = 0; // Variável para verificar se há igualdades
                            for (i = 0; i < l; i++) { // Loop para verificar a igualdade
                              for (j = 0; j < c; j++) {
                                if (mat_1[i][j] == mat_2[i][j]) { // Verifica se os valores das matrizes são iguais
                                  printf("\nPosição [\033[0;34m%d\033[0m][\033[0;31m%d\033[0m]: ", i, j);
                                  comp = 1; // Se houver igualdade, comp recebe 1
                                  if (mat_1[i][j] != 0) { // Verifica se o valor da matriz é diferente de 0
                                    printf("%d = %d", mat_1[i][j], mat_2[i][j]);
                                  }
                                    else if (mat_1[i][j] == 0) // Verifica se o valor da matriz é igual a 0
                                      printf("∅ = ∅");
                                }
                              }
                            }
                            if (comp == 1) { // Verifica se há valores iguais
                              printf("\n======================================\n");
                              printf("\033[0;33m[*∅ = Vazio]\033[0m");
                            }
                              else { // Se não houver valores iguais
                                printf("\n\033[0;33m[matriz[1] ≠ matriz[2]!]\033[0m");
                              }
                            printf("\n======================================\n");
                          }
                            else {
                              printf("\033[0;33m[As matrizes não possuem dados!]\033[0m");
                              printf("\n--------------------------------------\n");
                              printf("[Portanto, matriz[1] = matriz[2],");
                              printf("\npois não há dados diferentes!]");
                              printf("\n======================================\n");
                            }
                        }     

                          else { // |MENSAGEM DE ERRO|
                            printf("\n\033[0;31m[FATAL ERROR! Opção inválida!]\033[0m\n");
                          }
  } while (loop_m); // Fim do loop do menu
  return 0;
}