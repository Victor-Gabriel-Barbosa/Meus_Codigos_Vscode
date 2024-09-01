/*Matrícula: 32311BSI013
 * Nome: Victor Gabriel Barbosa
 * Atividade proposta:
 * 5) - Faça um programa que, dado um vetor com números inteiros, retornar outro vetor contendo
apenas aqueles números do vetor inicial que são primos.*/
programa
{
	
	funcao inicio()
	{inteiro vet[10], prim[10], i, n, x = 1, y = 0
		para(i = 0; i < 10; i++)
		{
			faca
			{
			escreva("Digite um número maior do que 1: ", "\n")
			leia(vet[i])
			n = vet[i]
				se(n < 1)
				{
				escreva("Erro! O número digitado é menor do que 1!")
				}
			}enquanto(vet[i] < 1)
				enquanto(x <= n)
				{
					se(n % x == 0)
					{
					y++
					}
				x++
				}
					se(y == 2)
					{
					prim[i] = n
					}	
		y = 0
		x = 1
		}
		para(i = 0; i < 10; i++)
		{
			se(prim[i] != 0)
			{
			escreva("O número: ", prim[i], " é primo", "\n")
			}
		}
	}
}

/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 552; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */