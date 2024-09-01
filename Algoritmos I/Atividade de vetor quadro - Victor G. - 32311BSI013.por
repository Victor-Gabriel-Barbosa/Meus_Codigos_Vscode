/*Matrícula: 32311BSI013
 * Nome: Victor Gabriel Barbosa
 * Atividade proposta:
 * Buscar um elemento no vetor e mostrar a posição.*/
programa
{
	
	funcao inicio()
	{inteiro vet[10], i, n
	para(i = 0; i < 10; i++)
	{
	escreva("Digite um número: ")
	leia(vet[i])
	}
	escreva("Digite um número do vetor que você deseja acessar: ")
	leia(n)
	para(i = 0; i < 10; i++)
	{
		se(vet[i] == n)
		{
		escreva("O elemento é o número: ", vet[i], " na posição: ", i)
		}
	}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 186; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */