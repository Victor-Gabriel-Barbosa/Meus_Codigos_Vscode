/*Matrícula: 32311BSI013
 * Nome: Victor Gabriel Barbosa
 * Atividade proposta:
 * 06) - Faça um programa que preencha um vetor com 10 números inteiros, calcule e mostre os
números maiores que 50 e suas posições. O programa deve mostra uma mensagem de erro se não
existir nenhum número nessa condição*/
programa
{
	
	funcao inicio()
	{inteiro vet[10], i, n = 0, x = 0, y = -1
	para(i = 0; i < 10; i++)
	{
		escreva("Digite um número qualquer: ")
		leia(n) 
		vet[i] = n
	}
	para(i = 0; i < 10; i++)
	{
		x++ 
		se(vet[i] > 50)
		{
		escreva("O número: ", vet[i], " é maior que 50, na posição: ", x, "\n")
		}
			senao
			{
			y++
			se(y == 10)
			{
			escreva("Erro!")
			}
		}
	}
	}
}

/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 526; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */