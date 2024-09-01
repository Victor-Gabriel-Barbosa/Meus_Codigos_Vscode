/*Matrícula: 32311BSI013
 * Nome: Victor Gabriel Barbosa
 * Descrição:
 * 06) - Faça um programa que preencha uma matriz 6 x 3, calcule e mostre:
a) o maior elemento e sua posição 
b) o menor elemento e sua posição*/
programa
{
	
	funcao inicio()
	{inteiro mat[3][3], i, j, l = 3, c = 3, x = 0, vet[10], get[10], x, y
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
			x = i
			}
				se(mat[i][j] < vet[i])
				{
				vet[i] = mat[i][j]
				y = i
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
 * @POSICAO-CURSOR = 715; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {mat, 11, 10, 3};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */