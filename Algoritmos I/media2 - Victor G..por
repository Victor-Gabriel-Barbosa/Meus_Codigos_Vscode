/*Nome: Victor Gabriel Barbosa
 * Data: 31/08/2023
 * Matrícula: 32311BSI013
 * 6) Faça um programa que receba n números, calcule e mostre a média aritmética entre eles. */
programa
{
	
	funcao inicio()
	{inteiro g, n, s = 0, x = 0
	escreva("Digite quantos números você quer somar: ")
	leia(g)
	enquanto(g != 0)
	{
	escreva("Digite um número: ")
	leia(n)
	s = n + s
	x++
	g--
	}
	s = s/x
	escreva("A média aritmética é: ", s)
}
}

/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 351; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */