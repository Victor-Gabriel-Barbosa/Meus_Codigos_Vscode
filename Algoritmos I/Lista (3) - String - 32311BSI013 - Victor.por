/*Nome: Victor Gabriel Barbosa
 * Matrícula: 32311BSI013
 * Descrição:
 * 3)- Faça um programa que receba uma frase e mostre a quantidade de vogais e a quantidade de 
consoantes da frase. (Considerar maiúsculas e minúsculas)*/
programa
{
	inclua biblioteca Texto
	funcao inicio()
	{cadeia a
	caracter c
	inteiro n, v = 0, s = 0
		escreva("Digite uma palavra: ")
		leia(a)
		n = Texto.numero_caracteres(a)
		para(inteiro i = 0; i < n; i++)
		{
		c = Texto.obter_caracter(a, i)
		se((c == 'a') ou (c == 'A'))
		{
		v++	
		}
		senao se((c == 'e') ou (c == 'E'))
		{
		v++	
		}
		senao se((c == 'i') ou (c == 'I'))
		{
		v++	
		}
		senao se((c == 'o') ou (c == 'O'))
		{
		v++	
		}
		senao se((c == 'u') ou (c == 'U'))
		{
		v++	
		}
		senao
		{
		s++
		}
		}
		escreva("A quantidade de vogais na frase é: ", v, "\n")
		escreva("A quantidade de consoantes na frase é: ", s)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 729; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */