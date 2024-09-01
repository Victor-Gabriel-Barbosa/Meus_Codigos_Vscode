/*Nome: Victor Gabriel Barbosa
 * Data: 31/08/2023
 * Matrícula: 32311BSI013
 * 5) Faça um programa que receba 20 números, calcule e mostre a média aritmética entre eles.*/
programa
{
	
	funcao inicio()
	{inteiro n, s = 0, x = 0
	para(inteiro I = 1; I <= 20; I++)
	{
	escreva("Digite um número: ")
	leia(n)
	s = n + s
	x++
	}
	s = s/x
	escreva("A média ar5itmética é: ", s)
}
}

/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 328; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */