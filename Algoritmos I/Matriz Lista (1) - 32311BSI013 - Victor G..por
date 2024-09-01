/*Matrícula: 32311BSI013
 * Nome: Victor Gabriel Barbosa
 * Descrição do problema:
 * 01) - Crie um programa que preencha uma matriz 10 x 20 com números inteiros e some cada uma
das linhas, armazenando o resultado das somas em um vetor. A seguir, o programa deverá
multiplicar cada elemento da matriz pela soma da sua linha correspondente e mostrar na matriz
resultante.
 */
programa
{
	
	funcao inicio()
	{inteiro mat[10][20], i, j, z, vet[10], l = 10, w = 20, s = 0, k = 0, cat[10][20]
	para(i = 0; i < l; i++)
	{
		para(j = 0; j < w; j++)
		{
		escreva("Digite um número: ")
		leia(mat[i][j])
		vet[i] = mat[i][j] + vet[i]
		}
	}
	para(z = 0; z < 2; z++)
	{
		s = vet[z] 
	para(i = 0; i < l; i++)
	{
		escreva("\n")
		para(j = 0; j < w; j++)
		{
		cat[i][j] = mat[i][j] * s
		escreva(cat[i][j], " ")
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
 * @POSICAO-CURSOR = 541; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {mat, 13, 10, 3}-{vet, 13, 32, 3}-{k, 13, 64, 1};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */