/*Nome: Victor Gabriel Barbosa
 * Matrícula: 32311BSI013
 * Descrição:
 * 2)- Faça um programa que receba uma frase e mostre a quantidade de palavras da frase.*/
programa
{
	inclua biblioteca Texto
	funcao inicio()
	{cadeia a
	caracter c
	inteiro n, f = 1
		escreva("Digite uma frase: ")
		leia(a)
		n = Texto.numero_caracteres(a)
		para(inteiro i = 0; i < n; i++)
		{
		c = Texto.obter_caracter(a, i)
		se(c == ' ')
		{
		f++
		}
		}
		escreva("A quantidade de palavras na frase é: ", f)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 255; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */