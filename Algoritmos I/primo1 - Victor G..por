/*/*Nome: Victor Gabriel Barbosa; 
 * Data: 29/08/2023
 * Descrição do problema: 
 * Faça um programa que receba um número inteiro maior que 1, verifique se o número fornecido é primo ou nãoe mostre uma mensagem 
 * de número primo ou de número não primo.
 * OBS.: Um número é primo quando ele é divisivel apenas por 1 e por ele mesmo"
Programa que verifica se um número é primo ou não*/
programa
{
	
	funcao inicio()
	{inteiro n, i = 1, i2 = 0
	faca
	{
	escreva("Digite um número maior do que 1: ")
	leia(n)
		se(n < 1)
		{
		escreva("Erro! O valor digitado é menor que 1", "\n")
		}
	}enquanto(n < 1)
	enquanto(i <= n)
	{
		se(n % i == 0)
		{
		i2++
		}
	i++
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
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 640; 
 * @DOBRAMENTO-CODIGO = [0];
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */