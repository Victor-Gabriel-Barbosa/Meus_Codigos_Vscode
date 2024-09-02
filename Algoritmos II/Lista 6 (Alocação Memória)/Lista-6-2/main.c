/* 2 - Codifique, compile e execute um programa em C que declare na função
principal uma estrutura para o cadastro de alunos de uma academia. 
a) Para cada aluno armazenar: nome, sobrenome (apenas um), ano de nascimento e 
um ponteiro para um vetor de 6 posições indicando quais dias da semana o aluno 
frequenta a academia. Lembrando que a academia funciona de segunda a sábado; 
b) Ao iniciar o programa, o usuário deverá informar o número de alunos que serão 
armazenados; 
c) O programa deverá alocar dinamicamente a quantidade necessária de memória para
armazenar os registros dos alunos; 
d) O programa deverá pedir ao usuário que
entre com as informações dos alunos; 
e) Ao final, o programa deve exibir na tela
os dados armazenados e liberar a memória alocada */

#include <stdio.h>
#include <stdlib.h>

typedef struct alunos { // Estrutura para armazenar os dados dos alunos
  char nome[100], sobrenome[100];
  int ano, *sem;
} alun;

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

int main(void) {
  int tam, i, j;
  char semana_aux[6][10] = {"Segunda", "Terça", "Quarta", "Quinta",  "Sexta", "Sábado"};
  do { // [VALIDAÇÃO DO NÚMERO DE ALUNOS]
    limpa_tela();
    tam = -1;
    printf("Digite o número de alunos: ");
    scanf("%d", &tam);
    limpa_buffer();
    if (tam < 1) {
      printf("\n\033[38;5;196mNúmero inválido!\033[0m\n");
    }
  } while (tam < 1);
  alun *al = (alun *)calloc(tam, sizeof(alun));
  for (i = 0; i < tam; i++) { // [ARMAZENAMENTO DOS DADOS]
    limpa_tela();
    printf("Digite o nome do(a) aluno(a) %d: ", i + 1);
    scanf("%99[^\n]", al[i].nome);
    limpa_buffer();
    printf("Digite o sobrenome do(a) aluno(a) %d: ", i + 1);
    scanf("%99[^\n]", al[i].sobrenome);
    limpa_buffer();
    printf("Digite o ano de nascimento do aluno(a) %d: ", i + 1);
    scanf("%d", &al[i].ano);
    limpa_buffer();
    al[i].sem = (int *)calloc(6, sizeof(int));
    for (j = 0; j < 6; j++) { // [ARMAZENAMENTO DOS DIAS DA SEMANA]
      do { // [VALIDAÇÃO DOS DIAS DA SEMANA]
        limpa_tela();
        printf("\nO(A) aluno(a) frequenta a aula de %s? \n[1 - Sim | 0 - Não]: ", semana_aux[j]);
        scanf("%d", &al[i].sem[j]);
        limpa_buffer();
        if (al[i].sem[j] != 1 && al[i].sem[j] != 0) { // [VALIDAÇÃO DOS DIAS DA SEMANA]
          printf("\n\033[38;5;196mOpção inválida!\033[0m\n");
        }
      } while (al[i].sem[j] != 1 && al[i].sem[j] != 0);
    }
  }
  for (i = 0; i < tam; i++) { // [EXIBIÇÃO DOS DADOS]
    printf("\n\nAluno(a) %d: %s %s", i + 1, al[i].nome, al[i].sobrenome);
    printf("\nAno de nascimento: %d", al[i].ano);
    printf("\nO(A) aluno(a) frequenta as aulas de: ");
    for (j = 0; j < 6; j++) { // [EXIBIÇÃO DOS DIAS DA SEMANA]
      if (al[i].sem[j] == 1) {
        printf("|%s|", semana_aux[j]);
      }
    }
  }
  for (i = 0; i < tam; i++) { // [LIBERAÇÃO DA MEMÓRIA]
    free(al[i].sem);
  }
  free(al); // [LIBERAÇÃO DA MEMÓRIA]
  return 0;
}