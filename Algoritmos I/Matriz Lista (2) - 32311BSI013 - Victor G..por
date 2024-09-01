/*Matrícula: 32311BSI013
 * Nome: Victor Gabriel Barbosa
 * Descrição:
 * 02) - Crie um programa que preencha uma matriz 6 x 4 com números inteiros, maiores que 0,
calcule e mostre quantos elementos são maiores que 30 e monte uma matriz, apresentando os
números menores que 30 em suas posições originais e, 0 nas posições onde encontramos os valores
maiores que 30.*/
programa
{
	
	funcao inicio()
	{inteiro mat[6][4], l = 6, w = 4, i, j, x = 0
	para(i = 0; i < l; i++)
	{
		para(j = 0; j < w; j++)
		{
		faca
		{
		escreva("Digite um número maior que 0: ")
		leia(mat[i][j])
			se(mat[i][j] <= 0)
			{
			escreva("Erro! O número digitado é menor ou igual a 0", "\n")
			}
		}enquanto(mat[i][j] <= 0)
			se(mat[i][j] >= 30)
			{
			mat[i][j] = 0
			}
				senao
				{
				x++
				}
		}
		}
	escreva("A quantidade de números maiores que 30 é: ", x)
	para(i = 0; i < l; i++)
	{
	escreva("\n")
		para(j = 0; j < w; j++)
		{
			escreva(mat[i][j], " ")		
		}
	}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 871; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {mat, 12, 10, 3};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */