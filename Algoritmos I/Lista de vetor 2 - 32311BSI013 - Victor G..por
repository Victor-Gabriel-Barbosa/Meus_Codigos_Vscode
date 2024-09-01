/*Matrícula: 32311BSI013
 * Nome: Victor Gabriel Barbosa
 * Atividade proposta:
 * 02) - Faça um algoritmo para ler e armazenar em um vetor a temperatura média de todos os meses
do ano. Calcular e escrever:
a) Menor temperatura do ano 
b) Maior temperatura do ano 
c) Temperatura média anual
d) O número de meses no ano em que a temperatura foi inferior a média anual*/
programa
{
	
	funcao inicio()
	{real temp[12], s = 0.0, menor = 0.0, maior = 0.0, x = 0.0, j = 0.0
	para(inteiro i = 0; i < 12; i++)
	{	
	escreva("A temperatura média no mês ", i + 1, " em °c foi de: ")
	leia(temp[i])
	menor = temp[i] + 1
	maior = temp[i] - 1
	s = temp[i] + s
	x++
	}
	s = s / x
	para(inteiro i = 0; i < 12; i++)
	{
		se(menor > temp[i])
		{
		menor = temp[i]
		}
			se(maior < temp[i])
			{
			maior = temp[i]
			}
				se(s < temp[i])
				{
				j++
				}
	}
	escreva("A menor tempreatura do ano foi de: ", menor, "°c", "\n", "A maior temperatura do ano foi de: ", maior, "°c", "\n")
	escreva("A média de temperaturas do ano foi de: ", s, "°c", "\n")
	escreva("O número de meses no ano em que a temperatura foi inferior a média anual foi de: ", j)
	}
}

/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 544; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {temp, 14, 7, 4};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */