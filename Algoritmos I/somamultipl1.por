/*Nome: Victor Gabriel Barbosa
 * Data: 31/08/2023
 * Matrícula: 32311BSI013
 * Faça um programa que receba 2 números do usuário, calcule e mostre o resultado da
multiplicação entre eles. Obs.: O programa deve ser feito sem o uso do operador "*"*/
programa
{
	
	funcao inicio()
	{inteiro n1, n2, s = 0
		escreva("Digite dois números inteiros: ")
		leia(n1, n2)
		enquanto(n2 >= 1)
		{
		s = n1 + s
		n2 = n2 - 1
		}
		escreva("A resposta é: ", s)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 263; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */