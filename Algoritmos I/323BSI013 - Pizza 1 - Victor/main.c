#include <stdio.h>
#include <string.h>
#include <locale.h>

#define x 100
void main()
{
setlocale(LC_ALL, "Portuguese");
int i;
typedef struct cliente{
    int num1, cep1;
    char nome1[x], comp[x], end[x];
};
struct cliente vetc[5];

typedef struct pizza{
    int cod1, val1;
    char nome2[x];
};
struct pizza vetz[3];

typedef struct pedido{
    int num2, num3, cod2, cod3, sit1;
};
struct pedido vetp[6];

do{
    for(i = 0; i < 3; i++){
        printf("\nEscreva o c�digo da pizza: ");
        scanf("%d", &vetz[i].cod1);
        fflush(stdin);
        printf("Escreva o nome da pizza: ");
        fgets(vetz[i].nome2, x, stdin);
        fflush(stdin);
        printf("Escreva o valor da pizza: ");
        scanf("%d", &vetz[i].val1);
        fflush(stdin);
    }
    for(i = 0; i < 5; i++){
        do{
        printf("\nEscreva o seu n�mero de telefone: ");
        scanf("%d", &vetc[i].num1);
        }while(vetc[i].num1 != vetc[i++].num1)
        fflush(stdin);
        printf("Escreva o seu nome: ");
        fgets(vetc[i].nome1, x, stdin);
        fflush(stdin);
        printf("Escreva seu endere�o: ");
        fgets(vetc[i].end, x, stdin);
        fflush(stdin);
        printf("Escreva o complemento: ");
        fgets(vetc[i].comp, x, stdin);
        fflush(stdin);
    }
    for(i = 0; i < 6; i++){
        printf("\nEscreva o n�mero do pedido: ");
        scanf("%d", &vetp[i].num2);
        fflush(stdin);
        printf("Escreva o seu n�mero de telefone: ");
        scanf("%d", &vetp[i].num3);
        fflush(stdin);
        printf("Escreva o c�digo da pizza: ");
        scanf("%d", &vetp[i].cod2);
        fflush(stdin);
        printf("Escreva o c�digo do motoqueiro: ");
        scanf("%d", &vetp[i].cod3);
        fflush(stdin);
        printf("Escreva a situa��o do seu pedido: (1 - Em preparo; 2 - A caminho; 3 - Entregue) ");
        scanf("%d", &vetp[i].sit1);
        fflush(stdin);
    }
}while()
}
