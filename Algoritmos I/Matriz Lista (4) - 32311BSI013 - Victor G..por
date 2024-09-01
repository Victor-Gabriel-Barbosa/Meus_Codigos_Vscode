/*Matrícula: 32311BSI013
 * Nome: Victor Gabriel Barbosa
 * Descrição:
 * 4) - Faça um programa que preencha uma matriz 7x7 de inteiros e crie dois vetores com 7 posições
cada, e que contenham, respectivamente, o maior e o menor elemento de cada uma das linhas.
Apresente os vetores gerados.*/
programa
{
	
	funcao inicio()
	{inteiro mat[7][4], vet[7], get[7], i, j, l = 2, c = 4, x = 0
	para(i = 0; i < l; i++)
	{
		para(j = 0; j < c; j++)
		{
		escreva("Digite um número: ")
		leia(mat[i][j])
		vet[i] = mat[i][j] + 1
		get[i] = mat[i][j] - 1 
		}
	}
	para(i = 0; i < l; i++)
	{
		para(j = 0; j < c; j++)
		{
			se(mat[i][j] > get[i])
			{
			get[i] = mat[i][j]
			}
				se(mat[i][j] < vet[i])
				{
				vet[i] = mat[i][j]
				}
		}
	}
	para(i = 0; i < l; i++)
	{
	escreva("O menor número da linha: ", x++, " é o número: ", vet[i], "\n")
	escreva("O maior número da linha: ", x, " é o número: ", get[i], "\n")
	}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 762; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {mat, 11, 10, 3};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */