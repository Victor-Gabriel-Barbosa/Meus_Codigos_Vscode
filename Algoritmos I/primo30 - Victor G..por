/*/*Nome: Victor Gabriel Barbosa; 
 * Data: 29/08/2023
 * Descrição do problema: 
 * Faça um programa que receba um número inteiro maior que 1, verifique se o número fornecido é primo ou nãoe mostre uma mensagem 
 * de número primo ou de número não primo.
 * OBS.: Um número é primo quando ele é divisivel apenas por 1 e por ele mesmo"
Programa que verifica se um número é primo ou não*/
programa
{
	inclua biblioteca Matematica
	
	funcao inicio()
	{inteiro n, i = 1, i2 = 0, y = 1
	para(y = 1; y <= 30; y++)
	{
	escreva("Digite um número maior do que 1: ")
	leia(n)
	se (n > 1)
	{
	enquanto(i <= n)
	{
	se(n % i == 0)
	{
	i2 = i2 + 1
	}
	i = i + 1
	}
	se(i2 == 2)
	{
	escreva("O número ", n, " é primo", "\n")
	}
	senao
	{
	escreva("O número ", n, " nãe é primo", "\n")
	}
	}
	senao
	{
	escreva("Erro! Valor menor ou igual a 1", "\n")
	}
	i = 1
	i2 = 0
	}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 720; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */