/*Matrícula: 32311BSI013
 * Nome: Victor Gabriel Barbosa
 * Descrição:
 * 05) - Faça um programa que preencha uma matriz 3 x 5, calcule e mostre a quantidade de elementos
entre 15 e 30.*/
programa
{
	
	funcao inicio()
	{inteiro mat[3][5], i, j, l = 3, c = 5, x = 0
	para(i = 0; i < l; i++)
	{
		para(j = 0; j < c; j++)
		{
		escreva("Digite um número: ")
		leia(mat[i][j])
			se(mat[i][j] > 15 e mat[i][j] <=30) 
			{
			x++
			}
		}
	}
	escreva("A quantidade de números entre 15 e 30 é: ", x)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 436; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {mat, 10, 10, 3};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */