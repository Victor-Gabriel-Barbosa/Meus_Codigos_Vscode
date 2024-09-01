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
	{inteiro vet[10], n, i
	para(i = 0; i < 10; i++)
	{	
	escreva("Digite um número qualquer: ")
	leia(vet[i])
	}
	escreva("Digite um outro número qualquer: ")
	leia(n)
	para(i = 0; i < 10; i++)
	{
		se(vet[i] == n)
		{
		escreva("O número: ", vet[i], " está no vetor", "na posição: ", i)
		}
	}
	}
}

/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 692; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */