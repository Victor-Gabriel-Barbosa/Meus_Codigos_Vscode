/*Nome: Victor Gabriel Barbosa
 * Matrícula: 32311BSI013
 * Descrição:
 * 4)- Faça um programa para criptografar uma frase dada pelo usuário (a criptografia troca as vogais 
por "*" */
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
		a = Texto.substituir(a, "a", "*")
		a = Texto.substituir(a, "A", "*")
		}
		senao se((c == 'e') ou (c == 'E'))
		{
		a = Texto.substituir(a, "e", "*")
		a = Texto.substituir(a, "E", "*")
		}
		senao se((c == 'i') ou (c == 'I'))
		{
		a = Texto.substituir(a, "i", "*")
		a = Texto.substituir(a, "I", "*")
		}
		senao se((c == 'o') ou (c == 'O'))
		{
		a = Texto.substituir(a, "o", "*")
		a = Texto.substituir(a, "O", "*")
		}
		senao se((c == 'u') ou (c == 'U'))
		{
		a = Texto.substituir(a, "u", "*")
		a = Texto.substituir(a, "U", "*")
		}
		}
		escreva("A frase criptografada é: ", a)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 1016; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */