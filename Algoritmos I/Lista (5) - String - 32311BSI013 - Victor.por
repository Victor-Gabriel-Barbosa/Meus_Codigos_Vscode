/*Nome: Victor Gabriel Barbosa
 * Matrícula: 32311BSI013
 * Descrição:
 * 5)- Faça um programa que receba uma frase e conte quantas palavras terminam em vogal. */
programa
{
	inclua biblioteca Texto
	funcao inicio()
	{cadeia a
	caracter c
	inteiro n, f = 1, v = 0, w
		escreva("Digite uma frase: ")
		leia(a)
		n = Texto.numero_caracteres(a)
		para(inteiro i = 0; i < n; i++)
		{
		c = Texto.obter_caracter(a, i)
		se(c == ' ')
		{
		w = i - 1
		c = Texto.obter_caracter(a, w)
		se(c == 'a')
		{
		v++	
		}
		senao se(c == 'e')
		{
		v++	
		}
		senao se(c == 'i')
		{
		v++	
		}
		senao se(c == 'o')
		{
		v++	
		}
		}
		}
		escreva("A quantidade de palavras na frase que terminam com vogal é: ", v)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 502; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */