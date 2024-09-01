/*Matrícula: 32311BSI013
 * Nome: Victor Gabriel Barbosa
 * Atividade proposta:
 * 03) - Faça um algoritmo para ler um vetor de 30 números. Após isto, ler mais um número qualquer,
calcular e escrever quantas vezes esse número aparece no vetor*/
programa
{
	
	funcao inicio()
	{inteiro vet[30], x, i, n, w = 0
	para(i = 0; i < 30; i++)
	{
	escreva("Digite um número qualquer: ")
	leia(n)
	vet[i] = n
	}
	escreva("Digite um outro número qualquer: ")
	leia(x)
	para(i = 0; i < 30; i++)
	{
		se(x == vet[i])
		{
		w++
		}
	}
	escreva("O número ", x, " aparece ", w, " vezes no vetor")
	}
}

/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 398; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */