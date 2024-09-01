/*Descrição:
 * 19) Faça um programa que preencha uma matriz 8 X 6 de inteiros, calcule e mostre a média dos elementos
das linhas pares da matriz. */
programa
{
	funcao inicio()
	{
        // Declaração de variáveis
        // mat é uma matriz 8x6, i e j são contadores para os loops, l e w são as dimensões da matriz,
        // s[10] é o vetor da soma dos elementos das linhas pares da matriz e m[10] é a vetor da média dos elementos das linhas pares da matriz
        // q é a soma de todos elementos das linhas pares da matriz e d é a média de todos os elementos das linhas pares da matriz
	    inteiro mat[8][6], i, j, l = 8, w = 6, s[10], m[10], q = 0, d = 0

        // Loop para preencher a matriz com números fornecidos pelo usuário
	    para(i = 0; i < l; i++)
	    {
		    para(j = 0; j < w; j++)
		    {
		        escreva("Digite um número: ")
		        leia(mat[i][j])
		    }
	    }
	    
        // Loop para somar todos os elementos da matriz e contar o número total de elementos
	    para(i = 1; i < l; i = i + 2)
	    {
		    para(j = 0; j < w; j++)
		    {
		    		q = mat[i][j] + q
		    		d++
				s[i] = mat[i][j] + s[i]
				m[i]++
		    }
		    
		     // Cálculo da média dos elementos das linhas pares da matriz
		    m[i] = s[i] / m[i]
		    
		     // Impressão da média dos elementos da matriz
		    escreva("A média na ", i+1, "° linha (par) é: ", m[i], "\n")
	    }
	    
	    // Cálculo da média dos elementos de todas as linhas pares da matriz
	    q = q/d
	    
	    // Impressão da média dos elementos das linhas pares da matriz
	    escreva("A média de todas as linhas pares é: ", q)
	}
}

/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 881; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */