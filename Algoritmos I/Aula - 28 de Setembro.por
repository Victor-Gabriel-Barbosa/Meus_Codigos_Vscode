programa
{
	inclua biblioteca Texto
	inclua biblioteca Tipos
	funcao inicio()
	{cadeia a = "abAcaxi", c, d, j, p, m = "B" /*Aspas simples: " "*/
	caracter b, l /*Aspas duplas: ' '*/
	inteiro f, q
		a = Texto.caixa_alta(a)
		escreva("a = ", a, "\n")
			a = Texto.caixa_baixa(a)
			escreva("b = ", a, "\n")
				c = Texto.extrair_subtexto(a, 0, 5)
				escreva("c = ", c, "\n")
					q = Texto.numero_caracteres(a)
					escreva("d = ", q, "\n")
						b = Texto.obter_caracter(a, 6)
						escreva("e = ", b, "\n")
							f = Texto.posicao_texto("aba", a, 0)
							escreva("f = ", f, "\n")
								j = Texto.preencher_a_esquerda('X', 8, a)
								escreva("g = ", j, "\n")
									p = Texto.substituir(a, "A", "O")
									escreva("h = ", p, "\n")
	l = Tipos.cadeia_para_caracter(m)
	escreva("i = ", l, "\n")
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 793; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */