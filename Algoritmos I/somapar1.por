/*Data: 31/08/2023
 * Matrícula: 32311BSI013
 * Descrição do problema:
 * 11) – Faça um programa que receba 10 números, calcule e mostre a soma dos números pares*/
programa
{
	
	funcao inicio()
	{inteiro n, s = 0, i = 1
	para(i = 1; i <= 10; i++)
	{
		escreva("Digite um número par: ")
		leia(n)
			se (n % 2 == 0)
			{
			s = s + n
			}
	}
	escreva("A soma dos números pares é: ", s)
}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 318; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */