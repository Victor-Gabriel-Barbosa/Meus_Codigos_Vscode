#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define x 100
void main()
{
setlocale(LC_ALL, "Portuguese");
int i;
struct medico{
    int cod_med, fone_m;
    char nome_m[x], endere�o_m[x];
};
struct medico med[3];

struct paciente{
    int cod_pac, fone_p;
    char nome_p[x], endere�o_p[x];
};
struct paciente pac[5];

struct consulta{
    int num_consulta, hora;
    char dia_s[x];
};
struct consulta cons;

for(i = 0; i < 5; i++){
    printf("Digite o seu c�digo: ");
    scanf("%d", pac[i].cod_pac);
    fflush(stdin);
    printf("Digite o seu n�mero de telefone: ");
    scanf("%d", pac[i].fone_p);
    fflush(stdin);
    printf("Digite o seu nome: ");
    fgets(pac[i].fone_p, x, stdin);
    fflush(stdin);
    printf("Digite o seu endere�o: ");
    fgets(pac[i].endere�o_p, x, stdin);
    fflush(stdin);
}
}
