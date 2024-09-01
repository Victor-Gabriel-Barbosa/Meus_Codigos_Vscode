/*Nome: Victor Gabriel Barbosa; 
 * Data: 29/08/2023
 * 
 * Descrição do problema: 
 * "Foi feita uma estatística em cinco cidades brasileiras para coletar dados sobre acidentes de trânsito.
 * Foram obtidos os seguintes dados:
 * O código da cidade;
 * O número de veículos de passeio;
 * O número de acidentes de trânsito com vítimas.
 * Deseja-se saber:
 * Qual é o maior e o menor índice de acidentes de trânsito e a que cidade pertencem;
 * Qual a média de veículos de passeios nas cinco cidades;
 * Qual a média de acidentes de trânsito nas cidades com menos de 2000 veículos de passeio."
Algorítimo que analisa os dados de veículos e acidentes de trânsito*/
programa
{
	inclua biblioteca Matematica
	
	funcao inicio()
	{real c, v, a, s = 0.0, x = 0.0, y = 0.0, maior_a = 0.0, menor_a = 99999999.0, maior_c = 0.0, menor_c = 0.0
	inteiro i = 1
	para(i = 1; i <= 5; i++)
	{
	escreva("Digite o código da cidade: ")
	leia(c)
	escreva("Digite o número de veículos de passeio da cidade: ")
	leia(v)
	escreva("Digite o número de acidentes de trânsito com vítimas da cidade: ")
	leia(a)
	s = s + v
	se(a > maior_a)
	{
	maior_a = a
	maior_c = c
	}
	se(a < menor_a)
	{
	menor_a = a
	menor_c = c
	}
	se(v < 2000)
	{
	x = x + a
	y++
	}
	}
	s = s/5
	x = x/y
	escreva("A cidade com o menor índice de acidentes é a cidade: ", menor_c, " com: ", menor_a, " acidentes", "\n", "E a cidade com maior número de acidentes é a cidade: ", maior_c, " com: ", maior_a, " acidentes")
	escreva("\n", "A média de veículos nas cinco cidades é: ", s)
	escreva("\n", "A média das cidades com menos de 2000 veículos de passeio é:", x)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 930; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */