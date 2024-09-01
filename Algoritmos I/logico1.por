/*Programa lógico que determina se a sentença é verdadeira ou falsa.
 * O Programa pede se a primeira e a segunda afirmação são iguais e determina se elas são equivalentes.*/
programa
{
	
	funcao inicio()
	{logico p, q, s /*P - Afirmação um, Q - Afirmação dois, s - Conclusão*/
		escreva("A afirmação: 'Está chovendo' é verdadeira ou falsa? ")
		leia(p)
		escreva("A afirmação: 'Peguei o guarda-chuva' é verdadeira ou falsa? ")
		leia (q)
		s = (p == q)
		escreva("A sentença é: ", s)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 479; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */