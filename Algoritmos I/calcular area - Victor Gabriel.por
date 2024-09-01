programa
{
	inclua biblioteca Matematica
	
	funcao inicio()
	{real o, n, l, s, b, h, x
	inteiro numero
	escreva("Digite qual área será calculada: 1 - Quadrado, 2 - Retângulo, 3 - Circunferência, 4 - Triângulo: ")
	leia(numero)
	escolha(numero)
	{
	caso 1:
		escreva("Digite o valor do lado: ")
			leia(l)
			s = l * l
			escreva("A área do quadrado é:", s)
	pare
	caso 2:
		escreva("Digite o valor da base e da altura: ")
			leia(b, h)
			s = b * h
			escreva("A área do retângulo é:", s)
	pare
	caso 3:
		escreva("Digite o valor do raio: ")
			leia(o)
			x = Matematica.potencia(o, 2.0)
			s = Matematica.PI * x
			escreva("A área da circunferência é:", s)
	pare
	caso 4:
		escreva("Digite o valor da base e da altura: ")
			leia(b, h)
			s = (b * h) / 2
			escreva("A área do triângulo é:", s)
	pare
	}
}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 210; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */