/*Nome: Victor Gabriel Barbosa
 * Matrícula: 32311BSI013
 * Descrição:
 * 6)- Faça um programa que receba uma frase e um caractere e retorne quantas vezes este caracter 
aparece na frase*/
programa
{
	inclua biblioteca Texto
	funcao inicio()
	{cadeia a
	caracter c, o
	inteiro n, v = 0
		escreva("Digite uma palavra: ")
		leia(a)
		escreva("Digite um caracter qualquer: ")
		leia(o)
		n = Texto.numero_caracteres(a)
		para(inteiro i = 0; i < n; i++)
		{
		c = Texto.obter_caracter(a, i)
		se(c == o)
		{
		v++	
		}
		}
		escreva("A quantidade de vezes que o caracter: ", o, " aparece na frase é: ", v)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 604; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */