programa
{
	
	funcao inicio()
	{inteiro n, c, s = 0
		escreva("Digite um número: ")
		leia(n)
		para(c = 1; c <=10; c += 1)
		{
			escreva("Mais: ")
			leia(n)
			s = s + n
			escreva("Resultado preliminar:", s, "\n")
		}
		escreva("O resultado da soma é:", s)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 92; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */