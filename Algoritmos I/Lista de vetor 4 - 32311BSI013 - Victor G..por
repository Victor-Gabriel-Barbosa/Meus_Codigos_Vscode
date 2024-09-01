/*Matrícula: 32311BSI013
 * Nome: Victor Gabriel Barbosa
 * Atividade proposta:
 * 4) - Escreva um algoritmo que, dado um vetor de números e um número, retornar quantos números
no vetor são maiores que o número dado como entrada.*/
programa
{
	
	funcao inicio()
	{inteiro vet[10], i, n, x = 0
	para(i = 0; i < 10; i++)
	{
	escreva("Digite um número para ser armazenado no vetor: ")
	leia(n)
	vet[i] = n
	}
	escreva("Digite um outro número a ser comparado com os números do vetor: ")
	leia(n)
	para(i = 0; i < 10; i++)
	{
	se(vet[i] > n)
		{
		x++
		}
	}
	escreva("A quantidade de números maiores do que ", n, " são: ", x)
	}
}

/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 540; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */