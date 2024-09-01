/*Nome: Victor Gabriel Barbosa
 * Matrícula: 32311BSI013
 * Descrição:
 * 1)- Faça um programa que receba uma frase, calcule e mostre a quantidade de vogais da frase 
digitada. (Considerar vogais maiúsculas e minúsculas)*/
programa
{
	inclua biblioteca Texto
	funcao inicio()
	{cadeia a
	caracter c
	inteiro n, v = 0
		escreva("Digite uma palavra: ")
		leia(a)
		n = Texto.numero_caracteres(a)
		para(inteiro i = 0; i < n; i++)
		{
		c = Texto.obter_caracter(a, i)
			se(c == 'a' ou c == 'e' ou c == 'i' ou c == 'o' ou c == 'u' ou c == 'A' ou c == 'E' ou c == 'I' ou c == 'O' ou c == 'U')
			{
			v++	
			}
		}
		escreva("A quantidade de vogais na frase é: ", v)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 667; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */