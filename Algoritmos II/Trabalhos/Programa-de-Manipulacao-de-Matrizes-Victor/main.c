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
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void limpa_buffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void limpa_tela() { // Função de limpar a tela
  printf("\033[0m\nAperte [\033[38;5;39mENTER\033[0m] para continuar...");
  limpa_buffer();
  #ifdef _WIN32 // Verifica se o sistema é Windows
    system("cls");
  #else // Caso contrário, assume que é um sistema Unix
    system("clear");
  #endif 
}

void mostra_matriz(int w, int z, int matriz[w][z]) { // Função de mostrar a matriz
  int i, j;
  printf("\n   |");
  for (j = 0; j < z; j++) { // Loop para mostrar as coordenadas das colunas
    printf("\033[38;5;196m%3d ", j);
  }
  printf("  ⬅ |y| (COLUNAS) \033[0m\n---+--");
  for (i = 0; i < z; i++) { // Loop para imprimir marcadores de separação
    printf("----");
  }
  printf("\n");
  for (i = 0; i < w; i++) { // Loop para mostrar as coordenadas das linhas e os elementos da matriz
    printf("\033[38;5;39m%2d\033[0m |", i); 
    for (j = 0; j < z; j++) {
      if (matriz[i][j] != 0) { // Mostra o elemento da matriz se ele não for 0
        printf("%3d ", matriz[i][j]); 
      }
        else // Mostra um espaço em branco se o elemento for 0
          printf("    ");
    }
    printf("\n");
  }
  printf(" \033[38;5;39m⬆ \n|x| (LINHAS)\033[0m\n");
}

void preencher_matriz_m(int w, int z, int matriz[w][z], int *cont) {
  srand(time(NULL));
  int i, j;
  for (i = 0; i < w; i++) { // Loop para preencher a matriz
    for (j = 0; j < z; j++) {
      if (matriz[i][j] == 0) {
        system("clear");
        printf("=========================================");
        mostra_matriz(w, z, matriz);
        printf("=========================================\n");
        printf("\033[38;5;220m[*0 = POSIÇÃO VAZIA]\033[0m");
        printf("\n=========================================\n");
        printf("Digite o valor da posição [\033[38;5;39m%d\033[0m][\033[38;5;196m%d\033[0m]: ", i, j);
        scanf("%d", &matriz[i][j]);
        limpa_buffer();
        if (matriz[i][j] != 0) { // Verifica se a posição foi preenchida
          (*cont)++; // Incrementa o contador de posições da matriz
        }
      }
    }
  }
  system("clear");
  printf("=========================================");
  mostra_matriz(w, z, matriz);
  printf("=========================================");
}
  
void preencher_matriz_a(int w, int z, int matriz[w][z], int *cont, int min, int max) {
  srand(time(NULL));
  int i, j;
  system("clear");
  for (i = 0; i < w; i++) { // Loop para preencher a matriz
    for (j = 0; j < z; j++) {
      if (matriz[i][j] == 0) {
        system("clear");
        matriz[i][j] = rand() % (max - min + 1) + min;
        printf("\n");
        printf("=========================================");
        mostra_matriz(w, z, matriz); // Mostra a matriz preenchida
        printf("=========================================");
        limpa_buffer();
        sleep(1);
        if (matriz[i][j] != 0) { // Verifica se a posição foi preenchida
          (*cont)++; // Incrementa o contador de posições da matriz
        }
      }
    }
  }
}
  
int escolhe_matriz(char *sub_menu) { // Função de escolher a matriz
  int esc; 
  do { // Loop para escolher a matriz
    limpa_tela(); 
    esc = -1;
    printf("\n=========================================\n");
    printf("\033[38;5;39m[%s]\033[0m", sub_menu);
    printf("\n=========================================");
    printf("\n[\033[38;5;201m1\033[0m]> Matriz 1");
    printf("\n[\033[38;5;201m2\033[0m]> Matriz 2");
    printf("\n=========================================\n");
    printf("[\033[38;5;46m0\033[0m]> Voltar");
    printf("\n=========================================\n");
    printf("Digite a opção desejada:\033[38;5;201m ");
    scanf("%d", &esc);
    limpa_buffer();
    if (esc < 0 || esc > 2) {
      printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
    }
  } while (esc < 0 || esc > 2);
  return esc; // Retorna a matriz escolhida
}

void escolhe_posicao(int w, int z, int *a, int *b, int matriz[w][z], int ax) { // Função de escolher a posição
  do { // Loop para escolher a posição para remover
    limpa_tela();
    *a = -1, *b = -1; 
    printf("\n=========================================\n");
    printf("\033[38;5;201m[Matriz %d]\033[0m", ax);
    printf("\n-----------------------------------------");
    mostra_matriz(w, z, matriz); // Mostra a matriz
    printf("=========================================\n");
    printf("Escolha a posição que deseja remover:\n");
    printf("\033[38;5;39m[Linha][0-%d]: ", w-1);
    scanf("%d", a);
    limpa_buffer();
    printf("\033[38;5;196m[Coluna][0-%d]: ", z-1);
    scanf("%d", b);
    limpa_buffer();
    printf("\033[0m=========================================\n");
    if (*a < 0 || *a > w-1 || *b < 0 || *b > z-1) {
      printf("\n\033[38;5;196m[Posição inválida! Tente novamente...]\033[0m\n");
    }
  } while (*a < 0 || *a > w-1 || *b < 0 || *b > z-1);
}

void remover_dados(int w, int z, int a, int b, int matriz[w][z], int *cont) { // Função de remover dados
  int i, j;
  for (i = a; i < w; i++) { // Loop para remover a posição escolhida e reordenar a matriz
    for (j = b; j < z; j++) {
      if (j + 1 < z) { // Se a próxima posição não é a última da linha
        matriz[i][j] = matriz[i][j+1];
      }
        else if (i + 1 < w) { // Se a próxima posição não é a última da coluna
          matriz[i][j] = matriz[i+1][0];
          b = 0;
        }
          else { // Se a posição é a última da matriz
            matriz[i][j] = 0;
            (*cont)--; // Decrementa o contador de posições preenchidas
          }
    }
  } 
}

void ordem_crescente(int w, int z, int matriz[w][z]) { // Função de reordenar a matriz crescente
  int t, i, j, k;
  for (k = 0; k < w*z-1; k++) { // "Bubble Sort"
    for (i = 0; i < w; i++) {
      for (j = 0; j < z; j++) {
        if (j + 1 < z && matriz[i][j] > matriz[i][j+1]) { // Ordem crescente
          t = matriz[i][j];
          matriz[i][j] = matriz[i][j+1];
          matriz[i][j+1] = t;
        }
          else if (i + 1 < w && matriz[i][j] > matriz[i+1][0]) {
            t = matriz[i][j];
            matriz[i][j] = matriz[i+1][0];
            matriz[i+1][0] = t;
          }
      }
    }
  }
}

void ordem_decrescente(int w, int z, int matriz[w][z]) { // Função de reordenar a matriz decrescente
  int t, i, j, k;
  for (k = 0; k < w*z-1; k++) { // "Bubble Sort"
    for (i = 0; i < w; i++) {
      for (j = 0; j < z; j++) {
        if (j + 1 < z && matriz[i][j] < matriz[i][j+1]) { // Ordem decrescente
          t = matriz[i][j];
          matriz[i][j] = matriz[i][j+1];
          matriz[i][j+1] = t;
        }
          else if (i + 1 < w && matriz[i][j] < matriz[i+1][0]) {
            t = matriz[i][j];
            matriz[i][j] = matriz[i+1][0];
            matriz[i+1][0] = t;
          }
      }
    }
  }
}

int determinante(int w, int z, int matriz[w][z], int cont) { // Função de calcular o determinante
  int dt, diag_p = 0, diag_s = 0, diag_p_aux, diag_s_aux, i, j;
  if (cont > 0) { // Verifica se há dados na matriz 
    for (i = 0; i < 2*w-3; i++) { // Loop para calcular as diagonais
      diag_p_aux = 1, diag_s_aux = 1; // Reseta as variáveis auxiliares
      for (j = 0; j < z; j++) { 
        diag_p_aux *= matriz[j][(j+i)%z]; // Calcula a diagonal principal
        diag_s_aux *= matriz[j][z-1-(j+i)%z]; // Calcula a diagonal secundária
      }
      diag_p += diag_p_aux; // Somatório das diagonais principais
      diag_s += diag_s_aux; // Somatório das diagonais secundárias
    }
    dt = diag_p - diag_s; // Determinante 
  }
    else { // Se não houver dados na matriz
      dt = 1; // Determinante é igual a 1
    }
  return dt; // Retorna o determinante
}

int main(void) { // Função principal
  srand(time(NULL)); // Função de gerar números aleatórios
  // Declaração de variáveis:
  int l = 3, c = 3, x, y, i, j, k, op, aux, loop_m = 1, ct_m1 = 0, ct_m2 = 0, comp, ord;
  int mat_1[l][c], mat_2[l][c], mat_aux[l][c*2], mat_soma[l][c], temp, soma, dtmn;
  int minimo = 0, maximo = 100;
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

  printf("\n[\033[38;5;196m*\033[38;5;39mBEM-VINDO AO PROGRAMA DE \033[38;5;196m[MANIPULAÇÃO] \033[38;5;39mDE \033[38;5;196m[MATRIZES]\033[38;5;39m!\033[38;5;196m*\033[0m]\n");
  do { // |LOOP PRINCIPAL|
    do { // |MENU DE OPÇÕES|
      limpa_tela(); // Limpa a tela
      op = -1;
      printf("=========================================\n");
      printf("\033[38;5;46m[MENU DE MANIPULAÇÃO DE MATRIZES]\033[0m");
      printf("\n=========================================");
      printf("\n[\033[38;5;51m1\033[0m]> Preencher matriz");
      printf("\n[\033[38;5;51m2\033[0m]> Mostrar matriz");
      printf("\n[\033[38;5;51m3\033[0m]> Remover dados de matriz");
      printf("\n[\033[38;5;51m4\033[0m]> Alterar dados de matriz");
      printf("\n[\033[38;5;51m5\033[0m]> Reordenar matriz");
      printf("\n[\033[38;5;51m6\033[0m]> Intercalar matrizes");
      printf("\n[\033[38;5;51m7\033[0m]> Somar matrizes");
      printf("\n[\033[38;5;51m8\033[0m]> Determinante de matriz");
      printf("\n[\033[38;5;51m9\033[0m]> Diferenças entre matrizes");
      printf("\n[\033[38;5;51m10\033[0m]> Igualdades entre matrizes");
      printf("\n=========================================\n");
      printf("[\033[38;5;196m0\033[0m]> Sair");
      printf("\n=========================================\n");
      printf("Digite a opção desejada:\033[38;5;51m ");
      scanf("%d", &op);
      limpa_buffer();
      if (op < 0 || op > 10) {
        printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
      }
    } while (op < 0 || op > 10);

    if (op == 0) { // |SAIR|
      do { // Loop de confirmação de saída
        limpa_tela(); // Limpa a tela
        printf("=========================================\n");
        printf("Tem certeza que deseja \033[38;5;196m[sair]\033[0m? ");
        printf("\n=========================================\n");
        printf("[\033[38;5;39mS\033[0m/\033[38;5;196mN\033[0m]: ");
        scanf("%c", &sim_nao);
        limpa_buffer();
        printf("=========================================\n");
        if (sim_nao == 'S' || sim_nao == 's') { // Confirma a saída
          printf("\n[\033[38;5;196m*\033[38;5;39mObrigado por usar o programa!\033[38;5;196m*\033[0m]\n");
          limpa_tela(); // Limpa a tela
          loop_m = 0;
        }
          else if (sim_nao == 'N' || sim_nao == 'n') { // Volta ao menu
            printf("\n\033[38;5;220m[Retornando ao menu...]\033[0m\n");
          }
            else { // Opção inválida
              printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n"); 
            }
      } while (sim_nao != 'S' && sim_nao != 's' && sim_nao != 'N' && sim_nao != 'n');
    }

      else if (op == 1) { // |PREENCHER MATRIZ|
        aux = escolhe_matriz("PREENCHER MATRIZ"); // Escolhe a matriz p/ preencher
        if (aux == 0) { // Voltar
          printf("\n\033[38;5;220m[Voltando ao menu...]\033[0m\n");
        }
          else if (aux == 1 && ct_m1 < l*c) { // Preencher matriz 1
            do { // Loop de escolha de modo de preencher: aleatório ou manual
              limpa_tela(); // Limpa a tela
              printf("\n=========================================\n");
              printf("\033[38;5;201m[Matriz 1]\033[0m");
              printf("\n=========================================\n");
              printf("Deseja aleatorizar os valores? \n[\033[38;5;39mS\033[0m/\033[38;5;196mN\033[0m]: ");
              scanf("%c", &sim_nao);
              limpa_buffer();
              printf("=========================================");
              if (sim_nao != 'S' && sim_nao != 's' && sim_nao != 'N' && sim_nao != 'n')
                printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
            } while (sim_nao != 'S' && sim_nao != 's' && sim_nao != 'N' && sim_nao != 'n');
            if (sim_nao == 'S' || sim_nao == 's') { // Aleatório
              preencher_matriz_a(l, c, mat_1, &ct_m1, minimo, maximo);
            }
              else if (sim_nao == 'N' || sim_nao == 'n') { // Manual
                preencher_matriz_m(l, c, mat_1, &ct_m1);
              }
            printf("\n\033[38;5;220m[Matriz[1] preenchida com sucesso!]\033[0m");
            printf("\n=========================================\n");
          }
            else if (aux == 2 && ct_m2 < l*c) { // Preencher matriz 2
              do { // Loop de escolha de modo de preencher: aleatório ou manual
                limpa_tela(); // Limpa a tela
                printf("\n=========================================\n");
                printf("\033[38;5;201m[Matriz 2]\033[0m");
                printf("\n=========================================\n");
                printf("Deseja aleatorizar os valores? \n[\033[38;5;39mS\033[0m/\033[38;5;196mN\033[0m]: ");
                scanf("%c", &sim_nao);
                limpa_buffer();
                printf("=========================================");
                if (sim_nao != 'S' && sim_nao != 's' && sim_nao != 'N' && sim_nao != 'n') {
                  printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
                }
              } while (sim_nao != 'S' && sim_nao != 's' && sim_nao != 'N' && sim_nao != 'n');
              if (sim_nao == 'S' || sim_nao == 's') { // Aleatório
                preencher_matriz_a(l, c, mat_2, &ct_m2, minimo, maximo);
              }
                else if (sim_nao == 'N' || sim_nao == 'n') { // Manual
                  preencher_matriz_m(l, c, mat_2, &ct_m2);
                }
              printf("\n\033[38;5;220m[Matriz[2] preenchida com sucesso!]\033[0m");
              printf("\n=========================================\n");
            }
              else
                printf("\n\033[38;5;220m[Matriz[%d] cheia! Voltando ao menu...]\033[0m\n", aux);
      }

        else if (op == 2) { // |MOSTRAR MATRIZ|
          aux = escolhe_matriz("MOSTRAR MATRIZ"); // Escolhe a matriz p/ mostrar
          if (aux == 0) { // Voltar
            printf("\n\033[38;5;220m[Voltando ao menu...]\033[0m\n");
          }
            else if (aux == 1) { // Mostra matriz 1
              limpa_tela(); // Limpa a tela
              printf("\n=========================================\n");
              printf("\033[38;5;201m[Matriz 1]\033[0m");
              printf("\n-----------------------------------------");
              mostra_matriz(l, c, mat_1); // Mostra a matriz 1
              printf("=========================================\n");
            }
              else if (aux == 2) { // Mostra matriz 2
                limpa_tela(); // Limpa a tela
                printf("\n=========================================\n");
                printf("\033[38;5;201m[Matriz 2]\033[0m");
                printf("\n-----------------------------------------");
                mostra_matriz(l, c, mat_2); // Mostra a matriz 2
                printf("=========================================\n");
              }
        }

          else if (op == 3) { // |REMOVER DADOS DE MATRIZ|
            if (ct_m1 > 0 || ct_m2 > 0) { // Verifica se a matriz possui dados
              aux = escolhe_matriz("REMOVER DADOS DE MATRIZ"); // Escolhe a matriz p/ remover dados
              if (aux == 0) { // Voltar
                printf("\n\033[38;5;220m[Voltando ao menu...]\033[0m\n");
              }
                else if (aux == 1 && ct_m1 > 0) { // Remover dados da matriz 1
                  escolhe_posicao(l, c, &x, &y, mat_1, aux); // Escolhe a posição p/ remover
                  if (mat_1[x][y] != 0) { // Verifica se a posição escolhida não está vazia
                    do { // Verifica se o usuário deseja excluir o valor
                      limpa_tela(); // Limpa a tela
                      printf("\n=========================================\n");
                      printf("Tem certeza que deseja remover a \nposição [\033[38;5;39m%d\033[0m][\033[38;5;196m%d\033[0m]: {%d}?", x, y, mat_1[x][y]);
                      printf("\n=========================================\n");
                      printf("[\033[38;5;39mS\033[0m/\033[38;5;196mN\033[0m]: ");
                      scanf("%c", &sim_nao);
                      limpa_buffer();
                      printf("=========================================\n");
                      if (sim_nao != 'S' && sim_nao != 's' && sim_nao != 'N' && sim_nao != 'n') {
                        printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
                      }
                    } while (sim_nao != 'S' && sim_nao != 's' && sim_nao != 'N' && sim_nao != 'n');     
                    if (sim_nao == 'S' || sim_nao == 's') { // Se o usuário deseja excluir o valor
                      remover_dados(l, c, x, y, mat_1, &ct_m1); // Remove o valor e reordena a matriz 1
                      printf("\033[38;5;220m[Posição [%d][%d] removida com sucesso!]\033[0m", x, y);
                      printf("\n=========================================\n");
                    }
                      else {
                        printf("\n\033[38;5;220m[Remoção cancelada! Voltando ao menu...]\033[0m\n");
                      }
                  }
                    else {
                      printf("\n\033[38;5;220m[Posição vazia! Voltando ao menu...]\033[0m\n");
                    }
                }
                  else if (aux == 2 && ct_m2 > 0) { // Remover dados da matriz 2
                    escolhe_posicao(l, c, &x, &y, mat_2, aux); // Escolhe a posição p/ remover
                    if (mat_2[x][y] != 0) { // Verifica se a posição escolhida não está vazia
                      do { // Verifica se o usuário deseja excluir o valor
                        limpa_tela(); // Limpa a tela
                        printf("\n=========================================\n");
                        printf("Tem certeza que deseja remover a \nposição [\033[38;5;39m%d\033[0m][\033[38;5;196m%d\033[0m]: {%d}?", x, y, mat_2[x][y]);
                        printf("\n=========================================\n");
                        printf("[\033[38;5;39mS\033[0m/\033[38;5;196mN\033[0m]: ");
                        scanf("%c", &sim_nao);
                        limpa_buffer();
                        printf("=========================================\n");
                        if (sim_nao != 'S' && sim_nao != 's' && sim_nao != 'N' && sim_nao != 'n') {
                          printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
                        }
                      } while (sim_nao != 'S' && sim_nao != 's' && sim_nao != 'N' && sim_nao != 'n');   
                      if (sim_nao == 'S' || sim_nao == 's') { // Se o usuário deseja excluir o valor
                        remover_dados(l, c, x, y, mat_2, &ct_m2); // Remove o valor e reordena a matriz 2
                        printf("\033[38;5;220m[Posição [%d][%d] removida com sucesso!]\033[0m", x, y);
                        printf("\n=========================================\n");
                      }
                        else 
                          printf("\n\033[38;5;220m[Remoção cancelada! Voltando ao menu...]\033[0m\n");
                    }
                      else
                        printf("\n\033[38;5;220m[Posição vazia! Voltando ao menu...]\033[0m\n");
                  }  
                    else
                      printf("\n\033[38;5;220m[Não há dados para remover! Voltando ao menu...]\033[0m\n");
            }
              else
                printf("\n\033[38;5;220m[Não há dados para remover! Voltando ao menu...]\033[0m\n");
          }

            else if (op == 4) { // |ALTERAR DADOS DE MATRIZ|
              if (ct_m1 > 0 || ct_m2 > 0) { // Verifica se a matriz possui dados
                aux = escolhe_matriz("ALTERAR DADOS DE MATRIZ"); // Escolhe a matriz p/ alterar dados
                if (aux == 0) { // Voltar
                  printf("\n\033[38;5;220m[Voltando ao menu...]\033[0m\n");
                }
                  else if (aux == 1 && ct_m1 > 0) { // Alterar dados da matriz 1
                    escolhe_posicao(l, c, &x, &y, mat_1, aux); // Escolhe a posição p/ alterar
                    if (mat_1[x][y] != 0) { // Verifica se a posição escolhida não está vazia
                      do { // Loop de confirmação de alteração
                        limpa_tela(); // Limpa a tela
                        printf("\n=========================================\n");
                        printf("Tem certeza que deseja alterar a \nposição [\033[38;5;39m%d\033[0m][\033[38;5;196m%d\033[0m]: {%d}?", x, y, mat_1[x][y]);
                        printf("\n=========================================\n");
                        printf("[\033[38;5;39mS\033[0m/\033[38;5;196mN\033[0m]: ");
                        scanf("%c", &sim_nao);
                        limpa_buffer();
                        printf("=========================================\n");
                        if (sim_nao != 'S' && sim_nao != 's' && sim_nao != 'N' && sim_nao != 'n')
                          printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
                      } while (sim_nao != 'S' && sim_nao != 's' && sim_nao != 'N' && sim_nao != 'n');
                      if (sim_nao == 'S' || sim_nao == 's') { // Se o usuário deseja alterar o valor
                        printf("\033[38;5;220m[*0 = POSIÇÃO VAZIA]\033[0m\n");
                        printf("Digite o novo valor para \na posição [\033[38;5;196m%d\033[0m][\033[38;5;39m%d\033[0m]: ", x, y);
                        scanf("%d", &mat_1[x][y]);
                        limpa_buffer();
                        if (mat_1[x][y] == 0) { // Verifica se o valor digitado é 0
                          ct_m1--; // Decrementa o contador de posições da matriz 1
                        }
                        printf("-----------------------------------------\n");
                        printf("\033[38;5;220m[Posição [%d][%d] alterada com sucesso!]\033[0m", x, y);
                        printf("\n=========================================\n");
                      }
                        else 
                          printf("\n\033[38;5;220m[Alteração cancelada! Voltando ao menu...]\033[0m\n");
                    }
                      else
                        printf("\n\033[38;5;220m[Posição vazia! Voltando ao menu...]\033[0m\n");
                  }
                    else if (aux == 2 && ct_m2 > 0) { // Alterar dados da matriz 2
                      escolhe_posicao(l, c, &x, &y, mat_2, aux); // Escolhe a posição p/ alterar
                      if (mat_2[x][y] != 0) { // Verifica se a posição escolhida não está vazia
                        do { // Loop de confirmação de alteração
                          limpa_tela(); // Limpa a tela
                          printf("\n=========================================\n");
                          printf("Tem certeza que deseja alterar a \nposição [\033[38;5;39m%d\033[0m][\033[38;5;196m%d\033[0m]: {%d}?", x, y, mat_2[x][y]);
                          printf("\n=========================================\n");
                          printf("[\033[38;5;39mS\033[0m/\033[38;5;196mN\033[0m]: ");
                          scanf("%c", &sim_nao);
                          limpa_buffer();
                          printf("=========================================\n");
                          if (sim_nao != 'S' && sim_nao != 's' && sim_nao != 'N' && sim_nao != 'n')
                            printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
                        } while (sim_nao != 'S' && sim_nao != 's' && sim_nao != 'N' && sim_nao != 'n');
                        if (sim_nao == 'S' || sim_nao == 's') {
                          printf("\033[38;5;220m[0 = POSIÇÃO VAZIA]\033[0m\n");
                          printf("Digite o novo valor para \na posição [\033[38;5;196m%d\033[0m][\033[38;5;39m%d\033[0m]: ", x, y);
                          scanf("%d", &mat_2[x][y]);
                          limpa_buffer();
                          if (mat_2[x][y] == 0) { // Verifica se o valor digitado é 0
                            ct_m2--; // Decrementa o contador de posições da matriz 2
                          }
                          printf("-----------------------------------------\n");
                          printf("\033[38;5;220m[Posição [%d][%d] alterada com sucesso!]\033[0m", x, y);
                          printf("\n=========================================\n");
                        }
                          else 
                            printf("\n\033[38;5;220m[Alteração cancelada! Voltando ao menu...]\033[0m\n");
                      }
                        else
                          printf("\n\033[38;5;220m[Posição vazia! Voltando ao menu...]\033[0m\n");
                    }  
                      else
                        printf("\n\033[38;5;220m[Não há dados para alterar! Voltando ao menu...]\033[0m\n");
              }
                else
                  printf("\n\033[38;5;220m[Não há dados para alterar! Voltando ao menu...]\033[0m\n");
            }

              else if (op == 5) { // |REORDENAR MATRIZ|
                if (ct_m1 > 0 || ct_m2 > 0) { // Verifica se há dados nas matrizes
                  aux = escolhe_matriz("REORDENAR MATRIZ"); // Escolhe a matriz p/ reordenar
                  if (aux == 0) { // Voltar
                    printf("\n\033[38;5;220m[Voltando ao menu...]\033[0m\n");
                  }
                    else if (aux == 1 && ct_m1 > 0 || aux == 2 && ct_m2 > 0) {
                      do { // Loop de escolha da forma de reordenação
                        limpa_tela(); // Limpa a tela
                        ord = -1;
                        printf("\n=========================================\n");
                        printf("\033[38;5;39mREORDENAR MATRIZ\033[0m");
                        printf("\n=========================================");
                        printf("\n[\033[38;5;201m1\033[0m]> Reordenar em ordem crescente");
                        printf("\n[\033[38;5;201m2\033[0m]> Reordenar em ordem decrescente");
                        printf("\n=========================================\n");
                        printf("[\033[38;5;46m0\033[0m]> Voltar");
                        printf("\n=========================================\n");
                        printf("Digite a opção desejada: ");
                        scanf("%d", &ord);
                        limpa_buffer();
                        if (ord < 0 || ord > 2)
                          printf("\n\033[38;5;196m[Opção inválida! Tente novamente...]\033[0m\n");
                      } while (ord < 0 || ord > 2);
                      if (ord == 0) { // Voltar
                        printf("\n\033[38;5;220m[Voltando ao menu...]\033[0m\n");
                      }
                        else if (aux == 1 && ord == 1) { // Reordena a matriz 1
                          limpa_tela(); // Limpa a tela
                          printf("\n=========================================\n");
                          printf("\033[38;5;39m[ORDEM CRESCENTE]\033[0m");
                          printf("\n=========================================\n");
                          ordem_crescente(l, c, mat_1); // Reordena a matriz 1
                          printf("\033[38;5;220m[Matriz 1 reordenada com sucesso!]\033[0m");
                          printf("\n-----------------------------------------");
                          mostra_matriz(l, c, mat_1); // Mostra a matriz 1 reordenada
                          printf("=========================================\n");
                        }
                          else if (aux == 1 && ord == 2) { // Reordena a matriz 1
                            limpa_tela(); // Limpa a tela
                            printf("\n=========================================\n");
                            printf("\033[38;5;39m[ORDEM DECRESCENTE]\033[0m");
                            printf("\n=========================================\n");
                            ordem_decrescente(l, c, mat_1); // Reordena a matriz 1
                            printf("\033[38;5;220m[Matriz 1 reordenada com sucesso!]\033[0m");
                            printf("\n-----------------------------------------");
                            mostra_matriz(l, c, mat_1); // Mostra a matriz 1 reordenada
                            printf("=========================================\n");
                          }
                            else if (aux == 2 && ord == 1) { // Reordena a matriz 2 
                              limpa_tela(); // Limpa a tela
                              printf("\n=========================================\n");
                              printf("\033[38;5;39m[ORDEM CRESCENTE]\033[0m");
                              printf("\n=========================================\n");
                              ordem_crescente(l, c, mat_2); // Reordena a matriz 2
                              printf("\033[38;5;220m[Matriz 2 reordenada com sucesso!]\033[0m");
                              printf("\n-----------------------------------------");
                              mostra_matriz(l, c, mat_2); // Mostra a matriz 2 reordenada
                              printf("=========================================\n");
                            }
                              else if (aux == 2 && ord == 2) { // Reordena a matriz 2 
                                limpa_tela(); // Limpa a tela
                                printf("\n=========================================\n");
                                printf("\033[38;5;39m[ORDEM DECRESCENTE]\033[0m");
                                printf("\n=========================================\n");
                                ordem_decrescente(l, c, mat_2); // Reordena a matriz 2
                                printf("\033[38;5;220m[Matriz 2 reordenada com sucesso!]\033[0m");
                                printf("\n-----------------------------------------");
                                mostra_matriz(l, c, mat_2); // Mostra a matriz 2 reordenada
                                printf("=========================================\n");
                              }
                                else { // Se acontecer algum erro anormal
                                  printf("\n\033[38;5;196m[FATAL ERROR!]\033[0m\n");
                                }
                    }
                      else {
                        printf("\n=========================================\n");
                        printf("\033[38;5;196m[Erro! Não há dados na matriz[%d]!]\033[0m", aux);
                        printf("\n-----------------------------------------\n");
                        printf("\033[38;5;220m[Voltando ao menu...]\033[0m");
                        printf("\n=========================================\n");
                      }
                }
                  else {
                    printf("\n\033[38;5;220m[Não há dados para reordenar! Voltando ao menu...]\033[0m\n");
                  }
              }
  
                else if (op == 6) { // |INTERCALAR MATRIZES|  
                  if (ct_m1 > 0 || ct_m2 > 0) { // Verifica se há dados nas matrizes
                    limpa_tela(); // Limpa a tela
                    aux = -1;
                    printf("\n=========================================\n");
                    printf("\033[38;5;39m[INTERCALAR MATRIZES]\033[0m");
                    printf("\n=========================================\n");
                    printf("\033[38;5;201m[Matriz 1]\033[0m");
                    printf("\n-----------------------------------------");
                    mostra_matriz(l, c, mat_1); // Mostra a matriz 1
                    printf("=========================================\n");
                    printf("\033[38;5;201m[Matriz 2]\033[0m");
                    printf("\n-----------------------------------------");
                    mostra_matriz(l, c, mat_2); // Mostra a matriz 2
                    printf("=========================================\n");
                    for (i = 0; i < l; i++) { // Loop para intercalar as matrizes
                      for (j = 0; j < c; j++) {
                        mat_aux[i][j*2] = mat_1[i][j];
                        mat_aux[i][j*2+1] = mat_2[i][j];
                      }
                    }
                    printf("\033[38;5;201m[Matriz Intercalada]\033[0m");
                    printf("\n-----------------------------------------");
                    mostra_matriz(l, c*2, mat_aux); // Mostra a matriz intercalada
                    printf("=========================================\n");
                  }
                    else { // Se as matrizes não tiverem dados
                      printf("\n\033[38;5;220m[Não há dados para intercalar! Voltando ao menu...]\033[0m\n");
                    }
                }
  
                  else if (op == 7) { // |SOMAR MATRIZES|
                    limpa_tela(); // Limpa a tela
                    printf("\n======================================\n");
                    printf("\033[38;5;39m[SOMAR MATRIZES]\033[0m");
                    printf("\n======================================\n");
                    printf("\033[38;5;201m[Matriz 1]\033[0m");
                    printf("\n--------------------------------------");
                    mostra_matriz(l, c, mat_1); // Mostra a matriz 1
                    printf("======================================\n");
                    printf("\033[38;5;201m[Matriz 2]\033[0m");
                    printf("\n--------------------------------------");
                    mostra_matriz(l, c, mat_2); // Mostra a matriz 2
                    printf("======================================\n");
                    soma = 0; // Inicializa a variável soma
                    for (i = 0; i < 3; i++) { // Loop para somar as matrizes
                      for (j = 0; j < 3; j++) {
                        mat_soma[i][j] = mat_1[i][j] + mat_2[i][j];
                        soma += mat_1[i][j] + mat_2[i][j];
                      }
                    }
                    printf("[A soma total das matrizes é: %d]", soma);
                    printf("\n======================================\n");
                    printf("\033[38;5;201m[Matriz Soma]\033[0m");
                    printf("\n--------------------------------------");
                    mostra_matriz(l, c, mat_soma); // Mostra a matriz de soma
                    printf("======================================\n");
                  }
  
                    else if (op == 8) { // |DETERMINANTE DE MATRIZ|
                      aux = escolhe_matriz("DETERMINANTE DE MATRIZ"); // Escolhe a matriz p/ calcular o determinante
                      if (aux == 0) {
                        printf("\n\033[38;5;220m[Voltando ao menu...]\033[0m\n");
                      }
                        else if (aux == 1) { // Determinante da matriz 1
                          if (l == c) { // Verifica se a matriz 1 é quadrada
                            limpa_tela(); // Limpa a tela
                            dtmn = determinante(l, c, mat_1, ct_m1); // Calcula o determinante da matriz 1
                            printf("\n======================================\n");
                            printf("\033[38;5;201m[Matriz 1]\033[0m");
                            printf("\n--------------------------------------");
                            mostra_matriz(l, c, mat_1); // Mostra a matriz 1
                            printf("======================================\n");
                            printf("[Determinante da matriz[\033[38;5;201m1\033[0m]: %d]", dtmn);
                            printf("\n======================================\n");
                          }
                            else {
                              printf("\n======================================\n");
                              printf("\033[38;5;196m[Erro! A matriz[1] não é quadrada!]\033[0m");
                              printf("\n======================================\n");
                            }
                        }
                          else if (aux == 2) { // Determinante da matriz 2
                            if (l == c) { // Verifica se a matriz 2 é quadrada
                              limpa_tela(); // Limpa a tela
                              dtmn = determinante(l, c, mat_2, ct_m2); // Calcula o determinante da matriz 2
                              printf("\n======================================\n");
                              printf("\033[38;5;201m[Matriz 2]\033[0m");
                              printf("\n--------------------------------------");
                              mostra_matriz(l, c, mat_2); // Mostra a matriz 2
                              printf("======================================\n");
                              printf("[Determinante da matriz[\033[38;5;201m2\033[0m]: %d]", dtmn);
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
                        limpa_tela(); // Limpa a tela
                        printf("\n======================================\n");
                        printf("\033[38;5;39m[DIFERENÇAS ENTRE MATRIZES]\033[0m");
                        printf("\n======================================\n");
                        if (ct_m1 > 0 || ct_m2 > 0) { // Verifica se há dados nas matrizes
                          printf("\033[38;5;201m[Matriz 1]\033[0m");
                          printf("\n--------------------------------------");
                          mostra_matriz(l, c, mat_1); // Mostra a matriz 1
                          printf("======================================\n");
                          printf("\033[38;5;201m[Matriz 2]\033[0m");
                          printf("\n--------------------------------------");
                          mostra_matriz(l, c, mat_2); // Mostra a matriz 2
                          printf("======================================");
                          comp = 0; // Variável para verificar se há diferenças
                          for (i = 0; i < 3; i++) { // Loop para verificar as diferenças entre as matrizes
                            for (j = 0; j < 3; j++) {
                              if (mat_1[i][j] != mat_2[i][j]) { // Verifica se os valores das matrizes são diferentes
                                printf("\nPosição [\033[38;5;39m%d\033[0m][\033[38;5;196m%d\033[0m]: ", i, j);
                                comp = 1; // Se houver diferença, comp recebe 1
                                if (mat_1[i][j] != 0 && mat_2[i][j] != 0) { // Verifica se os valores são diferentes de 0
                                  printf("%d ≠ %d", mat_1[i][j], mat_2[i][j]);
                                }  
                                  else if (mat_1[i][j] != 0 && mat_2[i][j] == 0) { // Verifica se o 1º valor é diferente de 0 e o 2º é 0
                                    printf("%d ≠ ∅", mat_1[i][j]);
                                  }
                                    else if (mat_1[i][j] == 0 && mat_2[i][j] != 0) { // Verifica se o 1º valor é 0 e o 2º é diferente de 0
                                      printf("∅ ≠ %d", mat_2[i][j]);
                                    }
                              }
                            }
                          }
                          if (comp == 1) { // Verifica se há valores diferentes
                            printf("\n======================================\n");
                            printf("\033[38;5;220m[*∅ = Vazio]\033[0m");
                          }
                            else { // Se não houver valores diferentes
                              printf("\n\033[38;5;220m[matriz[1] = matriz[2]!]\033[0m");
                            }
                          printf("\n======================================\n");
                        }
                          else {
                            printf("\033[38;5;220m[As matrizes não possuem dados!]\033[0m");
                            printf("\n--------------------------------------\n");
                            printf("[Logo, matriz[1] = matriz[2],");
                            printf("\npois não há dados diferentes!]");
                            printf("\n======================================\n");
                          }
                      }
  
                        else if (op == 10) { // |IGUALDADES ENTRE MATRIZES|
                          limpa_tela(); // Limpa a tela
                          printf("\n======================================\n");
                          printf("\033[38;5;39m[IGUALDADES ENTRE MATRIZES]\033[0m");
                          printf("\n======================================\n");
                          if (ct_m1 > 0 || ct_m2 > 0) { // Verifica se há dados nas matrizes
                            printf("\033[38;5;201m[Matriz 1]\033[0m");
                            printf("\n--------------------------------------");
                            mostra_matriz(l, c, mat_1); // Mostra a matriz 1
                            printf("======================================\n");
                            printf("\033[38;5;201m[Matriz 2]\033[0m");
                            printf("\n--------------------------------------");
                            mostra_matriz(l, c, mat_2); // Mostra a matriz 2
                            printf("======================================");
                            comp = 0; // Variável para verificar se há igualdades
                            for (i = 0; i < 3; i++) { // Loop para verificar a igualdade
                              for (j = 0; j < 3; j++) {
                                if (mat_1[i][j] == mat_2[i][j]) { // Verifica se os valores das matrizes são iguais
                                  printf("\nPosição [\033[38;5;39m%d\033[0m][\033[38;5;196m%d\033[0m]: ", i, j);
                                  comp = 1; // Se houver igualdade, comp recebe 1
                                  if (mat_1[i][j] != 0) { // Verifica se o valor da matriz é diferente de 0
                                    printf("%d = %d", mat_1[i][j], mat_2[i][j]);
                                  }
                                    else if (mat_1[i][j] == 0) { // Verifica se o valor da matriz é igual a 0
                                      printf("∅ = ∅");
                                    }
                                }
                              }
                            }
                            if (comp == 1) { // Verifica se há valores iguais
                              printf("\n======================================\n");
                              printf("\033[38;5;220m[*∅ = Vazio]\033[0m");
                            }
                              else { // Se não houver valores iguais
                                printf("\n\033[38;5;220m[matriz[1] ≠ matriz[2]!]\033[0m");
                              }
                            printf("\n======================================\n");
                          }
                            else {
                              printf("\033[38;5;220m[As matrizes não possuem dados!]\033[0m");
                              printf("\n--------------------------------------\n");
                              printf("[Logo, matriz[1] = matriz[2],");
                              printf("\npois não há dados diferentes!]");
                              printf("\n======================================\n");
                            }
                        }     
  
                          else { // |MENSAGEM DE ERRO|
                            printf("\n\033[38;5;196m[FATAL ERROR! Opção inválida!]\033[0m\n");
                          }
  } while (loop_m); // Fim do loop do menu
  return 0;
}