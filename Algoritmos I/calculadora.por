programa
{
	
	funcao inicio()
	{real n1, n2, s = 0.0 
	caracter fim, op
	faca
	{
		escreva("Digite um número, a operação e outro número: ")
		leia(n1, op, n2)
		se (op == '+')
		{
			s = s + n1 + n2
		}
		senao se (op == '-')
		{
			s = s - n1 - n2
		}
		senao se (op == '*')
		{
			se(s == 0.0)
			{
			s = n1 * n2	
			}
			senao
			{
			s = s * n1 * n2
			}
		}
		senao se (op == '/')
		{
			se(s == 0.0)
			{
			se(n2 == 0.0)
			{
				escreva("ERRO! Divisor igual a 0! Digite um divisor diferente de 0!!")
			}
			senao
			{
				s = n1 / n2
			}
			}
			senao
			{
			se(n2 == 0.0)
			{
				escreva("ERRO! Divisor igual a 0! Digite um divisor diferente de 0!!")
			}	
			senao 
			{
				s = s / n1 / n2
			}
			}
		}
		escreva("O resultado por enquanto é: ", s, "\n")
		escreva("Se deseja parar agora digite '=', senão aperte qualquer tecla: " )
		leia(fim)
	} enquanto (fim != '=')
	escreva("O resultador é: ", s)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 917; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */