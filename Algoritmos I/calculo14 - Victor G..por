/*Nome: Victor Gabriel Barbosa
 * Data: 31/08/2023
 * Matrícula: 32311BSI013
 * Descrição do problema: 
 * Faça um programa que receba n números, calcule e mostre:
a) Soma dos números 
b) Média Aritmética
c) Menor valor digitado
d) Quantidade de números que foram digitados 
Obs.: A entrada de dados deve ser finalizada quando o usuário informar o número 0*/
programa
{
	
	funcao inicio()
	{real n, s = 0.0, m = 0.0, x = 0.0, menor_n = 999999999.0
	faca	{
		escreva("Digite um número para fazer as operações, se o número for '0' a operação irá parar: ")
		leia(n)
		s = s+n
		se (n != 0)
		{
			se (n < menor_n)
			{
				menor_n = n
			}
		x++
		}
	}enquanto(n != 0)
	m = s/x
	escreva("A soma dos números é: ", s, "\n")
	escreva("A média aritmética dos números é: ", m, "\n")
	escreva("O menor número é: ", menor_n, "\n")
	escreva("A quantidade de números digitados é: ", x)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 747; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */