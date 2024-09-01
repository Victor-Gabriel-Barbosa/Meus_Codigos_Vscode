/*Matrícula: 32311BSI013
 * Nome: Victor Gabriel Barbosa
 * Descrição:
 * 07) Elabore um programa que preencha uma matriz 10x10 e execute as trocas abaixo, mostre a
matriz inicial e a resultante no fim. linha 2 com linha 8, coluna 4 com coluna 10, diagonal principal
com diagonal secundária, linha 5 com coluna 10 08) Crie um programa, que dada uma matriz
quadrada, verifique se ela é simétrica ( M[l,c] = M[c,l] */
programa
{
	
	funcao inicio()
	{inteiro mat_inicial[10][10], mat_final[10][10], i, j, l = 10, c = 10
	para(i = 0; i < l; i++)
	{
		para(j = 0; j < c; j++)
		{
		escreva("Digite um número: ")
		leia(mat_inicial[i][j])
		}
	}
	para(i = 0; i < l; i++)
	{escreva("\n")
		para(j = 0; j < c; j++)
		{
		escreva(mat_inicial[i][j], " ")
		}
	}
	para(i = 0; i < l; i++)
	{escreva("\n")
		para(j = 0; j < c; j++)
		{
		mat_final[i][j] = mat_inicial[j][i]
		mat_final[8][j] = mat_inicial[2][j]
		mat_final[i][10] = mat_inicial[i][4]
		}
		escreva(mat_final[i][j], " ")
	}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 487; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {mat_inicial, 12, 10, 11}-{mat_final, 12, 31, 9};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */