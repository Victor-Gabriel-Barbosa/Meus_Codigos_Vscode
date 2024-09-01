programa
{
	
	funcao inicio()
	{inteiro vet_1[10], vet_2[10], vet_3[20], t1 = 10, t2 = 20, i, j, a
	para(i = 0; i < t1; i++)
	{
		escreva("Digite o ", i+1, "° número do primeiro vetor: ")
		leia(vet_1[i])
		vet_3[i] = vet_1[i]
	}
	para(i = 0; i < t1; i++)
	{
		escreva("Digite o ", i+1, "° número do segundo vetor: ")
		leia(vet_2[i])
		vet_3[i + t1] = vet_2[i]
	}
	para(i = 0; i < t2; i++)
	{
		para(j = i + 1; j < t2; j++)
		{
		     se(vet_3[i] < vet_3[j])
		     {
		     a = vet_3[i]
			vet_3[i] = vet_3[j]
			vet_3[j] = a
		     }
	     }
	 }

        escreva("O terceiro vetor ordenado de maneira decrescente é: ")
        para(i = 0; i < 20; i++)
        {
            escreva(vet_3[i], " ")
        }
    }
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 239; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {vet_1, 5, 10, 5}-{vet_2, 5, 21, 5}-{vet_3, 5, 32, 5};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */