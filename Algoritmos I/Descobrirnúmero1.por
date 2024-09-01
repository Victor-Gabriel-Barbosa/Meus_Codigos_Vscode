/*Programa de tentativa de descobrir um número qualquer
 * O jogador escolhe um número aleatório e, se o número estiver correto ele acerta*/
programa
{
	
	funcao inicio()
	{inteiro n
		escreva("Digite um número entre 0 e 50: ")
		leia(n)
		se(n >= 1 e n <= 50)
		{
		enquanto (n!=26)
		{
			escreva("Que pena, você errou, tente outro número: ")
			leia(n)
		}
		escreva("Parabéns, você acertou!!")
		}
		senao escreva ("Você é desprovido de inteligência, não tem a capacidade de interpretar esse simples programa!!")
		}
}

/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 393; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */