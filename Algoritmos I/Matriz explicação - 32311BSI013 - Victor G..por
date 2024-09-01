/*Matrícula: 32311BSI013
 * Nome: Victor Gabriel Barbosa*/
programa
{
	
	funcao inicio()
	{inteiro mat[3][4]
	/*Para preencher a matriz e ler primeiro as linhas e depois as colunas:*/
		para(inteiro i = 0; i <  3; i++) /*Laço de repetição que irá andar as linhas da matriz*/
		{
			para(inteiro l = 0; l < 4; l++) /*Laço de repetição que irá andar as colunas da matriz*/
			{
			leia(mat[i]/*Primeiro linha*/[l]/*Depois coluna*/)
			}
		}
		/*Para inverter a matriz e ler primeiro as colunas e depois as linhas:*/
		para(inteiro l = 0; l < 4; l++) /*Laço de repetição que irá andar as linhas como se fossem colunas da matriz*/
		{
			para(inteiro i = 0; i <  3; i++) /*Laço de repetição que irá andar as colunas da matriz como se fossem linhas da matriz*/
			{
			leia(mat[i]/*Primeiro linha*/[l]/*Depois coluna*/)
			}
		}		
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 13; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */