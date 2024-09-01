/*Matrícula: 32311BSI013
 * Nome: Victor Gabriel Barbosa
 * 03) - Crie um programa que preencha uma matriz nxn com números inteiros e diga se esta matriz é
simétrica ou não. Uma matriz é simétrica se para todo i, j: A[i,j] = A[j,i]*/
programa
{
	
	funcao inicio()
	{inteiro mat[4][3], met[3][4], i, j, l = 4, w = 3, x = 0, y
	para(i = 0; i < l; i++)
	{
		para(j = 0; j < w; j++)
		{
			escreva("Digite um número: ")
			leia(mat[i][j])
			met[j][i] = mat[i][j]
				se(mat[i][j] == met[j][i])
				{
				x++ 
				}
		}
	}
	se(x == l*w)
	{
	escreva("A matriz é simétrica!")
	}
		senao
		{
		escreva("A matriz não é simétrica!")
		}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 445; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {mat, 9, 10, 3}-{x, 9, 52, 1}-{met, 9, 21, 3};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */