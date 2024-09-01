/*Nome: Victor Gabriel Barbosa; 
 * Data: 29/08/2023
 * 
 * Descrição do problema:
 * Um funcionário de uma empresa recebe, anualmente, aumento salarial. Sabe-se que:
 * Esse funcionário foi contratado em 2005, com um salário inicial de R$1000,00.
 * Em 2006, ele recebeu um aumento de 1,5% sobre seu salário inicial;
 * A partir de 2007  (inclusive), os aumentos sempre corresponderam ao dobro do percentual do ano anterior.
 * Faça um programa que determine o salário atual desse funcionário.*/
programa
{
	
	funcao inicio()
	{real s = 1000.0, x = 1.5/100
	inteiro a
		escreva("Digite quantos anos esse funcionário irá trabalhar: ")
		leia(a)
		s = s + s * x
		para(inteiro i = 1; i <= a; i++)
		{
		x = x * 2
		s = s + s * x
		}
		escreva("O salário atual desse funcionário apos trabalhar por ", a, " anos é de R$", s)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 824; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */