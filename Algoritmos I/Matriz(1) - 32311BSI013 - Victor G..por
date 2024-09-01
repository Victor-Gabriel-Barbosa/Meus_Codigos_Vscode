/*Matrícula: 32311BSI013
 * Nome: Victor Gabriel Barbosa*/
programa
{
	
	funcao inicio()
	{inteiro mat[3][4], i, l, menor[10], maior[10], s = 0, m = 0, vet[10], x = 0, w = 0
		para(i = 0; i < 3; i++)
		{
			para(l = 0; l < 4; l++)
			{
			escreva("Digite um número: ")
			leia(mat[i][l])
			}
		}
		para(i = 0; i < 3; i++) 
		{
			escreva("\n")
			para(l = 0; l < 4; l++)
			{
			escreva(mat[i][l], " ")
			s = mat[i][l] + s
			m++
			}
		vet[i] = s / m
		}
		para(i = 0; i < 3; i++)
		{
		escreva("\n", "A média aritmética da linha: ", x++, " é: ", vet[i], "\n")
		}
		para(i = 0; i < 3; i++) 
		{
			para(l = 0; l < 4; l++)
			{
			menor[i] = mat[i][l] + menor[i]
			maior[i] = mat[i][l] - maior[i]
			}
		}
		para(i = 0; i < 3; i++) 
		{
			para(l = 0; l < 4; l++)
			{
				se(mat[i][l] < menor[i])
				{
				menor[i] = mat[i][l]
				}
				se(mat[i][l] > maior[i])
				{
				maior[i] = mat[i][l] 
				}	
			}
		escreva("\n", "Na linha: ", w++, " o menor número é: ", menor[i], "\n", "E o maior número é: ", maior[i])
	}
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 772; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */