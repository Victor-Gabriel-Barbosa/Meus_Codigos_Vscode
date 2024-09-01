programa
{
	inclua biblioteca Matematica
	
	funcao inicio()
	{real o, n, l, s, b, h, x
	caracter a
		escreva("Digite a área a ser calculada: ")
		leia(a)
		se (a == 'q')
		{
			escreva("Digite o valor do lado: ")
			leia(l)
			s = l * l
			escreva("A área do quadrado é:", s)
		}
		senao se (a == 'r')
		{
			escreva("Digite o valor da base e da altura: ")
			leia(b, h)
			s = b * h
			escreva("A área do retângulo é:", s)
		}
		senao se (a == 'c')
		{
			escreva("Digite o valor do raio: ")
			leia(o)
			x = Matematica.potencia(o, 2)
			s = Matematica.PI * x
			escreva("A área da circunferência é:", s)
		}
		senao se (a == 't')
		{
			escreva("Digite o valor da base e da altura: ")
			leia(b, h)
			s = (b * h) / 2
			escreva("A área do triângulo é:", s)
		}
		
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 483; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */