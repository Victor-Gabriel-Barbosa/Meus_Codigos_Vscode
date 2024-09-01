/*Calculadora que opera com funções de soma, subtração, multiplicação e divisão
O programa pede a operação a ser realizada e, a partir dela pergunta qual o primeiro número (a) e o segundo número (b).
Por fim, o programa calcula e mostra o resultado da operação desejada*/
programa
{
	
	funcao inicio()
	{real a, b, s /*a - número 1, b - número 2, s - variável*/
	caracter op /*op - operação (soma/subtração/multiplicação/divisão)*/
	
		escreva("Digite a operação: ")
		leia(op)
		se (op == '+')
		{
		escreva("Digite o primeiro número: ")
		leia(a)
		escreva("Digite o segundo número: ")
		leia(b)
		s = (a + b)
		escreva("O resultado é: ", s)
		}
		senao se (op == '-')
		{
		escreva("Digite o primeiro número: ")
		leia(a)
		escreva("Digite o segundo número: ")
		leia(b)
		s = (a - b)
		escreva("O resultado é: ", s)
		} 
		senao se (op == '*')
		{
			escreva("Digite o primeiro número: ")
		leia(a)
		escreva("Digite o segundo número: ")
		leia(b)
		s = (a * b)
		escreva("O resultado é: ", s)
		}
		senao se (op == '/')
		{
		escreva("Digite o primeiro número: ")
		leia(a)
		escreva("Digite o segundo número: ")
		leia(b)
		se (b != 0)
		{s = (a / b)
		escreva("O resultado é: 9", s)}
		senao escreva("ERRO, digite um divisor diferente de 0")
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 902; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */