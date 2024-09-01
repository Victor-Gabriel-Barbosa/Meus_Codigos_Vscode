programa
{
	
	funcao inicio()
	{inteiro mat_1[2][2], mat_2[2][2], mat_3[2][4], t1 = 2, t2 = 4, i, a, j
	para(i = 0; i < t1; i++)
	{
		para(j = 0; j < t1; j++)
		{
		escreva("Digite o ", i+1, "° número da primeira matriz: ")
		leia(mat_1[i][j])
		mat_3[i][j] = mat_1[i][j]
		}
	}
	para(i = 0; i < t1; i++)
	{
		para(j = 0; j < t1; j++)
		{
		escreva("Digite o ", i+1, "° número da segunda matriz: ")
		leia(mat_2[i][j])
		mat_3[i][j + t1] = mat_2[i][j]
		}
	}
	para(i = 0; i < t1; i++)
	{
		para(j = 0; j < t2; j++)
		{mat[j][i] = mat[i][j]
		     se(mat_3[i][j] < mat_3[j][i])
		     {
		     a = mat_3[i][j]
			mat_3[i][j] = mat_3[j][i]
			mat_3[j][i] = a
		     }
	}

     escreva("O terceiro vetor ordenado de maneira decrescente é: ")
     para(i = 0; i < t1; i++)
     {escreva("\n")
     	para(j = 0; j < t2; j++)
        	{
          escreva(mat_3[i][j], " ")
        	}
     }
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 706; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */