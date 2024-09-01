/*Ordenador que pede três números e ordena em ordem crescente*/
programa
{
	
	funcao inicio()
	{inteiro a, b, c /*a - primeiro número, b - segundo número, c - terceiro número*/
		escreva("Digite o primeiro número: ")
		leia(a)
		escreva("Digite o primeiro número: ")
		leia(b)
		escreva("Digite o primeiro número: ")
		leia(c)
		se ((a <= b) e (b <= c))
		{
			escreva(a, ", ", b,", ", c)
		}
		senao se ((a <= c) e (c <= b))
		{
			escreva(a, ", ", c, ", ", b)
		}
		senao se ((b <= a) e (a <= c))
		{
			escreva(b, ", ", a, ", ", c)
		}
		senao se ((b <= c) e (c <= a))
		{
			escreva(b, ", ", c, ", ", a)
		}
		senao se ((c <= a) e (a <= b))
		{
			escreva(c, ", ", a, ", ", b)
		}
		senao se ((c <= b) e (b <= a))
		{
			escreva(c, ", ", b, ", ", a)
		}

	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 181; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */